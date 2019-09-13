/**
 * @file impl_ptr.hpp
 *
 * @copyright 2019 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_PATTERNS_PIMPL_IMPL_PTR_HPP_
#define INCLUDE_RCPPSW_PATTERNS_PIMPL_IMPL_PTR_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <ext/pimpl/include/impl_ptr.hpp>
#include "rcppsw/common/common.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, patterns, pimpl);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
using in_place_type = ::detail::in_place_type;

/*
 * Because this is not in boost yet (and might not ever be), it does some weird
 * non-std:: global namespace things that I have to correct.
 */
static constexpr in_place_type in_place {};

template<typename U,
         template<typename,
                  typename...> class P =::detail::no_policy,
         typename... M>
using impl_ptr = ::impl_ptr<U, P, M...>;

NS_END(pimpl, patterns, rcppsw);

#endif /* INCLUDE_RCPPSW_PATTERNS_PIMPL_IMPL_PTR_HPP_ */
