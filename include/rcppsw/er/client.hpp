/**
 * @file client.hpp
 * @ingroup er
 *
 * Interface for classes that want to be able to use the ER Server.
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

#ifndef INCLUDE_RCPPSW_ER_CLIENT_HPP_
#define INCLUDE_RCPPSW_ER_CLIENT_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <cassert>
#include <string>
#include <boost/uuid/uuid.hpp>
#include "rcppsw/er/server_mod.hpp"

/*******************************************************************************
 * Macros
 ******************************************************************************/
/**
 * @brief Event reporting macros. Use of these macros requires the class you are
 * using it in derives from \ref client. You cannot use these macros in a
 * non-class context.
 */
#ifndef NDEBUG
/* ---------- Explicit debug level statements (use these) ---------- */

/**
 * @def ER_ERR(...)
 *
 * Define a statement reporting the occurence of an \ref er_lvl::ERR
 * event. Works just like printf() from a syntax point of view.
 */
#define ER_ERR(...) ER_REPORT(rcppsw::er::er_lvl::ERROR, __VA_ARGS__)

/**
 * @def ER_WARN(...)
 *
 * Define a statement reporting the occurence of an \ref er_lvl::WARN
 * event. Works just like printf() from a syntax point of view.
 */
#define ER_WARN(...) ER_REPORT(rcppsw::er::er_lvl::WARN, __VA_ARGS__)

/**
 * @def ER_NOM(...)
 *
 * Define a statement reporting the occurence of an \ref er_lvl::NOM
 * event. Works just like printf() from a syntax point of view.
 */
#define ER_NOM(...) ER_REPORT(rcppsw::er::er_lvl::NOM, __VA_ARGS__)

/**
 * @def ER_DIAG(...)
 *
 * Define a statement reporting the occurence of an \ref er_lvl::DIAG
 * event. Works just like printf() from a syntax point of view.
 */
#define ER_DIAG(...) ER_REPORT(rcppsw::er::er_lvl::DIAG, __VA_ARGS__)

/**
 * @def ER_VER(...)
 *
 * Define a statement reporting the occurence of an \ref er_lvl::VER
 * event. Works just like printf() from a syntax point of view.
 */
#define ER_VER(...) ER_REPORT(rcppsw::er::er_lvl::VER, __VA_ARGS__)

/**
 * @internal
 * -------- Debug statements with level parameter (Don't use these) --------
 */

/**
 * @def ER_REPORT(lvl, msg, ...)
 *
 * Define a statement reporting the occurrence of an event with the specified
 * level. \a msg is the format string, and \a ... is the variadic argument list
 * (just like printf()).
 */
#define ER_REPORT(lvl, msg, ...)                       \
  {                                                    \
    char _str[1000];                                   \
    snprintf(static_cast<char*>(_str),                 \
             sizeof(_str),                             \
             "%s:%d:%s: " msg "\n",                    \
             __FILE__,                                 \
             __LINE__,                                 \
             reinterpret_cast<const char*>(__FUNCTION__),       \
             ##__VA_ARGS__);                           \
    __er_report__(rcppsw::er::client::server_handle(), \
                  rcppsw::er::client::er_id(),         \
                  lvl,                                 \
                  std::string(reinterpret_cast<char*>(_str)));  \
  }

#else
#define ER_REPORT(lvl, msg, ...)
#define ER_ERR(...)
#define ER_WARN(...)
#define ER_NOM(...)
#define ER_DIAG(...)
#define ER_VER(...)
#endif /* NDEBUG */

/**
 * @endinternal
 */

/**
 * @def ER_CHECK(cond, msg, ...)
 *
 * Check a boolean condition \a cond in a function. If condition is not true, go
 * to the error/bailout section for function (you must have a label called \c
 * error in your function) after reporting the event.
 *
 * You cannot use this macro in non-class contexts, and all classes using it
 * must derive from \ref client.
 */
#define ER_CHECK(cond, msg, ...)                           \
  {                                                        \
    if (!(cond)) {                                         \
      ER_REPORT(rcppsw::er::er_lvl::ERR, msg, ##__VA_ARGS__); \
      goto error;                                          \
    }                                                      \
  }

/**
 * @def ER_SENTINEL(msg,...)
 *
 * Mark a place in the code as being universally bad. If execution ever reaches
 * this spot, report the event and error out (you must have a label called \c
 * error in your function).
 *
 * You cannot use this macro in non-class contexts, and all classes using it
 * must derive from \ref client.
 */
#define ER_SENTINEL(msg, ...)                               \
  {                                                         \
    ER_REPORT(rcppsw::er::er_lvl::ERR, msg, ##__VA_ARGS__); \
    goto error;                                             \
  }

/**
 * @def ER_ASSERT(cond, msg, ...)
 *
 * Check a boolean condition \a cond in a function, halting the program if the
 * condition is not true. Like assert(), but allows for an additional custom to
 * be reported to the \ref server.
 *
 * You cannot use this macro in non-class contexts, and all classes using it
 * must derive from \ref client.
 */
#define ER_ASSERT(cond, msg, ...)                           \
  if (!(cond)) {                                            \
    ER_REPORT(rcppsw::er::er_lvl::ERR, msg, ##__VA_ARGS__); \
    assert(cond);                                           \
  }

/**
 * @def ER_FATAL_SENTINEL(msg,...)
 *
 * Mark a place in the code as being universally bad, like really really
 * bad. Fatally bad. If execution ever reaches this spot stop the program after
 * reporting the specified message.
 *
 * You cannot use this macro in non-class contexts, and all classes using it
 * must derive from \ref client.
 */
#define ER_FATAL_SENTINEL(msg, ...)                             \
  {                                                             \
    ER_REPORT(rcppsw::er::er_lvl::ERR, msg, ##__VA_ARGS__);     \
    assert(false);                                                  \
  }

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, er);

class server;
class global_server;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class client
 *
 * @brief A class that can connect to a \ref server for logging of important
 * events.
 *
 * In addition to deriving from this class, the automatically defined module for
 * the derived class must also be installed via \ref attmod() or \ref
 * server::insmod in order to enable reporting for messages from the class.
 */
class client {
 public:
  client(void);
  explicit client(std::shared_ptr<server> server_handle);
  virtual ~client(void);

  /**
   * @brief Initialize the client in cases where it was not possible to do
   * so in the initialization list in the class constructor.
   *
   * If the default constructor for client is used (and this function is
   * therefore needed), things will segfault/go badly if any reporting
   * statements are encountered in the client before this function is called.
   *
   * @param server_handle The server to attach to.
   */
  void deferred_init(std::shared_ptr<server> server_handle);

  /**
   * @brief Add a module to the active list (long version).
   *
   * @param loglvl The initial logging level for the module.
   * @param dbglvl The initial debug printing level for the module.
   * @param mod_name The name of the module, which will be prepended to all
   * debugging/logging statements.
   * @return OK if successful, ERROR otherwise.
   */
  status_t insmod(const std::string& mod_name,
                  const er_lvl::value& loglvl = er_lvl::NOM,
                  const er_lvl::value& dbglvl = er_lvl::NOM);
  /**
   * @brief Uninstall the module for this client. This function is called
   * automatically in the destructor, but can be called explicitly as well.
   *
   * @return \ref status_t.
   */
  status_t rmmod(void);

  /**
   * @brief Attach to an EXISTING module within the server by name.
   *
   * If the module exists, the UUID for this client is set to the UUID of the
   * module. If no module with the given name exists, no action is performed.
   *
   * @param mod_name Name of the module to attach to.
   *
   * @return \ref status_t.
   */
  status_t attmod(const std::string& mod_name);

  /**
   * @brief Get a reference to the ER server.
   *
   * @return A reference to the server handle.
   */
  server* server_handle(void) const { return m_server_handle.get(); }

 protected:
  const std::shared_ptr<server>& server_ref(void) const {
    return m_server_handle;
  }

  /**
   * @brief Get a reference to the UUID for the module. Should not be called
   * directly by the application (why would you even need this?).
   *
   * @return The UUID.
   */
  boost::uuids::uuid er_id(void) const { return m_er_id; }

 private:
  std::shared_ptr<server> m_server_handle;
  boost::uuids::uuid m_er_id;
};

/*******************************************************************************
 * Global Variables
 ******************************************************************************/
/**
 * @brief A common, global server that all applications utilizing rcppsw have
 * access to. Handy in cases where you don't want to pass the server handle down
 * through unrelated constructors until you get to the class you actually want
 * to enable reporting for.
 */
extern std::shared_ptr<rcppsw::er::global_server> g_server;

/*******************************************************************************
 * Forward Declarations
 ******************************************************************************/
/**
 * @internal
 * @brief The single, global entry point for all event reporting.
 *
 * This should never be called directly.
 *
 * @param server The server to report the event to.
 * @param er_id ID of the module reporting the event.
 * @param lvl The level of the event.
 * @param str The event message.
 *
 * @endinternal
 */
void __er_report__(server* server,
                   const boost::uuids::uuid& er_id,
                   const er_lvl::value& lvl,
                   const std::string& str);
NS_END(rcppsw, er);

#endif /* INCLUDE_RCPPSW_ER_CLIENT_HPP_ */
