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
#include <string>

#include "rcppsw/er/client.hpp"
#include "rcppsw/math/expression.hpp"
#include "rcppsw/math/sigmoid.hpp"
#include "rcppsw/task_allocation/time_estimate.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class partition_probability
 * @ingroup task_allocation
 *
 * @brief Calculates the probability that a robot partitions its current task
 * using the negative exponential distribution.
 *
 * Reactivity is assumed to be > 0.
 * Offset is assumed to be > 0.
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
class partition_probability : public math::sigmoid,
                              er::client<partition_probability> {
 public:
  static constexpr char kMethodPini2011[] = "pini2011";

  /*
   * A default reactivity value determined experimentally to work well.
   */
  static constexpr double kDEFAULT_REACTIVITY = 1.5;

  /*
   * A default reactivity value that does *not* induce singularities in the
   * overall equation. Choose not to employ it at your own risk...
   */
  static constexpr double kDEFAULT_OFFSET = 1.0;

  /* A default gamma value because there needs to be one */
  static constexpr double kDEFAULT_GAMMA = 1.0;

  static constexpr double kNO_EST_PARTITION_PROB = 0.5;

  /**
   * @brief Initialize partitioning probability with default values based on
   * whatever the selected method is.
   */
  explicit partition_probability(const std::string& method)
      : sigmoid(kDEFAULT_REACTIVITY, kDEFAULT_OFFSET, kDEFAULT_GAMMA),
        ER_CLIENT_INIT("rcppsw.ta.partition_probability"),
        mc_method(method) {}

  /**
   * @brief Initialize partitioning probability explicity with method +
   * parameter values.
   */
  explicit partition_probability(const struct sigmoid_sel_params* params);

  double operator()(const time_estimate& task,
                    const time_estimate& subtask1,
                    const time_estimate& subtask2);

  double calc(const time_estimate& task,
              const time_estimate& subtask1,
              const time_estimate& subtask2) {
    return operator()(task, subtask1, subtask2);
  }
  const std::string& method(void) const { return mc_method; }

 private:
  double calc_pini2011(const time_estimate& task,
                       const time_estimate& subtask1,
                       const time_estimate& subtask2);

  /* clang-format off */
  const std::string mc_method;
  /* clang-format on */
};

NS_END(task_allocation, rcppsw);

#endif /* INCLUDE_RCPPSW_TASK_ALLOCATION_PARTITION_PROBABILITY_HPP_ */
