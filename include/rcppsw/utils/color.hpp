/**
 * @file color.hpp
 *
 * @copyright 2018 John Harwell, All rights reserved.
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
#include "rcppsw/common/common.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, utils);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class color
 * @ingroup utils
 *
 * @brief A simple RGBA class representing colors as 4 8-bit numbers.
 *
 * Should be used to make color usage agnostic across projects, and not tied to
 * a particular platform, simulator, etc.
 */
class color {
 public:
  color(void) = default;

  static color kBLACK;
  static color kWHITE;
  static color kRED;
  static color kGREEN;
  static color kBLUE;
  static color kMAGENTA;
  static color kCYAN;
  static color kYELLOW;
  static color kORANGE;
  static color kBROWN;
  static color kPURPLE;
  static color kGRAY10;
  static color kGRAY20;
  static color kGRAY30;
  static color kGRAY40;
  static color kGRAY50;
  static color kGRAY60;
  static color kGRAY70;
  static color kGRAY80;
  static color kGRAY90;

  color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 255) :
      m_channels{red, green, blue, alpha} {}

  uint8_t red() const { return m_channels[0]; }
  void red(uint8_t red) { m_channels[0] = red; }

  uint8_t green() const { return m_channels[1]; }
  void green(uint8_t green) { m_channels[2] = green; }

  uint8_t blue() const { return m_channels[2]; }
  void blue(uint8_t blue) { m_channels[2] = blue; }

  uint8_t alpha() const { return m_channels[3]; }
  void alpha(uint8_t alpha) { m_channels[3] = alpha; }

  bool operator==(const color& c_color2) const {
    return m_channels[0] == c_color2.m_channels[0] &&
        m_channels[1] == c_color2.m_channels[1] &&
        m_channels[2] == c_color2.m_channels[2] &&
        m_channels[3] == c_color2.m_channels[3];
  }

  bool operator!=(const color& c_color2) const {
    return m_channels != c_color2.m_channels;
  }

 private:
  uint8_t m_channels[4];
};

NS_END(utils, rcppsw);

#endif /* INCLUDE_RCPPSW_UTILS_COLOR_HPP_ */
