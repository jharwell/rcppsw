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
 * msgto be logged.
 *
 * You cannot use this macro in non-class contexts, and all classes using it
 * must derive from \ref client.
 */
#ifndef ER_NDEBUG
#define ER_ASSERT(cond, msg, ...)               \
  if (!(cond)) {                                \
    ER_FATAL(msg, ##__VA_ARGS__);               \
    assert(cond);                               \
  }
#else
#define ER_ASSERT(cond, msg, ...)
#endif

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
#ifndef ER_NDEBUG
#define ER_FATAL_SENTINEL(msg, ...)                                 \
  {                                                                 \
    ER_FATAL(msg, ##__VA_ARGS__);                                   \
    assert(false);                                                  \
  }
#else
#define ER_FATAL_SENTINEL(msg, ...)
#endif

#define ER_CLIENT_INIT(parent) \
  rcppsw::er::client<typename std::remove_reference<decltype(*this)>::type>(parent)

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
 * events.
 */
template<class T>
class client {
 public:
  explicit client(const std::string& parent) :
      m_logger(log4cxx::Logger::getLogger(parent + "." +
                                          abi::__cxa_demangle(typeid(T).name(),
                                                              nullptr,
                                                              nullptr,
                                                              nullptr))) {}
  void change_logfile(const std::string& name) {
    log4cxx::LayoutPtr layout = new log4cxx::PatternLayout(mc_layout);
    log4cxx::AppenderPtr appender = new log4cxx::FileAppender(layout, name);
    logger()->addAppender(appender);
  }
  virtual ~client(void) = default;

  /**
   * @brief Get a reference to the ER logger.
   */
  log4cxx::LoggerPtr logger(void) const { return m_logger; }

 private:
  // clang-format off
  const std::string mc_layout{"%r [%-5p] %c{10} %l - %m%n"};
  log4cxx::LoggerPtr m_logger;
  // clang-format on
};

NS_END(rcppsw, er);

#endif /* INCLUDE_RCPPSW_ER_CLIENT_HPP_ */
