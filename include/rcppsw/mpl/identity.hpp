/**
 * \file identity.hpp
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
#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, mpl);

/*******************************************************************************
 * Struct Definitions
 ******************************************************************************/
/**
 * \class identity
 * \ingroup mpl
 *
 * \brief Some types are not not default constructible, and therefore cannot be
 * used with boost::mpl::for_each as is. If we only need the type of the class
 * during an operation, and do not need access to any of its methods, we can add
 * a layer of indirection with a simple struct that IS default constructible
 * that we CAN use.
 */
template <typename T>
struct identity {
  using type = T;
};

NS_END(mpl, rcppsw);

