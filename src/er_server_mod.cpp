/*******************************************************************************
 * Name            : er_server_mod.cpp
 * Project         : rcppsw
 * Module          : erf
 * Description     : ER Module class
 * Creation Date   : 06/24/15
 * Copyright       : Copyright 2015 John Harwell, All rights reserved
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/er_server_mod.hpp"
#include <fstream>

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace rcppsw {

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/
er_server_mod::er_server_mod(const boost::uuids::uuid& id_,
                           const er_lvl::value& loglvl_,
                           const er_lvl::value& dbglvl_,
                           const std::string& name_)
    : id(id_), name(name_), loglvl(loglvl_), dbglvl(dbglvl_) {}

er_server_mod::er_server_mod(const boost::uuids::uuid& id_,
                           const std::string& name_)
    : id(id_),
      name(name_),
      loglvl(static_cast<er_lvl::value>(0)),
      dbglvl(static_cast<er_lvl::value>(0)) {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

/**
 * er_server_mod::set_dbglvl() - Set the debug level for a module
 *
 * RETURN:
 *     N/A
 *
 **/
void er_server_mod::set_dbglvl(const er_lvl::value& lvl) {
  dbglvl = lvl;
} /* er_server_mod::set_dbglvl() */

/**
 * er_server_mod::set_loglvl() - Set the logging level for a module
 *
 * RETURN:
 *     N/A
 *
 **/
void er_server_mod::set_loglvl(const er_lvl::value& lvl) {
  loglvl = lvl;
} /* er_server_mod::set_loglvl() */

/**
 * er_server_mod::dbgmsg() - Print a debug msg to stdout
 *
 * RETURN:
 *     N/A
 *
 **/
void er_server_mod::dbgmsg(const std::string& msg,
                          const er_lvl::value& lvl) const {
  if (lvl <= dbglvl) {
    std::cout << msg;
    std::cout.flush();
  }
} /* er_server_mod::dbgmsg() */

/**
 * er_server_mod::logmsg() - Log a msg to a file
 *
 * RETURN:
 *     N/A
 *
 **/
void er_server_mod::logmsg(const std::string& msg, const er_lvl::value& lvl,
                          std::ofstream& file) const {
  if (lvl <= loglvl) {
    file << msg;
    file.flush();
  }
} /* er_server_mod::logmsg() */

/**
 * operator==() - Compare two ERF modules for equality
 *
 * RETURN:
 *     bool - true if they are the same, false otherwise
 *
 **/
bool er_server_mod::operator==(const er_server_mod& rhs) {
  return (this->id == rhs.id);
} /* operator==() */

/**
 * operator<<() - For printing an er_server_mod
 *
 * RETURN:
 *     std::ostream& - The output stream
 *
 **/
std::ostream& operator<<(std::ostream& os, const er_server_mod& mod) {
  os << mod.id << ": " << mod.name;
  return os;
} /* operator<<() */

} /* namespace rcppsw */
