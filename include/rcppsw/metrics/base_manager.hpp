/**
 * \file base_manager.hpp
 *
 * \copyright 2020 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <map>
#include <string>
#include <utility>

#include "rcppsw/math/vector2.hpp"
#include "rcppsw/math/vector3.hpp"
#include "rcppsw/metrics/collector_group.hpp"
#include "rcppsw/metrics/output_mode.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, metrics);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class base_manager
 * \ingroup metrics
 *
 * \brief Base class for managing metrics collected from variable sources across
 * all possible collector output modes and sinks.
 */
class base_manager {
 public:
  base_manager(void) = default;
  virtual ~base_manager(void) = default;

  /**
   * \brief Decorator around \ref collector_group::initialize().
   */
  virtual void initialize(void) = 0;

  virtual bool flush(const rmetrics::output_mode& mode,
                     const rtypes::timestep& t)  = 0;

  /**
   * \brief Decorator around \ref collector_group::interval_reset().
   */
  virtual void interval_reset(const rtypes::timestep& t) = 0;

  /**
   * \brief Decorator around \ref collector_group::finalize_all().
   */
  virtual void finalize(void) = 0;

  /**
   * \brief To be called before \ref collector_register(), in order to correctly
   * set up the collector map for the collector with the specified scoped
   * name.
   *
   * If you forget to do this you will get a segfault.
   */
  virtual void collector_preregister(const std::string& scoped_name,
                                     const rmetrics::output_mode& mode) = 0;

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
  template <typename T = base_collector>
  T* get(const std::string& key) {
    return m_collector_map[key]->get<T>(key);
  }

 protected:
  /**
   * \brief Maps the scoped name of the collector to the \ref collector_group it
   * belongs in.
   */
  using collector_map_type = std::map<std::string, rmetrics::collector_group*>;

  collector_map_type* collector_map(void) { return &m_collector_map; }


 private:
  /* clang-format off */
  collector_map_type m_collector_map{};
  /* clang-format on */
};

NS_END(metrics, rcppsw);
