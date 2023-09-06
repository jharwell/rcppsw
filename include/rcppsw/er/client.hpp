/**
 * \file client.hpp
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
#include "rcppsw/er/plugin/log4cxx/client.hpp"
#endif
