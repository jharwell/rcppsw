/**
 * \file timestep.hpp
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

#ifndef INCLUDE_RCPPSW_TYPES_TIMESTEP_HPP_
#define INCLUDE_RCPPSW_TYPES_TIMESTEP_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/types/named_type.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, types);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \brief Type to be used for representing timesteps in a simulation
 * environment.
 */
class timestep : public named_type<uint, struct timestep_tag> {
 public:
  using named_type<uint, timestep_tag>::named_type;

  timestep(const timestep&) = default;
  timestep& operator=(const timestep& other) {
    set(other.v());
    return *this;
  }
  timestep operator+(const timestep& other) const {
    timestep res(*this);
    return res += other;
  }

  timestep operator+(uint n) const {
    timestep res(v() + n);
    return res;
  }

  timestep& operator+=(const timestep& other) {
    set(v() + other.v());
    return *this;
  }
  timestep& operator+=(uint n) {
    set(v() + n);
    return *this;
  }

  timestep operator-(const timestep& other) const {
    timestep res(v() - other.v());
    return res;
  }
  timestep operator-(uint n) const {
    timestep res(v() - n);
    return res;
  }
  timestep operator%(uint n) const {
    timestep res(v() % n);
    return res;
  }
  bool operator==(uint n) const { return v() == n; }
  bool operator==(const timestep& other) const { return v() == other.v(); }
  bool operator<(const timestep& other) const { return v() < other.v(); }
  bool operator>(const timestep& other) const { return v() > other.v(); }
  bool operator>=(const timestep& other) const { return v() >= other.v(); }

  template <class T>
  bool operator>=(const T& other) const {
    return v() >= other;
  }

  template <class T>
  bool operator>(const T& other) const {
    return v() > other;
  }

  template <class T>
  bool operator<(const T& other) const {
    return v() < other;
  }
};

NS_END(types, rcppsw);

#endif /* INCLUDE_RCPPSW_TYPES_TIMESTEP_HPP_ */
