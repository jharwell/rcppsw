/**
 * \file color.hpp
 *
 * \copyright 2018 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_UTILS_COLOR_HPP_
#define INCLUDE_RCPPSW_UTILS_COLOR_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include <array>

#include "rcppsw/rcppsw.hpp"
#include "rcppsw/er/stringizable.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, utils);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class color
 * \ingroup utils
 *
 * \brief A simple RGBA class representing colors as 4 8-bit numbers.
 *
 * Should be used to make color usage agnostic across projects, and not tied to
 * a particular platform, simulator, etc.
 */
class color : public er::stringizable {
 public:
  static const color kBLACK;
  static const color kWHITE;
  static const color kRED;
  static const color kGREEN;
  static const color kBLUE;
  static const color kMAGENTA;
  static const color kCYAN;
  static const color kYELLOW;
  static const color kORANGE;
  static const color kBROWN;
  static const color kPURPLE;
  static const color kGRAY10;
  static const color kGRAY20;
  static const color kGRAY30;
  static const color kGRAY40;
  static const color kGRAY50;
  static const color kGRAY60;
  static const color kGRAY70;
  static const color kGRAY80;
  static const color kGRAY90;

  color(void) = default;
  color(const color&) = default;
  color& operator=(const color&) = default;

  color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 255)
      : m_channels{ red, green, blue, alpha } {}

  /* stringizable overrides */
  std::string to_str(void) const override;

  uint8_t red() const { return m_channels[0]; }
  void red(uint8_t red) { m_channels[0] = red; }

  uint8_t green() const { return m_channels[1]; }
  void green(uint8_t green) { m_channels[2] = green; }

  uint8_t blue() const { return m_channels[2]; }
  void blue(uint8_t blue) { m_channels[2] = blue; }

  uint8_t alpha() const { return m_channels[3]; }
  void alpha(uint8_t alpha) { m_channels[3] = alpha; }

  bool operator==(const color& c_color2) const {
    return m_channels == c_color2.m_channels;
  }

  bool operator!=(const color& c_color2) const {
    return !(*this == c_color2);
  }

 private:
  /* clang-format off */
  std::array<uint8_t, 4> m_channels{};
  /* clang-format on */
};

NS_END(utils, rcppsw);

#endif /* INCLUDE_RCPPSW_UTILS_COLOR_HPP_ */
