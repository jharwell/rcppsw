/*******************************************************************************
 * Name            : boolean_joint_distribution.cpp
 * Project         : rcppsw
 * Module          : bayes
 * Description     : Implementation of Boolean joint distribution, and
 *                   operations on/between them
 * Creation Date   : 02/13/17
 * Copyright       : Copyright 2017 John Harwell, All rights reserved
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/bayes/boolean_joint_distribution.hpp"
#include "rcsw/common/fpc.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace bayes = rcppsw::bayes;

/*******************************************************************************
 * Constant Definitions
 ******************************************************************************/

/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/

/*******************************************************************************
 * Global Variables
 ******************************************************************************/

/*******************************************************************************
 * Forward Declarations
 ******************************************************************************/

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
/**
 * boolean_joint_distribution::value() - Set the value of a preposition over the
 * distribution
 *
 * bool - TRUE is successful, FALSE otherwise
 **/
bool bayes::boolean_joint_distribution::preposition(
    const std::vector<std::pair<std::string, bool>>& spec,
    float value) {
  FPC_CHECK(false, spec.size() == n_vars_);
  std::size_t index = 0;
  for (std::size_t i = 0; i < n_vars_; ++i) {
    if (spec[i].second) {
      index += std::pow(2,i);
    }
  } /* for(i..) */
  dist_[index] = value;
  return true;
} /* boolean_joint_distribution::preposition() */

/**
 * boolean_joint_distribution::preposition() - Get the preposition of a
 * preposition over the distribution
 *
 * float - The preposition
 **/
float bayes::boolean_joint_distribution::preposition(
    const std::vector<std::pair<std::string, bool>>& spec) const {
  FPC_CHECK(std::numeric_limits<float>::quiet_NaN(),spec.size() == n_vars_);

  std::size_t index = preposition_to_index(spec);
  return dist_[index];
} /* boolean_joint_distribution::preposition() */

/**
 * boolean_joint_distribution::indices_t() - Get a list of all indices for
 * which the specified variable is true
 *
 * std::vector<std::size_t> - The list
 **/
std::vector<std::size_t> bayes::boolean_joint_distribution::indices_t(
    const std::string& name) const {
  std::size_t pos = std::distance(names_.begin(),
                                  std::find(names_.begin(), names_.end(), name));

  std::vector<std::size_t> indices_t;
  for (std::size_t i = 0; i < n_vars_; ++i) {
    if (i & (1 << pos)) {
      indices_t.push_back(i);
    }
  } /* for(i..) */
  return indices_t;
} /* boolean_joint_distribution::indices_t() */

/**
 * boolean_joint_distribution::indices_f() - Get a list of all indices for
 * which the specified variable is false
 *
 * std::vector<std::size_t> - The list
 **/
std::vector<std::size_t> bayes::boolean_joint_distribution::indices_f(
    const std::string& name) const {
  std::size_t pos = std::distance(names_.begin(),
                                  std::find(names_.begin(), names_.end(), name));

  std::vector<std::size_t> indices_f;
  for (std::size_t i = 0; i < n_vars_; ++i) {
    if (!(i & (1 << pos))) {
      indices_f.push_back(i);
    }
  } /* for(i..) */
  return indices_f;
} /* boolean_joint_distribution::indices_f() */

bayes::boolean_joint_distribution bayes::boolean_joint_distribution::operator*(const bayes::boolean_joint_distribution& rhs) {
    std::vector<std::string> new_names = this->names_;

    /* Find the 1 var that both distributions have in common */
    std::string common;
    assert(this->names_[0] == common);
    for (std::vector<std::string>::const_iterator it = new_names.begin(); it!= new_names.end(); ++it) {
      if (std::find(rhs.names_.begin(),
                    rhs.names_.end(), *it) != rhs.names_.end()) {
        common = *it;
      }
    } /* for(i..) */

    /* get common indices (must be same size!) */
    std::vector<std::size_t> lhs_indices_t = this->indices_t(common);
    std::vector<std::size_t> rhs_indices_t = rhs.indices_t(common);
    std::vector<std::size_t> lhs_indices_f = this->indices_f(common);
    std::vector<std::size_t> rhs_indices_f = rhs.indices_f(common);
    assert(lhs_indices_t.size() == rhs_indices_t.size());
    assert(lhs_indices_f.size() == rhs_indices_f.size());

    std::vector<float> res;

    /* MULTIPLY! */
    for (size_t i = 0; i < this->dist_.size(); ++i) {
      std::vector<std::pair<std::string, bool>> prep = index_to_preposition(i);
      if (true == value_in_preposition(prep, common)) {
        std::for_each(rhs_indices_t.begin(), rhs_indices_t.end(), [&](float f) {
            res.push_back(this->dist_[i]*f);
          });
      } else {
        std::for_each(rhs_indices_f.begin(), rhs_indices_f.end(), [&](float f) {
            res.push_back(this->dist_[i]*f);
          });
      }
    } /* for(i..) */
    bayes::boolean_joint_distribution ret(this->names_);
    ret.names_.insert(ret.names_.end(), rhs.names_.begin(), rhs.names_.end());
    ret.names_.erase(std::remove(ret.names_.begin(),
                                 ret.names_.end(), common),
                     ret.names_.end());
    return ret;
}

/**
 * boolean_joint_distribution::sum_out() - Sum out a variable from the
 * distribution
 *
 * void - N/A
 **/
void bayes::boolean_joint_distribution::sum_out(const std::string& name) {
  std::vector<std::size_t> indices_true = indices_t(name);
  std::vector<std::size_t> indices_false = indices_f(name);
  std::vector<float> dist_new(indices_true.size());
  for (size_t i = 0; i < indices_true.size(); ++i) {
    dist_new[i] = indices_true[i] + indices_false[i];
  } /* for(i..) */
  dist_ = dist_new;
} /* boolean_joint_distribution::sum_out() */
