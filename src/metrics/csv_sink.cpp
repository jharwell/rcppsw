/**
 * \file csv_sink.cpp
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

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/metrics/csv_sink.hpp"

#include <filesystem>
#include <numeric>
#include <fstream>

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, metrics);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
csv_sink::csv_sink(fs::path fpath,
                   const rmetrics::output_mode& mode,
                   const rtypes::timestep& interval)
    : file_sink(fpath.replace_extension(".csv"), mode, interval),
      ER_CLIENT_INIT("rcppsw.metrics.csv_sink") {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
write_status csv_sink::flush(const rmetrics::base_data* data,
                             const rtypes::timestep& t) {
  auto line = csv_line_build(data, t);
  if (!line) {
    return write_status::ekNO_ATTEMPT;
  }

  bool io_success = false;
  if (output_mode::ekAPPEND == output_mode()) {
    auto append_line = [&](void) {
                         *ofile() << rcppsw::to_string(t) + mc_separator + *line
                                 << std::endl;
    };
    io_success = retry_io(append_line);
  } else if (output_mode::ekTRUNCATE == output_mode()) {
    auto write_truncate = [&](void) {
                            std::filesystem::resize_file(fpath(), 0);
                            ofile()->seekp(0);
      initialize(data);
      *ofile() << *line << std::endl;
      ofile()->flush();
    };
    io_success = retry_io(write_truncate);
  } else if (output_mode::ekCREATE == output_mode()) {
    auto write_create = [&](void) {
      std::stringstream ss;
      ss << std::setw(10) << std::setfill('0') << t.v();

      /*
       * Insert a '_XXXX' before the '.csv' part of the output filename, where
       * XXXX is the current timestep.
       */
      auto path = fpath();
      path.replace_filename(path.stem().string() +
                            fs::path("_" + ss.str()).string() +
                            path.extension().string());
      ofile()->open(path, std::ios_base::trunc | std::ios_base::out);
      initialize(data);
      *ofile() << *line << std::endl;
      ofile()->flush();
      ofile()->close();
    };
    io_success = retry_io(write_create);
  } else {
    ER_FATAL_SENTINEL("Bad output mode '%d'",
                      rcppsw::as_underlying(output_mode()));
  }
  if (io_success) {
    return write_status::ekSUCCESS;
  } else {
    return write_status::ekFAILED;
  }
} /* flush() */

void csv_sink::initialize(const rmetrics::base_data* data) {
  if (output_mode::ekAPPEND == output_mode() ||
      output_mode::ekTRUNCATE == output_mode()) {
    /* close file if its open so we can truncate it if needed */
    if (ofile()->is_open()) {
      ofile()->close();
    }

    ofile()->open(fpath(), std::ios_base::trunc | std::ios_base::out);
    csv_header_write(data);
  } else if (output_mode::ekCREATE == output_mode()) {
    if (ofile()->is_open()) {
      csv_header_write(data);
    }
  }
} /* initialize() */

void csv_sink::csv_header_write(const rmetrics::base_data* data) {
auto cols = csv_header_cols(data);
  std::string header = std::accumulate(std::next(cols.begin()),
                                       cols.end(),
                                       cols.front(),
                                       [&](const auto& sum, const auto& col) {
                                         return sum + separator() + col;
                                       });
  ER_ASSERT(ofile()->is_open(),
            "Cannot write header to %s: not open",
            fpath().c_str());

  *ofile() << header + "\n";
  ofile()->flush();
} /* csv_header_write() */

void csv_sink::finalize(void) {
  ofile()->flush();
  ofile()->close();
} /* finalize() */

NS_END(metrics, rcppsw);
