/**
 * \file base_metric_collector.cpp
 *
 * \copyright 018 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/metrics/base_collector.hpp"

#include <fstream>

#include "rcppsw/metrics/base_sink.hpp"
#include "rcppsw/utils/maskable_enum.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, metrics);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
base_collector::base_collector(
    std::unique_ptr<base_sink> sink)
    : ER_CLIENT_INIT("rcppsw.metrics.base_collector"),
      m_sink(std::move(sink)) {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void base_collector::initialize(void) {
  /* initialize the sink */
  m_sink->initialize(data());

  /* initialize the collector's data */
  reset_after_interval();
} /* initialize() */

void base_collector::finalize(void) {
  m_sink->finalize();
} /* finalize() */

write_status base_collector::flush(const rtypes::timestep& t) {
  return m_sink->flush(data(), t);
} /* flush() */

void base_collector::interval_reset(const rtypes::timestep& t) {
  if (m_sink->ready_to_flush(t)) {
    reset_after_interval();
  }
} /* interval_reset() */

NS_END(metrics, rcppsw);
