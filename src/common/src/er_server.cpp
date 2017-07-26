/*******************************************************************************
 * Name            : er_server_base.cpp
 * Project         : rcppsw
 * Module          : er
 * Creation Date   : 06/24/15
 * Copyright       : Copyright 2015 John Harwell, All rights reserved
 *
 ******************************************************************************/

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
             hostname_, _curr_time.tv_sec, _curr_time.tv_nsec, __FILE__, \
             __LINE__, __FUNCTION__, ##__VA_ARGS__);                     \
    er_server::er_msg_int _msg(er_id_, lvl, std::string(_str));             \
    msg_report(_msg);                                                    \
  }

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/
er_server::er_server(const std::string& logfile_fname,
                     const er_lvl::value& dbglvl, const er_lvl::value& loglvl,
                     bool threaded)
    : threaded_(threaded),
      modules_(),
      queue_(),
      logfile_fname_(logfile_fname),
      logfile_(),
      loglvl_dflt_(loglvl),
      dbglvl_dflt_(dbglvl),
      gen_(),
      er_id_(idgen()) {
  /* get hostname */
  gethostname(hostname_, 32);

  if (boost::filesystem::exists(logfile_fname_)) {
    boost::filesystem::remove(logfile_fname_);
  }
  logfile_.open(logfile_fname_.c_str());
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
  CHECK(modules_.end() == std::find(modules_.begin(), modules_.end(), mod));
  modules_.push_back(mod);
  return OK;

error:
  REPORT_INTERNAL(er_lvl::ERR, "Failed to install module %s: module exists",
                  mod_name.c_str());
  return ERROR;
} /* insmod() */

status_t er_server::insmod(const boost::uuids::uuid& id,
                          const std::string& name) {
  return insmod(id, loglvl_dflt_, dbglvl_dflt_, name);
} /* insmod() */

void er_server::msg_report(const er_msg_int& msg) {
  er_server_mod tmp(msg.id_, "tmp");
  std::vector<er_server_mod>::const_iterator iter =
      std::find(modules_.begin(), modules_.end(), tmp);

  if (iter != modules_.end()) {
    iter->logmsg(msg.str_, msg.lvl_, logfile_);

    /* If NDEBUG is defined, debug printing is disabled. */
#ifndef NDEBUG
    iter->dbgmsg(msg.str_, msg.lvl_);
#endif
  }
} /* er_server::msg_report() */

int er_server::flush(void) {
  int count = 0;
  while (queue_.size() > 0) {
    er_msg_int next = queue_.dequeue();
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
      std::find(modules_.begin(), modules_.end(), mod);
  CHECK(iter != modules_.end());
  iter->set_dbglvl(lvl);

  REPORT_INTERNAL(er_lvl::VER, "Successfully updated dbglvl for module %s",
                  iter->name().c_str());
  return OK;

error:
  REPORT_INTERNAL(er_lvl::ERR,
                  "Failed to update dbglvl for module %s: no such module",
                  iter->name().c_str());
  return ERROR;
} /* er_server::mod_dbglvl() */

status_t er_server::mod_loglvl(const boost::uuids::uuid& id,
                              const er_lvl::value& lvl) {
  er_server_mod mod(id, er_lvl::NOM, er_lvl::NOM, "tmp");

  /* make sure module is already present */
  std::vector<er_server_mod>::iterator iter =
      std::find(modules_.begin(), modules_.end(), mod);
  CHECK(iter != modules_.end());
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
    while (0 == queue_.size()) sleep(1);
    er_msg_int msg = queue_.dequeue();
    msg_report(msg);
  } /* while() */
  REPORT_INTERNAL(er_lvl::NOM, "Exit");

  /* make sure all events remaining in queue are reported */
  while (queue_.size()) {
    er_msg_int msg = queue_.dequeue();
    msg_report(msg);
  } /* while() */
  return NULL;
} /* er_server::thread_main() */

NS_END(common, rcpppsw);
