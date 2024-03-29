/**
 * \file identity.hpp
 *
 * \copyright 2020 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace rcppsw::mpl {

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

} /* namespace rcppsw::mpl */

