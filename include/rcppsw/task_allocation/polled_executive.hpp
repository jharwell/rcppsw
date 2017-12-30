/**
 * @file polled_executive.hpp
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

#ifndef INCLUDE_RCPPSW_TASK_ALLOCATION_POLLED_EXECUTIVE_HPP_
#define INCLUDE_RCPPSW_TASK_ALLOCATION_POLLED_EXECUTIVE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/task_allocation/executive.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class polled_executive : public executive {
 public:
  polled_executive(const std::shared_ptr<rcppsw::er::server>& server,
                   executable_task* root)
      : executive(server, root) {}

  void run(void) override;

 private:
  void handle_task_start(class polled_task* new_task);
  void handle_task_abort(class polled_task* task);
  void handle_task_finish(class polled_task* task);
};

NS_END(task_allocation, rcppsw);

#endif /* INCLUDE_RCPPSW_TASK_ALLOCATION_POLLED_EXECUTIVE_HPP_ */
