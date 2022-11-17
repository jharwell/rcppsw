/**
 * \file hertz.hpp
 *
 * \copyright 2022 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/rcppsw.hpp"
#include "rcppsw/types/named_type.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, types);

/*******************************************************************************
 * Type Definitions
 ******************************************************************************/
/**
 * \class hertz
 * \ingroup types
 *
 * \brief A class fo representing rates.
 */
class hertz final : public rtypes::named_type<int, struct hertz_tag> {
 public:
  using named_type<int, hertz_tag>::named_type;

  hertz(const hertz&) = default;
  hertz& operator=(const hertz& other) {
    set(other.v());
    return *this;
  }
  template<class T>
  bool operator<(const T& other) const { return v() < other; }
  template<class T>
  bool operator>(const T& other) const { return v() > other; }
};

NS_START(constants);

/**
 * \brief Null identifier to indicate an unset value.
 */
extern hertz kNoRate;

NS_END(constants, types, rcppsw);
