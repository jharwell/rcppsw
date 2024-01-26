/**
 * \file file_sink.cpp
 *
 * \copyright 2018 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
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
namespace rcppsw::metrics {

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
file_sink::file_sink(fs::path fpath,
                     const rmetrics::output_mode& mode,
                     const rtypes::timestep& interval)
    : ER_CLIENT_INIT(),
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

} /* namespace rcppsw::metrics */
