/**
 * \file plugin.hpp
 *
 * \copyright 2023 John Harwell, All rights reserved.
 *
 * SPDX-License Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/er/er.hpp"

#if (RCPPSW_ER_PLUGIN == RCPPSW_ER_PLUGIN_LOG4CXX) || (RCPPSW_ER_PLUGIN == RCPPSW_ER_PLUGIN_LOG4CXX_CLASSFREE)
#include "rcppsw/er/plugin/log4cxx/log4cxx.hpp"
#else
/* assume a custom ER plugin */
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/
#ifndef RCPPSW_ER_PLUGIN_REPORT
#error "RCPPSW_ER_PLUGIN_REPORT() not defined"
#endif

#ifndef RCPPSW_ER_PLUGIN_HANDLE
#error "RCPPSW_ER_PLUGIN_HANDLE() not defined"
#endif

#ifndef RCPPSW_ER_PLUGIN_LVL_CHECK
#error "RCPPSW_ER_PLUGIN_LVL_CHECK() not defined"
#endif
