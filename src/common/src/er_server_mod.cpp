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
} /* er_server_mod::set_dbglvl() */

void er_server_mod::set_loglvl(const er_lvl::value& lvl) {
  m_loglvl = lvl;
} /* er_server_mod::set_loglvl() */

void er_server_mod::dbgmsg(const std::string& msg,
                          const er_lvl::value& lvl) const {
  if (lvl <= m_dbglvl) {
    std::cout << msg;
    std::cout.flush();
  }
} /* er_server_mod::dbgmsg() */

void er_server_mod::logmsg(const std::string& msg, const er_lvl::value& lvl,
                          std::ofstream& file) const {
  if (lvl <= m_loglvl) {
    file << msg;
    file.flush();
  }
} /* er_server_mod::logmsg() */

bool er_server_mod::operator==(const er_server_mod& rhs) {
  return (this->m_id == rhs.m_id);
} /* operator==() */

std::ostream& operator<<(std::ostream& os, const er_server_mod& mod) {
  os << mod.id() << ": " << mod.name();
  return os;
} /* operator<<() */

NS_END(common, rcppsw);
