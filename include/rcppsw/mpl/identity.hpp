/**
 * \file identity.hpp
 *
 * \copyright 2020 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
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

