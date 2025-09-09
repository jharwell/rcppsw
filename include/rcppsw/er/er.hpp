/**
 * \file er.hpp
 *
 * \copyright 2021 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Macros

 ******************************************************************************/
/*
 * If rcppsw is used in a context where this is not defined it is almost
 * assuredly an error.
 */
#if !defined(LIBRA_ERL)
#error LIBRA_ERL not defined--defaulting to ER_NONE
#endif

#if defined(LIBRA_ERL_INHERIT) && !defined(LIBRA_ERL)
#error LIBRA_ERL_INHERIT but LIBRA_ERL not defined
#endif

#define RCPPSW_ERL LIBRA_ERL

#define LIBRA_ERL_NONE  0 /* No event reporting */
#define LIBRA_ERL_FATAL 1 /* Fatal events only */
#define LIBRA_ERL_ALL   2 /* All event reporting  */

#define RCPPSW_ERL_NONE  LIBRA_ERL_NONE
#define RCPPSW_ERL_FATAL LIBRA_ERL_FATAL
#define RCPPSW_ERL_ALL   LIBRA_ERL_ALL

/*
 * Size of buffers to put on stack for creating debug strings.
 */
#define RCPPSW_ER_MSG_LEN_MAX 1000
#define RCPPSW_ER_FATAL_MSG_LEN_MAX 10000
