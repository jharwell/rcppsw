/**
 * \file network_sink.hpp
 *
 * \copyright 2022 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>

#include "rcppsw/metrics/base_sink.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace rcppsw::metrics {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class network_sink
 * \ingroup pal ros metrics
 *
 * \brief Metrics sink so that collectors can output their metrics to a machine
 * elsewhere on the network. Metrics are written at the specified interval to
 * the specified machine to collect and process.
 */
class network_sink : public rmetrics::base_sink,
                     public rer::client<network_sink> {
 public:
  network_sink(const std::string& dest,
               const rmetrics::output_mode& mode,
               const rtypes::timestep& interval)
      : base_sink(mode, interval),
        ER_CLIENT_INIT("rcppsw.metrics.network_sink"),
        mc_dest(dest) {}

  virtual ~network_sink(void) = default;

  const std::string& dest(void) const { return mc_dest; }

 private:
  /* clang-format off */
  const std::string mc_dest;
  /* clang-format on */
};

} /* namespace rcppsw::metrics */
