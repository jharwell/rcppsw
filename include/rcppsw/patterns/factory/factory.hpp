/**
 * @file factory.hpp
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

#ifndef INCLUDE_RCPPSW_PATTERNS_FACTORY_FACTORY_HPP_
#define INCLUDE_RCPPSW_PATTERNS_FACTORY_FACTORY_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include <map>
#include <memory>
#include <utility>
#include <vector>

#include "rcppsw/patterns/singleton.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, patterns, factory, detail);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class factory
 * @ingroup rcppsw patterns factory
 *
 * @brief Dispatcher factory class that releases or shares ownership of the
 * created objects to the class/context that requests object creation. All
 * classes of the derived type must have compatible constructor signatures.
 *
 * @tparam TPointerWrapper Type of pointer wrapper (shared or unique).
 * @tparam TBase Type of objects capable of creation from this factory
 * (restricted to this type and its derived types).
 *
 * @tparam Args List of constructor arguments for the types to be
 * constructed.
 */
template <template <class WrappedTBase, typename...> class TPointerWrapper,
          typename TBase,
          typename ...Args>
class base_factory {
  template<template <class, typename...> class Wrapper>
  using wrapper_is_shared = typename std::is_same<Wrapper<int>,
                                         std::shared_ptr<int>
                                                  >;
  template<template <class, typename...> class Wrapper>
  using wrapper_is_unique = typename std::is_same<Wrapper<int>,
                                                  std::unique_ptr<int>
                                                  >;
  static_assert(wrapper_is_shared<TPointerWrapper>::value ||
                wrapper_is_unique<TPointerWrapper>::value,
                "ERROR: TPointerWrapper must be std::unique_ptr or std::shared_ptr");

 public:
  TPointerWrapper<TBase> create(const std::string& name, Args... args) {
    auto it = m_workers.find(name);
    if (it != m_workers.end()) {
      return it->second->create(args...);
    }
    return nullptr;
  }

  template <typename TDerived>
  void register_type(const std::string& name) {
    static_assert(std::is_base_of<TBase, TDerived>::value,
                  "register_type() only accepts types derived from the base");
    if (m_workers.end() == m_workers.find(name)) {
      m_workers[name] = rcppsw::make_unique<
        factory_worker_impl<TDerived,
                            wrapper_is_shared<TPointerWrapper>::value>>();
    }
  }

 private:
  /**
   * @brief Helper interface class to actually do object creation. Must be
   * nested *inside* the factory class so that we can use the variadic arguments
   * passed to the template AND still be able to use virtual functions.
   */

  struct factory_worker {
    virtual ~factory_worker(void) = default;
    virtual TPointerWrapper<TBase> create(Args...args) = 0;
  };

  /**
   * @brief Implementation of \ref factory_worker interface. We need two
   * specializations: one for std::shared_ptr, and one for std::unique_ptr,
   * because we need to maintain a list of the objects we have created for
   * std::shared_ptr. Returning the shared_ptr object without doing this can
   * result in dangling references if the calling application thinks *we* are
   * maintaining a copy of the shared_ptr, and it is safe for them to use the
   * underlying raw pointer to indicate non-owning access.
   */
  template<typename TDerived, bool TForShared>
  struct factory_worker_impl {};

  template<typename TDerived>
  struct factory_worker_impl<TDerived,
                             std::true_type::value > final : public factory_worker {
    ~factory_worker_impl(void) override = default;
    TPointerWrapper<TBase> create(Args... args) override {
      m_items.push_back(std::make_shared<TDerived>(std::forward<Args>(args)...));
      return m_items.back();
    }
    std::vector<TPointerWrapper<TBase>> m_items{};
  };

  template<typename TDerived>
  struct factory_worker_impl<TDerived,
                             std::false_type::value> final : public factory_worker {
    ~factory_worker_impl(void) override = default;
    TPointerWrapper<TBase> create(Args... args) override  {
      return TPointerWrapper<TDerived>(new TDerived(std::forward<Args>(args)...));
    }
  };
  std::map<std::string, std::unique_ptr<factory_worker>> m_workers{};
};

template<typename TBase, typename...Args>
class factory_singleton : public singleton<base_factory<std::unique_ptr,
                                                                  TBase,
                                                                  Args...>> {};

template<typename TBase, typename...Args>
class retaining_factory_singleton : public singleton<base_factory<std::shared_ptr,
                                                                  TBase,
                                                                  Args...>> {};
/**
 * @class multifactory
 * @ingroup rcppsw patterns factory
 *
 * @brief A factory that releases or retains ownership of the created objects to
 * the class/context that requests object creation. Derived types do not have to
 * hve compatible constructor signatures. HOWEVER, though this class can handle
 * heterogenous constructor signatures, you will likely need a switch() to
 * determine what parameters to pass based on the name of the thing you want to
 * build, thus limiting utility somewhat.
 *
 * @tparam TBase Type of objects capable of creation from this factory
 * (restricted to this type and its derived types).
 *
 * @tparam TPointerWrapper std::shared_ptr or std::unique_ptr.
 */
template <template <class WrappedTBase, typename...> class TPointerWrapper,
          typename TBase>
class multifactory {
 public:
  multifactory(void) = default;
  virtual ~multifactory(void) = default;

  /**
   * @brief Register a type with the factory, and associate it with the
   * specified name.
   *
   * The type to register must be derived from the factory base class.
   */
  template <typename TDerived, typename...Args>
  void register_type(const std::string& name) {
    static_assert(std::is_base_of<TBase, TDerived>::value,
                  "register_type() only accepts types derived from the base");
    factory_singleton<TBase, Args...>().instance().template register_type<TDerived>(name);
  }

 /**
   * @brief Create the requested object, and release ownership to the calling
   * context/application.
   */
  template<typename TDerived, typename ...Args>
  TPointerWrapper<TBase> create(const std::string& name, Args...args) {
    factory_singleton<TBase, Args...>().instance().create(name, args...);
  }
};

NS_END(detail);

template<typename TBase, typename...Args>
class releasing_factory : public detail::base_factory<std::unique_ptr,
                                                      TBase,
                                                      Args...> {};

template<typename TBase, typename...Args>
class sharing_factory : public detail::base_factory<std::shared_ptr,
                                                      TBase,
                                                      Args...> {};

template<typename TBase, typename...Args>
class releasing_multifactory : public detail::multifactory<std::unique_ptr,
                                                           TBase> {};

template<typename TBase, typename...Args>
class sharing_multifactory : public detail::multifactory<std::shared_ptr,
                                                           TBase> {};


NS_END(factory, patterns, rcppsw);

#endif /* INCLUDE_RCPPSW_PATTERNS_FACTORY_FACTORY_HPP_ */
