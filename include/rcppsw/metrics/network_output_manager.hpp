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

#ifndef INCLUDE_RCPPSW_METRICS_NETWORK_OUTPUT_MANAGER_HPP_
#define INCLUDE_RCPPSW_METRICS_NETWORK_OUTPUT_MANAGER_HPP_

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
  network_output_manager(void)
      : ER_CLIENT_INIT("rcppsw.metrics.network_output_manager") {}
  ~network_output_manager(void) override = default;

  void collector_preregister(const std::string& scoped_name,
                             const rmetrics::output_mode& mode) override {
    if (rmetrics::output_mode::ekSTREAM == mode) {
      collector_map()->at(scoped_name) = &m_stream;
    } else {
      ER_FATAL_SENTINEL("Unhandled output mode %d",
                        rcppsw::as_underlying(mode));
    }
  }

  void initialize(void) override {
    m_stream.initialize();
  }

  bool flush(const rmetrics::output_mode& mode) override {
    if (rmetrics::output_mode::ekSTREAM == mode) {
      return m_stream.flush(true);
    } else {
      ER_FATAL_SENTINEL("Unhandled output mode %d",
                        rcppsw::as_underlying(mode));
    }
    return false;
  }

  void timestep_inc(void) override {
    m_stream.timestep_inc();
  }

  void interval_reset(void) override {
    m_stream.interval_reset();
  }

  void finalize(void) override {
    m_stream.finalize();
  }

 private:
  /* clang-format off */
  rmetrics::collector_group m_stream{};
  /* clang-format on */
};

NS_END(metrics, rcppsw);

#endif /* INCLUDE_RCPPSW_METRICS_NETWORK_OUTPUT_MANAGER_HPP_ */
