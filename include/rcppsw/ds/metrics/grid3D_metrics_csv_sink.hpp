/**
 * \file grid3D_metrics_csv_sink.hpp
 *
 * \copyright 2019 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <list>
#include <string>

#include "rcppsw/ds/grid3D.hpp"
#include "rcppsw/metrics/csv_sink.hpp"
#include "rcppsw/ds/metrics/cell_op.hpp"
#include "rcppsw/ds/metrics/grid3D_metrics_data.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, ds, metrics);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class grid3D_metrics_csv_sink
 * \ingroup ds metrics
 *
 * \brief Base class for the .csv sinks for metrics using a 3D grid to fill with
 * counts of SOMETHING, to be averaged over the entire simulation. Each line of
 * the resulting .csv file corresponds to an XY plane for a value of Z in the
 * grid.
 */
template<typename TCellOp>
class grid3D_metrics_csv_sink : public rmetrics::csv_sink {
 public:
  /**
   * \see rmetrics::csv_sink.
   */
  grid3D_metrics_csv_sink(const std::string& fpath_stem,
                          const rmetrics::output_mode& mode,
                          const types::timestep& interval)
      : csv_sink(fpath_stem, mode, interval) {}


  std::list<std::string> csv_header_cols(
      const rmetrics::base_data* data) const override {
    auto* d = dynamic_cast<const grid3D_metrics_data*>(data);
    std::list<std::string> cols;
    for (size_t i = 0; i < d->grid.xsize(); ++i) {
      for (size_t j = 0; j < d->grid.ysize(); ++j) {
        cols.push_back("x" + rcppsw::to_string(i) + "y" + rcppsw::to_string(j));
      } /* for(i..) */
    } /* for(j..) */

    return cols;
  }

  boost::optional<std::string>
  csv_line_build(const rmetrics::base_data* data,
                 const rtypes::timestep& t) override {
    if (!ready_to_flush(t)) {
      return boost::none;
    }

    auto* d = dynamic_cast<const grid3D_metrics_data*>(data);

    std::string line;
    for (size_t k = 0; k < d->grid.zsize(); ++k) {
      for (size_t i = 0; i < d->grid.xsize(); ++i) {
        for (size_t j = 0; j < d->grid.ysize(); ++j) {
          if constexpr(std::is_same<TCellOp, cell_avg>::value) {
              line += csv_entry_domavg(d->grid.access(i, j, k),
                                       d->total_count,
                                       (k == d->grid.zsize() - 1));
            } else {
            line += rcppsw::to_string(d->grid.access(i, j, k));
          }
        } /* for(j..) */
        line += "\n";
      } /* for(i..) */
    } /* for(k..) */

    return boost::make_optional(line);
  } /* csv_line_build() */
};

NS_END(metrics, ds, rcppsw);

