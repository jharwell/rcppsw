/**
 * \file grid2D_avg_metrics_collector.cpp
 *
 * \copyright 2019 John Harwell, All rights reserved.
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
#include "rcppsw/metrics/spatial/grid2D_avg_metrics_collector.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, metrics, spatial);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
grid2D_avg_metrics_collector::grid2D_avg_metrics_collector(
    const std::string& ofname,
    const types::timestep& interval,
    const math::vector2u& dims)
    : base_metrics_collector(ofname, interval, true),
      m_stats(dims.x(), dims.y()) {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
std::list<std::string> grid2D_avg_metrics_collector::csv_header_cols(void) const {
  std::list<std::string> cols;
  for (size_t i = 0; i < m_stats.xsize(); ++i) {
    cols.push_back("y" + rcppsw::to_string(i));
  } /* for(i..) */

  return cols;
} /* csv_header_cols() */

void grid2D_avg_metrics_collector::reset(void) {
  base_metrics_collector::reset();
  reset_after_interval();
} /* reset() */

boost::optional<std::string> grid2D_avg_metrics_collector::csv_line_build(void) {
  if (!((timestep() + 1) % interval() == 0)) {
    return boost::none;
  }
  std::string line;
  for (size_t j = 0; j < m_stats.ysize(); ++j) {
    for (size_t i = 0; i < m_stats.xsize(); ++i) {
      line += csv_entry_domavg(m_stats.access(i, j),
                               m_total_count,
                               (j == m_stats.xsize() - 1));
    } /* for(i..) */
    line += "\n";
  } /* for(j..) */

  return boost::make_optional(line);
} /* csv_line_build() */

NS_END(spatial, metrics, fordyca);
