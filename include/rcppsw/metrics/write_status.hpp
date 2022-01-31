/**
 * \file write_status.hpp
 *
 * \copyright 2020 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_METRICS_WRITE_STATUS_HPP_
#define INCLUDE_RCPPSW_METRICS_WRITE_STATUS_HPP_

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

#endif /* INCLUDE_RCPPSW_METRICS_WRITE_STATUS_HPP_ */
