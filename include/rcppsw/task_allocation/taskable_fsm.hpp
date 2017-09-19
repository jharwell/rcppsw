/**
 * @file taskable_fsm.hpp
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

#ifndef INCLUDE_RCPPSW_TASK_ALLOCATION_TASKABLE_FSM_HPP_
#define INCLUDE_RCPPSW_TASK_ALLOCATION_TASKABLE_FSM_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/task_allocation/taskable.hpp"
#include "rcppsw/patterns/state_machine/base_fsm.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class taskable_fsm : public taskable, public patterns::state_machine::base_fsm {
 public:
  explicit taskable_fsm(const std::shared_ptr<common::er_server>& server) :
      base_fsm(server) {}
  virtual ~taskable_fsm(void) {}

  virtual void task_reset(void) { init(); }
  virtual void task_start(void) { generated_event(true); state_engine(); }
};

NS_END(rcppsw, task_allocation);

#endif /* INCLUDE_RCPPSW_TASK_ALLOCATION_TASKABLE_FSM_HPP_ */
