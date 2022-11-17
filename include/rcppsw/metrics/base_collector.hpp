/**
 * \file base_collector.hpp
 *
 * \copyright 018 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <memory>
#include <list>

#include "rcppsw/er/client.hpp"
#include "rcppsw/types/timestep.hpp"
#include "rcppsw/metrics/write_status.hpp"
#include "rcppsw/metrics/base_data.hpp"
#include "rcppsw/metrics/base_sink.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, metrics);
class base_metrics;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class base_collector
 * \ingroup metrics
 *
 * \brief Base class that uses the template design pattern to provide hooks for
 * derived classes so that the process of writing out metrics is centralized in
 * one place (here).
 *
 * Metrics are written out in .csv format at whatever frequency derived classes
 * choose.
 */
class base_collector : public er::client<base_collector> {
 public:
  /**
   * \param sinks The sinks for the metrics that determines how they will be
   *              written to the filesystem.
   */
  explicit base_collector(std::unique_ptr<base_sink> sink);

  virtual ~base_collector(void) = default;

  /**
   * \brief Collect metrics from an object which implements the necessary
   * interface (must be checked with a dynamic cast in the function itself).
   */
  virtual void collect(const rcppsw::metrics::base_metrics& metrics) = 0;

  /**
   * \brief Initialize metrics collection.
   *
   * Should be called only on collection start.
   */
  void initialize(void);

  /**
   * \see base_sink::finalize();
   */
  void finalize(void);

  /**
   * \see base_sink::flush();
   */
  write_status flush(const rtypes::timestep& t);

  /**
   * \brief Reset metrics at the end of an interval.
   *
   * Can be called every timestep (and probably should be for consistency as
   * behavior of derived classes possibly changes), and metrics will only be
   * reset after the specified number of timesteps in the interval has elapsed.
   */
  void interval_reset(const rtypes::timestep& t);

  /**
   * \brief Get a handle to the gathered data.
   */
  virtual const rmetrics::base_data* data(void) const = 0;

 protected:
  /**
   * \brief Reset some metrics (possibly).
   *
   * Can be called at the end of every interval. By default it does nothing.
   */
  virtual void reset_after_interval(void) {}

 private:
  /* clang-format off */
  std::unique_ptr<base_sink> m_sink;
  /* clang-format on */

 public:
  RCPPSW_WRAP_DECLDEF(output_mode, *m_sink, const);
  RCPPSW_WRAP_DECLDEF(ready_to_flush, *m_sink, const);
};

NS_END(metrics, rcppsw);
