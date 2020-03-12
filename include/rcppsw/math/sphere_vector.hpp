/**
 * \file sphere_vector.hpp
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

#ifndef INCLUDE_RCPPSW_MATH_SPHERE_VECTOR_HPP_
#define INCLUDE_RCPPSW_MATH_SPHERE_VECTOR_HPP_

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
 * \class sphere_vector
 * \ingroup math
 *
 * \brief Representation of a point in 3D space in spherical coordinates.
 */
template <class T>
class sphere_vector {
 public:
  sphere_vector(const T& radius,
                const radians& inclination,
                const radians& azimuth)
      : m_radius(radius), m_inclination(inclination), m_azimuth(azimuth) {}

  const radians& azimuth(void) const { return m_azimuth; }
  const radians& inclination(void) const { return m_inclination; }
  const T& radius(void) const { return m_radius; }

 private:
  /* clang-format off */
  T       m_radius;
  radians m_inclination;
  radians m_azimuth;
  /* clang-format on */
};

NS_END(math, rcppsw);

#endif /* INCLUDE_RCPPSW_MATH_SPHERE_VECTOR_HPP_ */
