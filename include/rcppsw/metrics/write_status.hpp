/**
 * \file write_status.hpp
 *
 * \copyright 2020 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, metrics);

/*******************************************************************************
 * Type Definitions
 ******************************************************************************/
/**
 * \brief Status of attempts to write metrics to the filesystem. Used to
 * correctly triage I/O errors.
 */
enum write_status {
  /**
   * No write was attempted this timestep.
   */
  ekNO_ATTEMPT = 1 << 0,

  /**
   * A write was attempted, but was unsuccessful this timestep.
   */
  ekFAILED = 1 << 1,

  /**
   * A write was attempted and was successful this timestep.
   */
  ekSUCCESS = 1 << 2
};

NS_END(metrics, rcppsw);

