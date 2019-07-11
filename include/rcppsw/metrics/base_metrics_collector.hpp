/**
 * @file base_metrics_collector.hpp
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

#ifndef INCLUDE_RCPPSW_METRICS_BASE_METRICS_COLLECTOR_HPP_
#define INCLUDE_RCPPSW_METRICS_BASE_METRICS_COLLECTOR_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <fstream>
#include <list>
#include <string>

#include "rcppsw/common/common.hpp"
#include "rcppsw/types/timestep.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, metrics);
class base_metrics;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class base_metrics_collector
 * @ingroup rcppsw metrics
 *
 * @brief Base class that uses the template design pattern to provide hooks for
 * derived classes so that the process of writing out metrics is centralized in
 * one place (here).
 *
 * Metrics are written out in .csv format at whatever frequency derived classes
 * choose.
 */
class base_metrics_collector {
 public:
  /**
   * @param ofname Output file name.
   * @param interval Collection interval.
   * @param cum_only The metrics to be collected are cumulative only. This means
   * that (1) no header will be written, (2) the output file will be truncated
   * each time \ref csv_line_build() returns true. Default = \c false;
   */
  base_metrics_collector(const std::string& ofname,
                         uint interval,
                         bool cum_only = false);

  virtual ~base_metrics_collector(void) = default;

  /**
   * @brief Reset the metrics completely, as if none have yet been collected.
   *
   * Should be called only on collection start/reset.
   */
  virtual void reset(void);

  virtual void collect(const rcppsw::metrics::base_metrics& metrics) = 0;

  /**
   * @brief Reset metrics at the end of an interval.
   *
   * Can be called every timestep (and probably should be for consistency as
   * behavior of derived classes possibly changes), and metrics will only be
   * reset after the specified number of timesteps in the interval has elapsed.
  */
  void interval_reset(void);
  types::timestep timestep(void) const { return m_timestep; }
  void timestep_inc(void) { m_timestep.set(m_timestep.v() + 1); }

  /**
   * @brief Reset metrics at the end of a timestep.
   *
   * Should be called every timestep (default implementation does nothing).
   */
  void timestep_reset(void) { reset_after_timestep(); }

  /**
   * @brief Write out the gathered metrics.
   *
   * @param timestep The current timestep.
   *
   * @return \c TRUE if a line was written, \c FALSE otherwise.
   */
  bool csv_line_write(types::timestep t);

  /**
   * @brief Finalize metrics and flush files.
   */
  void finalize(void) { m_ofile.close(); }

  /**
   * @brief Set the interval (# timesteps) for the current collector.
   */
  void interval(int interval) { m_interval = interval; }
  int interval(void) const { return m_interval; }

 protected:
  /**
   * @brief Reset some metrics (possibly).
   *
   * Can be called at the end of every interval. By default it does nothing.
   */
  virtual void reset_after_interval(void) {}

  /**
   * @brief Reset some metrics (possibly).
   *
   * Can be called every timestep. By default it does nothing.
   */
  virtual void reset_after_timestep(void) {}

  /**
   * @brief Return a list of additional columns that should be in the emitted
   * .csv file for the collector.
   */
  virtual std::list<std::string> csv_header_cols(void) const = 0;

  /**
   * @brief Build the next line of metrics
   *
   * @param line The current line, to be filled.
   *
   * @return \c TRUE if the metrics should be written out, or \c FALSE if
   * not. This allows metrics to be gathered across multiple timesteps, but only
   * written out once an interesting event has occurred.
   */
  virtual bool csv_line_build(std::string& line) = 0;

  /**
   * @brief Return a list of default columns that should be include in (almost)
   * all emitted .csv files for the collector.
   */
  std::list<std::string> dflt_csv_header_cols(void) const { return {"clock"}; }

  /**
   * @brief Write out constructed header.
   */
  void csv_header_write(void);

  const std::string& separator(void) const { return m_separator; }

  /**
   * @brief Return a string of the average value of a sum of SOMETHING over an
   * interval + separator (if the csv entry is not the last one in a line)
   */
  template <class T>
  std::string csv_entry_intavg(T sum, bool last = false) const {
    return std::to_string(static_cast<double>(sum) / interval()) +
           ((last) ? "" : separator());
  }

  /**
   * @brief Return a string of the average value of a sum of SOMETHING over the
   * elapsed simulation time so far + separator  (if the csv entry is not the
   * last one in a line).
   */
  template <class T>
  std::string csv_entry_tsavg(T sum, bool last = false) const {
    return std::to_string(static_cast<double>(sum) / (timestep() + 1).v()) +
           ((last) ? "" : separator());
  }

  /**
   * @brief Return a string of the average value of a sum of SOMETHING divided
   * by a COUNT + separator (if the csv entry is not the last one in a line). If
   * the count is 0, then "0" + separator (if the csv entry is not the last one
   * in a line) is returned
   */
  template <class T, class U>
  std::string csv_entry_domavg(T sum, U count, bool last = false) const {
    return (count > 0) ? std::to_string(static_cast<double>(sum) /
                                        static_cast<double>(count)) +
                             ((last) ? "" : separator())
                       : "0" + ((last) ? "" : separator());
  }

 private:
  /**
   * @brief Build the header line for a particular collector using \ref
   * csv_header_cols().
   *
   * @return The built header.
   */
  std::string csv_header_build(void) const;

  /* clang-format off */
  int             m_interval;
  types::timestep m_timestep{0};
  bool            m_cum_only;
  std::string     m_ofname;
  std::string     m_separator;
  std::ofstream   m_ofile{};
  /* clang-format on */
};

NS_END(metrics, rcppsw);

#endif /* INCLUDE_RCPPSW_METRICS_BASE_METRICS_COLLECTOR_HPP_ */
