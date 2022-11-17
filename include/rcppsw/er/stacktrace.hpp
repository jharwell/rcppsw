/**
 * \file stacktrace.hpp
 *
 * \copyright 2021 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#define BOOST_STACKTRACE_USE_ADDR2LINE
#include <boost/stacktrace.hpp>

#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, er);

namespace stacktrace = boost::stacktrace;

/*******************************************************************************
* Forward Decls
 ******************************************************************************/
/**
 * \brief A signal handler to dump the current stacktrace to a file upon a fatal
 * signal using boost.
 */
void sigsegv_sighandler(int signum);

/**
 * \brief A handler to be called instead of std::terminate(), for better
 * debugging of WHERE an exception came from.
 */
RCPPSW_DEAD void terminate_handler(void);


NS_END(er, rcppsw);
