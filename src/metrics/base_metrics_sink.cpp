/**
 * \file base_metrics_sink.cpp
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
#include "rcppsw/metrics/base_metrics_sink.hpp"

#include <fstream>
#include <iostream>

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, metrics);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
base_metrics_sink::base_metrics_sink(fs::path fpath,
                                     const enum output_mode& mode,
                                     const rtypes::timestep& interval)
    : ER_CLIENT_INIT("rcppsw.metrics.base_sink"),
      mc_fpath(fpath),
      mc_output_mode(mode),
      mc_output_interval(interval),
      m_ofile(std::make_unique<std::ofstream>()) {
  ER_ASSERT(mc_fpath.has_extension(),
            "Output path %s does not include extension!", mc_fpath.c_str());
}

base_metrics_sink::~base_metrics_sink(void) = default;

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
bool base_metrics_sink::retry_io(const std::function<void(void)>& cb) {
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

bool base_metrics_sink::ready_to_flush(const rtypes::timestep& t) const {
  return t % mc_output_interval == 0UL;
} /* ready_to_flush() */

NS_END(metrics, rcppsw);
