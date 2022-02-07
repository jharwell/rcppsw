/**
 * \file macros.hpp
 *
 * \copyright 2021 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_ER_MACROS_HPP_
#define INCLUDE_RCPPSW_ER_MACROS_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/er/er.hpp"
#include "rcppsw/er/stacktrace.hpp"

#if (RCPPSW_ER >= RCPPSW_ER_FATAL)
#include <array>
#include <cassert>
#include <string>
#include <iostream>
#endif

#if (RCPPSW_ER == RCPPSW_ER_ALL)
#include <type_traits>
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/
#define ER_GET_LOGGER(...) \
  rer::client                                                           \
  <typename std::remove_cv                                              \
   <typename std::remove_reference                                      \
    <decltype(*this)                                                    \
     >::type                                                            \
    >::type                                                             \
   >::logger();

#if (RCPPSW_ER == RCPPSW_ER_NONE)

/*
 * Don't define the macro to be nothing, as that can leave tons of "unused
 * variable" warnings in the code for variables which are only used in
 * asserts. The sizeof() trick here does *NOT* actually evaluate the
 * condition--only the size of whatever it returns. The variables are "used",
 * making the compiler happy, but ultimately removed by the optimizer.
 */
#define ER_ASSERT(cond, msg, ...)               \
  do {                                          \
    (void)sizeof((cond));                       \
  } while (0)

#define ER_FATAL_SENTINEL(...)
#define ER_FATAL(...)

#define ER_ERR(...)
#define ER_WARN(...)
#define ER_INFO(...)
#define ER_DEBUG(...)
#define ER_TRACE(...)
#define ER_CONDW(...)
#define ER_CONDI(...)
#define ER_CONDD(...)

#elif (RCPPSW_ER == RCPPSW_ER_FATAL)

#define ER_ERR(...)
#define ER_WARN(...)
#define ER_INFO(...)
#define ER_DEBUG(...)
#define ER_TRACE(...)
#define ER_REPORT(...)
#define ER_CONDI(...)
#define ER_CONDW(...)
#define ER_CONDD(...)

#define ER_FATAL_NO_CLIENT(msg, ...)                                    \
  {                                                                     \
    std::array<char, RCPPSW_ER_MSG_LEN_MAX> _str{};                     \
    snprintf(_str.data(), RCPPSW_ER_MSG_LEN_MAX, msg, ##__VA_ARGS__);   \
    std::cerr                                                           \
        << _str.data() << "\n"                                          \
        << "Backtrace:\n" << rer::stacktrace::stacktrace() << '\n';     \
  }                                                                     \

/**
 * \def ER_ASSERT(cond, msg, ...)
 *
 * Check a boolean condition \a cond in a function, halting the program if the
 * condition is not true. Like assert(), but allows for an additional custom
 * msg to be logged.
 *
 * You can use this macro in non-class contexts.
 */
#define ER_ASSERT(cond, msg, ...) {                     \
  if (RCPPSW_UNLIKELY(!(cond))) {                       \
    ER_FATAL_NO_CLIENT(msg, ##__VA_ARGS__);             \
  }                                                     \
  }

/**
 * \def ER_FATAL_SENTINEL(msg,...)
 *
 * Mark a place in the code as being universally bad, like really really
 * bad. Fatally bad. If execution ever reaches this spot stop the program after
 * reporting the specified message.
 *
 * You can use this macro in non-class contexts.
 */
#define ER_FATAL_SENTINEL(msg, ...)                     \
  {                                                     \
    ER_FATAL_NO_CLIENT(msg, ##__VA_ARGS__);             \
    std::abort();                                       \
  }


#elif (RCPPSW_ER == RCPPSW_ER_ALL)

/**
 * \def ER_REPORT(lvl, msg, ...)
 *
 * Define a statement reporting the occurrence of an event with the specified
 * level. \a msg is the format string, and \a ... is the variadic argument list
 * (just like printf()).
 *
 * This macro is only available if event reporting is fully enabled.
 */
#define ER_REPORT(lvl, logger, msg, ...)                        \
  {                                                             \
    std::array<char, RCPPSW_ER_MSG_LEN_MAX> _report_str{};      \
    snprintf(_report_str.data(),                                \
             sizeof(_report_str),                               \
             msg,                                               \
             ##__VA_ARGS__);                                    \
    LOG4CXX_##lvl(logger, _report_str.data());                  \
  }

/**
 * \def ER_ERR(...)
 *
 * Report a non-FATAL ERROR message.
 */
#define ER_ERR(...)                             \
  {                                             \
    auto logger = ER_GET_LOGGER();              \
    if (logger->isErrorEnabled()) {             \
      ER_REPORT(ERROR, logger, __VA_ARGS__)     \
          }                                     \
  }

/**
 * \def ER_WARN(...)
 *
 * Report a WARNING message (duh).
 */
#define ER_WARN(...)                            \
  {                                             \
    auto logger = ER_GET_LOGGER();              \
    if (logger->isWarnEnabled()) {              \
      ER_REPORT(WARN, logger, __VA_ARGS__)      \
          }                                     \
  }

/**
 * \def ER_INFO(...)
 *
 * Report an INFOrmational message.
 */
#define ER_INFO(...)                            \
  {                                             \
    auto logger = ER_GET_LOGGER();              \
    if (logger->isInfoEnabled()) {              \
      ER_REPORT(INFO, logger, __VA_ARGS__)      \
          }                                     \
  }

/**
 * \def ER_DEBUG(...)
 *
 * Report a DEBUG message.
 */
#define ER_DEBUG(...)                           \
  {                                             \
    auto logger = ER_GET_LOGGER();              \
    if (logger->isDebugEnabled()) {             \
      ER_REPORT(DEBUG, logger, __VA_ARGS__)     \
          }                                     \
  }

/**
 * \def ER_TRACE(...)
 *
 * Report a TRACE message.
 */
#define ER_TRACE(...)                           \
  {                                             \
    auto logger = ER_GET_LOGGER();              \
    if (logger->isTraceEnabled()) {             \
      ER_REPORT(TRACE, logger, __VA_ARGS__)     \
          }                                     \
  }


#define ER_FATAL_WITH_CLIENT(cond, msg, ...)                            \
  {                                                                     \
  std::array<char, RCPPSW_ER_MSG_LEN_MAX> _str{};                       \
  snprintf(_str.data(), RCPPSW_ER_MSG_LEN_MAX, msg, ##__VA_ARGS__);     \
  std::ostringstream _buf;                                              \
  _buf                                                                  \
      << _str.data() << "\n"                                            \
      << "Backtrace:\n" << rer::stacktrace::stacktrace() << '\n';       \
  auto logger = ER_GET_LOGGER();                                        \
  if (logger->isFatalEnabled()) {                                       \
    LOG4CXX_FATAL(logger, _buf.str());                                  \
  }                                                                     \
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
#define ER_ASSERT(cond, msg, ...)                       \
  if (RCPPSW_UNLIKELY(!(cond))) {                       \
    ER_FATAL_WITH_CLIENT(cond, msg, ##__VA_ARGS__);     \
    assert(cond);                                       \
  }

/**
 * \def ER_FATAL_SENTINEL(msg,...)
 *
 * Mark a place in the code as being universally bad, like really really
 * bad. Fatally bad. If execution ever reaches this spot stop the program after
 * reporting the specified message.
 *
 * You cannot use this macro non-class contexts; all classes using it must
 * derive from \ref client.
 */
#define ER_FATAL_SENTINEL(msg, ...)                     \
  {                                                     \
    ER_FATAL_WITH_CLIENT(false, msg, ##__VA_ARGS__);    \
    std::abort();                                       \
  }

/**
 * \def ER_CHECKW(cond, msg, ...)
 *
 * Check a boolean condition \a cond in a function. If condition IS true,
 * emit a warning message.
 *
 * You cannot use this macro in non-class contexts, and all classes using it
 * must derive from \ref client. This macro is only available if event reporting
 * is fully enabled.
 */
#define ER_CONDW(cond, msg, ...)                \
  {                                             \
    if (RCPPSW_LIKELY((cond))) {                  \
      ER_WARN(msg, ##__VA_ARGS__);              \
    }                                           \
  }

/**
 * \def ER_CHECKI(cond, msg, ...)
 *
 * Check a boolean condition \a cond in a function. If condition IS true,
 * emit an informational message.
 *
 * You cannot use this macro in non-class contexts, and all classes using it
 * must derive from \ref client. This macro is only available if event reporting
 * is fully enabled.
 */
#define ER_CONDI(cond, msg, ...)               \
  {                                             \
    if (RCPPSW_LIKELY((cond))) {                \
      ER_INFO(msg, ##__VA_ARGS__);              \
    }                                           \
  }

/**
 * \def ER_CHECKD(cond, msg, ...)
 *
 * Check a boolean condition \a cond in a function. If condition IS true,
 * emit a debug message.
 *
 * You cannot use this macro in non-class contexts, and all classes using it
 * must derive from \ref client. This macro is only available if event reporting
 * is fully enabled.
 */
#define ER_CONDD(cond, msg, ...)               \
  {                                             \
    if (RCPPSW_LIKELY((cond))) {                \
      ER_DEBUG(msg, ##__VA_ARGS__);             \
    }                                           \
  }

#endif

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
  {                                             \
    if (RCPPSW_UNLIKELY(!(cond))) {             \
      ER_ERR(msg, ##__VA_ARGS__);               \
      goto error;                               \
    }                                           \
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

#endif /* INCLUDE_RCPPSW_ER_MACROS_HPP_ */
