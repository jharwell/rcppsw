/**
 * \file simple_fsm.hpp
 *
 * \copyright 2017 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/patterns/fsm/base_fsm.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, patterns, fsm);

/*******************************************************************************
 * Type Definitions
 ******************************************************************************/
/**
 * \typedef simple_fsm
 * \ingroup patterns fsm
 *
 * \brief Simple non-heirarchical state machine class.
 */
using simple_fsm = base_fsm;

NS_END(fsm, patterns, rcppsw);

