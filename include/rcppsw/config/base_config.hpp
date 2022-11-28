/**
 * \file base_config.hpp
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
NS_START(rcppsw, config);

/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/
/**
 * \struct base_config
 * \ingroup config
 *
 * \brief A stub base class for any and all derived configuration class types
 * that may need polymorphism or covariance.
 */
struct base_config {
  base_config(void) = default;
  virtual ~base_config(void) = default;
  base_config(const base_config&) = default;
  base_config& operator=(const base_config&) = default;
};

NS_END(config, config);

