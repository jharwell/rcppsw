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
#include "rcppsw/er/er_msg.hpp"

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
void server_mod::msg_report(const std::string& header,
                            const er_msg& msg,
                            er_lvl::value lvl,
                            std::ostream& stream) const {
  if (msg.lvl <= lvl) {
    stream << header << " " << name() << ": " << msg.str;
    /*
     * Unless we are doing an optimized build, flush the stream after every line
     * printed, so that you get all relevant messages on a crash.
     */
#ifndef NDEBUG
    stream.flush();
#endif
  }
} /* server_mod::msg_report() */

__pure bool server_mod::will_report(const er_msg& msg, er_lvl::value lvl) const {
  return (msg.lvl <= lvl);
} /* will_report() */

std::ostream& operator<<(std::ostream& os, const server_mod& mod) {
  os << mod.id() << ": " << mod.name();
  return os;
} /* operator<<() */

NS_END(er, rcppsw);
