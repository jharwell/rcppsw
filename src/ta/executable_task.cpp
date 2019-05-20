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
#include "rcppsw/ta/executable_task.hpp"
#include "rcppsw/math/config/ema_config.hpp"
#include "rcppsw/ta/config/src_sigmoid_sel_config.hpp"
#include "rcppsw/ta/time_estimate.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ta);

/*******************************************************************************
 * Global Variables
 ******************************************************************************/
constexpr char executable_task::kAbortSrcExec[];
constexpr char executable_task::kAbortSrcInterface[];

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
executable_task::executable_task(const std::string& name,
                                 const config::src_sigmoid_sel_config* abort,
                                 const math::config::ema_config* estimation)
    : logical_task(name),
      ER_CLIENT_INIT("rcppsw.ta.executable_task"),
      mc_abort_src(abort->input_src),
      m_interface_in_prog(kMAX_INTERFACES, false),
      m_interface_times(kMAX_INTERFACES, 0.0),
      m_last_interface_times(kMAX_INTERFACES, 0.0),
      m_interface_start_times(kMAX_INTERFACES, 0.0),
      m_interface_estimates(kMAX_INTERFACES, time_estimate(estimation->alpha)),
      m_exec_estimate(estimation->alpha),
      m_abort_prob(&abort->sigmoid.sigmoid) {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
__rcsw_pure int executable_task::active_interface(void) const {
  for (size_t i = 0; i < m_interface_in_prog.size(); ++i) {
    if (m_interface_in_prog[i]) {
      return i;
    }
  } /* for(i..) */

  return -1;
} /* active_interface() */

NS_END(ta, rcppsw);
