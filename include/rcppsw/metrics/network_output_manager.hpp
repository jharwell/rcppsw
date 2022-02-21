/**
 * \file network_output_manager.hpp
 *
 * \copyright 2020 John Harwell, All rights reserved.
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

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <map>
#include <utility>
#include <string>

#include "rcppsw/metrics/base_manager.hpp"
#include "rcppsw/metrics/config/metrics_config.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, metrics);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class network_output_manager
 * \ingroup metrics
 *
 * \brief Base class for managing metrics collected from variable sources across
 * all possible collector output modes and sinks which ultimately output their
 * metrics to the filesystem.
 */
class network_output_manager : public rer::client<network_output_manager>,
                          public rmetrics::base_manager {
 public:
  network_output_manager(const std::string& dest_prefix)
      : ER_CLIENT_INIT("rcppsw.metrics.network_output_manager"),
        mc_dest_prefix(dest_prefix) {}

  ~network_output_manager(void) override = default;

  const std::string& dest_prefix(void) const { return mc_dest_prefix; }

  /* base_manager overrides */
  void collector_preregister(const std::string& scoped_name,
                             const rmetrics::output_mode& mode) override;
  void initialize(void) override;
  bool flush(const rmetrics::output_mode& mode,
             const rtypes::timestep& t) override;
  void interval_reset(const rtypes::timestep& t) override;
  void finalize(void) override;

 private:
  /* clang-format off */
  const std::string         mc_dest_prefix{};

  rmetrics::collector_group m_stream{};
  /* clang-format on */
};

NS_END(metrics, rcppsw);
