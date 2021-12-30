/**
 * \file orientation.hpp
 *
 * \copyright 2021 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_MATH_ORIENTATION_HPP_
#define INCLUDE_RCPPSW_MATH_ORIENTATION_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/math/radians.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, math);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class euler_angles
 * \ingroup math
 *
 * \brief A class representing the orientation of a point or body in space using
 * Euler angles.
 */
class euler_angles {
 public:
  /**
   * \brief Initializes to (0,0,0).
   */
  euler_angles(void) = default;

  euler_angles(const rmath::radians& x,
               const rmath::radians& y,
               const rmath::radians& z) : m_x(x), m_y(y), m_z(z) {}

  const rmath::radians& x(void) const { return m_x; }
  const rmath::radians& y(void) const { return m_y; }
  const rmath::radians& z(void) const { return m_z; }

 private:
  /* clang-format off */
  rmath::radians m_x{};
  rmath::radians m_y{};
  rmath::radians m_z{};
  /* clang-format on */
};

NS_END(math, rcppsw);

#endif /* INCLUDE_RCPPSW_MATH_ORIENTATION_HPP_ */
