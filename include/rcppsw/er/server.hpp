/**
 * @file server.hpp
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

#ifndef INCLUDE_RCPPSW_ER_SERVER_HPP_
#define INCLUDE_RCPPSW_ER_SERVER_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <boost/uuid/uuid_generators.hpp>
#include <iosfwd>
#include <string>
#include <vector>
#include "rcppsw/common/common.hpp"
#include "rcppsw/er/server_mod.hpp"
#include "rcppsw/patterns/singleton.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, er);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class server
 *
 * @brief Logging server for events.
 *
 * Each event can be reported on any combination of the following streams:
 * [stdout, file]. Each reported event must be reported from a class derived
 * from \ref client.
 *
 * Modules corresponding to classes derived from \ref client are run-time
 * installable/removable, and can independently have their logging (writing to a
 * file) and debugging (writing to stdout) levels set.
 */
class server {
 public:
  /**
   * @internal
   * @struct msg_int
   *
   * @brief Internal class wrapping all the information needed to processing a
   * message besides the text of the message itself.
   *
   * @endinternal
   */
  struct msg_int {
    msg_int(const boost::uuids::uuid& id_,
            const er_lvl::value& lvl_,
            std::string str_)
        : id(id_), lvl(lvl_), str(std::move(str_)) {}
    boost::uuids::uuid id;
    er_lvl::value lvl;
    std::string str;
  };

  /**
   * @brief Initialize an Event Reporting Server.
   *
   * @param logfile_fname The name of the file to log events to. If the file
   *                      already exists, it is deleted. If the special value
   *                      \c __no_file__ is passed, then the logging part of the
   *                      server will be disabled.
   *
   * @param dbglvl The initial debug printing level.
   * @param loglvl The initial logging level.
   */
  server(std::string logfile_fname,
         const er_lvl::value& dbglvl,
         const er_lvl::value& loglvl);

  /**
   * @brief Initialize and Event Reporting Server with defaults logfile names
   * and initial logging/debugging levels.
   */
  server(void): server("__no_file__", er_lvl::NOM, er_lvl::NOM) {}

  virtual ~server(void);

  /**
   * @brief Get a reference to the logging stream.
   */
  std::ofstream& log_stream(void);

  /**
   * @brief Get a reference to the debugging stream.
   */
  std::ostream& dbg_stream(void);

  const std::string& logfile_fname(void) const { return m_logfile_fname; }

  /**
   * @brief Install a callback to calculate a timestamp to be prepended to every
   * message that is sent to stdout.
   *
   * This is useful when working with frameworks that do not provide such a
   * timestamp, or that provide it for only logged messages.
   */
  void dbg_ts_calculator(std::function<std::string(void)> cb);
  const std::function<std::string(void)>& dbg_ts_calculator(void) const;

  /**
   * @brief Install a callback to calculate a timestamp to be prepended to every
   * message that is sent to a logfile.
   *
   * This is useful when working with frameworks that do not provide such a
   * timestamp, or that provide it for only messages sent to stdout.
   */
  void log_ts_calculator(std::function<std::string(void)> cb);
  const std::function<std::string(void)>& log_ts_calculator(void) const;

  /**
   * @brief Find an existing module already installed on the server. Modules are
   * search/compared by name, rather than UUID, because if you knew the UUID of
   * the module you wanted to attach as, you would just go ahead and use it,
   * right?
   *
   * @param mod_name Name of the module.
   * @param mod_id To be filled with the UUID of the module, if it exists.
   *
   * @return \ref status_t.
   */
  status_t findmod(const std::string& mod_name, boost::uuids::uuid& mod_id);

  /**
   * @brief Unconditionally install a new module into the list of active
   * debugging/logging modules.
   *
   * @param mod_id The UUID of the module to install.
   * @param loglvl The initial logging level of the module.
   * @param dbglvl The initial debug printing level of the module.
   * @param mod_name The name of the module, which will be prepended to all
   *                 messages.
   *
   * @return \ref status_t.
   */
  status_t insmod(const boost::uuids::uuid& mod_id,
                  const er_lvl::value& loglvl,
                  const er_lvl::value& dbglvl,
                  const std::string& mod_name);
  /**
   * @brief Unconditionally install a new module into the list of active
   * debuging/logging modules, short version. Uses the default logging/debugging
   * levels of the server when installing the new module.
   *
   * @param id The UUID of the module to install.
   * @param name The name of the module, which will be prepended to all
   *                 messages.
   *
   * @return \ref status_t.
   */
  status_t insmod(const boost::uuids::uuid& id, const std::string& name) {
    return insmod(id, m_loglvl_dflt, m_dbglvl_dflt, name);
  }

  /**
   * @brief Remove a module from the list of active debugging/logging modules.
   *
   * @param id The UUID of the module to remove.
   *
   * @return \ref status_t.
   */
  status_t rmmod(const boost::uuids::uuid& id);

  /**
   * @brief Set the debugging level of a module.
   *
   * @param id The UUID of the module.
   * @param lvl The new level.
   *
   * @return \ref status_t.
   */
  status_t mod_dbglvl(const boost::uuids::uuid& id, const er_lvl::value& lvl);

  /**
   * @brief Get the current debugging level for the module.
   *
   * @return The debugging level for the module, or -1 if no such module is
   * currently installed.
   */
  er_lvl::value mod_dbglvl(const boost::uuids::uuid& id);

  /**
   * @brief Get the current logging level for the module.
   *
   * @return The logging level for the module, or -1 if no such module is
   * currently installed.
   */
  er_lvl::value mod_loglvl(const boost::uuids::uuid& id);

  /**
   * @brief Set the logging level of a module.
   *
   * @param id The UUID of the module.
   * @param lvl The new level.
   *
   * @return \ref status_t.
   */
  status_t mod_loglvl(const boost::uuids::uuid& id, const er_lvl::value& lvl);

  /**
   * @brief Change the logfile that the server will report events to.
   */
  void change_logfile(const std::string& new_fname);

  /**
   * @brief Generate a UUID for a new module.
   *
   * @return The UUID.
   */
  boost::uuids::uuid idgen(void);

  /**
   * @brief Get the current default logging level.
   *
   * @return The current default logging level.
   */
  er_lvl::value loglvl(void) { return m_loglvl_dflt; }

  /**
   * @brief Get the current default debug printing level.
   *
   * @return The current default debug printing level.
   */
  er_lvl::value dbglvl(void) { return m_dbglvl_dflt; }

  /**
   * @brief Set the default logging level.
   */
  void loglvl(const er_lvl::value& lvl) { m_loglvl_dflt = lvl; }

  /**
   * @brief Set the default debug printing level.
   */
  void dbglvl(const er_lvl::value& lvl) { m_dbglvl_dflt = lvl; }

  /**
   * @brief Get the hostname the server is running on.
   *
   * @return The hostname.
   */
  char* hostname(void) { return reinterpret_cast<char*>(m_hostname); }

  /**
   * @internal
   *
   * @brief Enable debugging for the ER server. For debugging purposes only.
   *
   * @endinternal
   */
  void self_er_en(void);

  /**
   * @brief Report a message. Messages may or not actually be printed/logged,
   * depending on the current level settings in the server/module.
   *
   * @param er_id The module reporting the message.
   * @param lvl The level of the message.
   * @param str The message.
   */
  virtual void report(const boost::uuids::uuid& er_id,
                      const er_lvl::value& lvl,
                      const std::string& str) {
    msg_int msg(er_id, lvl, str);
    msg_report(msg);
  }

  /**
   * @brief Flush all pending messages to stdout/the log file.
   */
  virtual void flush(void);

 protected:
  void msg_report(const msg_int& msg);

 private:
  /* data members */
  char m_hostname[32];

  std::vector<server_mod> m_modules;
  std::string m_logfile_fname;              /// File to log events to.
  std::unique_ptr<std::ofstream> m_logfile; /// Logfile handle.

  /** Default log level for new modules */
  er_lvl::value m_loglvl_dflt;

  /** Default debug printing level for new modules. */
  er_lvl::value m_dbglvl_dflt;

  std::function<std::string(void)> m_dbg_ts_calculator;
  std::function<std::string(void)> m_log_ts_calculator;

  /** Generator for universally unique identifiers for modules */
  boost::uuids::random_generator m_generator;
  boost::uuids::uuid m_er_id;
};

/**
 * @class global_server
 *
 * @brief A singleton, global event reporting server provided by rcppsw that all
 * applications can use.
 */
class global_server : public patterns::singleton<server>, public server {
 public:
  global_server(void) : server() {}
  ~global_server(void) override;

  global_server(const global_server& other) = delete;
  global_server& operator=(const global_server& other) = delete;
  global_server(global_server&& other) = delete;
  global_server& operator=(global_server&& other) = delete;
};

NS_END(er, rcppsw);

#endif /* INCLUDE_RCPPSW_ER_SERVER_HPP_ */
