/**
 * \file output_mode_config.hpp
 *
 * \copyright 2021 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
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
namespace rcppsw::metrics::config {

/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/
struct output_mode_config {
  using enabled_map_type = std::map<std::string, std::string>;
  rtypes::timestep output_interval{0};
  enabled_map_type enabled{};
};

} /* namespace rcppsw::metrics::config */

