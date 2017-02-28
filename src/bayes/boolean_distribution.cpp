/*******************************************************************************
 * Name            : boolean_distribution.cpp
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
#include "rcppsw/bayes/boolean_distribution.hpp"
#include <algorithm>
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
 * boolean_distribution::value() - Set the value of a preposition over the
 * distribution. The preposition must be ordered from MSB to LSB variables
 *
 * bool - TRUE is successful, FALSE otherwise
 **/
bool bayes::boolean_distribution::preposition(
    const std::vector<std::pair<std::string, bool>>& spec,
    float value) {
  FPC_CHECK(false, spec.size() == n_vars_);

  auto spec2 = spec;
  std::reverse(spec2.begin(), spec2.end());

  std::size_t index = 0;
  for (size_t i = 0 ; i < n_vars_; ++i) {
    /* std::cout << "pos " << i << " " << spec2[i].second <<std::endl; */
    if (spec2[i].second) {
      index += std::pow(2, i);
    }
  } /* for(i..) */
  dist_[index] = value;
  return true;
} /* boolean_distribution::preposition() */

/**
 * boolean_distribution::preposition() - Get the preposition of a
 * preposition over the distribution
 *
 * float - The preposition
 **/
float bayes::boolean_distribution::preposition(
    const std::vector<std::pair<std::string, bool>>& spec) const {
  FPC_CHECK(std::numeric_limits<float>::quiet_NaN(),spec.size() == n_vars_);

  std::size_t index = preposition_to_index(spec);
  return dist_[index];
} /* boolean_distribution::preposition() */

/**
 * boolean_distribution::indices_t() - Get a list of all indices for
 * which the specified variable is true
 *
 * std::vector<std::size_t> - The list
 **/
std::vector<std::size_t> bayes::boolean_distribution::indices_t(
    const std::string& name) const {
  std::size_t pos = std::distance(names_.begin(),
                                  std::find(names_.begin(), names_.end(), name));

  std::vector<std::size_t> indices_t;
  for (std::size_t i = 0; i < std::pow(2, n_vars_); ++i) {
    if (i & (1 << pos)) {
      indices_t.push_back(i);
    }
  } /* for(i..) */
  return indices_t;
} /* boolean_distribution::indices_t() */

/**
 * boolean_distribution::indices_f() - Get a list of all indices for
 * which the specified variable is false
 *
 * std::vector<std::size_t> - The list
 **/
std::vector<std::size_t> bayes::boolean_distribution::indices_f(
    const std::string& name) const {
  std::size_t pos = std::distance(names_.begin(),
                                  std::find(names_.begin(), names_.end(), name));

  std::vector<std::size_t> indices_f;
  for (std::size_t i = 0; i < std::pow(2, n_vars_); ++i) {
    if (!(i & (1 << pos))) {
      indices_f.push_back(i);
    }
  } /* for(i..) */
  return indices_f;
} /* boolean_distribution::indices_f() */

/**
 * boolean_distribution::sum_out() - Sum out a variable from the
 * distribution
 *
 * void - N/A
 **/
void bayes::boolean_distribution::sum_out(const std::string& name) {
  std::vector<std::size_t> indices_true = indices_t(name);
  std::vector<std::size_t> indices_false = indices_f(name);
  std::vector<float> dist_new(indices_true.size());
  std::cout << "Sum out " << name << std::endl;
  for (size_t i = 0; i < indices_true.size(); ++i) {
    dist_new[i] = dist_[indices_true[i]] + dist_[indices_false[i]];
  } /* for(i..) */

  dist_ = dist_new;
  names_.erase(std::find(names_.begin(),
                         names_.end(), name));
  n_vars_--;
  assert(names_.size() == n_vars_);
  assert(dist_.size() == std::pow(2,n_vars_));

  std::cout << "Result:\n";
  std::cout << *this;
} /* boolean_distribution::sum_out() */

/**
 * boolean_distribution::not_sum() - Sum out all variables except the one
 * specified
 *
 * void - N/A
 **/
void bayes::boolean_distribution::not_sum(const std::string& name) {
  std::vector<std::string> names2 = names_;
  std::cout << "Not sum over " << name << std::endl;
  for (auto it = names2.begin(); it != names2.end(); ++it) {
    if ((*it) != name) {
      sum_out(*it);
    }
  } /* (it...) */
  std::cout << "Result:\n";
  std::cout << *this;
} /* boolean_distribution::not_sum() */

/*******************************************************************************
 * Operators
 ******************************************************************************/
bayes::boolean_distribution bayes::boolean_distribution::operator*(
    const bayes::boolean_distribution& rhs) {
    std::vector<std::string> new_names = this->names_;
    std::cout << "Multiplying" << std::endl;
    std::cout << *this;
    std::cout << "and" << std::endl;
    std::cout << rhs;
    if (rhs.names_[0] == "unity") {
      return *this;
    }
    /* Find the 1 var that both distributions have in common */
    std::string common;
    for (std::vector<std::string>::const_iterator it = new_names.begin();
         it!= new_names.end(); ++it) {
      if (std::find(rhs.names_.begin(),
                    rhs.names_.end(), *it) != rhs.names_.end()) {
        common = *it;
      }
    } /* for(i..) */

    /* get common indices */
    std::vector<std::size_t> lhs_indices_t = this->indices_t(common);
    std::vector<std::size_t> rhs_indices_t = rhs.indices_t(common);
    std::vector<std::size_t> lhs_indices_f = this->indices_f(common);
    std::vector<std::size_t> rhs_indices_f = rhs.indices_f(common);

    std::vector<float> res;

    /* MULTIPLY! */
    for (int i = 0; i < std::pow(2, n_vars_); ++i) {
      std::vector<std::pair<std::string, bool>> prep = index_to_preposition(i);
      if (true == value_in_preposition(prep, common)) {
        std::for_each(rhs_indices_t.begin(), rhs_indices_t.end(),
                      [&](std::size_t index) {
            res.push_back(this->dist_[i]*rhs.dist_[index]);
          });
      } else {
        std::for_each(rhs_indices_f.begin(), rhs_indices_f.end(),
                      [&](std::size_t index) {
            res.push_back(this->dist_[i]*rhs.dist_[index]);
          });
      }
    } /* for(i..) */
    std::vector<std::string> names2 = this->names_;
    std::reverse(names2.begin(), names2.end());
    bayes::boolean_distribution ret(names2);
    std::vector<std::string> additional_names = rhs.names_;
    additional_names.erase(std::remove(additional_names.begin(),
                                       additional_names.end(),
                                       common));
    ret.names_.insert(ret.names_.end(), additional_names.begin(), additional_names.end());
    /* ret.names_.erase(std::remove(ret.names_.begin(), */
    /*                              ret.names_.end(), common), */
    /*                  ret.names_.end()); */
    ret.dist_ = res;
    std::cout << "Result:\n";
    std::cout << ret;
    return ret;
} /* boolean_distribution::operator*() */

std::ostream& bayes::operator<<(std::ostream& stream,
                         const bayes::boolean_distribution& rhs) {
  return rhs.operator<<(stream);
}
std::ostream& bayes::boolean_distribution::operator<<(
    std::ostream& stream) const {
  std::for_each(names_.rbegin(), names_.rend(),
                [&](const std::string& name) {
                  stream << name << ",";
                });
  stream << std::endl;
  stream << "----------\n";
  for (size_t i = 0; i < std::pow(2, n_vars_); ++i) {
    for (int j = n_vars_ - 1; j >= 0; --j) {
      if (i & (1 << j)) {
        stream << "T ";
      } else {
        stream << "F ";
      }
    } /* for(j..) */
    stream << dist_[i] << std::endl;
  } /* for(i..) */
  return stream;
} /* boolean_distribution::to_stream() */
