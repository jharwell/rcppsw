/**
 * \file base_metrics_sink.hpp
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

#ifndef INCLUDE_RCPPSW_METRICS_BASE_METRICS_SINK_HPP_
#define INCLUDE_RCPPSW_METRICS_BASE_METRICS_SINK_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iosfwd>
#include <memory>
#include <string>
#include <filesystem>

#include "rcppsw/er/client.hpp"
#include "rcppsw/metrics/metrics_write_status.hpp"
#include "rcppsw/metrics/output_mode.hpp"
#include "rcppsw/types/timestep.hpp"
#include "rcppsw/metrics/base_metrics_data.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace fs = std::filesystem;

NS_START(rcppsw, metrics);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class base_metrics_sink
 * \ingroup metrics
 *
 * \brief Base class that uses the template design pattern to provide hooks for
 * derived classes so that the process of writing out collected metrics is
 * centralized in one place (here).
 *
 * Metrics are written out in .csv format at whatever frequency derived classes
 * choose.
 */
class base_metrics_sink : public er::client<base_metrics_sink> {
 public:
  /**
   * \param fpath Full path to output file, including the extension.
   * \param mode The output mode. See \ref output_mode for possible values.
   * \param interval Metric output interval.
   */
  base_metrics_sink(fs::path fpath,
                    const enum output_mode& mode,
                    const rtypes::timestep& interval);

  virtual ~base_metrics_sink(void);

  /**
   * \brief Initialize any required files for the metrics sink (i.e., .csv
   * headers).
   */
  virtual void initialize(const rmetrics::base_metrics_data* data) = 0;

  /**
   * \brief Finalize metrics and flush files in preparation for program exit.
   */
  virtual void finalize(void) = 0;

  /**
   * \brief Flush gathered metrics data to file; might do nothing if the
   * internal conditions for writing metrics (e.g., the configured interval) are
   * not met.
   */
  virtual metrics_write_status flush(const rmetrics::base_metrics_data* data,
                                     const rtypes::timestep& t) = 0;

  /**
   * \brief Have the conditions been met to flush the metrics ?
   */
  bool ready_to_flush(const rtypes::timestep& t) const RCPPSW_PURE;

  const fs::path& fpath(void) const { return mc_fpath; }
  const enum output_mode& output_mode(void) const { return mc_output_mode; }
  const rtypes::timestep& output_interval(void) const {
    return mc_output_interval;
  }

 protected:
  std::ofstream* ofile(void) { return m_ofile.get(); }

  /**
   * \brief Retry the I/O operation contained in \p cb.
   */
  bool retry_io(const std::function<void(void)>& cb);

 private:
  /**
   * \brief The # of times to retry a failed I/O operation (only an issue on HPC
   * environments generally).
   */
  static constexpr size_t kN_RETRIES = 10;


  /* clang-format off */
  const fs::path                 mc_fpath;
  const rmetrics::output_mode    mc_output_mode;
  const rtypes::timestep         mc_output_interval;

  std::unique_ptr<std::ofstream> m_ofile;
  /* clang-format on */
};

NS_END(metrics, rcppsw);

#endif /* INCLUDE_RCPPSW_METRICS_BASE_METRICS_SINK_HPP_ */
