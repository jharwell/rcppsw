/**
 * \file base_data.hpp
 *
 * \copyright 2017 John Harwell, All rights reserved.
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
 * Class Definitions
 ******************************************************************************/
/**
 * \interface base_data
 * \ingroup metrics
 *
 * \brief Base class for the containers of data extracted through classes
 * derived from \ref base_metrics.
 */
struct base_data {
  base_data(void) = default;
  virtual ~base_data(void) = default;
};

NS_END(metrics, rcppsw);

