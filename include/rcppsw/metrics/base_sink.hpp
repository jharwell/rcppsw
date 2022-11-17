/**
 * \file base_sink.hpp
 *
 * \copyright 2021 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/er/client.hpp"
#include "rcppsw/metrics/write_status.hpp"
#include "rcppsw/types/timestep.hpp"
#include "rcppsw/metrics/base_data.hpp"
#include "rcppsw/metrics/output_mode.hpp"
#include "rcppsw/metrics/utils.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, metrics);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class base_sink
 * \ingroup metrics
 *
 * \brief Base class that uses the template design pattern to provide hooks for
 * derived classes so that the process of writing out collected metrics is
 * centralized in one place (here).
 *
 * Metrics are written out in .csv format at whatever frequency derived classes
 * choose.
 */
class base_sink : public er::client<base_sink> {
 public:
  /**
   * \param mode The output mode. See \ref output_mode for possible values.
   * \param interval Metric output interval.
   */
  base_sink(const rmetrics::output_mode& mode,
            const rtypes::timestep& interval);

  virtual ~base_sink(void);

  /**
   * \brief Initialize any required files for the metrics sink (i.e., .csv
   * headers).
   */
  virtual void initialize(const rmetrics::base_data* data) = 0;

  /**
   * \brief Finalize metrics and flush files in preparation for program exit.
   */
  virtual void finalize(void) = 0;

  /**
   * \brief Flush gathered metrics data to file; might do nothing if the
   * internal conditions for writing metrics (e.g., the configured interval) are
   * not met.
   */
  virtual write_status flush(const rmetrics::base_data* data,
                             const rtypes::timestep& t) = 0;

  /**
   * \brief Have the conditions been met to flush the metrics ?
   */
  bool ready_to_flush(const rtypes::timestep& t) const RCPPSW_PURE;

  const rtypes::timestep& output_interval(void) const {
    return mc_output_interval;
  }

  const rmetrics::output_mode& output_mode(void) const { return mc_output_mode; }

 private:
  /* clang-format off */
  const rmetrics::output_mode mc_output_mode;
  const rtypes::timestep      mc_output_interval;
  /* clang-format on */
};

NS_END(metrics, rcppsw);
