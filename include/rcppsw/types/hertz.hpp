/**
 * \file hertz.hpp
 *
 * \copyright 2022 John Harwell, All rights reserved.
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
class hertz final : public rtypes::named_type<size_t, struct hertz_tag> {
 public:
  using named_type<size_t, hertz_tag>::named_type;

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
