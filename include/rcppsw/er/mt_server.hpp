/**
 * @file mt_server.hpp
 * @ingroup er
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

#ifndef INCLUDE_RCPPSW_ER_MT_SERVER_HPP_
#define INCLUDE_RCPPSW_ER_MT_SERVER_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <fstream>
#include <string>
#include <vector>
#include "rcppsw/er/server.hpp"
#include "rcppsw/multithread/mt_queue.hpp"
#include "rcppsw/multithread/threadable.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, er);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class mt_server
 *
 * @brief A multithreaded version of the \ref server for reporting events.
 */
class mt_server : public server, public multithread::threadable {
 public:
  /**
   * @brief Initialize a multithreaded ER server.
   *
   * @param logfile_fname The name of the file to log events to. If the file
   *                      already exists, it is deleted.
   * @param dbglvl The initial debug printing level.
   * @param loglvl The initial logging level.
   */
  mt_server(const std::string& logfile_fname,
                     const er_lvl::value& dbglvl,
                     const er_lvl::value& loglvl);

  /**
   * @brief Initialize a multithreaded ER server with default values.
   */
  mt_server(void): mt_server("__no_file__", er_lvl::NOM, er_lvl::NOM) {}

  ~mt_server(void) override { join(); }

  /**
   * @brief Flush all remaining entries in the queue to stdout/the log file.
   */
  void flush(void) override;

  /**
   * @brief The entry point of the server thread.
   *
   * @param arg Unused.
   *
   * @return Unused.
   */
  void* thread_main(__unused void* arg) override;

  /**
   * @brief Report a message. Messages may or not actually be printed/logged,
   * depending on the current level settings in the server/module.
   *
   * @param er_id The module reporting the message.
   * @param lvl The level of the message.
   * @param str The message.
   */
  void report(const boost::uuids::uuid& er_id,
              const er_lvl::value& lvl,
              const std::string& str) override {
    msg_int msg(er_id, lvl, str);
    msg_report(msg);
    m_queue.enqueue(msg);
  }

 private:
  multithread::mt_queue<msg_int> m_queue;
};

NS_END(er, rcppsw);

#endif /* INCLUDE_RCPPSW_ER_SERVER_HPP_ */
