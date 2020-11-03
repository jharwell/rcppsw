/**
 * \file multifactory.hpp
 *
 * \copyright 2017 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_PATTERNS_FACTORY_MULTIFACTORY_HPP_
#define INCLUDE_RCPPSW_PATTERNS_FACTORY_MULTIFACTORY_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <memory>

#include "rcppsw/patterns/factory/base_factory.hpp"
#include "rcppsw/patterns/singleton/singleton.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, patterns, factory, detail);

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

NS_END(detail);


/**
 * \class releasing_multifactory
 * \ingroup patterns factory
 *
 * \brief Specialization of the \ref multifactory class for releasing ownership
 * of created objects via std::unique_ptr.
 */
template<typename TBase, typename...Args>
class releasing_multifactory : public detail::multifactory<detail::factory_releasing_type,
                                                           std::unique_ptr,
                                                           TBase> {
 public:
  ~releasing_multifactory(void) override = default;
};

/**
 * \class sharing_multifactory
 * \ingroup patterns factory
 *
 * \brief Specialization of the \ref multifactory class for sharing ownership of
 * created objects via std::shared_ptr.
 */
template<typename TBase, typename...Args>
class sharing_multifactory : public detail::multifactory<detail::factory_sharing_type,
                                                         std::shared_ptr,
                                                         TBase> {
 public:
  ~sharing_multifactory(void) override = default;
};

NS_END(factory, patterns, rcppsw);

#endif /* INCLUDE_RCPPSW_PATTERNS_FACTORY_MULTIFACTORY_HPP_ */
