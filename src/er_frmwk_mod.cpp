/*******************************************************************************
 * Name            : er_frwk_mod.cpp
 * Project         : rcppsw
 * Module          : erf
 * Description     : ERF module class
 * Creation Date   : 06/24/15
 * Copyright       : Copyright 2015 John Harwell, All rights reserved
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/er_frmwk_mod.hpp"
#include <fstream>

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
using namespace rcppsw;

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/
er_frmwk_mod::er_frmwk_mod(const boost::uuids::uuid& id_,
                           const erf_lvl::value& loglvl_,
                           const erf_lvl::value& dbglvl_,
                           const std::string& name_)
    : id(id_), name(name_), loglvl(loglvl_), dbglvl(dbglvl_) {}

er_frmwk_mod::er_frmwk_mod(const boost::uuids::uuid& id_,
                           const std::string& name_)
    : id(id_),
      name(name_),
      loglvl(static_cast<erf_lvl::value>(0)),
      dbglvl(static_cast<erf_lvl::value>(0)) {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

/**
 * er_frmwk_mod::set_dbglvl() - Set the debug level for a module
 *
 * RETURN:
 *     N/A
 *
 **/
void er_frmwk_mod::set_dbglvl(const erf_lvl::value& lvl) {
  dbglvl = lvl;
} /* er_frmwk_mod::set_dbglvl() */

/**
 * er_frmwk_mod::set_loglvl() - Set the logging level for a module
 *
 * RETURN:
 *     N/A
 *
 **/
void er_frmwk_mod::set_loglvl(const erf_lvl::value& lvl) {
  loglvl = lvl;
} /* er_frmwk_mod::set_loglvl() */

/**
 * er_frmwk_mod::dbgmsg() - Print a debug msg to stdout
 *
 * RETURN:
 *     N/A
 *
 **/
void er_frmwk_mod::dbgmsg(const std::string& msg,
                          const erf_lvl::value& lvl) const {
  if (lvl <= dbglvl) {
    std::cout << msg;
    std::cout.flush();
  }
} /* er_frmwk_mod::dbgmsg() */

/**
 * er_frmwk_mod::logmsg() - Log a msg to a file
 *
 * RETURN:
 *     N/A
 *
 **/
void er_frmwk_mod::logmsg(const std::string& msg, const erf_lvl::value& lvl,
                          std::ofstream& file) const {
  if (lvl <= loglvl) {
    file << msg;
    file.flush();
  }
} /* er_frmwk_mod::logmsg() */

/**
 * operator==() - Compare two ERF modules for equality
 *
 * RETURN:
 *     bool - true if they are the same, false otherwise
 *
 **/
bool er_frmwk_mod::operator==(const er_frmwk_mod& rhs) {
  return (this->id == rhs.id);
} /* operator==() */

/**
 * operator<<() - For printing an er_frmwk_mod
 *
 * RETURN:
 *     std::ostream& - The output stream
 *
 **/
std::ostream& operator<<(std::ostream& os, const er_frmwk_mod& mod) {
  os << mod.id << ": " << mod.name;
  return os;
} /* operator<<() */
