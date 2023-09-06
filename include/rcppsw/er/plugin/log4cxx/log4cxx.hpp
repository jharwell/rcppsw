/**
 * \file log4cxx.hpp
 *
 * \copyright 2023 John Harwell, All rights reserved.
 *
 * SPDX-License Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#if (RCPPSW_ERL > RCPPSW_ERL_FATAL)
#include <string>
#include <memory>
#include <log4cxx/consoleappender.h>
#include <log4cxx/fileappender.h>
#include <log4cxx/logger.h>
#include <log4cxx/ndc.h>
#include <log4cxx/patternlayout.h>
#include <log4cxx/xml/domconfigurator.h>
#endif

#include "rcppsw/common/macros.hpp"

/*******************************************************************************
 * RCSW ER Plugin Definitions
 ******************************************************************************/
/* \cond INTERNAL */

/*
 * We get handed [FATAL,ERROR,WARN,INFO,DEBUG,TRACE] when checking the effective
 * level of a module vs. that of a statement, and we need to translate that
 * level to is[Fatal,Error,Warn,Info,Debug,Trace]Enabled(). Like most CS things,
 * we can solve it with a layer of indirection, in this case using (abusing?)
 * the preprocessor.
 */
#define RCPPSW_ER_LOG4CXX_FATAL Fatal
#define RCPPSW_ER_LOG4CXX_ERROR Error
#define RCPPSW_ER_LOG4CXX_WARN  Warn
#define RCPPSW_ER_LOG4CXX_INFO  Info
#define RCPPSW_ER_LOG4CXX_DEBUG Debug
#define RCPPSW_ER_LOG4CXX_TRACE Trace

#define RCPPSW_ER_LOG4CXX_LVL_TRANSLATE(LVL) RCPPSW_JOIN(RCPPSW_ER_LOG4CXX_,LVL)

#define RCPPSW_ER_PLUGIN_LVL_CHECK(HANDLE, LVL)                         \
  RCPPSW_ER_PLUGIN_LVL_CHECK_IMPL(HANDLE,                               \
                                  RCPPSW_ER_LOG4CXX_LVL_TRANSLATE(LVL))

#define RCPPSW_ER_PLUGIN_LVL_CHECK_IMPL(HANDLE, LVL)            \
  ((HANDLE)->RCPPSW_JOIN(RCPPSW_JOIN(is, LVL), Enabled)())


#define RCPPSW_ER_PLUGIN_REPORT(LVL, HANDLE, MSG, ...)          \
  {                                                             \
    std::array<char, RCPPSW_ER_MSG_LEN_MAX> _report_str{};      \
    snprintf(_report_str.data(),                                \
             sizeof(_report_str),                               \
             MSG,                                               \
             ## __VA_ARGS__);                                   \
    LOG4CXX_ ## LVL(HANDLE, _report_str.data());                \
  }

#if RCPPSW_ER_PLUGIN != RCPPSW_ER_PLUGIN_LOG4CXX_CLASSFREE

/*
 * Get the logger handle from the class type of the current object.
 */
#define RCPPSW_ER_PLUGIN_HANDLE()               \
  rer::client                                   \
  <typename std::remove_cv                      \
   <typename std::remove_reference              \
    <decltype(*this)                            \
     >::type                                    \
    >::type                                     \
   >::logger()

#else

/*
 * Require a "logger" variable to be in the present scope and of the
 * appropriate type.
 */
#define RCPPSW_ER_PLUGIN_HANDLE() logger.logger()

#endif
/* \endcond */
