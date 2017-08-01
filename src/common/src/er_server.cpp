/**
 * @file er_server.cpp
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
#include "rcppsw/common/er_server.hpp"
#include <algorithm>
#include <boost/filesystem.hpp>
#include "rcppsw/common/er_client.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, common);

/*******************************************************************************
 * Macros
 ******************************************************************************/
#define REPORT_INTERNAL(lvl, msg, ...)                                   \
  {                                                                      \
    char _str[6000];                                                     \
    struct timespec _curr_time;                                          \
    clock_gettime(CLOCK_REALTIME, &_curr_time);                          \
    snprintf(_str, sizeof(_str), "[%s:%lu.%lu]:%s:%d:%s: " msg "\n",     \
             m_hostname, _curr_time.tv_sec, _curr_time.tv_nsec, __FILE__, \
             __LINE__, __FUNCTION__, ##__VA_ARGS__);                     \
    er_server::er_msg_int _msg(m_er_id, lvl, std::string(_str));             \
    msg_report(_msg);                                                    \
  }

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/
er_server::er_server(const std::string& logfile_fname,
                     const er_lvl::value& dbglvl, const er_lvl::value& loglvl,
                     bool threaded)
    : m_threaded(threaded),
      m_modules(),
      m_queue(),
      m_logfile_fname(logfile_fname),
      m_logfile(),
      m_loglvl_dflt(loglvl),
      m_dbglvl_dflt(dbglvl),
      m_gen(),
      m_er_id(idgen()) {
  gethostname(m_hostname, 32);

  change_logfile(m_logfile_fname);
} /* er_server::er_server() */

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
status_t er_server::insmod(const boost::uuids::uuid& mod_id,
                          const er_lvl::value& loglvl,
                          const er_lvl::value& dbglvl,
                          const std::string& mod_name) {
  er_server_mod mod(mod_id, loglvl, dbglvl, mod_name);

  /* make sure module not already present */
  CHECK(m_modules.end() == std::find(m_modules.begin(), m_modules.end(), mod));
  m_modules.push_back(mod);
  return OK;

error:
  REPORT_INTERNAL(er_lvl::ERR, "Failed to install module %s: module exists",
                  mod_name.c_str());
  return ERROR;
} /* insmod() */

status_t er_server::insmod(const boost::uuids::uuid& id,
                          const std::string& name) {
  return insmod(id, m_loglvl_dflt, m_dbglvl_dflt, name);
} /* insmod() */

void er_server::msg_report(const er_msg_int& msg) {
  er_server_mod tmp(msg.m_id, "tmp");
  std::vector<er_server_mod>::const_iterator iter =
      std::find(m_modules.begin(), m_modules.end(), tmp);

  if (iter != m_modules.end()) {
    iter->logmsg(msg.str_, msg.lvl_, m_logfile);

    /* If NDEBUG is defined, debug printing is disabled. */
#ifndef NDEBUG
    iter->dbgmsg(msg.str_, msg.lvl_);
#endif
  }
} /* er_server::msg_report() */

int er_server::flush(void) {
  int count = 0;
  while (m_queue.size() > 0) {
    er_msg_int next = m_queue.dequeue();
    er_server::msg_report(next);
    count++;
  } /* while() */
  return count;
} /* er_server::flush() */

status_t er_server::mod_dbglvl(const boost::uuids::uuid& id,
                              const er_lvl::value& lvl) {
  er_server_mod mod(id, er_lvl::NOM, er_lvl::NOM, "tmp");

  /* make sure module is already present */
  std::vector<er_server_mod>::iterator iter =
      std::find(m_modules.begin(), m_modules.end(), mod);
  CHECK(iter != m_modules.end());
  iter->set_dbglvl(lvl);

  REPORT_INTERNAL(er_lvl::VER, "Successfully updated dbglvl for module %s",
                  iter->name().c_str());
  return OK;

error:
  REPORT_INTERNAL(er_lvl::ERR,
                  "Failed to update dbglvl for module %s: no such module",
                  iter->name().c_str());
  return ERROR;
} /* mod_dbglvl() */

er_lvl::value er_server::mod_dbglvl(const boost::uuids::uuid& id) {
  er_server_mod mod(id, er_lvl::NOM, er_lvl::NOM, "tmp");

  /* make sure module is already present */
  std::vector<er_server_mod>::iterator iter =
      std::find(m_modules.begin(), m_modules.end(), mod);
  CHECK(iter != m_modules.end());
  return iter->dbglvl();
error:
  return (er_lvl::value)-1;
} /* dbglvl() */

er_lvl::value er_server::mod_loglvl(const boost::uuids::uuid& id) {
  er_server_mod mod(id, er_lvl::NOM, er_lvl::NOM, "tmp");

  /* make sure module is already present */
  std::vector<er_server_mod>::iterator iter =
      std::find(m_modules.begin(), m_modules.end(), mod);
  CHECK(iter != m_modules.end());
  return iter->loglvl();

error:
  return (er_lvl::value)-1;
} /* loglvl() */

void er_server::change_logfile(const std::string& new_fname) {
  if (boost::filesystem::exists(new_fname)) {
    boost::filesystem::remove(new_fname);
  }
  m_logfile_fname = new_fname;
  m_logfile.open(m_logfile_fname.c_str());
} /* change_logfile() */

status_t er_server::mod_loglvl(const boost::uuids::uuid& id,
                              const er_lvl::value& lvl) {
  er_server_mod mod(id, er_lvl::NOM, er_lvl::NOM, "tmp");

  /* make sure module is already present */
  std::vector<er_server_mod>::iterator iter =
      std::find(m_modules.begin(), m_modules.end(), mod);
  CHECK(iter != m_modules.end());
  iter->set_loglvl(lvl);

  REPORT_INTERNAL(er_lvl::VER, "Successfully updated loglvl for module %s",
                  iter->name().c_str());
  return OK;

error:
  REPORT_INTERNAL(er_lvl::ERR,
                  "Failed to update loglvl for module %s: no such module",
                  iter->name().c_str());
  return ERROR;
} /* er_server::mod_loglvl() */

void* er_server::thread_main(void* arg) {
  REPORT_INTERNAL(er_lvl::NOM, "Start");
  while (!terminated()) {
    while (0 == m_queue.size()) sleep(1);
    er_msg_int msg = m_queue.dequeue();
    msg_report(msg);
  } /* while() */
  REPORT_INTERNAL(er_lvl::NOM, "Exit");

  /* make sure all events remaining in queue are reported */
  while (m_queue.size()) {
    er_msg_int msg = m_queue.dequeue();
    msg_report(msg);
  } /* while() */
  return NULL;
} /* er_server::thread_main() */

NS_END(common, rcpppsw);
