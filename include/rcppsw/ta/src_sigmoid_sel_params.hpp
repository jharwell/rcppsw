/**
 * @file src_sigmoid_sel_params.hpp
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

#ifndef INCLUDE_RCPPSW_TA_SRC_SIGMOID_SEL_PARAMS_HPP_
#define INCLUDE_RCPPSW_TA_SRC_SIGMOID_SEL_PARAMS_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "rcppsw/params/base_params.hpp"
#include "rcppsw/ta/sigmoid_sel_params.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ta);

/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/
/**
 * @struct src_sigmoid_sel_params
* @ingroup params ta
 */
struct src_sigmoid_sel_params : public params::base_params {
  /**
   * @brief What should the source of the input into abort probability
   * calculations be? Valid values are: ["exec", "interface"], referring to
   * execution time and interface time for a task.
   */
  std::string input_src{};
  sigmoid_sel_params sigmoid{};
};

NS_END(ta, rcppsw);

#endif /* INCLUDE_RCPPSW_TA_SRC_SIGMOID_SEL_PARAMS_HPP_ */
