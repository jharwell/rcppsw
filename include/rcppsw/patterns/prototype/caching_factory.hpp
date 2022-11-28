/**
 * \file caching_factory.hpp
 *
 * \copyright 2019 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <map>
#include <string>
#include <memory>
#include <utility>

#include "rcppsw/rcppsw.hpp"
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
 *
 * \tparam TBase The base class of objects to be created.
 * \tparam Args Arguments for class constructors.
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
  patterns::factory::sharing_factory<TBase,
                                     std::string, /* key type */
                                     Args...> m_factory{};
  std::map<std::string, TBase*>               m_objs{};
  /* clang-format on */
};

NS_END(prototype, patterns, rcppsw);

