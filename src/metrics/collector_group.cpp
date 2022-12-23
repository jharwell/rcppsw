/**
 * \file collector_group.cpp
 *
 * \copyright 2022 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/metrics/collector_group.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace rcppsw::metrics {

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/
collector_group::collector_group(void)
    : ER_CLIENT_INIT("rcppsw.metrics.collector_group") {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
bool collector_group::collector_unregister(const key_type& name) {
  auto it = m_collectors.find(name);
  if (it != m_collectors.end()) {
    m_collectors.erase(name);
    return true;
  }
  return false;
}

bool collector_group::collect(const key_type& name,
                              const base_metrics& metrics) {
  ER_DEBUG("Received collection request for collector '%s'", name.c_str());
  auto it = m_collectors.find(name);
  if (it != m_collectors.end()) {
    ER_DEBUG("Executing collection request for collector '%s'", name.c_str());
    it->second->collect(metrics);
    return true;
  }
  return false;
}

bool collector_group::collect_if(const key_type& name,
                const base_metrics& metrics,
                const std::function<bool(const base_metrics&)>& predicate) {
  auto it = m_collectors.find(name);
  if (it != m_collectors.end()) {
    if (predicate(metrics)) {
      it->second->collect(metrics);
      return true;
    }
  }
  return false;
}

void collector_group::initialize(void) {
  std::for_each(m_collectors.begin(),
                m_collectors.end(),
                [&](const auto& pair) {
                  pair.second->initialize();
                });
}

void collector_group::interval_reset(const rtypes::timestep& t) {
  ER_DEBUG("Reseting %zu collectors after interval, ts=%zu",
           m_collectors.size(),
           t.v());
  std::for_each(m_collectors.begin(),
                m_collectors.end(),
                [&](const std::pair<const key_type, mapped_type>& pair) {
                  pair.second->interval_reset(t);
                });
}

void collector_group::finalize(void) {
  std::for_each(m_collectors.begin(),
                m_collectors.end(),
                [&](const auto& pair) {
                  pair.second->finalize();
                });
}

bool collector_group::flush(bool fail_ok,
                            const rtypes::timestep& t) {
  bool ret = true;
  ER_DEBUG("Flushing %zu collectors", m_collectors.size());
  for (auto &pair : m_collectors) {
    auto res = pair.second->flush(t);
    ER_TRACE("Flushed '%s': %d", pair.first.c_str(), res);
    if (fail_ok) {
      ret &= !(res & write_status::ekNO_ATTEMPT);
    } else {
      ret &= (res & write_status::ekSUCCESS);
    }
  } /* for(&pair..) */
  return ret;
}

} /* namespace rcppsw::metrics */
