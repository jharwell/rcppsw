/**
 * \file multifactory.hpp
 *
 * \copyright 2017 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <memory>

#include "rcppsw/patterns/factory/base_factory.hpp"
#include "rcppsw/patterns/singleton/singleton.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace rcppsw::patterns::factory {

namespace detail {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
template<typename TBase, typename TType, typename...Args>
class factory_singleton : public singleton::singleton<base_factory<TType,
                                                                   std::unique_ptr,
                                                                   TBase,
                                                                   Args...>> {};
/**
 * \class multifactory
 * \ingroup patterns factory
 *
 * \brief A factory that releases or shares ownership of the created objects to
 * the class/context that requests object creation. Derived types do not have to
 * hve compatible constructor signatures. HOWEVER, though this class can handle
 * heterogenous constructor signatures, you will likely need a switch() to
 * determine what parameters to pass based on the name of the thing you want to
 * build, thus defeating the purpose of a factory to some degree.
 *
 * \tparam TType The type of the factory.
 *
 * \tparam TBase Type of objects capable of creation from this factory
 * (restricted to this type and its derived types).
 *
 * \tparam TPointerWrapper std::shared_ptr or std::unique_ptr.
 */
template <typename TType,
          template <class WrappedTBase, typename...> class TPointerWrapper,
          typename TBase>
class multifactory {
 public:
  multifactory(void) = default;
  virtual ~multifactory(void) = default;

  /**
   * \brief Register a type with the factory, and associate it with the
   * specified name.
   *
   * The type to register must be derived from the factory base class.
   */
  template <typename TDerived, typename...Args>
  void register_type(const std::string& name) {
    static_assert(std::is_base_of<TBase, TDerived>::value,
                  "register_type() only accepts types derived from the base");
    factory_singleton<TType,
                      TBase,
                      Args...>().instance().template register_type<TDerived>(name);
  }

  template<typename TDerived, typename ...Args>
  TPointerWrapper<TBase> create(const std::string& name, Args...args) {
    factory_singleton<TType,
                      TBase,
                      Args...>().instance().create(name, args...);
  }
};

} /* namespace detail */


/**
 * \ingroup patterns factory
 *
 * \brief Specialization of the \ref multifactory class for releasing ownership
 * of created objects via std::unique_ptr.
 *
 * \tparam TBase The base class that all factory-constructed types must derive
 *               from.
 * \tparam Args Arguments common to ALL factory-constructible types.
 */
template<typename TBase, typename...Args>
class releasing_multifactory : public detail::multifactory<detail::factory_releasing_type,
                                                           std::unique_ptr,
                                                           TBase> {
 public:
  ~releasing_multifactory(void) override = default;
};

/**
 * \ingroup patterns factory
 *
 * \brief Specialization of the \ref multifactory class for sharing ownership of
 * created objects via std::shared_ptr.
 *
 * \tparam TBase The base class that all factory-constructed types must derive
 *               from.
 * \tparam Args Arguments common to ALL factory-constructible types.
 */
template<typename TBase, typename...Args>
class sharing_multifactory : public detail::multifactory<detail::factory_sharing_type,
                                                         std::shared_ptr,
                                                         TBase> {
 public:
  ~sharing_multifactory(void) override = default;
};

} /* namespace rcppsw::patterns::factory */

