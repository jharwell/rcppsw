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
#include <string>

#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace rcppsw::config {


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

namespace constants {
/**
 * \brief A sentinel value for XML fields which are strings, for indicating
 * that the field is set to NOTHING (as opposed to being omitted, which could
 * result in a default which is different than the desired NOTHING).
 */
static inline const std::string kNoValue = "none";

} /* namespace constants */
} /* namespace rcppsw::config */
