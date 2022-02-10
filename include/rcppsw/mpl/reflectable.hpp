/**
 * \file reflectable.hpp
 *
 * \copyright 2020 John Harwell, All rights reserved.
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
#include <typeindex>

#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, mpl);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class reflectable
 * \ingroup mpl
 *
 * \brief Interface for classes wishing to employ pseudo-reflection in C++.
 */
class reflectable {
 public:
  virtual ~reflectable(void) = default;

  /**
   * \brief Return the \ref std::type_index of the derived class. This is useful
   * in conjunction with \ref boost::variant and \ref boost::apply_visitor, as
   * it allows for run-time reflection based on the actual type of the derived
   * class.
   */
  virtual std::type_index type_index(void) const = 0;
};

NS_END(mpl, rcppsw);

