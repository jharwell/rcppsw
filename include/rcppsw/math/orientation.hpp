/**
 * \file orientation.hpp
 *
 * \copyright 2021 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#pragma once

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

