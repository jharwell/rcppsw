/**
 * \file file_sink.cpp
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
#include "rcppsw/metrics/file_sink.hpp"

#include <fstream>
#include <iostream>

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, metrics);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
file_sink::file_sink(fs::path fpath,
                     const rmetrics::output_mode& mode,
                     const rtypes::timestep& interval)
    : ER_CLIENT_INIT("rcppsw.metrics.file_sink"),
      base_sink(mode, interval),
      mc_fpath(fpath),
      m_ofile(std::make_unique<std::ofstream>()) {
  ER_ASSERT(mc_fpath.has_extension(),
            "Output path %s does not include extension!", mc_fpath.c_str());
}

file_sink::~file_sink(void) = default;

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
bool file_sink::retry_io(const std::function<void(void)>& cb) {
  int tries = kN_RETRIES;
  std::string error;

  do {
    try {
      cb();
      return true;
    } catch (std::filesystem::filesystem_error& e) {
      error = e.what();
      tries--;
    }
  } while (tries > 0);

  std::cout << error << std::endl;
  return false;
} /* retry_io() */

NS_END(metrics, rcppsw);
