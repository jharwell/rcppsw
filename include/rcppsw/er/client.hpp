/**
 * \file client.hpp
 *
 * Interface for classes that want to be able to use the ER Server.
 *
 * \copyright 2017 John Harwell, All rights reserved.
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
 * Constants
 ******************************************************************************/
#define LIBRA_ER_NONE 0  /* No event reporting */
#define LIBRA_ER_FATAL 1 /* Fatal events only */
#define LIBRA_ER_ALL 2   /* All event reporting  */

/*
 * Size of buffer put on stack for creating debug strings. This probably never
 * will need to be overridden, but if it does...
 */
#ifndef LIBRA_ER_MSGLEN_MAX
#define LIBRA_ER_MSGLEN_MAX 1000
#endif

/*******************************************************************************
 * Includes
 ******************************************************************************/
#if (LIBRA_ER >= LIBRA_ER_ALL)
#include <log4cxx/consoleappender.h>
#include <log4cxx/fileappender.h>
#include <log4cxx/logger.h>
#include <log4cxx/ndc.h>
#include <log4cxx/patternlayout.h>
#include <log4cxx/xml/domconfigurator.h>
#endif

#include <cassert>
#include <string>

#include "rcppsw/common/common.hpp"

/*******************************************************************************
 * Macros
 ******************************************************************************/
/*
 * FATAL event reporting can be enabled using log4cxx, which has much higher
 * overhead than just printf(), but also much better contextual information and
 * controllability without recompilation. However, it can also be useful to be
 * able to *JUST* see what fatal events have happened/asserts have failed in
 * multithreaded contexts where the overhead of log4cxx will make possible race
 * conditions much less likely to occur.
 */
#if (LIBRA_ER == LIBRA_ER_FATAL)

#define ER_FATAL(...) \
  { ER_REPORT(__VA_ARGS__); }
#define ER_REPORT(msg, ...) \
  { printf(msg "\n", ##__VA_ARGS__); }

#elif (LIBRA_ER == LIBRA_ER_NONE)

#define ER_REPORT(...)
#define ER_FATAL(...)

#endif /* LIBRA_ER == LIBRA_ER_FATAL */

#if (LIBRA_ER >= LIBRA_ER_ALL)

/**
 * \def ER_REPORT(lvl, msg, ...)
 *
 * Define a statement reporting the occurrence of an event with the specified
 * level. \a msg is the format string, and \a ... is the variadic argument list
 * (just like printf()).
 *
 * This macro is only available if event reporting is fully enabled.
 */
#define ER_REPORT(lvl, logger, msg, ...)                                  \
  {                                                                       \
    char _str[LIBRA_ER_MSGLEN_MAX];                                       \
    snprintf(static_cast<char*>(_str), sizeof(_str), msg, ##__VA_ARGS__); \
    LOG4CXX_##lvl(logger, _str);                                          \
  }

#define ER_FATAL(...)                                                            \
  {                                                                              \
    auto logger = rcppsw::er::client<typename std::remove_cv<                    \
        typename std::remove_reference<decltype(*this)>::type>::type>::logger(); \
    if (logger->isFatalEnabled()) {                                              \
      ER_REPORT(FATAL, logger, __VA_ARGS__)                                      \
    }                                                                            \
  }

#define ER_ERR(...)                                                              \
  {                                                                              \
    auto logger = rcppsw::er::client<typename std::remove_cv<                    \
        typename std::remove_reference<decltype(*this)>::type>::type>::logger(); \
    if (logger->isErrorEnabled()) {                                              \
      ER_REPORT(ERROR, logger, __VA_ARGS__)                                      \
    }                                                                            \
  }

#define ER_WARN(...)                                                             \
  {                                                                              \
    auto logger = rcppsw::er::client<typename std::remove_cv<                    \
        typename std::remove_reference<decltype(*this)>::type>::type>::logger(); \
    if (logger->isWarnEnabled()) {                                               \
      ER_REPORT(WARN, logger, __VA_ARGS__)                                       \
    }                                                                            \
  }
#define ER_INFO(...)                                                             \
  {                                                                              \
    auto logger = rcppsw::er::client<typename std::remove_cv<                    \
        typename std::remove_reference<decltype(*this)>::type>::type>::logger(); \
    if (logger->isInfoEnabled()) {                                               \
      ER_REPORT(INFO, logger, __VA_ARGS__)                                       \
    }                                                                            \
  }
#define ER_DEBUG(...)                                                            \
  {                                                                              \
    auto logger = rcppsw::er::client<typename std::remove_cv<                    \
        typename std::remove_reference<decltype(*this)>::type>::type>::logger(); \
    if (logger->isDebugEnabled()) {                                              \
      ER_REPORT(DEBUG, logger, __VA_ARGS__)                                      \
    }                                                                            \
  }
#define ER_TRACE(...)                                                            \
  {                                                                              \
    auto logger = rcppsw::er::client<typename std::remove_cv<                    \
        typename std::remove_reference<decltype(*this)>::type>::type>::logger(); \
    if (logger->isTraceEnabled()) {                                              \
      ER_REPORT(TRACE, logger, __VA_ARGS__)                                      \
    }                                                                            \
  }
#else

#define ER_ERR(...)
#define ER_WARN(...)
#define ER_INFO(...)
#define ER_DEBUG(...)
#define ER_TRACE(...)
#endif /* LIBRA_ER >= LIBRA_ER_ALL */

/**
 * \def ER_CHECK(cond, msg, ...)
 *
 * Check a boolean condition \a cond in a function. If condition is not true, go
 * to the error/bailout section for function (you must have a label called \c
 * error in your function) after reporting the event.
 *
 * You cannot use this macro in non-class contexts, and all classes using it
 * must derive from \ref client. This macro is only available if event reporting
 * is fully enabled.
 */
#define ER_CHECK(cond, msg, ...)  \
  {                               \
    if (!(cond)) {                \
      ER_ERR(msg, ##__VA_ARGS__); \
      goto error;                 \
    }                             \
  }

/**
 * \def ER_SENTINEL(msg,...)
 *
 * Mark a place in the code as being universally bad. If execution ever reaches
 * this spot, report the event and error out (you must have a label called \c
 * error in your function).
 *
 * You cannot use this macro in non-class contexts, and all classes using it
 * must derive from \ref client. This macro is only available if event
 * reporting is fully enabled.
 */
#define ER_SENTINEL(msg, ...)   \
  {                             \
    ER_ERR(msg, ##__VA_ARGS__); \
    goto error;                 \
  }

/**
 * \def ER_ASSERT(cond, msg, ...)
 *
 * Check a boolean condition \a cond in a function, halting the program if the
 * condition is not true. Like assert(), but allows for an additional custom
 * msg to be logged.
 *
 * You cannot use this macro in non-class contexts, and all classes using it
 * must derive from \ref client.
 */
#define ER_ASSERT(cond, msg, ...) \
  if (!(cond)) {                  \
    ER_FATAL(msg, ##__VA_ARGS__); \
    assert(cond);                 \
  }

/**
 * \def ER_FATAL_SENTINEL(msg,...)
 *
 * Mark a place in the code as being universally bad, like really really
 * bad. Fatally bad. If execution ever reaches this spot stop the program after
 * reporting the specified message.
 *
 * You cannot use this macro in non-class contexts, and all classes using it
 * must derive from \ref client.
 */
#define ER_FATAL_SENTINEL(msg, ...) \
  {                                 \
    ER_FATAL(msg, ##__VA_ARGS__);   \
    assert(false);                  \
  }

/**
 * \def ER_CLIENT_INIT(name)
 *
 * Initialize a logging client with the specified name (easier to do a macro
 * than to have to try do the casting every single time).
 */
#if (LIBRA_ER >= LIBRA_ER_ALL)
#define ER_CLIENT_INIT(name)                                                 \
  rcppsw::er::client<typename std::remove_reference<decltype(*this)>::type>( \
      name)
#else
#define ER_CLIENT_INIT(name) \
  rcppsw::er::client<typename std::remove_reference<decltype(*this)>::type>()
#endif /* LIBRA_ER >= LIBRA_ER_ALL */

/**
 * \def ER_LOGGING_INIT(fname)
 *
 * Initialize logging by specifying the log4cxx configuration file.
 */
#define ER_LOGGING_INIT(fname) \
  rcppsw::er::client<          \
      typename std::remove_reference<decltype(*this)>::type>::logging_init(fname)

/**
 * \def ER_LOGFILE_SET(logger, fname)
 *
 * Set the logfile for the specified logger. Idempotent.
 */
#define ER_LOGFILE_SET(logger, fname)                                         \
  rcppsw::er::client<typename std::remove_reference<decltype(*this)>::type>:: \
      logfile_set(logger, fname)

/**
 * \def ER_NDC_PUSH(s)
 *
 * Push the specified NDC context (prepended to every message).
 */
#define ER_NDC_PUSH(s) \
  rcppsw::er::client<  \
      typename std::remove_reference<decltype(*this)>::type>::push_ndc(s)

/**
 * \def ER_NDC_POP()
 *
 * Pop the last pushed NDC context.
 */
#define ER_NDC_POP(...) \
  rcppsw::er::client<   \
      typename std::remove_reference<decltype(*this)>::type>::pop_ndc()

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, er);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class client
 * \ingroup er
 *
 * \brief A class that can connect to a logging server for logging of important
 * events. Basically a thin wrapper around log4cxx. If ER_NDEBUG is defined,
 * then this class will mostly compile away to nothing, and most member
 * functions will not be defined.
 */
template <typename T>
class client {
 public:
#if (LIBRA_ER >= LIBRA_ER_ALL)
  /**
   * \brief Initialize logging by specifying the path to the log4cxx
   * configuration file.
   */
  static void logging_init(const std::string& fpath) {
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
   * \brief Set the log file for the specified logger. Idempotent. If the
   * logfile currently exists, it will be truncated.
   *
   * Logfile is an appender, which is given the same name as the logfile
   * itself.
   */
  static void logfile_set(const log4cxx::LoggerPtr& logger,
                          const std::string& name) {
    for (auto& a : logger->getAllAppenders()) {
      if (a->getName() == name) {
        return;
      }
    } /* for(&a..) */

    log4cxx::LayoutPtr layout = new log4cxx::PatternLayout(kFileLayout);
    log4cxx::AppenderPtr appender =
        new log4cxx::FileAppender(layout, name, false);
    appender->setName(name);
    logger->addAppender(appender);
  }

  /**
   * \brief Push a log4cxx NDC context.
   *
   * \param s The context.
   */
  static void push_ndc(const std::string& s) { log4cxx::NDC::push(s); }

  /**
   * \brief Pop the top of the log4cxx NDC stack.
   */
  static void pop_ndc(void) { log4cxx::NDC::pop(); }

  /**
   * \param name Name of client/new logger.
   */
  explicit client(const std::string& name)
      : m_logger(log4cxx::Logger::getLogger(name)) {}

  /**
   * \brief Set the logfile of the current logger. Not idempotent.
   */
  void logfile_set(const std::string& name) {
    log4cxx::LayoutPtr layout = new log4cxx::PatternLayout(kFileLayout);
    log4cxx::AppenderPtr appender = new log4cxx::FileAppender(layout, name);
    logger()->addAppender(appender);
  }

  /**
   * \brief Get current logger name.
   */
  std::string logger_name(void) const {
    std::string name;
    m_logger->getName(name);
    return name;
  }

  /**
   * \brief Get a reference to the ER logger.
   */
  log4cxx::LoggerPtr logger(void) const { return m_logger; }

#else
  client(void) = default;
  void logfile_set(const std::string&) {}

  std::string logger_name(void) const { return ""; }
  void push_ndc(const std::string&) {}
  void pop_ndc(void) {}
#endif /* LIBRA_ER >= LIBRA_ER_ALL */

  virtual ~client(void) = default;
  client(const client&) = default;
  client& operator=(const client&) = default;

 private:
  /* clang-format off */
  static const char         kConsoleLayout[];
  static const char         kFileLayout[];

  static bool               m_initialized;

#if(LIBRA_ER >= LIBRA_ER_ALL)
  log4cxx::LoggerPtr        m_logger{};
#endif  /* LIBRA_ER >= LIBRA_ER_ALL */
  /* clang-format on */
};

template <typename T>
bool client<T>::m_initialized = false;
template <typename T>
const char client<T>::kConsoleLayout[] = "%x [%-5p] %c - %m%n";
template <typename T>
const char client<T>::kFileLayout[] = "%x [%-5p] %c %l - %m%n";

NS_END(rcppsw, er);

#endif /* INCLUDE_RCPPSW_ER_CLIENT_HPP_ */
