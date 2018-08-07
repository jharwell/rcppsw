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
#include "rcppsw/task_allocation/task_params.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
executable_task::executable_task(const std::string &name,
                                 const struct task_params *c_params)
    : logical_task(name), m_interface_estimate(c_params->estimation.alpha),
      m_exec_estimate(c_params->estimation.alpha) {}

executable_task::executable_task(const executable_task &other)
    : logical_task(other), m_interface_time(other.m_interface_time),
      m_interface_start_time(other.m_interface_start_time),
      m_exec_time(other.m_exec_time),
      m_exec_start_time(other.m_exec_start_time),
      m_interface_estimate(other.m_interface_estimate),
      m_exec_estimate(other.m_exec_estimate) {}

executable_task::~executable_task(void) = default;

NS_END(task_allocation, rcppsw);
