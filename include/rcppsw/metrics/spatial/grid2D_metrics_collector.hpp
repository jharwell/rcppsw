/**
 * \file grid2D_metrics_collector.hpp
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

#ifndef INCLUDE_RCPPSW_METRICS_SPATIAL_GRID2D_METRICS_COLLECTOR_HPP_
#define INCLUDE_RCPPSW_METRICS_SPATIAL_GRID2D_METRICS_COLLECTOR_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <list>
#include <string>

#include "rcppsw/ds/grid2D.hpp"
#include "rcppsw/metrics/base_metrics_collector.hpp"
#include "rcppsw/math/vector2.hpp"
#include "rcppsw/metrics/spatial/spatial.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, metrics, spatial);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class grid2D_metrics_collector
 * \ingroup metrics spatial
 *
 * \brief Base class for collectors using a 2D grid to fill with counts of
 * SOMETHING, to be averaged over the entire simulation. Each line of the
 * resulting .csv file corresponds directly to a row in X of the 2D grid.
 */
template<typename TCellOp>
class grid2D_metrics_collector : public metrics::base_metrics_collector {
 public:
  /**
   * \param ofname The output file name.
   * \param interval Collection interval.
   * \param dims Dimensions of grid.
   */
  grid2D_metrics_collector(const std::string& ofname,
                              const types::timestep& interval,
                              const math::vector2u& dims)
      : base_metrics_collector(ofname, interval, true),
        m_stats(dims.x(), dims.y()) {}


  void reset(void) override {
    base_metrics_collector::reset();
    m_total_count = 0;
  }

  std::list<std::string> csv_header_cols(void) const override {
    std::list<std::string> cols;
    for (size_t i = 0; i < m_stats.xsize(); ++i) {
      cols.push_back("y" + rcppsw::to_string(i));
    } /* for(i..) */

    return cols;
  }

  boost::optional<std::string> csv_line_build(void) override {
    if (!((timestep() + 1) % interval() == 0)) {
      return boost::none;
    }
    std::string line;
    for (size_t j = 0; j < m_stats.ysize(); ++j) {
      for (size_t i = 0; i < m_stats.xsize(); ++i) {
        if constexpr(std::is_same<TCellOp, cell_avg>::value) {
            line += csv_entry_domavg(m_stats.access(i, j),
                                     m_total_count,
                                     (j == m_stats.xsize() - 1));
          } else {
          line += rcppsw::to_string(m_stats.access(i, j)) + separator();
        }
      } /* for(i..) */
      line += "\n";
    } /* for(j..) */

    return boost::make_optional(line);
  } /* csv_line_build() */

 protected:
  void inc_cell_count(const math::vector2u& c) {
    m_stats.access(c) += 1;
  }
  void inc_total_count(void) { ++m_total_count; }
  size_t xsize(void) const { return m_stats.xsize(); }
  size_t ysize(void) const { return m_stats.ysize(); }

 private:
  /* clang-format off */
  rcppsw::ds::grid2D<uint> m_stats;
  uint                     m_total_count{0};
  /* clang-format on */
};

NS_END(spatial, metrics, rcppsw);

#endif /* INCLUDE_RCPPSW_METRICS_SPATIAL_GRID2D_METRICS_COLLECTOR_HPP_ */
