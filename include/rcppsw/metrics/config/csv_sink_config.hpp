/**
 * \file csv_sink_config.hpp
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

#ifndef INCLUDE_RCPPSW_METRICS_CONFIG_CSV_SINK_CONFIG_HPP_
#define INCLUDE_RCPPSW_METRICS_CONFIG_CSV_SINK_CONFIG_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <map>
#include <string>

#include "rcppsw/config/base_config.hpp"
#include "rcppsw/rcppsw.hpp"
#include "rcppsw/types/timestep.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, metrics, config);

/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/
struct csv_sink_output_mode_config {
  using enabled_map_type = std::map<std::string, std::string>;
  rtypes::timestep output_interval{0};
  enabled_map_type enabled{};
};

/**
 * \struct csv_sink_config
 * \ingroup metrics config
 *
 * \brief Configuration for metrics which will/can be output as .csv files.
 */
struct csv_sink_config final : public rconfig::base_config {
  csv_sink_output_mode_config append{};
  csv_sink_output_mode_config truncate{};
  csv_sink_output_mode_config create{};
};

NS_END(config, metrics, rcppsw);

#endif /* INCLUDE_RCPPSW_METRICS_CONFIG_CSV_SINK_CONFIG_HPP_ */
