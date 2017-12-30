/**
 * @file subtask_selection_probability.hpp
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

#ifndef INCLUDE_RCPPSW_TASK_ALLOCATION_SUBTASK_SELECTION_PROBABILITY_HPP_
#define INCLUDE_RCPPSW_TASK_ALLOCATION_SUBTASK_SELECTION_PROBABILITY_HPP_

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
 * @brief Calculates the probability that a robot selects subtask 2 when it has
 * most recently executed subtask 1 (assuming partitioning is employed).
 *
 * Taken/adapted from Brutschy2014.
 *
 * Depends on:
 *
 * - The robot's time estimates of how long it takes to complete each of the two
 *   subtasks
 *
 * - The reactivity parameter: how quickly should the increase in selection
 *   probability be for an increasing difference between subtask time estimates.
 *
 * - The offset parameter: how quickly should robots react to an increasing
 *   difference between subtask time estimates?
 *
 * - 0 < reactivity < 1.
 * - offset > 1.
 * - 0 < gamma < 1.
 *
 */
class subtask_selection_probability : public rcppsw::math::expression<double> {
 public:
  explicit subtask_selection_probability(std::string method)
      : mc_method(std::move(method)), m_reactivity(0), m_offset(0), m_gamma(0) {}

  void init_brutschy2014(double reactivity, double offset, double gamma);
  double calc(const time_estimate* subtask1, const time_estimate* subtask2);

  const std::string& method(void) const { return mc_method; }

 private:
  double calc_random(void);
  double calc_brutschy2014(const time_estimate& subtask1,
                           const time_estimate& subtask2);

  const std::string mc_method;
  double m_reactivity;
  double m_offset;
  double m_gamma;
};

NS_END(task_allocation, rcppsw);

#endif /* INCLUDE_RCPPSW_TASK_ALLOCATION_SUBTASK_SELECTION_PROBABILITY_HPP_ */
