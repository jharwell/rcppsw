/**
 * \file caching_factory.hpp
 *
 * \copyright 2019 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_PATTERNS_PROTOTYPE_CACHING_FACTORY_HPP_
#define INCLUDE_RCPPSW_PATTERNS_PROTOTYPE_CACHING_FACTORY_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <map>
#include <string>
#include <memory>

#include "rcppsw/common/common.hpp"
#include "rcppsw/patterns/factory/factory.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, patterns, prototype);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class caching_factory
 * \ingroup patterns prototype
 *
 * \brief Each time an object construction is requested, if an object type has
 * been previously created with the same name, then a reference to that a
 * previously created object of is returned, rather than a new instance of
 * it. If construction of a previously constructed type of object is requested
 * with a *NEW* name, then a new instance of the object type is created.
 *
 * Only objects derived from the base class can be created.
 */
template<typename TBase, typename...Args>
class caching_factory {
 public:
  template<typename TDerived>
  void register_type(const std::string& name) {
    m_factory.template register_type<TDerived>(name);
  }

  TBase* create(const std::string& name, Args... args) {
    auto it = m_objs.find(name);
    if (m_objs.end() == it) {
      std::shared_ptr<TBase> created = m_factory.create(name,
                                                        std::forward<Args>(args)...);
      return m_objs.insert({name, created.get()}).first->second;
    } else {
      return it->second;
    }
  }

 private:
  /* clang-format off */
  patterns::factory::sharing_factory<TBase, Args...>   m_factory{};
  std::map<std::string, TBase*>                        m_objs{};
  /* clang-format on */
};

NS_END(prototype, patterns, rcppsw);

#endif /* INCLUDE_RCPPSW_PATTERNS_PROTOTYPE_CACHING_FACTORY_HPP_ */
