/*******************************************************************************
 * Name            : er_server_mod.cpp
 * Project         : rcppsw
 * Module          : dbg
 * Creation Date   : 06/24/15
 * Copyright       : Copyright 2015 John Harwell, All rights reserved
 *
 ******************************************************************************/

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
    : id_(id), name_(name), loglvl_(loglvl), dbglvl_(dbglvl) {}

er_server_mod::er_server_mod(const boost::uuids::uuid& id,
                             const std::string& name)
    : id_(id),
      name_(name),
      loglvl_(er_lvl::NOM),
      dbglvl_(er_lvl::NOM) {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void er_server_mod::set_dbglvl(const er_lvl::value& lvl) {
  dbglvl_ = lvl;
} /* er_server_mod::set_dbglvl() */

void er_server_mod::set_loglvl(const er_lvl::value& lvl) {
  loglvl_ = lvl;
} /* er_server_mod::set_loglvl() */

void er_server_mod::dbgmsg(const std::string& msg,
                          const er_lvl::value& lvl) const {
  if (lvl <= dbglvl_) {
    std::cout << msg;
    std::cout.flush();
  }
} /* er_server_mod::dbgmsg() */

void er_server_mod::logmsg(const std::string& msg, const er_lvl::value& lvl,
                          std::ofstream& file) const {
  if (lvl <= loglvl_) {
    file << msg;
    file.flush();
  }
} /* er_server_mod::logmsg() */

bool er_server_mod::operator==(const er_server_mod& rhs) {
  return (this->id_ == rhs.id_);
} /* operator==() */

std::ostream& operator<<(std::ostream& os, const er_server_mod& mod) {
  os << mod.id() << ": " << mod.name();
  return os;
} /* operator<<() */

NS_END(common, rcppsw);
