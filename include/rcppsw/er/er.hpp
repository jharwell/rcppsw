/**
 * \file er.hpp
 *
 * \copyright 2021 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcsw/er/er.h"

/*******************************************************************************
 * Constant Definitions
 ******************************************************************************/
/* \cond INTERNAL */
#define RCPPSW_ERL_NONE  LIBRA_ERL_NONE
#define RCPPSW_ERL_FATAL LIBRA_ERL_FATAL
#define RCPPSW_ERL_ERROR LIBRA_ERL_ERROR
#define RCPPSW_ERL_WARN  LIBRA_ERL_WARN
#define RCPPSW_ERL_INFO  LIBRA_ERL_INFO
#define RCPPSW_ERL_DEBUG LIBRA_ERL_DEBUG
#define RCPPSW_ERL_TRACE LIBRA_ERL_TRACE
#define RCPPSW_ERL_ALL   LIBRA_ERL_ALL

/*
 * If rcppsw is used in a context where this is not defined it is almost
 * assuredly an error, buuuuttttttt RCPPSW might need to compile in weird
 * environments.
 */
#if !defined(LIBRA_ER)
#define LIBRA_ERL LIBRA_ERL_ALL
#endif
/* \endcond */

#if defined(LIBRA_ER_INHERIT) && !defined(LIBRA_ER)
#error LIBRA_ER_INHERIT but LIBRA_ER not defined
#endif

/**
 * \brief The compile-time event reporting level.
 */
#define RCPPSW_ERL LIBRA_ERL

/**
 * Specify that all logging go to the log4cxx framework.
 *
 * Defaults to requiring that all log4cxx-enabled functionality be in classes
 * derived from \ref rer::client. Can be overrided to class-free on a per-file
 * basis, since the underlying library is the same. See docs for details.
 *
 * This is useful in:
 *
 * - Linux targets and targets with a full-featured OS.
 */
#define RCPPSW_ER_PLUGIN_LOG4CXX 0

/**
 * Specify that all logging go to the log4cxx framework.
 *
 * Defaults to requiring that all log4cxx-enabled functionality NOT be in
 * classes.Can be overrided to class-free on a per-file basis, since the
 * underlying library is the same. See docs for details.
 *
 * This is useful in:
 *
 * - Linux targets and targets with a full-featured OS.

 */
#define RCPPSW_ER_PLUGIN_LOG4CXX_CLASSFREE 1

/**
 * The simple bare-bones logger. See docs for a detailed description.
 */
#define RCPPSW_ER_PLUGIN_SIMPLE 2

/**
 * Specify that all logging go to a custom reporting macro.
 */
#define RCPPSW_ER_PLUGIN_CUSTOM 3

/*
 * Size of buffers to put on stack for creating debug strings.
 */
#define RCPPSW_ER_MSG_LEN_MAX 1000
#define RCPPSW_ER_FATAL_MSG_LEN_MAX 10000
