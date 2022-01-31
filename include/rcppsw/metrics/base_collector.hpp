/**
 * \file base_collector.hpp
 *
 * \copyright 018 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_METRICS_BASE_COLLECTOR_HPP_
#define INCLUDE_RCPPSW_METRICS_BASE_COLLECTOR_HPP_

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
  write_status flush(void);

  /**
   * \brief Reset metrics at the end of an interval.
   *
   * Can be called every timestep (and probably should be for consistency as
   * behavior of derived classes possibly changes), and metrics will only be
   * reset after the specified number of timesteps in the interval has elapsed.
   */
  void interval_reset(void);

  /**
   * \brief Return the current timestep tracked by the collector.
   */
  types::timestep timestep(void) const { return m_timestep; }

  /**
   * \brief Increment the timestep referenced by the collector during metric
   * collection and .csv line building.
   */
  void timestep_inc(void) { m_timestep += 1; }


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
  types::timestep            m_timestep{0};
  std::unique_ptr<base_sink> m_sink;
  /* clang-format on */
};

NS_END(metrics, rcppsw);

#endif /* INCLUDE_RCPPSW_METRICS_BASE_COLLECTOR_HPP_ */
