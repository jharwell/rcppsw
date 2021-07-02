/**
 * \file base_metrics_manager.hpp
 *
 * \copyright 2020 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_METRICS_BASE_METRICS_MANAGER_HPP_
#define INCLUDE_RCPPSW_METRICS_BASE_METRICS_MANAGER_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <filesystem>
#include <map>
#include <string>
#include <utility>
#include <memory>

#include "rcppsw/er/client.hpp"
#include "rcppsw/math/vector2.hpp"
#include "rcppsw/math/vector3.hpp"
#include "rcppsw/metrics/collector_group.hpp"

#include "rcppsw/rcppsw.hpp"
#include "rcppsw/metrics/config/metrics_config.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/

NS_START(rcppsw, metrics);
namespace fs = std::filesystem;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class base_metrics_manager
 * \ingroup metrics
 *
 * \brief Base class for managing metrics collected from variable sources across
 * all possible collector output modes and sinks.
 */
class base_metrics_manager : public rer::client<base_metrics_manager> {
 public:
  base_metrics_manager(const rmconfig::metrics_config* mconfig,
                       const fs::path& output_root);
  ~base_metrics_manager(void) override = default;

  const fs::path& metrics_path(void) const { return m_metrics_path; }

  /**
   * \brief To be called before \ref collector_register(), in order to correctly
   * set up the collector map for the collector with the specified scoped
   * name.
   *
   * If you forget to do this you will get a segfault.
   */
  void collector_preregister(const std::string& scoped_name,
                             const rmetrics::output_mode& mode) {
    if (rmetrics::output_mode::ekAPPEND == mode) {
      m_collector_map[scoped_name] = &m_append;
    } else if (rmetrics::output_mode::ekTRUNCATE == mode) {
      m_collector_map[scoped_name] = &m_truncate;
    } else if (rmetrics::output_mode::ekCREATE == mode) {
      m_collector_map[scoped_name] = &m_create;
    }
  }

  /**
   * \brief Decorator around \ref collector_group::collector_register().
   */
  template <typename TCollector, typename... Args>
  bool collector_register(const std::string& scoped_name,
                          Args&&... args) {
    return m_collector_map[scoped_name]->collector_register<TCollector>(
        scoped_name,
        std::forward<Args>(args)...);
  }

  /**
   * \brief Decorator around \ref collector_group::initialize().
   */
  void initialize(void) {
    m_create.initialize();
    m_append.initialize();
    m_truncate.initialize();
  }

  /**
   * \brief Decorator around \ref collector_group::collect().
   */
  template <typename T>
  void collect(const std::string& scoped_name, const T& collectee) {
    auto it = m_collector_map.find(scoped_name);
    if (it != m_collector_map.end()) {
      it->second->collect(scoped_name, collectee);
    }
  } /* collect() */

  /**
   * \brief Decorator around \ref collector_group::collect_if().
   */
  template <typename T>
  void
  collect_if(const std::string& scoped_name,
             const T& collectee,
             const std::function<bool(const rmetrics::base_metrics&)>& pred) {
    auto it = m_collector_map.find(scoped_name);
    if (it != m_collector_map.end()) {
      it->second->collect_if(scoped_name, collectee, pred);
    }
  } /* collect() */

  /**
   * \brief Decorator around \ref collector_group::collector_unregister().
   */
  bool collector_unregister(const std::string& scoped_name) {
    auto it = m_collector_map.find(scoped_name);
    if (it != m_collector_map.end()) {
      return it->second->collector_unregister(scoped_name);
    }
    return false;
  }

  /**
   * \brief Decorator around \ref collector_group::get().
   */
  template <typename T>
  const T* get(const std::string& key) {
    return m_collector_map[key]->get<T>(key);
  }

  bool flush(const rmetrics::output_mode& mode) {
    if (rmetrics::output_mode::ekAPPEND == mode) {
      return m_append.flush(true);
    } else if (rmetrics::output_mode::ekTRUNCATE == mode) {
      return m_truncate.flush(true);
    } else if (rmetrics::output_mode::ekCREATE == mode) {
      return m_create.flush(true);
    }
    return false;
  }

  /**
   * \brief Decorator around \ref collector_group::timestep_inc().
   */
  void timestep_inc(void) {
    m_append.timestep_inc();
    m_truncate.timestep_inc();
    m_create.timestep_inc();
  }

  /**
   * \brief Decorator around \ref collector_group::interval_reset().
   */
  void interval_reset(void) {
    m_append.interval_reset();
    m_truncate.interval_reset();
    m_create.interval_reset();
  }

  /**
   * \brief Decorator around \ref collector_group::finalize_all().
   */
  void finalize(void) {
    m_append.finalize();
    m_truncate.finalize();
    m_create.finalize();
  }

 private:
  /**
   * \brief Maps the scoped name of the collector to the \ref collector_group it
   * belongs in.
   */
  using collector_map_type = std::map<std::string, rmetrics::collector_group*>;

  /* clang-format off */
  fs::path                  m_metrics_path;
  collector_map_type        m_collector_map{};
  rmetrics::collector_group m_append{};
  rmetrics::collector_group m_truncate{};
  rmetrics::collector_group m_create{};
  /* clang-format on */
};

NS_END(metrics, rcppsw);

#endif /* INCLUDE_RCPPSW_METRICS_BASE_METRICS_MANAGER_HPP_ */
