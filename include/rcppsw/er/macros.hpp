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

#if (RCPPSW_ERL >= RCPPSW_ERL_FATAL)
#endif

/* #if (RCPPSW_ERL == RCPPSW_ERL_FATAL) */
/* #include <type_traits> */
/* #endif */

#if (RCPPSW_ERL >= RCPPSW_ERL_FATAL)
#include <array>
#include <cassert>
#include <string>
#include <iostream>

#include "rcppsw/er/stacktrace.hpp"
#endif

/*******************************************************************************
 * Macros when ER is enabled for severity level >= FATAL:
 *
 * - The configured plugin is disabled. Only [FATAL] events are compiled in;
 *   others are discarded.
 ******************************************************************************/
#if (RCPPSW_ERL == RCPPSW_ERL_FATAL)

/**
 * \brief Emit a FATAL message.
 */
#define ER_FATAL(msg, ...)                                              \
  {                                                                     \
    std::array<char, RCPPSW_ER_MSG_LEN_MAX> _str{};                     \
    snprintf(_str.data(), RCPPSW_ER_MSG_LEN_MAX, msg, ##__VA_ARGS__);   \
    std::ostringstream _buf;                                            \
    _buf                                                                \
    << _str.data() << "\n"                                              \
    << "Backtrace:\n" << rer::stacktrace::stacktrace() << '\n';         \
  }

#elif (RCPPSW_ERL > RCPPSW_ERL_FATAL)

#define ER_FATAL(...) ER_FATAL_IMPL(RCPPSW_ER_PLUGIN_HANDLE(), __VA_ARGS__)

/* \cond INTERNAL */
#define ER_FATAL_IMPL(handle, ...) {                                    \
    if (RCPPSW_ER_PLUGIN_LVL_CHECK(handle, FATAL)) {         \
      ER_REPORT(FATAL, handle, __VA_ARGS__)                             \
    }                                                                   \
  }
/* \endcond */
#endif

/*******************************************************************************
 * Macros when ER is enabled for severity level >= ERROR:
 *
 * - The configured plugin is used. Only [FATAL,ERROR] events are compiled in;
 *   others are discarded.
 ******************************************************************************/
#if (RCPPSW_ERL >= RCPPSW_ERL_ERROR)
/**
 * \def ER_ERR(...)
 *
 * Report a non-FATAL ERROR message.
 */
#define ER_ERR(...)  ER_ERR_IMPL(RCPPSW_ER_PLUGIN_HANDLE(), __VA_ARGS__)

/* \cond INTERNAL */
#define ER_ERR_IMPL(handle, ...) {                                      \
    if (RCPPSW_ER_PLUGIN_LVL_CHECK(handle, ERROR)) {       \
      ER_REPORT(ERROR, handle, __VA_ARGS__)                             \
    }                                                                   \
  }
/* \endcond */

#endif /* RCPPSW_ERL >= RCPPSW_ERL_ERROR */

/*******************************************************************************
 * Macros when ER is enabled for severity level >= WARN:
 *
 * - The configured plugin is used. Only [FATAL,ERROR,WARN] events are compiled
 *   in; others are discarded.
 ******************************************************************************/
#if (RCPPSW_ERL >= RCPPSW_ERL_WARN)

/**
 * \def ER_WARN(...)
 *
 * Report a WARNING message (duh).
 */
#define ER_WARN(...)  ER_WARN_IMPL(RCPPSW_ER_PLUGIN_HANDLE(), __VA_ARGS__)


/* \cond INTERNAL */
#define ER_WARN_IMPL(handle, ...) {                                     \
    if (RCPPSW_ER_PLUGIN_LVL_CHECK(handle, WARN)) {        \
      ER_REPORT(WARN, handle, ## __VA_ARGS__)                           \
    }                                                                   \
  }
/* \endcond */
#endif /* RCPPSW_ERL >= RCPPSW_ERL_WARN */

/*******************************************************************************
 * Macros when ER is enabled for severity level >= INFO:
 *
 * - The configured plugin is used. Only [FATAL,ERROR,WARN,INFO] events are
 *   compiled in; others are discarded.
 ******************************************************************************/
#if (RCPPSW_ERL >= RCPPSW_ERL_INFO)

/**
 * \def ER_INFO(...)
 *
 * Report a INFOrmational message.
 */
#define ER_INFO(...)  ER_INFO_IMPL(RCPPSW_ER_PLUGIN_HANDLE(), __VA_ARGS__)

/* \cond INTERNAL */
#define ER_INFO_IMPL(handle, ...) {                                     \
    if (RCPPSW_ER_PLUGIN_LVL_CHECK(handle, INFO)) {        \
      ER_REPORT(INFO, handle, ## __VA_ARGS__)                           \
    }                                                                   \
  }
/* \endcond */
#endif /* RCPPSW_ERL >= RCPPSW_ERL_INFO */

/*******************************************************************************
 * Macros when ER is enabled for severity level >= DEBUG:
 *
 * - The configured plugin is used. Only [FATAL,ERROR,WARN,INFO,DEBUG] events
 *   are compiled in; others are discarded.
 ******************************************************************************/
#if (RCPPSW_ERL >= RCPPSW_ERL_DEBUG)

/**
 * \def ER_DEBUG(...)
 *
 * Report a DEBUGging message.
 */
#define ER_DEBUG(...)  ER_DEBUG_IMPL(RCPPSW_ER_PLUGIN_HANDLE(), __VA_ARGS__)

/* \cond INTERNAL */
#define ER_DEBUG_IMPL(handle, ...) {                                     \
    if (RCPPSW_ER_PLUGIN_LVL_CHECK(handle, DEBUG)) {        \
      ER_REPORT(DEBUG, handle, ## __VA_ARGS__)                           \
    }                                                                   \
  }
/* \endcond */
#endif /* RCPPSW_ERL >= RCPPSW_ERL_DEBUG */

/*******************************************************************************
 * Macros when ER is enabled for severity level >= TRACE:
 *
 * - The configured plugin is used. Only [FATAL,ERROR,WARN,INFO,DEBUG,TRACE]
 *   events are compiled in; others are discarded.
 *
 * - Debug printing macros enabled.
 ******************************************************************************/
#if (RCPPSW_ERL >= RCPPSW_ERL_TRACE)

/**
 * \def ER_TRACE(...)
 *
 * Report a TRACE message.
 */
#define ER_TRACE(...)  ER_TRACE_IMPL(RCPPSW_ER_PLUGIN_HANDLE(), __VA_ARGS__)

/* \cond INTERNAL */
#define ER_TRACE_IMPL(handle, ...) {                                     \
    if (RCPPSW_ER_PLUGIN_LVL_CHECK(handle, TRACE)) {        \
      ER_REPORT(TRACE, handle, ## __VA_ARGS__)                           \
    }                                                                   \
  }
/* \endcond */
#endif /* RCPPSW_ERL >= RCPPSW_ERL_TRACE */


/*******************************************************************************
 * General ER macros for when ER is != NONE.
 ******************************************************************************/
#if RCPPSW_ERL != RCPPSW_ERL_NONE

/**
 * \def ER_REPORT(lvl, msg, ...)
 *
 * Define a statement reporting the occurrence of an event with the specified
 * level \a lvl.
 *
 * This macro is only available if the event reporting level is > NONE.
 */
#define ER_REPORT(LVL, HANDLE, MSG, ...)        \
  {                                             \
    RCPPSW_ER_PLUGIN_REPORT(LVL,                \
                            HANDLE,             \
                            MSG "\n",           \
                            ## __VA_ARGS__)     \
  }

#endif /* (RCPPSW_ERL != RCPPSW_ERL_NONE) */

/*******************************************************************************
 * General ER macros independent of level
 ******************************************************************************/
/**
 * \brief Platform/OS independent macro for printing to the terminal
 */
#define PRINTF(...) RCPPSW_ER_PLUGIN_PRINTF(__VA_ARGS__)

/**
 * \def ER_ASSERT(cond, msg, ...)
 *
 * Check a boolean condition \a cond in a function, halting the program if the
 * condition is not true. Like assert(), but allows for an additional custom
 * msg to be logged.
 */
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
    if (RCPPSW_UNLIKELY(!(cond))) {               \
      ER_FATAL( msg, ##__VA_ARGS__);            \
      assert(cond);                             \
    }                                           \
  } while (0);

/**
 * \def ER_CONDW(cond, msg, ...)
 *
 * Check a boolean condition \a cond in a function. If condition IS true,
 * emit a warning message.
 */
#define ER_CONDW(cond, msg, ...)                \
  {                                             \
    if (RCPPSW_LIKELY((cond))) {                  \
      ER_WARN(msg, ##__VA_ARGS__);              \
    }                                           \
  }

/**
 * \def ER_CONDI(cond, msg, ...)
 *
 * Check a boolean condition \a cond in a function. If condition IS true,
 * emit an informational message.
 */
#define ER_CONDI(cond, msg, ...)                \
  {                                             \
    if (RCPPSW_LIKELY((cond))) {                  \
      ER_INFO(msg, ##__VA_ARGS__);              \
    }                                           \
  }

/**
 * \def ER_CONDD(cond, msg, ...)
 *
 * Check a boolean condition \a cond in a function. If condition IS true,
 * emit a debug message.
 */
#define ER_CONDD(cond, msg, ...)                \
  {                                             \
    if (RCPPSW_LIKELY((cond))) {                  \
      ER_DEBUG(msg, ##__VA_ARGS__);             \
    }                                           \
  }


/**
 * \def ER_FATAL_SENTINEL(msg,...)
 *
 * Mark a place in the code as being universally bad, like really really
 * bad. Fatally bad. If execution ever reaches this spot stop the program after
 * reporting the specified message.
 */
#define ER_FATAL_SENTINEL(msg, ...)             \
  {                                             \
    ER_FATAL(msg, ##__VA_ARGS__);               \
    std::abort();                               \
  }


/**
 * \def ER_CHECK(cond, msg, ...)
 *
 * Check a boolean condition \a cond in a function. If condition is not true, go
 * to the error/bailout section for function (you must have a label called \c
 * error in your function) after reporting the event.
 */
#define ER_CHECK(cond, msg, ...)                \
  {                                             \
    if (RCPPSW_UNLIKELY(!(cond))) {               \
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
#define ER_SENTINEL(msg, ...)                   \
  {                                             \
    ER_ERR(msg, ##__VA_ARGS__);                 \
    goto error;                                 \
  }

/*******************************************************************************
 * Macro Cleanup
 *
 * Depending on compile-time level, one or more of these macros may be
 * undefined, so make sure everything is defined so things build cleanly.
 ******************************************************************************/
#ifndef ER_FATAL
#define ER_FATAL(...)
#endif

#ifndef ER_ERR
#define ER_ERR(...)
#endif

#ifndef ER_WARN
#define ER_WARN(...)
#endif

#ifndef ER_INFO
#define ER_INFO(...)
#endif

#ifndef ER_DEBUG
#define ER_DEBUG(...)
#endif

#ifndef ER_TRACE
#define ER_TRACE(...)
#endif

#ifndef ER_REPORT
#define ER_REPORT(...)
#endif

