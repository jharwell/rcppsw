/**
 * @file partition_probability.hpp
 * @ingroup task_allocation
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
#include <string>

#include "rcppsw/math/expression.hpp"
#include "rcppsw/task_allocation/time_estimate.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class partition_probability
 *
 * @brief Calculates the probability that a robot partitions its current task
 * using the negative exponential distribution.
 *
 * Reactivity is assumed to be > 0.
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
class partition_probability : public rcppsw::math::expression<double> {
 public:
  explicit partition_probability(std::string method, double reactivity)
      : mc_method(std::move(method)), m_reactivity(reactivity) {}

  double calc(const time_estimate& task,
              const time_estimate& subtask1,
              const time_estimate& subtask2);

  const std::string& method(void) const { return mc_method; }

 private:
  double calc_pini2011(const time_estimate& task,
                       const time_estimate& subtask1,
                       const time_estimate& subtask2);

  const std::string mc_method;
  double m_reactivity;
};

NS_END(task_allocation, rcppsw);

#endif /* INCLUDE_RCPPSW_TASK_ALLOCATION_PARTITION_PROBABILITY_HPP_ */
