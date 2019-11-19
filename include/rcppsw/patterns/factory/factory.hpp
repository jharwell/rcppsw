/**
 * \file factory.hpp
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

#ifndef INCLUDE_RCPPSW_PATTERNS_FACTORY_FACTORY_HPP_
#define INCLUDE_RCPPSW_PATTERNS_FACTORY_FACTORY_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/patterns/factory/base_factory.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, patterns, factory);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class releasing_factory
 * \ingroup patterns factory
 *
 * \brief Specialization of the \ref detail::base_factory class for releasing
 * ownership of created objects via std::unique_ptr.
 */
template<typename TBase, typename...Args>
class releasing_factory : public detail::base_factory<detail::factory_releasing_type,
                                                      std::unique_ptr,
                                                      TBase,
                                                      Args...> {
 public:
  ~releasing_factory(void) override = default;
};


/**
 * \class sharing_factory
 * \ingroup patterns factory
 *
 * \brief Specialization of the @line detail::base_factory @endlink class for
 * sharing ownership of created objects via std::shared_ptr.
 */
template<typename TBase, typename...Args>
class sharing_factory : public detail::base_factory<detail::factory_sharing_type,
                                                    std::shared_ptr,
                                                    TBase,
                                                    Args...> {
 public:
  ~sharing_factory(void) override = default;
};

NS_END(factory, patterns, rcppsw);

#endif /* INCLUDE_RCPPSW_PATTERNS_FACTORY_FACTORY_HPP_ */
