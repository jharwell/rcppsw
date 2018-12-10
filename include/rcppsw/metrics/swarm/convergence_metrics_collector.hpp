/**
 * @file convergence_metrics_collector.hpp
 *
 * @copyright 2018 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_METRICS_SWARM_CONVERGENCE_METRICS_COLLECTOR_HPP_
#define INCLUDE_RCPPSW_METRICS_SWARM_CONVERGENCE_METRICS_COLLECTOR_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include <vector>

#include "rcppsw/metrics/base_metrics_collector.hpp"
#include "rcppsw/patterns/visitor/visitable.hpp"
#include "rcppsw/swarm/interactivity.hpp"
#include "rcppsw/math/range.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, metrics, swarm);

namespace iswarm = rcppsw::swarm;
namespace rmath = rcppsw::math;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class convergence_metrics_collector
 * @ingroup metrics swarm
 *
 * @brief Collector for \ref convergence_metrics.
 *
 * Metrics are written out each timestep.
 */
class convergence_metrics_collector
    : public metrics::base_metrics_collector,
      public patterns::visitor::visitable_any<convergence_metrics_collector> {
 public:
  /**
   * @param ofname The output file name.
   * @param interval Collection interval.
   */
  convergence_metrics_collector(const std::string& ofname,
                                uint interval,
                                bool pos_ent_enable,
                                const rmath::ranged& pos_ent_horizon,
                                double pos_ent_hdelta);

  void reset(void) override;
  void collect(const metrics::base_metrics& metrics) override;

 private:
  struct interact_stats {
    double raw{0.0};
    double start_raw{0.0};
    double norm{0.0};
    double start_norm{0.0};
  };

  struct order_stats {
    double order{0.0};
    double start_order{0.0};
  };

  struct pos_entropy_stats {
    double entropy{0.0};
    double start_entropy{0.0};
  };

  std::string csv_header_build(const std::string& header) override;
  bool csv_line_build(std::string& line) override;
  void reset_after_interval(void) override;

  // clang-format off
  const bool                 mc_pos_ent_enable;
  const double               mc_pos_ent_hdelta;
  const rmath::ranged        mc_pos_ent_horizon;
  iswarm::interactivity      m_interact{};

  struct interact_stats      m_interact_stats{};
  struct order_stats         m_order_stats{};
  struct pos_entropy_stats   m_pos_ent_stats{};
  // clang-format on
};

NS_END(swarm, metrics, rcppsw);

#endif /* INCLUDE_RCPPSW_METRICS_SWARM_CONVERGENCE_METRICS_COLLECTOR_HPP_ */
