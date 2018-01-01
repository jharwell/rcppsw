/**
 * @file server_mod.hpp
 * @ingroup er
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
#include "rcppsw/common/common.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, er);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class er_lvl
 *
 * @brief The different levels of reportable events.
 *
 * OFF: Used when you want to turn debugging OFF for all modules.
 *
 * ERR: Used to print things regarding errors, as in something bad happened
 *      in your program.
 *
 * WARN: Used to print warning things, as in something happened athat is
 *       somewhat alarming/sub-optimal, but not in of itself
 *       catastrophic/fatal.
 *
 * NOM: Normal/nominative printing. Use this for things that you want your
 *      program to print when everything is going smoothly. According to UNIX
 *      philosophy, if your program has nothing interesting to say, it should
 *      say nothing if this is the debugging level.
 *
 * DIAG: Used to print diagnostic information, as in additional info that
 *       a developer can use to help debug a problem.
 *
 * VER: Used to print verbose information, for use on tough problems when you
 *      want the use to get as much information from your program as
 *      possible.
 */

class er_lvl {
 public:
  enum value { OFF, ERR, WARN, NOM, DIAG, VER };
};

/**
 * @class server_mod
 *
 * @brief Representation of a module within the ER framework.
 */
class server_mod {
 public:
  /* member functions */
  server_mod(boost::uuids::uuid id,
             er_lvl::value loglvl,
             er_lvl::value dbglvl,
             std::string name);
  server_mod(boost::uuids::uuid id, std::string name);

  /**
   * @brief Set the debug printing level for a module.
   *
   * @param lvl The new level.
   */
  void set_dbglvl(const er_lvl::value& lvl);

  /**
   * @brief Set the logging level for a module.
   *
   * @param lvl The new level.
   */
  void set_loglvl(const er_lvl::value& lvl);

  er_lvl::value dbglvl(void) { return m_dbglvl; }
  er_lvl::value loglvl(void) { return m_loglvl; }

  /**
   * @brief Log a message to a file if the message level is high enough.
   *
   * @param header The header for the msg (timestamp, etc.). Can be empty.
   * @param msg The message to log.
   * @param msg_lvl The level of the message.
   * @param log_lvl The level of the message.
   * @param stream The stream to log the message to.
   */
  void msg_report(const std::string& header,
                  const std::string& msg,
                  er_lvl::value msg_lvl,
                  er_lvl::value log_lvl,
                  std::ostream& stream) const;
  bool operator==(const server_mod& rhs);
  const boost::uuids::uuid& id(void) const { return m_id; }
  void change_id(boost::uuids::uuid id) { m_id = id; }
  const std::string& name(void) const { return m_name; }

 private:
  /* data members */
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
