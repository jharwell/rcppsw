/**
 * \file concepts.hpp
 *
 * \copyright 2023 John Harwell, All rights reserved.
 *
 * SPDX-License Identifier: MIT
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
 * Concepts
 ******************************************************************************/
template<typename T>
concept is_mappish = requires(T& v) {
  typename std::void_t<typename T::key_type,
              typename T::mapped_type,
              decltype(std::declval<T&>()[std::declval<
                                          const typename T::key_type&>()])>;

};

} /* namespace rcppsw */
