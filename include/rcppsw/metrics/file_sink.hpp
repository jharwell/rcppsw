/**
 * \file file_sink.hpp
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

#ifndef INCLUDE_RCPPSW_METRICS_FILE_SINK_HPP_
#define INCLUDE_RCPPSW_METRICS_FILE_SINK_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iosfwd>
#include <memory>
#include <string>
#include <filesystem>

#include "rcppsw/metrics/base_sink.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace fs = std::filesystem;

NS_START(rcppsw, metrics);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class file_sink
 * \ingroup metrics
 *
 * \brief Base class for all metrics which are to be written out to a file.
 */
class file_sink : public rer::client<file_sink>,
                  public rmetrics::base_sink {
 public:
  /**
   * \param fpath Full path to output file, including the extension.
   * \param mode The output mode. See \ref output_mode for possible values.
   * \param interval Metric output interval.
   */
  file_sink(fs::path fpath,
            const rmetrics::output_mode& mode,
            const rtypes::timestep& interval);

  virtual ~file_sink(void);

  const fs::path& fpath(void) const { return mc_fpath; }

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

  std::unique_ptr<std::ofstream> m_ofile;
  /* clang-format on */
};

NS_END(metrics, rcppsw);

#endif /* INCLUDE_RCPPSW_METRICS_FILE_SINK_HPP_ */
