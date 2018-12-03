/**
 * @file client.hpp
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
#include <cxxabi.h>
#include <log4cxx/logger.h>
#include <log4cxx/patternlayout.h>
#include <log4cxx/fileappender.h>
#include <log4cxx/consoleappender.h>
#include <log4cxx/xml/domconfigurator.h>
#include <log4cxx/ndc.h>

#include <cassert>
#include <string>
#include "rcppsw/common/common.hpp"

/*******************************************************************************
 * Macros
 ******************************************************************************/
#ifndef ER_NREPORT
#define ER_FATAL(...)                                   \
  {                                                                     \
   auto logger = rcppsw::er::client<typename std::remove_cv<typename std::remove_reference<decltype(*this)>::type>::type>::logger(); \
   if (logger->isFatalEnabled()) {                                      \
     ER_REPORT(FATAL, logger, __VA_ARGS__)                              \
         }                                                              \
  }
#define ER_ERR(...)                                   \
  {                                                                     \
    auto logger = rcppsw::er::client<typename std::remove_cv<typename std::remove_reference<decltype(*this)>::type>::type>::logger(); \
    if (logger->isErrorEnabled()) {                                      \
      ER_REPORT(ERROR, logger, __VA_ARGS__)                              \
          }                                                             \
  }

#define ER_WARN(...)                                   \
  {                                                                     \
   auto logger = rcppsw::er::client<typename std::remove_cv<typename std::remove_reference<decltype(*this)>::type>::type>::logger(); \
   if (logger->isWarnEnabled()) {                                      \
     ER_REPORT(WARN, logger, __VA_ARGS__)                              \
         }                                                              \
  }
#define ER_INFO(...)                                   \
  {                                                                     \
    auto logger = rcppsw::er::client<typename std::remove_cv<typename std::remove_reference<decltype(*this)>::type>::type>::logger(); \
    if (logger->isInfoEnabled()) {                                      \
      ER_REPORT(INFO, logger, __VA_ARGS__)                              \
          }                                                             \
  }
#define ER_DEBUG(...)                                   \
  {                                                                     \
    auto logger = rcppsw::er::client<typename std::remove_cv<typename std::remove_reference<decltype(*this)>::type>::type>::logger(); \
    if (logger->isDebugEnabled()) {                                     \
      ER_REPORT(DEBUG, logger, __VA_ARGS__)                             \
          }                                                             \
  }
#define ER_TRACE(...)                                   \
  {                                                                     \
  auto logger = rcppsw::er::client<typename std::remove_cv<typename std::remove_reference<decltype(*this)>::type>::type>::logger(); \
  if (logger->isTraceEnabled()) {                                       \
    ER_REPORT(TRACE, logger, __VA_ARGS__)                               \
        }                                                               \
  }
#else

#define ER_FATAL(...)
#define ER_ERR(...)
#define ER_WARN(...)
#define ER_INFO(...)
#define ER_DEBUG(...)
#define ER_TRACE(...)

#endif /* ER_NREPORT */

/**
 * @def ER_REPORT(lvl, msg, ...)
 *
 * Define a statement reporting the occurrence of an event with the specified
 * level. \a msg is the format string, and \a ... is the variadic argument list
 * (just like printf()).
 */
#define ER_REPORT(lvl, logger, msg, ...)                         \
    {                                                           \
      char _str[1000];                                          \
      snprintf(static_cast<char*>(_str),                        \
               sizeof(_str),                                    \
               msg,                                             \
               ##__VA_ARGS__);                                  \
      LOG4CXX_##lvl(logger, _str); \
    }

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
      ER_ERR(msg, ##__VA_ARGS__);                          \
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
    ER_ERR(msg, ##__VA_ARGS__);                             \
    goto error;                                             \
  }

/**
 * @def ER_ASSERT(cond, msg, ...)
 *
 * Check a boolean condition \a cond in a function, halting the program if the
 * condition is not true. Like assert(), but allows for an additional custom
 * msg to be logged.
 *
 * You cannot use this macro in non-class contexts, and all classes using it
 * must derive from \ref client.
 */
#define ER_ASSERT(cond, msg, ...)               \
  if (!(cond)) {                                \
    ER_FATAL(msg, ##__VA_ARGS__);               \
    assert(cond);                               \
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
#define ER_FATAL_SENTINEL(msg, ...)                                 \
  {                                                                 \
    ER_FATAL(msg, ##__VA_ARGS__);                                   \
    assert(false);                                                  \
  }

/**
 * @def ER_CLIENT_INIT(name)
 *
 * Initialize a logging client with the specified name (easier to do a macro
 * than to have to try do the casting every single type).
 */
#define ER_CLIENT_INIT(name)                                         \
  rcppsw::er::client<typename std::remove_reference<decltype(*this)>::type>(name)

/**
 * @def ER_SET_LOGFILE(logger, fname)
 *
 * Set the logfile for the specified logger. Idempotent.
 */
#define ER_SET_LOGFILE(logger, fname) \
  rcppsw::er::client<typename std::remove_reference<decltype(*this)>::type>::set_logfile(logger,\
                                                                                         fname)

/**
 * @def ER_NDC_PUSH(s)
 *
 * Push the specified NDC context (prepended to every message).
 */
#define ER_NDC_PUSH(s) \
  rcppsw::er::client<typename std::remove_reference<decltype(*this)>::type>::push_ndc(s)

/**
 * @def ER_NDC_POP()
 *
 * Pop the last pushed NDC context.
 */
#define ER_NDC_POP(...)                                                  \
  rcppsw::er::client<typename std::remove_reference<decltype(*this)>::type>::pop_ndc()

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, er);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class client
 * @ingroup er
 *
 * @brief A class that can connect to a logging server for logging of important
 * events. Basically a thin wrapper around log4cxx.
 */
template<typename T>
class client {
 public:
  /**
   * @brief Initialize logging by specifying the path to the log4cxx
   * configuration file.
   */
  static void init_logging(const std::string& fpath) {
    /*
     * Multiple initializations will cause duplicate messages to show up in
     * logfiles.
     */
    if (!m_initialized) {
      log4cxx::xml::DOMConfigurator::configure(fpath);
      m_initialized = true;
    }
  }

  /**
   * @brief Set the log file for the specified logger. Idempotent. If the
   * logfile currently exists, it will be truncated.
   *
   * Logfile is an appender, which is given the same name as the logfile
   * itself.
   */
  static void set_logfile(log4cxx::LoggerPtr logger, const std::string& name) {
    for (auto &a : logger->getAllAppenders()) {
      if (a->getName() == name) {
        return;
      }
    } /* for(&a..) */

    log4cxx::LayoutPtr layout = new log4cxx::PatternLayout(mc_file_layout);
    log4cxx::AppenderPtr appender = new log4cxx::FileAppender(layout,
                                                              name,
                                                              false);
    appender->setName(name);
    logger->addAppender(appender);
  }

  /**
   * @param name Name of client/new logger.
   */
  explicit client(const std::string& name)
      : m_logger(log4cxx::Logger::getLogger(name)) {}

  /**
   * @brief Set the logfile of the current logger. Not idempotent.
   */
  void set_logfile(const std::string& name) {
    log4cxx::LayoutPtr layout = new log4cxx::PatternLayout(mc_file_layout);
    log4cxx::AppenderPtr appender = new log4cxx::FileAppender(layout, name);
    logger()->addAppender(appender);
  }

  /**
   * @brief Get current logger name.
   */
  std::string logger_name(void) const {
    std::string name;
    m_logger->getName(name);
    return name;
  }

  /**
   * @brief Push a log4cxx NDC context.
   *
   * @param s The context.
   */
  void push_ndc(const std::string& s) { log4cxx::NDC::push(s); }

  /**
   * @brief Pop the top of the log4cxx NDC stack.
   */
  void pop_ndc(void) { log4cxx::NDC::pop(); }

  virtual ~client(void) = default;

  /**
   * @brief Get a reference to the ER logger.
   */
  log4cxx::LoggerPtr logger(void) const { return m_logger; }

 private:
  // clang-format off
  static const char         mc_console_layout[];
  static const char         mc_file_layout[];
  static bool               m_initialized;
  log4cxx::LoggerPtr        m_logger{};
  // clang-format on
};

template<typename T>
bool client<T>::m_initialized = false;
template<typename T>
const char client<T>::mc_console_layout[] = "%x [%-5p] %c - %m%n";
template<typename T>
const char client<T>::mc_file_layout[] = "%x [%-5p] %c %l - %m%n";

NS_END(rcppsw, er);

#endif /* INCLUDE_RCPPSW_ER_CLIENT_HPP_ */
