/**
 * \file stacktrace.hpp
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
