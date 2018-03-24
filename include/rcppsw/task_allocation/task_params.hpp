/**
 * @file task_params.hpp
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

#ifndef INCLUDE_RCPPSW_TASK_ALLOCATION_TASK_PARAMS_HPP_
#define INCLUDE_RCPPSW_TASK_ALLOCATION_TASK_PARAMS_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "rcppsw/params/base_params.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/
/**
 * @struct task_params
 * @ingroup task_allocation
 *
 * @brief Parameters used by \ref executable_task tasks.
 */
struct task_params : public params::base_params {
  double estimation_alpha{0.0};
  double abort_reactivity{0.0};
  double abort_offset{0.0};
  double partition_reactivity{0.0};
  double partition_offset{0.0};
};

NS_END(task_allocation, rcppsw);

#endif /* INCLUDE_RCPPSW_TASK_ALLOCATION_TASK_PARAMS_HPP_ */
