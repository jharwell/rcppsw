/**
 * \file fs_output_manager.hpp
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

#ifndef INCLUDE_RCPPSW_METRICS_FS_OUTPUT_MANAGER_HPP_
#define INCLUDE_RCPPSW_METRICS_FS_OUTPUT_MANAGER_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <filesystem>
#include <map>
#include <utility>
#include <string>

#include "rcppsw/metrics/base_manager.hpp"
#include "rcppsw/metrics/config/metrics_config.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, metrics);

namespace fs = std::filesystem;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class fs_output_manager
 * \ingroup metrics
 *
 * \brief Base class for managing metrics collected from variable sources across
 * all possible collector output modes and sinks which ultimately output their
 * metrics to the filesystem.
 */
class fs_output_manager : public rer::client<fs_output_manager>,
                          public rmetrics::base_manager {
 public:
  fs_output_manager(const rmconfig::metrics_config* mconfig,
                    const fs::path& output_root);
  ~fs_output_manager(void) override = default;

  const fs::path& metrics_path(void) const { return m_metrics_path; }

  void collector_preregister(const std::string& scoped_name,
                             const rmetrics::output_mode& mode) override {
    if (rmetrics::output_mode::ekAPPEND == mode) {
      collector_map()->at(scoped_name) = &m_append;
    } else if (rmetrics::output_mode::ekTRUNCATE == mode) {
      collector_map()->at(scoped_name) = &m_truncate;
    } else if (rmetrics::output_mode::ekCREATE == mode) {
      collector_map()->at(scoped_name) = &m_create;
    } else {
      ER_FATAL_SENTINEL("Unhandled output mode %d",
                        rcppsw::as_underlying(mode));
    }
  }

  void initialize(void) override {
    m_create.initialize();
    m_append.initialize();
    m_truncate.initialize();
  }

  bool flush(const rmetrics::output_mode& mode) override {
    if (rmetrics::output_mode::ekAPPEND == mode) {
      return m_append.flush(true);
    } else if (rmetrics::output_mode::ekTRUNCATE == mode) {
      return m_truncate.flush(true);
    } else if (rmetrics::output_mode::ekCREATE == mode) {
      return m_create.flush(true);
    } else if (rmetrics::output_mode::ekSTREAM == mode) {
      return m_create.flush(true);
    } else {
      ER_FATAL_SENTINEL("Unhandled output mode %d",
                        rcppsw::as_underlying(mode));
    }
    return false;
  }

  void timestep_inc(void) override {
    m_append.timestep_inc();
    m_truncate.timestep_inc();
    m_create.timestep_inc();
  }

  void interval_reset(void) override {
    m_append.interval_reset();
    m_truncate.interval_reset();
    m_create.interval_reset();
  }

  void finalize(void) override {
    m_append.finalize();
    m_truncate.finalize();
    m_create.finalize();
  }

 private:
  /* clang-format off */
  fs::path                  m_metrics_path;
  rmetrics::collector_group m_append{};
  rmetrics::collector_group m_truncate{};
  rmetrics::collector_group m_create{};
  /* clang-format on */
};

NS_END(metrics, rcppsw);

#endif /* INCLUDE_RCPPSW_METRICS_FS_OUTPUT_MANAGER_HPP_ */
