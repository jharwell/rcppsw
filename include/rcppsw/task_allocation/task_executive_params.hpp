/**
 * @file task_executive_params.hpp
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

#ifndef INCLUDE_RCPPSW_TASK_ALLOCATION_TASK_EXECUTIVE_PARAMS_HPP_
#define INCLUDE_RCPPSW_TASK_ALLOCATION_TASK_EXECUTIVE_PARAMS_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "rcppsw/params/base_params.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/
/**
 * @struct task_executive_params
* @ingroup params task_allocation
 */
struct task_executive_params : public params::base_params {
  /**
   * @brief Should the executive automatically update execution time estimates
   * for tasks, or will that be handled in the application via callbacks?
   */
  bool update_exec_ests{true};

  /**
   * @brief Should the executive automatically update interface time estimates
   * for tasks, or will that be handled in the application via callbacks?
   */
  bool update_interface_ests{true};

  /**
   * @brief Method for specifying the initially active TAB in the
   * executive. Valid values are: [root, random, max_depth].
   */
  std::string tab_init_method{""};
};

NS_END(task_allocation, rcppsw);

#endif /* INCLUDE_RCPPSW_TASK_ALLOCATION_TASK_EXECUTIVE_PARAMS_HPP_ */
