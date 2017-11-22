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
executable_task::executable_task(const std::string& name,
                                 const struct task_params* const params,
                executable_task* const parent) :
    logical_task(name, parent),
    m_is_atomic(false),
    m_is_partitionable(false),
    m_exec_time(0.0), m_start_time(),
    m_estimate(params->estimation_alpha),
    m_abort_prob(params->reactivity,
                 params->proportionality_estimate,
                 params->abort_offset) {}

executable_task::executable_task(const executable_task& other) :
    logical_task(other), m_is_atomic(false), m_is_partitionable(false),
    m_exec_time(other.m_exec_time),
    m_start_time(other.m_start_time),
    m_estimate(other.m_estimate),
    m_abort_prob(other.m_abort_prob) {}

executable_task::~executable_task(void) {}

NS_END(task_allocation, rcppsw);
