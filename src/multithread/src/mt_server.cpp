/**
 * @file mt_server.cpp
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
#include "rcppsw/multithread/mt_server.hpp"
#include <algorithm>

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, multithread);

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/
mt_server::mt_server(const std::string &logfile_fname,
                     const er::er_lvl::value &dbglvl,
                     const er::er_lvl::value &loglvl)
    : server(logfile_fname, dbglvl, loglvl), m_queue() {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void mt_server::flush(void) {
  while (m_queue.size() > 0) {
    er::er_msg next = m_queue.dequeue();
    server::report(next);
  } /* while() */
} /* flush() */

void *mt_server::thread_main(__rcsw_unused void *arg) {
  while (!terminated()) {
    while (0 == m_queue.size()) {
      sleep(1);
    }
    er::er_msg msg = m_queue.dequeue();
    server::report(msg);
  } /* while() */

  /* make sure all events remaining in queue are reported */
  while (m_queue.size() > 0) {
    er::er_msg msg = m_queue.dequeue();
    server::report(msg);
  } /* while() */
  return nullptr;
} /* thread_main() */

NS_END(multithread, rcpppsw);
