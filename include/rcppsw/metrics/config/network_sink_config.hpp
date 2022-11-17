/**
 * \file network_sink_config.hpp
 *
 * \copyright 2021 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/config/base_config.hpp"
#include "rcppsw/metrics/config/output_mode_config.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, metrics, config);

/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/
/**
 * \struct network_sink_config
 * \ingroup metrics config
 *
 * \brief Configuration for metrics which will/can be output to the network.
 */
struct network_sink_config final : public rconfig::base_config {
  rmetrics::config::output_mode_config stream{};
};

NS_END(config, metrics, rcppsw);

