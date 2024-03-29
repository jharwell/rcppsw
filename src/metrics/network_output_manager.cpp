/**
 * \file network_output_manager.cpp
 *
 * \copyright 2022 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/metrics/network_output_manager.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace rcppsw::metrics {

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void network_output_manager::collector_preregister(const std::string& scoped_name,
                           const rmetrics::output_mode& mode) {
  if (rmetrics::output_mode::ekSTREAM == mode) {
    collector_map()->insert({scoped_name, &m_stream});
  } else {
    ER_FATAL_SENTINEL("Unhandled output mode %d",
                      rcppsw::as_underlying(mode));
  }
}

void network_output_manager::initialize(void) {
  ER_DEBUG("Initialize %zu collectors", collector_map()->size());
  for (RCPPSW_UNUSED auto &pair : *collector_map()) {
    ER_DEBUG("'%s' -> %p", pair.first.c_str(), pair.second);
  } /* for(&pair..) */

  m_stream.initialize();
}

bool network_output_manager::flush(const rmetrics::output_mode& mode,
                                   const rtypes::timestep& t) {
  if (rmetrics::output_mode::ekSTREAM == mode) {
    ER_DEBUG("Flush %zu ekSTREAM collectors", m_stream.size());
    return m_stream.flush(true, t);
  } else {
    ER_FATAL_SENTINEL("Unhandled output mode %d",
                      rcppsw::as_underlying(mode));
    return false;
  }
}

void network_output_manager::interval_reset(const rtypes::timestep& t) {
  m_stream.interval_reset(t);
}

void network_output_manager::finalize(void) {
  m_stream.finalize();
}

} /* namespace rcppsw::metrics */
