/**
 * \file base_sink.hpp
 *
 * \copyright 2021 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_METRICS_BASE_SINK_HPP_
#define INCLUDE_RCPPSW_METRICS_BASE_SINK_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/er/client.hpp"
#include "rcppsw/metrics/write_status.hpp"
#include "rcppsw/types/timestep.hpp"
#include "rcppsw/metrics/base_data.hpp"
#include "rcppsw/metrics/output_mode.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, metrics);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class base_sink
 * \ingroup metrics
 *
 * \brief Base class that uses the template design pattern to provide hooks for
 * derived classes so that the process of writing out collected metrics is
 * centralized in one place (here).
 *
 * Metrics are written out in .csv format at whatever frequency derived classes
 * choose.
 */
class base_sink : public er::client<base_sink> {
 public:
  /**
   * \param mode The output mode. See \ref output_mode for possible values.
   * \param interval Metric output interval.
   */
  base_sink(const rmetrics::output_mode& mode,
            const rtypes::timestep& interval);

  virtual ~base_sink(void);

  /**
   * \brief Initialize any required files for the metrics sink (i.e., .csv
   * headers).
   */
  virtual void initialize(const rmetrics::base_data* data) = 0;

  /**
   * \brief Finalize metrics and flush files in preparation for program exit.
   */
  virtual void finalize(void) = 0;

  /**
   * \brief Flush gathered metrics data to file; might do nothing if the
   * internal conditions for writing metrics (e.g., the configured interval) are
   * not met.
   */
  virtual write_status flush(const rmetrics::base_data* data,
                             const rtypes::timestep& t) = 0;

  /**
   * \brief Have the conditions been met to flush the metrics ?
   */
  bool ready_to_flush(const rtypes::timestep& t) const RCPPSW_PURE;

  const rtypes::timestep& output_interval(void) const {
    return mc_output_interval;
  }

  const rmetrics::output_mode& output_mode(void) const { return mc_output_mode; }

 private:
  /* clang-format off */
  const rmetrics::output_mode mc_output_mode;
  const rtypes::timestep      mc_output_interval;
  /* clang-format on */
};

NS_END(metrics, rcppsw);

#endif /* INCLUDE_RCPPSW_METRICS_BASE_SINK_HPP_ */
