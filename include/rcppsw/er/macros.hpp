/**
 * \file macros.hpp
 *
 * \copyright 2021 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/er/er.hpp"

#if (RCPPSW_ER >= RCPPSW_ER_FATAL)
#include <array>
#include <cassert>
#include <string>
#include <iostream>

#endif

#if (RCPPSW_ER == RCPPSW_ER_FATAL)
#include <type_traits>
#endif

#if (RCPPSW_ER >= RCPPSW_ER_FATAL)
#include "rcppsw/er/stacktrace.hpp"
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/
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

#define ER_FATAL(...)

#define ER_ERR(...)
#define ER_WARN(...)
#define ER_INFO(...)
#define ER_DEBUG(...)
#define ER_TRACE(...)
#define ER_CONDW(...)
#define ER_CONDI(...)
#define ER_CONDD(...)
#define ER_REPORT(...)

#if defined(RCPPSW_ER_CLASSFREE)
#define ER_GET_LOGGER(logger)
#else
#define ER_GET_LOGGER(...)
#endif

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

#define ER_FATAL(msg, ...)                                              \
  {                                                                     \
    std::array<char, RCPPSW_ER_MSG_LEN_MAX> _str{};                     \
    snprintf(_str.data(), RCPPSW_ER_MSG_LEN_MAX, msg, ##__VA_ARGS__);   \
    std::cerr                                                           \
    << "FATAL: " << _str.data() << "\n"                                 \
    << "Backtrace:\n" << rer::stacktrace::stacktrace() << '\n';         \
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
    if (RCPPSW_UNLIKELY(!(cond))) {                     \
      ER_FATAL(msg, ##__VA_ARGS__);                     \
    }                                                   \
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
    ER_FATAL(msg, ##__VA_ARGS__);              \
    std::abort();                                       \
  }

#elif (RCPPSW_ER == RCPPSW_ER_ALL)

#if defined RCPPSW_ER_CLASSFREE
/**
 * \def ER_GET_LOGGER(logger)
 *
 * Get the log4cxx logger associated with a \ref rer::client instance. For use
 * in non-class contexts.
 */
#define ER_GET_LOGGER(logger) logger.logger()

#define ER_FATAL(msg, ...)                                              \
  {                                                                     \
    std::array<char, RCPPSW_ER_MSG_LEN_MAX> _str{};                     \
    snprintf(_str.data(), RCPPSW_ER_MSG_LEN_MAX, msg, ##__VA_ARGS__);   \
    std::cerr                                                           \
    << "FATAL: " << _str.data() << "\n"                                 \
    << "Backtrace:\n" << rer::stacktrace::stacktrace() << '\n';         \
  }                                                                     \

#else
/**
 * \def ER_GET_LOGGER(logger)
 *
 * Get the log4cxx logger associated with a \ref rer::client instance. For use
 * in class contexts.
 */
#define ER_GET_LOGGER(...) \
  rer::client                                                           \
  <typename std::remove_cv                                              \
   <typename std::remove_reference                                      \
    <decltype(*this)                                                    \
     >::type                                                            \
    >::type                                                             \
   >::logger()

#define ER_FATAL(msg, ...)                                      \
  {                                                                     \
    std::array<char, RCPPSW_ER_MSG_LEN_MAX> _str{};                     \
    snprintf(_str.data(), RCPPSW_ER_MSG_LEN_MAX, msg, ##__VA_ARGS__);   \
    std::ostringstream _buf;                                            \
    _buf                                                                \
    << _str.data() << "\n"                                              \
    << "Backtrace:\n" << rer::stacktrace::stacktrace() << '\n';         \
    auto logger = ER_GET_LOGGER();                                      \
    if (logger->isFatalEnabled()) {                                     \
      LOG4CXX_FATAL(logger, _buf.str());                                \
    }                                                                   \
  }

#endif /* RCPPS_ER_CLASSFREE */

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

#define ER_INFO_IMPL(logger, ...) {             \
    if (logger->isInfoEnabled()) {            \
      ER_REPORT(INFO, logger, __VA_ARGS__)    \
    }                                          \
  }
#define ER_ERR_IMPL(logger, ...) {              \
    if (logger->isErrorEnabled()) {            \
      ER_REPORT(ERROR, logger, __VA_ARGS__)    \
    }                                          \
  }

#define ER_WARN_IMPL(logger, ...) {               \
    if (logger->isWarnEnabled()) {             \
      ER_REPORT(WARN, logger, __VA_ARGS__)     \
    }                                           \
  }
#define ER_DEBUG_IMPL(logger, ...) {               \
    if (logger->isDebugEnabled()) {             \
      ER_REPORT(DEBUG, logger, __VA_ARGS__)     \
    }                                           \
  }
#define ER_TRACE_IMPL(logger, ...) {               \
    if (logger->isTraceEnabled()) {             \
      ER_REPORT(TRACE, logger, __VA_ARGS__)     \
    }                                           \
  }

/**
 * \def ER_ERR(...)
 *
 * Report a non-FATAL ERROR message.
 */
#if defined RCPPSW_ER_CLASSFREE
#define ER_ERR(client, ...)  ER_ERR_IMPL(ER_GET_LOGGER(client), __VA_ARGS__)
#else
#define ER_ERR(...)  ER_ERR_IMPL(ER_GET_LOGGER(), __VA_ARGS__)
#endif /* RCPPSW_ER_CLASSFREE */

/**
 * \def ER_WARN(...)
 *
 * Report a WARNING message (duh).
 */
#if defined RCPPSW_ER_CLASSFREE
#define ER_WARN(client, ...)  ER_WARN_IMPL(ER_GET_LOGGER(client), __VA_ARGS__)
#else
#define ER_WARN(...)  ER_WARN_IMPL(ER_GET_LOGGER(), __VA_ARGS__)
#endif /* RCPPSW_ER_CLASSFREE */

/**
 * \def ER_INFO(...)
 *
 * Report an INFOrmational message.
 */
#if defined RCPPSW_ER_CLASSFREE
#define ER_INFO(client, ...)  ER_INFO_IMPL(ER_GET_LOGGER(client), __VA_ARGS__)
#else
#define ER_INFO(...)  ER_INFO_IMPL(ER_GET_LOGGER(), __VA_ARGS__)
#endif /* RCPPSW_ER_CLASSFREE */

/**
 * \def ER_DEBUG(...)
 *
 * Report a DEBUG message.
 */
#if defined RCPPSW_ER_CLASSFREE
#define ER_DEBUG(client, ...)  ER_DEBUG_IMPL(ER_GET_LOGGER(client), __VA_ARGS__)
#else
#define ER_DEBUG(...)  ER_DEBUG_IMPL(ER_GET_LOGGER(), __VA_ARGS__)
#endif /* RCPPSW_ER_CLASSFREE */

/**
 * \def ER_TRACE(...)
 *
 * Report a TRACE message.
 */
#if defined RCPPSW_ER_CLASSFREE
#define ER_TRACE(client, ...)  ER_TRACE_IMPL(ER_GET_LOGGER(client), __VA_ARGS__)
#else
#define ER_TRACE(...)  ER_TRACE_IMPL(ER_GET_LOGGER(), __VA_ARGS__)
#endif /* RCPPSW_ER_CLASSFREE */

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
    ER_FATAL( msg, ##__VA_ARGS__); \
    assert(cond);                                       \
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


#endif /* (RCPPSW_ER == RCPPSW_ER_ALL) */

#if !defined RCPPSW_ER_CLASSFREE

/**
 * \def ER_FATAL_SENTINEL(msg,...)
 *
 * Mark a place in the code as being universally bad, like really really
 * bad. Fatally bad. If execution ever reaches this spot stop the program after
 * reporting the specified message.
 */
#define ER_FATAL_SENTINEL(msg, ...)                     \
  {                                                     \
    ER_FATAL(msg, ##__VA_ARGS__);    \
    std::abort();                                       \
  }


/**
 * \def ER_CHECK(cond, msg, ...)
 *
 * Check a boolean condition \a cond in a function. If condition is not true, go
 * to the error/bailout section for function (you must have a label called \c
 * error in your function) after reporting the event.
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
 */
#define ER_SENTINEL(msg, ...)   \
  {                             \
    ER_ERR(msg, ##__VA_ARGS__); \
    goto error;                 \
  }

#endif /* !RCPPSW_ER_CLASSFREE */
