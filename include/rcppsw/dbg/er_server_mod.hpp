/*******************************************************************************
 * Name            : er_server_mod.hpp
 * Project         : rcppsw
 * Module          : dbg
 * Description     : Representation of a module within the ER framework.
 * Creation Date   : 6/24/15
 * Copyright       : Copyright 2016 John Harwell, All rights reserved.
 *
 ******************************************************************************/

#ifndef INCLUDE_RCPPSW_ER_SERVER_MOD_HPP_
#define INCLUDE_RCPPSW_ER_SERVER_MOD_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <iostream>
#include <string>
#include "rcsw/common/common.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace rcppsw {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class er_lvl {
 public:
  enum value { OFF, ERR, WARN, NOM, DIAG, VER };
};

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

} /* namespace rcppsw */

/*******************************************************************************
 * Operator Definitions
 ******************************************************************************/
std::ostream& operator<<(std::ostream& os, const rcppsw::er_server_mod& mod);

#endif /* INCLUDE_RCPPSW_ER_SERVER_MOD_HPP_ */
