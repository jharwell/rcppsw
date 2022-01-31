/**
 * \file grid2D_metrics_csv_sink.hpp
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

#ifndef INCLUDE_RCPPSW_DS_METRICS_GRID2D_METRICS_CSV_SINK_HPP_
#define INCLUDE_RCPPSW_DS_METRICS_GRID2D_METRICS_CSV_SINK_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <list>
#include <string>

#include "rcppsw/ds/grid2D.hpp"
#include "rcppsw/metrics/csv_sink.hpp"
#include "rcppsw/ds/metrics/grid2D_metrics_data.hpp"
#include "rcppsw/ds/metrics/cell_op.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, ds, metrics);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class grid2D_metrics_csv_sink
 * \ingroup ds metrics
 *
 * \brief Base class for the .csv sinks for metrics using a 2D grid to fill with
 * counts of SOMETHING, to be averaged over the entire simulation. Each line of
 * the resulting .csv file corresponds to an XY plane for a value of Z in the
 * grid.
 */
template<typename TCellOp>
class grid2D_metrics_csv_sink : public rmetrics::csv_sink {
 public:
  /**
   * \see rmetrics::csv_sink.
   */
  grid2D_metrics_csv_sink(const std::string& fpath_stem,
                          const rmetrics::output_mode& mode,
                          const types::timestep& interval)
      : csv_sink(fpath_stem, mode, interval) {}

  std::list<std::string> csv_header_cols(
      const rmetrics::base_data* data) const override {
    std::list<std::string> cols;
    auto* d = dynamic_cast<const grid2D_metrics_data*>(data);

      for (size_t j = 0; j < d->grid.ysize(); ++j) {
        cols.push_back("y" + rcppsw::to_string(j));
    } /* for(j..) */

    return cols;
  }

  boost::optional<std::string>
  csv_line_build(const rmetrics::base_data* data,
                 const rtypes::timestep& t) override {
    if (!ready_to_flush(t)) {
      return boost::none;
    }

    auto* d = dynamic_cast<const grid2D_metrics_data*>(data);
    std::string line;

    for (size_t i = 0; i < d->grid.xsize(); ++i) {
      for (size_t j = 0; j < d->grid.ysize(); ++j) {
        if constexpr(std::is_same<TCellOp, cell_avg>::value) {
            line += csv_entry_domavg(d->grid.access(i, j),
                                     d->total_count,
                                     (j == d->grid.ysize() - 1));
          } else {
          line += rcppsw::to_string(d->grid.access(i, j));
        }
      } /* for(j..) */
      line += "\n";
    } /* for(i..) */

    return boost::make_optional(line);
  } /* csv_line_build() */
};

NS_END(metrics, ds, rcppsw);

#endif /* INCLUDE_RCPPSW_DS_METRICS_GRID2D_METRICS_CSV_SINK_HPP_ */
