/**
 * \file sphere_vector.hpp
 *
 * \copyright 2020 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/math/radians.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace rcppsw::math {

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
                const rmath::radians& zenith,
                const rmath::radians& azimuth)
      : m_radius(radius), m_zenith(zenith), m_azimuth(azimuth) {}

  const rmath::radians& azimuth(void) const { return m_azimuth; }
  const rmath::radians& zenith(void) const { return m_zenith; }
  const T& radius(void) const { return m_radius; }

 private:
  /* clang-format off */
  T              m_radius;
  rmath::radians m_zenith;
  rmath::radians m_azimuth;
  /* clang-format on */
};

} /* namespace rcppsw::math */

