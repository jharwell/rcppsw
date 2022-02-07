/**
 * \file metrics_config.hpp
 *
 * \copyright 2021 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_METRICS_CONFIG_METRICS_CONFIG_HPP_
#define INCLUDE_RCPPSW_METRICS_CONFIG_METRICS_CONFIG_HPP_

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

#endif /* INCLUDE_RCPPSW_METRICS_CONFIG_METRICS_CONFIG_HPP_ */
