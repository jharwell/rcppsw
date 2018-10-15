/**
 * @file executable_task.cpp
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

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/task_allocation/executable_task.hpp"
#include "rcppsw/math/ema_params.hpp"
#include "rcppsw/task_allocation/time_estimate.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
executable_task::executable_task(const std::string &name,
                                 const struct math::sigmoid_params* abort,
                                 const struct math::ema_params* estimation)
    : logical_task(name),
      m_interface_in_prog(kMAX_INTERFACES, false),
      m_interface_times(kMAX_INTERFACES, 0.0),
      m_last_interface_times(kMAX_INTERFACES, 0.0),
      m_interface_start_times(kMAX_INTERFACES, 0.0),
      m_interface_estimates(kMAX_INTERFACES, time_estimate(estimation->alpha)),
      m_exec_estimate(estimation->alpha),
      m_abort_prob(abort) {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
int executable_task::active_interface(void) const {
  for (size_t i = 0; i < m_interface_in_prog.size(); ++i) {
    if (m_interface_in_prog[i]) {
      return i;
    }
  } /* for(i..) */

return -1;
} /* active_interface() */


NS_END(task_allocation, rcppsw);
