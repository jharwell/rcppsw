/**
 * \file network_sink.hpp
 *
 * \copyright 2022 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_METRICS_NETWORK_SINK_HPP_
#define INCLUDE_RCPPSW_METRICS_NETWORK_SINK_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>

#include "rcppsw/metrics/base_sink.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, metrics);

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

NS_END(metrics, rcppsw);

#endif /* INCLUDE_RCPPSW_METRICS_NETWORK_SINK_HPP_ */
