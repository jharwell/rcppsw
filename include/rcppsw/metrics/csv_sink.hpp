/**
 * \file csv_sink.hpp
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

#ifndef INCLUDE_RCPPSW_METRICS_CSV_SINK_HPP_
#define INCLUDE_RCPPSW_METRICS_CSV_SINK_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <boost/optional.hpp>
#include <list>
#include <string>
#include <filesystem>
#include <memory>

#include "rcppsw/metrics/file_sink.hpp"
#include "rcppsw/metrics/output_mode.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, metrics);
namespace fs = std::filesystem;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class csv_sink
 * \ingroup metrics
 *
 * \brief Metrics sink so that collectors can output their metrics to a \c .csv
 * file. Metrics are written out in .csv format at whatever frequency derived
 * classes choose.
 */
class csv_sink : public rmetrics::file_sink,
                 public rer::client<csv_sink> {
 public:
  /**
   * \param fpath Full path to output file, sans the \c .csv extension.
   * \param mode The output mode. See \ref output_mode for possible values.
   */
  csv_sink(fs::path fpath,
           const rmetrics::output_mode& mode,
           const rtypes::timestep& interval);

  virtual ~csv_sink(void) = default;

  /* base metrics sink overrides */
  void finalize(void) override;
  void initialize(const rmetrics::base_data* data) override;
  write_status flush(const rmetrics::base_data* data,
                     const rtypes::timestep& t) override;

 protected:
  /**
   * \brief Return a list of additional columns that should be in the emitted
   * .csv file for the sink.
   *
   * \return a list of the names of the columns for the .csv.
   */
  virtual std::list<std::string> csv_header_cols(
      const rmetrics::base_data* data) const = 0;

  /**
   * \brief Build the next line of metrics
   *
   * \return The line that should be added to the .csv file, or empty if the
   * necessary conditions are not met. This allows metrics to be gathered across
   * multiple timesteps, but only written out once an interesting event has
   * occurred.
   */
  virtual boost::optional<std::string> csv_line_build(
      const rmetrics::base_data* data,
      const rtypes::timestep& t) = 0;

  /**
   * \brief Return a list of default columns that should be include in (almost)
   * all emitted .csv files for the sink.
   *
   * \return A list of the names of the default header columns for the .csv,
   * which is: [clock].
   */
  std::list<std::string> dflt_csv_header_cols(void) const { return { "clock" }; }

  /**
   * \brief Return the separator used to separate .csv entries from each other.
   */
  const std::string& separator(void) const { return mc_separator; }

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
  std::string
  csv_entry_domavg(const T& sum, const U& count, bool last = false) const {
    return (count > 0) ? rcppsw::to_string(static_cast<double>(sum) /
                                           static_cast<double>(count)) +
                             ((last) ? "" : separator())
                       : "0" + ((last) ? "" : separator());
  }

  /**
   * \brief Return a string of the average value of a sum of SOMETHING over an
   * interval (using the value of \ref interval()) + \ref separator() (if the
   * csv entry is not the last one in a line).
   *
   * \param sum The count of SOMETHING.
   * \param last Is this the last column in the .csv row?
   */
  template <class T>
  std::string csv_entry_intavg(const T& sum, bool last = false) const {
    return rcppsw::to_string(static_cast<double>(sum) / output_interval().v()) +
        ((last) ? "" : separator());
  }

  /**
   * \brief Return a string of the average value of a sum of SOMETHING over the
   * elapsed simulation time so far (using the value of \ref timestep()) + \ref
   * separator() (if the csv entry is not the last one in a line).
   *
   * \param sum The count of SOMETHING.
   * \param last Is this the last column in the .csv row?
   */
  template <class T>
  std::string csv_entry_tsavg(const T& sum,
                              const rtypes::timestep& t,
                              bool last = false) const {
    return rcppsw::to_string(static_cast<double>(sum) / t.v()) +
        ((last) ? "" : separator());
  }

  /**
   * \brief Construct and write out the .csv header.
   */
  void csv_header_write(const rmetrics::base_data* data);


  /* clang-format off */
  const std::string mc_separator{";"};
  /* clang-format on */
};

NS_END(metrics, rcppsw);

#endif /* INCLUDE_RCPPSW_METRICS_CSV_SINK_HPP_ */
