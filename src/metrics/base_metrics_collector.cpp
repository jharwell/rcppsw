/**
 * @file base_metric_collector.cpp
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

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/metrics/base_metrics_collector.hpp"
#include <experimental/filesystem>
#include <numeric>

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, metrics);
namespace fs = std::experimental::filesystem;

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
base_metrics_collector::base_metrics_collector(const std::string& ofname,
                                               uint interval,
                                               bool cum_only)
    : m_interval(interval),
      m_cum_only(cum_only),
      m_ofname(ofname),
      m_separator(";") {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
bool base_metrics_collector::csv_line_write(uint timestep) {
  std::string line;
  if (csv_line_build(line)) {
    if (!m_cum_only) {
      m_ofile << std::to_string(timestep) + m_separator + line << std::endl;
    } else {
      fs::resize_file(m_ofname, 0);
      m_ofile.seekp(0);
      csv_header_write();
      m_ofile << line << std::endl;
    }
    return true;
  }
  return false;
} /* csv_line_write() */

void base_metrics_collector::csv_header_write(void) {
  auto cols = csv_header_cols();
  std::string header = std::accumulate(cols.begin(),
                                       cols.end(),
                                       std::string(),
                                       [&](const auto& sum, const auto& col) {
                                         return sum + col + separator();
                                       });
  m_ofile << header + "\n";
  m_ofile.flush();
} /* csv_header_write() */

void base_metrics_collector::reset(void) {
  /* Open output file and truncate */
  if (m_ofile.is_open()) {
    m_ofile.close();
  }
  m_ofile.open(m_ofname.c_str(), std::ios_base::trunc | std::ios_base::out);
  csv_header_write();
} /* reset() */

void base_metrics_collector::interval_reset(void) {
  if (m_timestep > 0 && (m_timestep % m_interval == 0)) {
    reset_after_interval();
  }
} /* interval_reset() */

NS_END(metrics, rcppsw);
