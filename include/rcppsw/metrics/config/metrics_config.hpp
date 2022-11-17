/**
 * \file metrics_config.hpp
 *
 * \copyright 2021 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <filesystem>

#include "rcppsw/config/base_config.hpp"
#include "rcppsw/metrics/config/file_sink_config.hpp"
#include "rcppsw/metrics/config/network_sink_config.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, metrics, config);

namespace fs = std::filesystem;

/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/
/**
 * \struct metrics_config
 * \ingroup metrics config
 */
struct metrics_config final : public rconfig::base_config {
  /**
   * \brief Path to the output directory for metrics RELATIVE to the overall
   * output directory.
   */
  fs::path                      metrics_path{};
  rmconfig::file_sink_config    csv{};
  rmconfig::network_sink_config network{};
};

NS_END(config, metrics, rcppsw);

