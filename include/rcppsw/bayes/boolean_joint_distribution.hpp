/*******************************************************************************
 * Name            : boolean_joint_distribution.hpp
 * Project         : rcppsw
 * Module          : bayes
 * Description     : Representation of a joint probability distribution between
 *                   multiple Boolean_Joint variables
 * Creation Date   : 02/13/17
 * Copyright       : Copyright 2017 John Harwell, All rights reserved
 *
 ******************************************************************************/

#ifndef INCLUDE_RCPPSW_BAYES_BOOLEAN_JOINT_DISTRIBUTION_HPP_
#define INCLUDE_RCPPSW_BAYES_BOOLEAN_JOINT_DISTRIBUTION_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <assert.h>

#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <iostream>
#include "rcppsw/bayes/boolean_variable.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace rcppsw {
namespace bayes {

/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class boolean_joint_distribution {
 public:
  /* constructors */
  explicit boolean_joint_distribution(const std::vector<std::string>& names) :
      n_vars_(names.size()),
      dist_(std::pow(2, n_vars_)), names_(names) {
    std::reverse(names_.begin(), names_.end());
  }

  boolean_joint_distribution(void) : n_vars_(0), dist_(), names_() {}

  /* member functions */
  bool preposition(const std::vector<std::pair<std::string, bool>>& spec,
                   float value);
  float preposition(const std::vector<std::pair<std::string,
                    bool>>& spec) const;

  const std::vector<std::string>& names(void) const { return names_; }
  std::vector<std::size_t> indices_t(const std::string& name) const;
  std::vector<std::size_t> indices_f(const std::string& name) const;

  void sum_out(const std::string& name);
  void not_sum(const std::string& name);
  boolean_joint_distribution& normalize(void) {
    float total = std::accumulate(dist_.begin(), dist_.end(), 0.0);
    for (size_t i = 0; i < dist_.size(); ++i) {
      dist_[i] /= total;
    } /* for(i..) */
    return *this;
  }

  /* operators */
  boolean_joint_distribution operator*(
      const bayes::boolean_joint_distribution& rhs);
  std::ostream& operator<<(
      std::ostream& stream) const;

 private:
  /* member functions */
  std::size_t preposition_to_index(const std::vector<std::pair<std::string,
                                   bool>>& spec) const {
    std::size_t index = 0;
    for (std::size_t i = 0; i < n_vars_; ++i) {
      if (spec[i].second) {
        index += std::pow(2, i);
      }
    } /* for(i..) */
    return index;
  }

  std::vector<std::pair<std::string, bool>> index_to_preposition(
      std::size_t index) const {
    assert(index <= std::pow(2, n_vars_) - 1);
    std::vector<std::pair<std::string, bool>> res(n_vars_,
                                                  std::pair<std::string,
                                                  bool>("", false));
    for (size_t i = 0; i < n_vars_; ++i) {
      res[i].first = names_[i];
    } /* for(i..) */

    for (std::size_t i = 0; i < index; ++i) {
      if (index & (1 << i)) {
        res[i].second = true;
      }
    } /* for(i..) */
    return res;
  }
  bool value_in_preposition(
      const std::vector<std::pair<std::string, bool>>& prep,
      const std::string& name) {
    bool ret = false;
    std::for_each(prep.begin(), prep.end(),
                  [&](const std::pair<std::string, bool>& p) {
                    if (p.first == name) {
                      ret = true;
                    }
                  });
    return ret;
  }
  /* data members */
  std::size_t n_vars_;
  std::vector<float> dist_;
  std::vector<std::string> names_;
};

/*******************************************************************************
 * Operater Definitions
 ******************************************************************************/
std::ostream& operator<<(std::ostream& stream,
                         const boolean_joint_distribution& rhs);

} /* namespace bayes */
} /* namespace rcppsw */

#endif /* INCLUDE_RCPPSW_BAYES_BOOLEAN_JOINT_DISTRIBUTION_HPP_ */
