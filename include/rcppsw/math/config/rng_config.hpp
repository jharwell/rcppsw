/**
 * \file rng_config.hpp
 *
 * \copyright 2018 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/config/base_config.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace rcppsw::math::config {

/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/
/**
 * \struct rng_config
 * \ingroup config math
 *
 * \brief Parameters for \ref rng objects.
 */
struct rng_config final : public rcppsw::config::base_config {
  /**
   * \brief The seed to use. If -1, then the current time should be used to seed
   * RNG.
   */
  int seed{-1};
};

} /* namespace rcppsw::math::config */

