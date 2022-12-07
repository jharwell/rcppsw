/**
 * \file orientation.hpp
 *
 * \copyright 2021 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>

#include "rcppsw/math/radians.hpp"
#include "rcppsw/er/stringizable.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace rcppsw::math {

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
class euler_angles : public rer::stringizable {
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

  euler_angles operator+(const euler_angles& rhs) const {
    return euler_angles(x() + rhs.x(),
                        y() + rhs.y(),
                        z() + rhs.z());
  }
  euler_angles operator/(double rhs) const {
    return euler_angles(x() / rhs, y() / rhs, z() / rhs);
  }

  euler_angles& operator+=(const euler_angles &rhs) {
    this->m_x += rhs.m_x;
    this->m_y += rhs.m_y;
    this->m_z += rhs.m_z;

    return *this;
  }

  std::string to_str(void) const override {
    return "(" +
        rcppsw::to_string(m_x.v()) +
        "," +
        rcppsw::to_string(m_y.v()) +
        "," +
        rcppsw::to_string(m_z.v()) +
        ")";
  }

 private:
  /* clang-format off */
  rmath::radians m_x{};
  rmath::radians m_y{};
  rmath::radians m_z{};
  /* clang-format on */
};

} /* namespace rcppsw::math */
