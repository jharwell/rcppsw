/**
 * \file hertz.hpp
 *
 * \copyright 2022 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
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
namespace rcppsw::types {

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

namespace constants {

/**
 * \brief Null identifier to indicate an unset value.
 */
extern hertz kNoRate;
} /* namespace constants */

} /* namespace rcppsw::types::constants */
