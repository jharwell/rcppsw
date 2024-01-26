/**
 * \file base_sink.cpp
 *
 * \copyright 2018 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/metrics/base_sink.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace rcppsw::metrics {

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
base_sink::base_sink(const rmetrics::output_mode& mode,
                     const rtypes::timestep& interval)
    : ER_CLIENT_INIT(),
      mc_output_mode(mode),
      mc_output_interval(interval) {}

base_sink::~base_sink(void) = default;

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
bool base_sink::ready_to_flush(const rtypes::timestep& t) const {
  return utils::ready_to_flush(mc_output_interval, t);
} /* ready_to_flush() */

} /* namespace rcppsw::metrics */
