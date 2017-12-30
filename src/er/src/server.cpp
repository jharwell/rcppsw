/**
 * @file server.cpp
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
#include "rcppsw/er/server.hpp"
#include <algorithm>
#include <boost/filesystem.hpp>
#include <fstream>
#include <iostream>

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, er);

/*******************************************************************************
 * Macros
 ******************************************************************************/
#define REPORT_INTERNAL(lvl, msg, ...)                     \
  {                                                        \
    char _str[1000];                                       \
    snprintf(static_cast<char*>(_str),                     \
             sizeof(_str),                                 \
             "%s:%d:%s: " msg "\n",                        \
             __FILE__,                                     \
             __LINE__,                                     \
             reinterpret_cast<const char*>(__FUNCTION__),  \
             ##__VA_ARGS__);                               \
    server::msg_int _msg(m_er_id, lvl, std::string(reinterpret_cast<char*>(_str))); \
    msg_report(_msg);                                      \
  }

/*******************************************************************************
 * Global Variables
 ******************************************************************************/
std::shared_ptr<global_server> g_server(std::make_shared<global_server>());

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/
server::server(std::string logfile_fname,
               const er_lvl::value& dbglvl,
               const er_lvl::value& loglvl)
    : m_modules(),
      m_logfile_fname(std::move(logfile_fname)),
      m_logfile(new std::ofstream()),
      m_loglvl_dflt(loglvl),
      m_dbglvl_dflt(dbglvl),
      m_dbg_ts_calculator(nullptr),
      m_log_ts_calculator(nullptr),
      m_generator(),
      m_er_id(idgen()) {
  gethostname(reinterpret_cast<char*>(m_hostname), 32);

  change_logfile(m_logfile_fname);
}

server::~server(void) { m_logfile->close(); }

global_server::~global_server(void) = default;

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void server::dbg_ts_calculator(std::function<std::string(void)> cb) {
  m_dbg_ts_calculator = std::move(cb);
} /* dbg_ts_calculator() */

const std::function<std::string(void)>& server::dbg_ts_calculator(void) const {
  return m_dbg_ts_calculator;
} /* dbg_ts_calculator() */

void server::log_ts_calculator(std::function<std::string(void)> cb) {
  m_log_ts_calculator = std::move(cb);
} /* log_ts_calculator() */

const std::function<std::string(void)>& server::log_ts_calculator(void) const {
  return m_log_ts_calculator;
} /* log_ts_calculator() */

void server::self_er_en(void) {
  insmod(m_er_id, "ER Server");
  mod_dbglvl(m_er_id, er_lvl::NOM);
} /* self_er_en() */

status_t server::insmod(const boost::uuids::uuid& mod_id,
                        const er_lvl::value& loglvl,
                        const er_lvl::value& dbglvl,
                        const std::string& mod_name) {
  server_mod mod(mod_id, loglvl, dbglvl, mod_name);

  /* make sure module not already present */
  CHECK(m_modules.end() == std::find(m_modules.begin(), m_modules.end(), mod));
  m_modules.push_back(mod);
  return OK;

error:
  REPORT_INTERNAL(er_lvl::ERR,
                  "Failed to install module %s: module exists",
                  mod_name.c_str());
  return ERROR;
} /* insmod() */

status_t server::findmod(const std::string& mod_name,
                         boost::uuids::uuid& mod_id) {
  for (auto& mod : m_modules) {
    if (mod.name() == mod_name) {
      mod_id = mod.id();
      return OK;
    }
  } /* for(mod..) */
  return ERROR;
} /* findmod() */

status_t server::rmmod(const boost::uuids::uuid& id) {
  server_mod tmp(id, er_lvl::NOM, er_lvl::NOM, "tmp");
  auto iter = std::find(m_modules.begin(), m_modules.end(), tmp);
  m_modules.erase(iter);
  return OK;
} /* rmmod() */

void server::msg_report(const msg_int& msg) {
  server_mod tmp(msg.id, er_lvl::NOM, er_lvl::NOM, "tmp");
  auto iter = std::find(m_modules.begin(), m_modules.end(), tmp);

  std::string header;
  if (iter != m_modules.end()) {
    if (m_log_ts_calculator) {
      header = m_log_ts_calculator();
    }
    iter->msg_report(header, msg.str, msg.lvl, iter->loglvl(), *m_logfile);

/* If NDEBUG is defined, debug printing is disabled. */
#ifndef NDEBUG
    header = "";
    if (m_dbg_ts_calculator) {
      header = m_dbg_ts_calculator();
    }
    iter->msg_report(header, msg.str, msg.lvl, iter->dbglvl(), std::cout);
#endif
  }
} /* msg_report() */

void server::flush(void) {
  std::fflush(nullptr);
  m_logfile->flush();
} /* flush() */

status_t server::mod_dbglvl(const boost::uuids::uuid& id,
                            const er_lvl::value& lvl) {
  server_mod mod(id, er_lvl::NOM, er_lvl::NOM, "tmp");

  /* make sure module is already present */
  auto iter = std::find(m_modules.begin(), m_modules.end(), mod);
  CHECK(iter != m_modules.end());
  iter->set_dbglvl(lvl);

  REPORT_INTERNAL(er_lvl::VER,
                  "Successfully updated dbglvl for module %s",
                  iter->name().c_str());
  return OK;

error:
  REPORT_INTERNAL(er_lvl::ERR,
                  "Failed to update dbglvl for module %s: no such module",
                  iter->name().c_str());
  return ERROR;
} /* mod_dbglvl() */

er_lvl::value server::mod_dbglvl(const boost::uuids::uuid& id) {
  server_mod mod(id, er_lvl::NOM, er_lvl::NOM, "tmp");

  /* make sure module is already present */
  auto iter = std::find(m_modules.begin(), m_modules.end(), mod);
  CHECK(iter != m_modules.end());
  return iter->dbglvl();

error:
  return static_cast<er_lvl::value>(-1);
} /* dbglvl() */

er_lvl::value server::mod_loglvl(const boost::uuids::uuid& id) {
  server_mod mod(id, er_lvl::NOM, er_lvl::NOM, "tmp");

  /* make sure module is already present */
  auto iter = std::find(m_modules.begin(), m_modules.end(), mod);
  CHECK(iter != m_modules.end());
  return iter->loglvl();

error:
  return static_cast<er_lvl::value>(-1);
} /* loglvl() */

void server::change_logfile(const std::string& new_fname) {
  m_logfile->close();
  if (boost::filesystem::exists(new_fname)) {
    boost::filesystem::remove(new_fname);
  }
  m_logfile_fname = new_fname;
  if (m_logfile_fname != "__no_file__") {
    m_logfile->open(m_logfile_fname.c_str());
  }
} /* change_logfile() */

status_t server::change_id(const boost::uuids::uuid& old_id,
                           boost::uuids::uuid new_id) {
  server_mod mod(old_id, er_lvl::NOM, er_lvl::NOM, "tmp");

  /* make sure module is already present */
  auto iter = std::find(m_modules.begin(), m_modules.end(), mod);
  CHECK(iter != m_modules.end());
  iter->change_id(new_id);
  return OK;

error:
  return ERROR;
} /* change_id() */

status_t server::mod_loglvl(const boost::uuids::uuid& id,
                            const er_lvl::value& lvl) {
  server_mod mod(id, er_lvl::NOM, er_lvl::NOM, "tmp");

  /* make sure module is already present */
  auto iter = std::find(m_modules.begin(), m_modules.end(), mod);
  CHECK(iter != m_modules.end());
  iter->set_loglvl(lvl);

  REPORT_INTERNAL(er_lvl::VER,
                  "Successfully updated loglvl for module %s",
                  iter->name().c_str());
  return OK;

error:
  REPORT_INTERNAL(er_lvl::ERR,
                  "Failed to update loglvl for module %s: no such module",
                  iter->name().c_str());
  return ERROR;
} /* mod_loglvl() */

boost::uuids::uuid server::idgen(void) { return m_generator(); } /* idgen() */

std::ostream& server::dbg_stream(void) { return std::cout; }

NS_END(er, rcpppsw);
