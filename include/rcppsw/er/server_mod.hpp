/**
 * @file server_mod.hpp
 *
 * Interface for classes that want to be able to use the ER Server.
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

#ifndef INCLUDE_RCPPSW_ER_SERVER_MOD_HPP_
#define INCLUDE_RCPPSW_ER_SERVER_MOD_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <boost/uuid/uuid.hpp>
#include <iosfwd>
#include <string>
#include "rcppsw/er/er_lvl.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, er);
struct er_msg;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class server_mod
 * @ingroup er
 *
 * @brief Representation of a module within the ER framework.
 */
class server_mod {
 public:
  server_mod(boost::uuids::uuid id,
             er_lvl::value loglvl,
             er_lvl::value dbglvl,
             std::string name);
  server_mod(boost::uuids::uuid id, std::string name);

  bool operator==(const server_mod& rhs) const {
    return (this->m_id == rhs.m_id);
  }

  /**
   * @brief Set the debug printing level for a module.
   *
   * @param lvl The new level.
   */
  void set_dbglvl(const er_lvl::value& lvl) { m_dbglvl = lvl; }

  /**
   * @brief Set the logging level for a module.
   *
   * @param lvl The new level.
   */
  void set_loglvl(const er_lvl::value& lvl) { m_loglvl = lvl; }

  er_lvl::value dbglvl(void) const { return m_dbglvl; }
  er_lvl::value loglvl(void) const { return m_loglvl; }
  const boost::uuids::uuid& id(void) const { return m_id; }
  void change_id(boost::uuids::uuid id) { m_id = id; }
  const std::string& name(void) const { return m_name; }


  /**
   * @brief Report the specified message if the level for it is high enough.
   *
   * @param header The header for the msg (timestamp, etc.). Can be empty.
   * @param msg The message to log.
   * @param msg_lvl The level of the message.
   * @param lvl The level of the module for the stream.
   * @param stream The stream to log the message to.
   */
  void msg_report(const std::string& header,
                  const er_msg& msg,
                  er_lvl::value lvl,
                  std::ostream& stream) const;

  /**
   * @brief Determine if the specified message WOULD be reported if
   * \ref msg_report was called.
   *
   * Used to short circuit potentially wasteful calls to constructing messages
   * that will never be reported.
   *
   * @param msg The message to check.
   * @param lvl The level of the module.
   *
   * @return \c TRUE if the message will be reported, \c FALSE otherwise.
   */
  bool will_report(const er_msg& msg, er_lvl::value lvl) const;

 private:
  boost::uuids::uuid m_id;
  std::string m_name;
  er_lvl::value m_loglvl;
  er_lvl::value m_dbglvl;
};

/*******************************************************************************
 * Operator Definitions
 ******************************************************************************/
std::ostream& operator<<(std::ostream& os, const rcppsw::er::server_mod& mod);

NS_END(er, rcppsw);

#endif /* INCLUDE_RCPPSW_ER_SERVER_MOD_HPP_ */
