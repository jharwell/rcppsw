/**
 * @file sharing_factory.hpp
 *
 * @copyright 2017 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_PATTERNS_FACTORY_SHARING_FACTORY_HPP_
#define INCLUDE_RCPPSW_PATTERNS_FACTORY_SHARING_FACTORY_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "rcppsw/patterns/factory/base_factory.hpp"
#include "rcsw/common/fpc.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, patterns, factory);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
template <typename T>
class sharing_factory : public base_factory {
 public:
  sharing_factory(void) : m_items(), m_retain_funcs() {}
   ~sharing_factory(void) override = default;

  template <typename TDerived>
  status_t register_type(const std::string& name) {
    static_assert(std::is_base_of<T, TDerived>::value,
                  "sharing_factory::register_type only accepts types derived from the base");
    if (m_retain_funcs.end() == m_retain_funcs.find(name)) {
      m_retain_funcs[name] = &sharing_factory::template do_create_retain<TDerived>;
    }
    return OK;
  }

  std::shared_ptr<T> create(const std::string& name) {
    auto it = m_retain_funcs.find(name);
    if (it != m_retain_funcs.end()) {
      return (this->*(it->second))();
    }
    return nullptr;
    }

 private:
  using instance_create_func = std::shared_ptr<T> (sharing_factory<T>::*)();

  template <typename TDerived>
  std::shared_ptr<T> do_create_retain() {
    m_items.push_back(std::make_shared<TDerived>());
    return m_items.back();
  }

  std::vector<std::shared_ptr<T>> m_items;
  std::map<std::string, instance_create_func> m_retain_funcs;
};

NS_END(factory, patterns, rcppsw);

#endif /* INCLUDE_RCPPSW_PATTERNS_FACTORY_SHARING_FACTORY_HPP_ */
