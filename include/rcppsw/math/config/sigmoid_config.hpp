/**
 * \file sigmoid_config.hpp
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
 * \struct sigmoid_config
 * \ingroup math
 *
 * \brief Parameters for probabilistic exponentials (aka sigmoids).
 */
struct sigmoid_config final : public rcppsw::config::base_config {
  double reactivity{0.0};
  double offset{0.0};
  double gamma{0.0};
};

} /* namespace rcppsw::math::config */

