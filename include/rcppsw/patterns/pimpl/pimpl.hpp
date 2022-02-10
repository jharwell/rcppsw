/**
 * \file pimpl.hpp
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

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <memory>
#include <utility>

#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, patterns, pimpl);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class pimpl
 * \ingroup pimpl
 *
 * \brief Super-simple templated implementation of the PIMPL idiom. Does not
 * exist in boost, and the boost candidate I found had subtle memory issues when
 * optimizations were on.
 *
 * \tparam TImpl The type of the implementation you wish to hide.
 */
template<typename TImpl>
struct pimpl {
  template<typename ...Args>
  explicit pimpl(Args&&... args) :
      impl(std::make_unique<TImpl>(std::forward<Args>(args)...)) {}
  virtual ~pimpl(void) = default;

  std::unique_ptr<TImpl> impl;
};

NS_END(pimpl, patterns, rcppsw);

