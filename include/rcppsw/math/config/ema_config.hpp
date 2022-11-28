/**
 * \file ema_config.hpp
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
NS_START(rcppsw, math, config);

/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/
/**
 * \struct ema_config
 * \ingroup config math
 *
 * \brief Parameters for \ref ema objects.
 */
struct ema_config final : public rcppsw::config::base_config {
  double alpha{0.0};
};

NS_END(config, math, rcppsw);

