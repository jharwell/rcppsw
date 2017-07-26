/**
 * @file er_server_mod.hpp
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

#ifndef INCLUDE_RCPPSW_DBG_ER_SERVER_MOD_HPP_
#define INCLUDE_RCPPSW_DBG_ER_SERVER_MOD_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <string>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include "rcppsw/common/common.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, common);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class er_lvl {
 public:
  enum value { OFF, ERR, WARN, NOM, DIAG, VER };
};

/**
 * @brief Representation of a module within the ER framework.
 */
class er_server_mod {
 public:
  /* member functions */
  er_server_mod(const boost::uuids::uuid& id, const er_lvl::value& loglvl,
                const er_lvl::value& dbglvl, const std::string& name);
  er_server_mod(const boost::uuids::uuid& id, const std::string& name);
  /**
   * @brief Set the debug printing level for a module.
   *
   * @param The new level.
   */
  void set_dbglvl(const er_lvl::value& lvl);
  /**
   * @brief Set the logging level for a module.
   *
   * @param The new level.
   */
  void set_loglvl(const er_lvl::value& lvl);

  /**
   * @brief Print a debug msg to stdout if the message level is high enough.
   *
   * @param msg The message to print.
   * @param lvl The level of the message.
   */
  void dbgmsg(const std::string& msg, const er_lvl::value& lvl) const;

  /**
   * @brief Log a message to a file if the message level is high enough.
   *
   * @param msg The message to log.
   * @param lvl The level of the message.
   * @param file The file to log the message to.
   */
  void logmsg(const std::string& msg, const er_lvl::value& lvl,
              std::ofstream& file) const;
  bool operator==(const er_server_mod& rhs);
  const boost::uuids::uuid& id(void) const {return id_; }
  const std::string& name(void) const { return name_; }

 private:
  /* data members */
  boost::uuids::uuid id_;
  std::string name_;
  er_lvl::value loglvl_;
  er_lvl::value dbglvl_;
};

NS_END(common, rcppsw);

/*******************************************************************************
 * Operator Definitions
 ******************************************************************************/
std::ostream& operator<<(std::ostream& os,
                         const rcppsw::common::er_server_mod& mod);

#endif /* INCLUDE_RCPPSW_DBG_ER_SERVER_MOD_HPP_ */
