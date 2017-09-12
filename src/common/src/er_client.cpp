/**
 * @file er_client.cpp
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
#include "rcppsw/common/er_client.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, common);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
status_t er_client::attmod(const std::string& mod_name) {
  return server_handle()->findmod(mod_name, m_er_id);
} /* attmod() */

void er_client::deferred_init(const std::shared_ptr<er_server>& server_handle) {
  m_server_handle = server_handle;
  m_er_id = m_server_handle->idgen();
} /* deferred_init() */

NS_END(common, rcppsw);
