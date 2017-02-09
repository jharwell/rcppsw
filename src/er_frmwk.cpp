/*******************************************************************************
 * Name            : er_frmwk_base.cpp
 * Project         : rcppsw
 * Module          : erf
 * Description     : Event Reporting Framework (ERF)
 * Creation Date   : 06/24/15
 * Copyright       : Copyright 2015 John Harwell, All rights reserved
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/er_frmwk.hpp"
#include <algorithm>
#include <boost/filesystem.hpp>

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
using namespace rcppsw;

/*******************************************************************************
 * Macros
 ******************************************************************************/
/*
 * Reporting events. This needs to be a macro, instead of a function call so
 * I can get the line # and function from the preprocessor/compiler. For
 * internal use inside ERF only.
 */
#define REPORT_INTERNAL(lvl, msg, ...)                                   \
  {                                                                      \
    char _str[6000];                                                     \
    struct timespec _curr_time;                                          \
    clock_gettime(CLOCK_REALTIME, &_curr_time);                          \
    snprintf(_str, sizeof(_str), "[%s:%lu.%lu]:%s:%d:%s: " msg "\n",     \
             hostname_, _curr_time.tv_sec, _curr_time.tv_nsec, __FILE__, \
             __LINE__, __FUNCTION__, ##__VA_ARGS__);                     \
    er_frmwk::erf_msg _msg(erf_id_, lvl, std::string(_str));             \
    msg_report(_msg);                                                    \
  }

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/
er_frmwk::er_frmwk(const std::string& logfile_fname,
                   const erf_lvl::value& dbglvl, const erf_lvl::value& loglvl)
    : modules_(),
      queue_(),
      logfile_fname_(logfile_fname),
      logfile_(),
      loglvl_dflt_(loglvl),
      dbglvl_dflt_(dbglvl),
      gen_(),
      erf_id_(idgen()) {
  /* get hostname */
  gethostname(hostname_, 32);

  if (boost::filesystem::exists(logfile_fname_)) {
    boost::filesystem::remove(logfile_fname_);
  }
  logfile_.open(logfile_fname_.c_str());
} /* er_frmwk::er_frmwk() */

er_frmwk::~er_frmwk(void) { logfile_.close(); } /* er_frmwk::~er_frmwk() */

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
/**
 * insmod() - Install a new reporting module
 *
 * RETURN:
 *     status_t - OK if successful, ERROR otherwise
 *
 **/
status_t er_frmwk::insmod(const boost::uuids::uuid& mod_id,
                          const erf_lvl::value& loglvl,
                          const erf_lvl::value& dbglvl,
                          const std::string& mod_name) {
  er_frmwk_mod mod(mod_id, loglvl, dbglvl, mod_name);

  /* make sure module not already present */
  CHECK(modules_.end() == std::find(modules_.begin(), modules_.end(), mod));
  modules_.push_back(mod);
  return OK;

error:
  REPORT_INTERNAL(erf_lvl::err, "Failed to install module %s: module exists",
                  mod_name.c_str());
  return ERROR;
} /* insmod() */

/**
 * insmod() - Install a new reporting module, with inherited initial levels
 *
 * RETURN:
 *     status_t - OK if successful, ERROR otherwise
 *
 **/
status_t er_frmwk::insmod(const boost::uuids::uuid& id,
                          const std::string& name) {
  return insmod(id, loglvl_dflt_, dbglvl_dflt_, name);
} /* insmod() */

/**
 * er_frmwk::recv() - Add a msg to the queue
 *
 * RETURN:
 *     status_t - OK if successful, ERROR otherwise
 *
 **/
status_t er_frmwk::recv(const boost::uuids::uuid& mod_id,
                        const erf_lvl::value& lvl, const std::string& str) {
  queue_.enqueue(erf_msg(mod_id, lvl, str));
  return OK;
} /* er_frmwk::recv() */

/**
 * er_frmwk::msg_report() - Report a msg
 *
 * RETURN:
 *     N/A
 *
 **/

void er_frmwk::msg_report(const erf_msg& msg) {
  er_frmwk_mod tmp(msg.id_, "tmp");
  std::vector<er_frmwk_mod>::const_iterator iter =
      std::find(modules_.begin(), modules_.end(), tmp);

  if (iter != modules_.end()) {
    iter->logmsg(msg.str_, msg.lvl_, logfile_);
    iter->dbgmsg(msg.str_, msg.lvl_);
  }
} /* er_frmwk::msg_report() */

/**
 * er_frmwk::flush() - Flush all msgs in the queue to stdout/logfile
 *
 * RETURN:
 *     int - How many msgs were flushed
 *
 **/
int er_frmwk::flush(void) {
  int count = 0;
  while (queue_.size() > 0) {
    erf_msg next = queue_.dequeue();
    er_frmwk::msg_report(next);
    count++;
  } /* while() */
  return count;
} /* er_frmwk::flush() */

/**
 * er_frmwk::mod_dbglvl() - Set debugging lvl for a module
 *
 * RETURN:
 *     status_t - OK if successful, ERROR otherwise
 *
 **/
status_t er_frmwk::mod_dbglvl(const boost::uuids::uuid& id,
                              const erf_lvl::value& lvl) {
  er_frmwk_mod mod(id, erf_lvl::nom, erf_lvl::nom, "tmp");

  /* make sure module is already present */
  std::vector<er_frmwk_mod>::iterator iter =
      std::find(modules_.begin(), modules_.end(), mod);
  CHECK(iter != modules_.end());
  iter->set_dbglvl(lvl);

  REPORT_INTERNAL(erf_lvl::ver, "Successfully updated dbglvl for module %s",
                  iter->name.c_str());
  return OK;

error:
  REPORT_INTERNAL(erf_lvl::err,
                  "Failed to update dbglvl for module %s: no such module",
                  iter->name.c_str());
  return ERROR;
} /* er_frmwk::mod_dbglvl() */

/**
 * er_frmwk::mod_loglvl() - Set logging lvl for a module
 *
 * RETURN:
 *     status_t - OK if successful, ERROR otherwise
 *
 **/
status_t er_frmwk::mod_loglvl(const boost::uuids::uuid& id,
                              const erf_lvl::value& lvl) {
  er_frmwk_mod mod(id, erf_lvl::nom, erf_lvl::nom, "tmp");

  /* make sure module is already present */
  std::vector<er_frmwk_mod>::iterator iter =
      std::find(modules_.begin(), modules_.end(), mod);
  CHECK(iter != modules_.end());
  iter->set_loglvl(lvl);

  REPORT_INTERNAL(erf_lvl::ver, "Successfully updated loglvl for module %s",
                  iter->name.c_str());
  return OK;

error:
  REPORT_INTERNAL(erf_lvl::err,
                  "Failed to update loglvl for module %s: no such module",
                  iter->name.c_str());
  return ERROR;
} /* er_frmwk::mod_loglvl() */

/**
 * er_frmwk::thread_main() - Main ERF thread for the master
 *
 * RETURN:
 *     N/A
 *
 **/
void* er_frmwk::thread_main(void* arg) {
  REPORT_INTERNAL(erf_lvl::nom, "Start");
  while (!terminated()) {
    while (0 == queue_.size()) sleep(1);
    erf_msg msg = queue_.dequeue();
    msg_report(msg);
  } /* while() */
  REPORT_INTERNAL(erf_lvl::nom, "Exit");

  /* make sure all events remaining in queue are reported */
  while (queue_.size()) {
    erf_msg msg = queue_.dequeue();
    msg_report(msg);
  } /* while() */
  return NULL;
} /* er_frmwk::thread_main() */
