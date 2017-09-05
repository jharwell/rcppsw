/**
 * @file partition_probability.hpp
 *
 * @copyright 2017 John Harwell, All rights reserved.
 *
 * This file is part of RCPPSW.
 *
 * RCPPSW is free software: you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 *
 * RCPPSW is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 * A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * RCPPSW.  If not, see <http://www.gnu.org/licenses/
 */

#ifndef INCLUDE_RCPPSW_TASK_ALLOCATION_PARTITION_PROBABILITY_HPP_
#define INCLUDE_RCPPSW_TASK_ALLOCATION_PARTITION_PROBABILITY_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <cmath>
#include "rcppsw/math/expression.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Calculates the probability that a robot partitions its current task.
 *
 * Depends on:
 *
 * - The robot's time estimates of how long it takes to complete each of the two
 *   subtasks, as well as an estimate of how long it takes to complete the
 *   unpartitioned task.
 *
 * - The reactivity parameter: how sensitive should robots be to abrupt changes
 *   in the estimates?
 */
class partition_probability: public rcppsw::math::expression<double> {
 public:
  explicit partition_probability(double reactivity) :
      m_reactivity(reactivity) {}

  double calc(double task_time_estimate, double subtask1_time_estimate,
              double subtask2_time_estimate) {
    if (task_time_estimate > subtask1_time_estimate + subtask2_time_estimate) {
      double res = 1 + std::exp(-m_reactivity *
                                ((task_time_estimate /
                                  (subtask1_time_estimate + subtask2_time_estimate)) - 1));
      return set_result(1/res);
    } else {
      double res = 1 + std::exp(-m_reactivity * (1 -
                                                 ((subtask1_time_estimate + subtask2_time_estimate) /
                                                  task_time_estimate)));
      return set_result(1/res);
    }
  }
 private:
  double m_reactivity;
};

NS_END(task_allocation, rcppsw);

#endif /* INCLUDE_RCPPSW_TASK_ALLOCATION_PARTITION_PROBABILITY_HPP_ */
