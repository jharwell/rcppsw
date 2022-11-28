/**
 * \file base_factory.hpp
 *
 * \copyright 2017 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <map>
#include <vector>
#include <memory>

#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, patterns, factory, detail);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
struct factory_releasing_type {};
struct factory_sharing_type {};

/**
 * \class base_factory
 * \ingroup patterns factory
 *
 * \brief Dispatcher factory class that releases or shares ownership of the
 * created objects to the class/context that requests object creation. All
 * classes of the derived type must have compatible constructor signatures.
 *
 * \tparam TType The factory type.
 *
 * \tparam TPointerWrapper Type of pointer wrapper (shared or unique).
 *
 * \tparam TBase Type of objects capable of creation from this factory
 * (restricted to this type and its derived types).
 *
 * \tparam TKeyType Type of key for the type identifier.
 *
 * \tparam Args List of constructor arguments for the types to be
 * constructed.
 */
template <typename TType,
          template <class WrappedTBase, typename...> class TPointerWrapper,
          typename TBase,
          typename TKeyType,
          typename ...Args>
class base_factory {
 private:
  template<typename T>
  using is_sharing = typename std::is_same<T,
                                           factory_sharing_type>;
  template<typename T>
  using is_releasing = typename std::is_same<T,
                                             factory_releasing_type>;

  static_assert(is_sharing<TType>::value ||
                is_releasing<TType>::value,
                "ERROR: TType must be [releasing,sharing]");

 public:
  virtual ~base_factory(void) = default;

  /* clang-format off */
  template<typename TFactoryType = TType,
           RCPPSW_SFINAE_DECLDEF(is_sharing<TFactoryType>::value || is_releasing<TFactoryType>::value)>
  /* clang-format on */
  TPointerWrapper<TBase> create(const TKeyType& name, Args... args) {
    auto it = m_workers.find(name);
    if (it != m_workers.end()) {
      return it->second->create(args...);
    }
    return nullptr;
  }


  template <typename TDerived>
  void register_type(const TKeyType& name) {
    static_assert(std::is_base_of<TBase, TDerived>::value,
                  "register_type() only accepts types derived from the base");
    if (m_workers.end() == m_workers.find(name)) {
      m_workers[name] = std::make_unique<
        factory_worker_impl<TDerived, TType>>();
    }
  }

  template <typename TDerived>
  void unregister_type(const TKeyType& name) {
    static_assert(std::is_base_of<TBase, TDerived>::value,
                  "unregister_type() only accepts types derived from the base");
    auto it = m_workers.find(name);
    if (m_workers.end() != it) {
      m_workers.erase(it);
    }
  }

 private:
  /**
   * \brief Helper interface class to actually do object creation. Must be
   * nested *inside* the factory class so that we can use the variadic arguments
   * passed to the template AND still be able to use virtual functions.
   */

  struct factory_worker {
    virtual ~factory_worker(void) = default;
    virtual TPointerWrapper<TBase> create(Args...args) = 0;
  };

  /**
   * \brief Implementation of \ref factory_worker interface. We need different
   * specializations: one for std::shared_ptr, and one for std::unique_ptr,
   * because we need to maintain a list of the objects we have created for
   * std::shared_ptr. Returning the shared_ptr object without doing this can
   * result in dangling references if the calling application thinks *we* are
   * maintaining a copy of the shared_ptr, and it is safe for them to use the
   * underlying raw pointer to indicate non-owning access.
   */
  template<typename TDerived, typename TFactoryWorkerType>
  struct factory_worker_impl {};

  /*
   * Sharing factory worker. Maintains a vector of std::shared_ptr of the
   * objects it has created.
   */
  template<typename TDerived>
  struct factory_worker_impl<TDerived,
                             factory_sharing_type> final : public factory_worker {
    ~factory_worker_impl(void) override = default;
    std::shared_ptr<TBase> create(Args... args) override {
      m_items.push_back(std::make_shared<TDerived>(std::forward<Args>(args)...));
      return m_items.back();
    }
    std::vector<TPointerWrapper<TBase>> m_items{};
  };

  /*
   * Releasing factory worker. Maintains no state, returning std::unique_ptrs to
   * created objects.
   */
  template<typename TDerived>
  struct factory_worker_impl<TDerived,
                             factory_releasing_type> final : public factory_worker {
    ~factory_worker_impl(void) override = default;
    std::unique_ptr<TBase> create(Args... args) override {
      return std::make_unique<TDerived>(std::forward<Args>(args)...);
    }
  };

  using worker_map_type = std::map<TKeyType, std::unique_ptr<factory_worker>>;

  /* clang-format off */
  worker_map_type m_workers{};
  /* clang-format on */
};

NS_END(detail, factory, patterns, rcppsw);

