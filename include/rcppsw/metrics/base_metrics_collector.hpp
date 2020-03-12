/**
 * \file base_metrics_collector.hpp
 *
 * \copyright 2018 John Harwell, All rights reserved.
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
#include <boost/optional.hpp>
#include <fstream>
#include <list>
#include <string>

#include "rcppsw/common/common.hpp"
#include "rcppsw/er/client.hpp"
#include "rcppsw/metrics/output_mode.hpp"
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
 * \class base_metrics_collector
 * \ingroup metrics
 *
 * \brief Base class that uses the template design pattern to provide hooks for
 * derived classes so that the process of writing out metrics is centralized in
 * one place (here).
 *
 * Metrics are written out in .csv format at whatever frequency derived classes
 * choose.
 */
class base_metrics_collector : public er::client<base_metrics_collector> {
 public:
  /**
   * \param ofname_stem Output file name stem; full path to output file, sans
   *                    the \c .csv extension which is added internally.
   * \param interval Collection interval.
   * \param mode The output mode. See \ref output_mode for possible values.
   */
  base_metrics_collector(const std::string& ofname_stem,
                         const types::timestep& interval,
                         const output_mode& mode);

  virtual ~base_metrics_collector(void) = default;

  /**
   * \brief Reset the metrics completely, as if none have yet been collected.
   *
   * Should be called only on collection start/reset.
   */
  virtual void reset(void);

  /**
   * \brief Collect metrics from an object which implements the necessary
   * interface (must be checked with a dynamic cast in the function itself).
   */
  virtual void collect(const rcppsw::metrics::base_metrics& metrics) = 0;

  /**
   * \brief Reset metrics at the end of an interval.
   *
   * Can be called every timestep (and probably should be for consistency as
   * behavior of derived classes possibly changes), and metrics will only be
   * reset after the specified number of timesteps in the interval has elapsed.
  */
  void interval_reset(void);

  /**
   * \brief Return the current timestep tracked by the collector.
   */
  types::timestep timestep(void) const { return m_timestep; }

  /**
   * \brief Increment the timestep referenced by the collector during metric
   * collection and .csv line building.
   */
  void timestep_inc(void) { m_timestep += 1; }

  /**
   * \brief Write out the gathered metrics.
   *
   * \param t The current timestep.
   *
   * \return \c TRUE if a line was written, \c FALSE otherwise.
   */
  bool csv_line_write(void);

  /**
   * \brief Finalize metrics and flush files.
   */
  void finalize(void) { m_ofile.close(); }

  /**
   * \brief Return the current output interval for the current collector.
   */
  const types::timestep& interval(void) const { return m_interval; }

 protected:
  /**
   * \brief Reset some metrics (possibly).
   *
   * Can be called at the end of every interval. By default it does nothing.
   */
  virtual void reset_after_interval(void) {}

  /**
   * \brief Reset some metrics (possibly).
   *
   * Can be called every timestep. By default it does nothing.
   */
  virtual void reset_after_timestep(void) {}

  /**
   * \brief Return a list of additional columns that should be in the emitted
   * .csv file for the collector.
   *
   * \return a list of the names of the columns for the .csv.
   */
  virtual std::list<std::string> csv_header_cols(void) const = 0;

  /**
   * \brief Build the next line of metrics
   *
   * \return The line that should be added to the .csv file, or empty if the
   * necessary conditions are not met. This allows metrics to be gathered across
   * multiple timesteps, but only written out once an interesting event has
   * occurred.
   */
  virtual boost::optional<std::string> csv_line_build(void) = 0;

  /**
   * \brief Return a list of default columns that should be include in (almost)
   * all emitted .csv files for the collector.
   *
   * \return A list of the names of the default header columns for the .csv,
   * which is: [clock].
   */
  std::list<std::string> dflt_csv_header_cols(void) const { return {"clock"}; }

  /**
   * \brief Write out constructed header.
   */
  void csv_header_write(void);

  /**
   * \brief Return the separator used to separate .csv entries from each other.
   */
  const std::string& separator(void) const { return mc_separator; }

  /**
   * \brief Return a string of the average value of a sum of SOMETHING over an
   * interval (using the value of \ref interval()) + separator (if the csv entry
   * is not the last one in a line).
   *
   * \param sum The count of SOMETHING.
   * \param last Is this the last column in the .csv row?
   */
  template <class T>
  std::string csv_entry_intavg(const T& sum, bool last = false) const {
    return rcppsw::to_string(static_cast<double>(sum) / interval().v()) +
           ((last) ? "" : separator());
  }

  /**
   * \brief Return a string of the average value of a sum of SOMETHING over the
   * elapsed simulation time so far (using the value of \ref timestep()) +
   * separator (if the csv entry is not the last one in a line).
   *
   * \param sum The count of SOMETHING.
   * \param last Is this the last column in the .csv row?
   */
  template <class T>
  std::string csv_entry_tsavg(const T& sum, bool last = false) const {
    return rcppsw::to_string(static_cast<double>(sum) / (timestep() + 1).v()) +
           ((last) ? "" : separator());
  }

  /**
   * \brief Return a string of the average value of a sum of SOMETHING divided
   * by a COUNT + separator (if the csv entry is not the last one in a line). If
   * the count is 0, then "0" + separator (if the csv entry is not the last one
   * in a line) is returned.
   *
   * \param sum The count of SOMETHING.
   * \param count The divisor for the SOMETHING.
   * \param last Is this the last column in the .csv row?
   */
  template <class T, class U>
  std::string csv_entry_domavg(const T& sum,
                               const U& count,
                               bool last = false) const {
    return (count > 0) ? rcppsw::to_string(static_cast<double>(sum) /
                                           static_cast<double>(count)) +
                             ((last) ? "" : separator())
                       : "0" + ((last) ? "" : separator());
  }

 private:
  /**
   * \brief Build the header line for a particular collector using \ref
   * csv_header_cols().
   *
   * \return The built header.
   */
  std::string csv_header_build(void) const;

  /* clang-format off */
  const output_mode mc_output_mode;
  const std::string mc_separator{";"};
  const std::string mc_ofname_ext{".csv"};
  const std::string mc_ofname_stem;

  types::timestep   m_interval;
  types::timestep   m_timestep{0};
  std::ofstream     m_ofile{};
  /* clang-format on */
};

NS_END(metrics, rcppsw);

#endif /* INCLUDE_RCPPSW_METRICS_BASE_METRICS_COLLECTOR_HPP_ */
