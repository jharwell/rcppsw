/**
 * @file task_allocation_params.hpp
 *
 * @copyright 2018 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_TASK_ALLOCATION_TASK_ALLOCATION_PARAMS_HPP_
#define INCLUDE_RCPPSW_TASK_ALLOCATION_TASK_ALLOCATION_PARAMS_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/params/base_params.hpp"
#include "rcppsw/task_allocation/exec_estimates_params.hpp"
#include "rcppsw/task_allocation/src_sigmoid_sel_params.hpp"
#include "rcppsw/task_allocation/task_partition_params.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/
/**
 * @struct task_allocation_params
 * @ingroup task_allocation params
 */
struct task_allocation_params : public rcppsw::params::base_params {
  exec_estimates_params exec_est{};
  src_sigmoid_sel_params abort{};
  src_sigmoid_sel_params subtask_sel{};
  task_partition_params partitioning{};
  src_sigmoid_sel_params tab_sel{};
};

NS_END(task_allocation, rcppsw);

#endif /* INCLUDE_RCPPSW_TASK_ALLOCATION_TASK_ALLOCATION_PARAMS_HPP_ */
