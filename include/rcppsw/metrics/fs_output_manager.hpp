/**
 * \file fs_output_manager.hpp
 *
 * \copyright 2020 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

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
namespace rcppsw::metrics {

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

  /* base_manager overrides */
  void collector_preregister(const std::string& scoped_name,
                             const rmetrics::output_mode& mode) override final;
  void initialize(void) override;
  bool flush(const rmetrics::output_mode& mode,
             const rtypes::timestep& t) override;
  void interval_reset(const rtypes::timestep& t) override;
  void finalize(void) override;

 private:
  /* clang-format off */
  fs::path                  m_metrics_path;
  rmetrics::collector_group m_append{};
  rmetrics::collector_group m_truncate{};
  rmetrics::collector_group m_create{};
  /* clang-format on */
};

} /* namespace rcppsw::metrics */
