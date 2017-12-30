/**
 * @file server_mod.cpp
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
#include "rcppsw/er/server_mod.hpp"
#include <boost/uuid/uuid_io.hpp>
#include <fstream>

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, er);

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/
server_mod::server_mod(boost::uuids::uuid id,
                       er_lvl::value loglvl,
                       er_lvl::value dbglvl,
                       std::string name)
    : m_id(id), m_name(std::move(name)), m_loglvl(loglvl), m_dbglvl(dbglvl) {}

server_mod::server_mod(boost::uuids::uuid id, std::string name)
    : m_id(id),
      m_name(std::move(name)),
      m_loglvl(er_lvl::NOM),
      m_dbglvl(er_lvl::NOM) {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void server_mod::set_dbglvl(const er_lvl::value& lvl) {
  m_dbglvl = lvl;
} /* set_dbglvl() */

void server_mod::set_loglvl(const er_lvl::value& lvl) {
  m_loglvl = lvl;
} /* set_loglvl() */

void server_mod::msg_report(const std::string& header,
                            const std::string& msg,
                            er_lvl::value msg_lvl,
                            er_lvl::value log_lvl,
                            std::ostream& stream) const {
  if (msg_lvl <= log_lvl) {
    stream << header << " " << name() << ": " << msg;
    stream.flush();
  }
} /* server_mod::msg_report() */

bool server_mod::operator==(const server_mod& rhs) {
  return (this->m_id == rhs.m_id);
} /* operator==() */

std::ostream& operator<<(std::ostream& os, const server_mod& mod) {
  os << mod.id() << ": " << mod.name();
  return os;
} /* operator<<() */

NS_END(er, rcppsw);
