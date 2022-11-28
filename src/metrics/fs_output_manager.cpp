/**
 * \file fs_output_manager.cpp
 *
 * \copyright 2020 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/metrics/fs_output_manager.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, metrics);

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/
fs_output_manager::fs_output_manager(
    const rmconfig::metrics_config* const mconfig,
    const fs::path& output_root)
    : ER_CLIENT_INIT("rcppsw.metrics.fs_output_manager"),
      m_metrics_path(fs::current_path() / output_root / mconfig->metrics_path) {
  ER_DEBUG("Output metrics root: %s", m_metrics_path.c_str());
  if (!fs::exists(m_metrics_path)) {
    fs::create_directories(m_metrics_path);
  } else {
    ER_WARN("Output metrics root '%s' already exists", m_metrics_path.c_str());
  }
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void fs_output_manager::collector_preregister(const std::string& scoped_name,
                           const rmetrics::output_mode& mode) {
  if (rmetrics::output_mode::ekAPPEND == mode) {
    collector_map()->insert({scoped_name, &m_append});
  } else if (rmetrics::output_mode::ekTRUNCATE == mode) {
    collector_map()->insert({scoped_name, &m_truncate});
  } else if (rmetrics::output_mode::ekCREATE == mode) {
    collector_map()->insert({scoped_name,&m_create});
  } else {
    ER_FATAL_SENTINEL("Unhandled output mode %d",
                      rcppsw::as_underlying(mode));
  }
}

void fs_output_manager::initialize(void) {
  ER_DEBUG("Initialize %zu collectors", collector_map()->size());
  for (RCPPSW_UNUSED auto &pair : *collector_map()) {
    ER_TRACE("'%s' -> %p", pair.first.c_str(), pair.second);
  } /* for(&pair..) */

  m_create.initialize();
  m_append.initialize();
  m_truncate.initialize();
}

bool fs_output_manager::flush(const rmetrics::output_mode& mode,
                              const rtypes::timestep& t) {
  if (rmetrics::output_mode::ekAPPEND == mode) {
    ER_TRACE("Flush %zu ekAPPEND collectors", m_append.size());
    return m_append.flush(true, t);
  } else if (rmetrics::output_mode::ekTRUNCATE == mode) {
    ER_TRACE("Flush %zu ekTRUNCATE collectors", m_truncate.size());
    return m_truncate.flush(true, t);
  } else if (rmetrics::output_mode::ekCREATE == mode) {
    ER_TRACE("Flush %zu ekCREATE collectors", m_create.size());
    return m_create.flush(true, t);
  } else {
    ER_FATAL_SENTINEL("Unhandled output mode %d",
                      rcppsw::as_underlying(mode));
    return false;
  }
}

void fs_output_manager::interval_reset(const rtypes::timestep& t) {
  m_append.interval_reset(t);
  m_truncate.interval_reset(t);
  m_create.interval_reset(t);
}

void fs_output_manager::finalize(void) {
  m_append.finalize();
  m_truncate.finalize();
  m_create.finalize();
}


NS_END(metrics, rcppsw);
