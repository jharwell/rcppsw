/**
 * \file base_metric_collector.cpp
 *
 * \copyright 018 John Harwell, All rights reserved.
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

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/metrics/base_metrics_collector.hpp"
#include "rcppsw/metrics/base_metrics_sink.hpp"
#include "rcppsw/utils/maskable_enum.hpp"

#include <fstream>

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, metrics);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
base_metrics_collector::base_metrics_collector(
    std::unique_ptr<base_metrics_sink> sink)
    : ER_CLIENT_INIT("rcppsw.metrics.base_collector"),
      m_sink(std::move(sink)) {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void base_metrics_collector::initialize(void) {
  /* initialize the sink */
  m_sink->initialize(data());

  /* initialize the collector's data */
  reset_after_interval();
} /* initialize() */

void base_metrics_collector::finalize(void) {
  m_sink->finalize();
} /* finalize() */

metrics_write_status base_metrics_collector::flush(void) {
  return m_sink->flush(data(), m_timestep);
} /* flush() */

void base_metrics_collector::interval_reset(void) {
  if (m_timestep > 0UL && (m_timestep % m_sink->output_interval() == 0UL)) {
    reset_after_interval();
  }
} /* interval_reset() */

NS_END(metrics, rcppsw);
