/**
 * @file er_server_mod.cpp
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
#include "rcppsw/common/er_server_mod.hpp"
#include <fstream>

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, common);

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/
er_server_mod::er_server_mod(const boost::uuids::uuid& id,
                           const er_lvl::value& loglvl,
                           const er_lvl::value& dbglvl,
                           const std::string& name)
    : m_id(id), m_name(name), m_loglvl(loglvl), m_dbglvl(dbglvl) {}

er_server_mod::er_server_mod(const boost::uuids::uuid& id,
                             const std::string& name)
    : m_id(id),
      m_name(name),
      m_loglvl(er_lvl::NOM),
      m_dbglvl(er_lvl::NOM) {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void er_server_mod::set_dbglvl(const er_lvl::value& lvl) {
  m_dbglvl = lvl;
} /* set_dbglvl() */

void er_server_mod::set_loglvl(const er_lvl::value& lvl) {
  m_loglvl = lvl;
} /* set_loglvl() */

void er_server_mod::msg_report(const std::string& msg, er_lvl::value msg_lvl,
                           er_lvl::value log_lvl, std::ostream& stream) const {
    if (msg_lvl <= log_lvl) {
      stream << name() << ": " << msg;
      stream.flush();
    }
} /* er_server_mod::msg_report() */

bool er_server_mod::operator==(const er_server_mod& rhs) {
  return (this->m_id == rhs.m_id);
} /* operator==() */

std::ostream& operator<<(std::ostream& os, const er_server_mod& mod) {
  os << mod.id() << ": " << mod.name();
  return os;
} /* operator<<() */

NS_END(common, rcppsw);
