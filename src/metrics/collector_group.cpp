/**
 * \file collector_group.cpp
 *
 * \copyright 2022 John Harwell, All rights reserved.
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

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/metrics/collector_group.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, metrics);

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
  auto it = m_collectors.find(name);
  if (it != m_collectors.end()) {
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
  ER_TRACE("Flushing %zu collectors", m_collectors.size());
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

NS_END(metrics, rcppsw);
