/**
 * @file er_server.hpp
 *
 * Event Reporting Server, used for level and & module based debug printing and
 * logging.
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

#ifndef INCLUDE_RCPPSW_COMMON_ER_SERVER_HPP_
#define INCLUDE_RCPPSW_COMMON_ER_SERVER_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <fstream>
#include <string>
#include <vector>
#include "rcppsw/common/common.hpp"
#include "rcppsw/common/er_server_mod.hpp"
#include "rcppsw/multithread/mt_queue.hpp"
#include "rcppsw/multithread/threadable.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, common);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class er_server : public multithread::threadable {
 public:
  /**
   * @brief Internal class wrapping all the information needed to processing a
   * message besides the text of the message itself.
   */
  struct er_msg_int {
    explicit er_msg_int(const boost::uuids::uuid& id, const er_lvl::value& lvl,
                     const std::string& str)
        : m_id(id), lvl_(lvl), str_(str) {}
    boost::uuids::uuid m_id;
    er_lvl::value lvl_;
    std::string str_;
  };

  /**
   * @brief Initialize an Event Reporting Server.
   *
   * @param logfile_fname The name of the file to log events to. If the file
   *                      already exists, it is deleted.
   * @param dbglvl The initial debug printing level.
   * @param loglvl The initial logging level.
   * @param threaded Whether or not messages will be enqueued into a queue and
   *                 handled synchronously by a dedicated thread, or if
   *                 messages will be handled inline in the calling thread
   *                 (asynchronously).
   */
  er_server(const std::string& logfile_fname = "logfile",
            const er_lvl::value& dbglvl = er_lvl::NOM,
            const er_lvl::value& loglvl = er_lvl::NOM,
            bool threaded = true);

  /* destructor */
  ~er_server(void) { join(); m_logfile.close(); }

  /**
   * @brief Enable debugging for the ER server. For debugging purposes only.
   */
  void self_common_en(void) {
    insmod(m_er_id, "ER Server");
    mod_dbglvl(m_er_id, er_lvl::NOM);
  }
  /**
   * @brief Install a new module into the list of active debugging/logging
   * modules.
   *
   * @param mod_id The UUID of the module to install.
   * @param loglvl The initial logging level of the module.
   * @param dbglvl The initial debug printing level of the module.
   * @param mod_name The name of the module, which will be prepended to all
   *                 messages.
   *
   * @return OK if successful, ERROR otherwise.
   */
  status_t insmod(const boost::uuids::uuid& mod_id,
                  const er_lvl::value& loglvl, const er_lvl::value& dbglvl,
                  const std::string& mod_name);
  /**
   * @brief Install a new module into the list of active debuging/logging
   * modules, short version. Uses the default logging/debugging levels of the
   * server when installing the new module.
   *
   * @param mod_id The UUID of the module to install.
   * @param name The name of the module, which will be prepended to all
   *                 messages.
   * @return OK if successful, ERROR otherwise.
   */
  status_t insmod(const boost::uuids::uuid& id, const std::string& name);

  /**
   * @brief Remove a module from the list of active debugging/logging modules.
   *
   * @param id The UUID of the module to remove.
   *
   * @return OK if successful, ERROR otherwise.
   */
  status_t rmmod(const boost::uuids::uuid& id);

  /**
   * @brief Set the debugging level of a module.
   *
   * @param id The UUID of the module.
   * @param lvl The new level.
   *
   * @return OK if successful, ERROR otherwise.
   */
  status_t mod_dbglvl(const boost::uuids::uuid& id, const er_lvl::value& lvl);

  /**
   * @brief Set the logging level of a module.
   *
   * @param id The UUID of the module.
   * @param lvl The new level.
   *
   * @return OK if successful, ERROR otherwise.
   */
  status_t mod_loglvl(const boost::uuids::uuid& id, const er_lvl::value& lvl);
  /**
   * @brief Flush all remaining entries in the queue to stdout/the log file.
   *
   * @return # of messages flushed.
   */
  int flush(void);

  void change_logfile(const std::string& new_fname);

  /**
   * @brief Generate a UUID for a new module.
   *
   * @return The UUID.
   */
  boost::uuids::uuid idgen(void) { return m_gen(); }

  /**
   * @brief The entry point of the er_server thread.
   *
   * @param arg Unused.
   *
   * @return Unused.
   */
  void* thread_main(void* arg);

  /**
   * @brief Get the current logging level.
   *
   * @return The current logging level.
   */
  er_lvl::value loglvl(void) { return m_loglvl_dflt; }

  /**
   * @brief Get the current debug printing level.
   *
   * @return The current debug printing level.
   */
  er_lvl::value dbglvl(void) { return m_dbglvl_dflt; }

  /**
   * @brief Set the logging level.
   */
  void loglvl(const er_lvl::value& lvl) { m_loglvl_dflt = lvl; }

  /**
   * @brief Set the debug printing level.
   */
  void dbglvl(const er_lvl::value& lvl) { m_dbglvl_dflt = lvl; }

  /**
   * @brief Get the hostname the server is running on.
   *
   * @return The hostname.
   */
  char* hostname(void) { return m_hostname; }

  /**
   * @brief Report a message. Messages may or not actually be printed/logged,
   * depending on the current level settings in the server/module.
   *
   * @param er_id The module reporting the message.
   * @param lvl The level of the message.
   * @param str The message.
   */
  void report(const boost::uuids::uuid& er_id, const er_lvl::value& lvl,
              const std::string& str) {
    er_msg_int msg(er_id, lvl, str);
    msg_report(msg);
    if (m_threaded) {
      m_queue.enqueue(msg);
    }
  }

 private:
  void msg_report(const er_msg_int& msg);

  /* data members */
  char                              m_hostname[32];

  /** If true. the server is handling events synchronously. */
  bool                              m_threaded;
  std::vector<er_server_mod>        m_modules;
  multithread::mt_queue<er_msg_int> m_queue;
  std::string                       m_logfile_fname;  /// File to log events to.
  std::ofstream                     m_logfile;        /// Logfile handle.

  /** Default log level for new modules */
  er_lvl::value                     m_loglvl_dflt;

  /** Default debug printing level for new modules. */
  er_lvl::value                     m_dbglvl_dflt;

  /** Generator for universally unique identifiers for modules */
  boost::uuids::random_generator m_gen;
  boost::uuids::uuid m_er_id;
};

NS_END(common, rcppsw);

#endif /* INCLUDE_RCPPSW_COMMON_ER_SERVER_HPP_ */
