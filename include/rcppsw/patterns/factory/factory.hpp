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
#include <typeindex>
#include <memory>
#include <utility>

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
 * @brief Dispatcher factory class that releases or retains ownership of the
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
      m_workers[name] = TPointerWrapper<factory_worker_impl<TDerived>>();
    }
  }

 private:
  struct factory_worker {
    virtual ~factory_worker(void) = default;
    virtual TPointerWrapper<TBase> create(Args...args) = 0;
  };
  template<typename TDerived>
  struct factory_worker_impl : public factory_worker {
    TPointerWrapper<TBase> create(Args... args) override {
      return TPointerWrapper<TDerived>(new TDerived(std::forward<Args>(args)...));
    }
  };
  std::map<std::string, TPointerWrapper<factory_worker>> m_workers{};
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
class retaining_factory : public detail::base_factory<std::shared_ptr,
                                                      TBase,
                                                      Args...> {};

template<typename TBase, typename...Args>
class releasing_multifactory : public detail::multifactory<std::unique_ptr,
                                                           TBase> {};

template<typename TBase, typename...Args>
class retaining_multifactory : public detail::multifactory<std::shared_ptr,
                                                           TBase> {};


NS_END(factory, patterns, rcppsw);

#endif /* INCLUDE_RCPPSW_PATTERNS_FACTORY_FACTORY_HPP_ */
