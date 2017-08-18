/**
 * @file releasing_factory.hpp
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

#ifndef INCLUDE_RCPPSW_PATTERNS_FACTORY_RELEASING_FACTORY_HPP_
#define INCLUDE_RCPPSW_PATTERNS_FACTORY_RELEASING_FACTORY_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "rcsw/common/fpc.h"
#include "rcppsw/patterns/factory/base_factory.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, patterns, factory);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
template <typename T>
class releasing_factory : public base_factory<T> {
 public:
  releasing_factory(void) : m_release_funcs() {}

 public:
  template <typename TDerived>
  status_t register_type(const std::string& name) {
    static_assert(std::is_base_of<T, TDerived>::value,
                  "releasing_factory::register_type doesn't accept this type because doesn't derive from base class");
    FPC_CHECK(ERROR, m_release_funcs.end() == m_release_funcs.find(name));
    m_release_funcs[name] = &do_create_release<TDerived>;
    return OK;
  }

  T* create(const std::string& name) {
    auto it = m_release_funcs.find(name);
    if (it != m_release_funcs.end()) {
      return it->second();
    }
    return nullptr;
  }

 private:
  template <typename TDerived>
  static T* do_create_release() { return new TDerived(); }

  std::map<std::string,
           typename base_factory<T>::instance_create_func> m_release_funcs;
};

NS_END(factory, patterns, rcppsw);

#endif /* INCLUDE_RCPPSW_PATTERNS_FACTORY_RELEASING_FACTORY_HPP_ */
