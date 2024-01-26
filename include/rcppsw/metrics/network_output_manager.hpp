/**
 * \file network_output_manager.hpp
 *
 * \copyright 2020 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
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
namespace rcppsw::metrics {

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
      : ER_CLIENT_INIT(),
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

} /* namespace rcppsw::metrics */
