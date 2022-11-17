/**
 * \file output_mode_config.hpp
 *
 * \copyright 2021 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <map>
#include <string>

#include "rcppsw/rcppsw.hpp"
#include "rcppsw/types/timestep.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, metrics, config);

/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/
struct output_mode_config {
  using enabled_map_type = std::map<std::string, std::string>;
  rtypes::timestep output_interval{0};
  enabled_map_type enabled{};
};

NS_END(config, metrics, rcppsw);

