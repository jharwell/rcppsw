/**
 * \file color.cpp
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

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/utils/color.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, utils);

/*******************************************************************************
 * Global Variables
 ******************************************************************************/
RCPPSW_WARNING_DISABLE_PUSH()
RCPPSW_WARNING_DISABLE_GLOBAL_CTOR()

const color color::kBLACK(0, 0, 0);
const color color::kWHITE(255, 255, 255);
const color color::kRED(255, 0, 0);
const color color::kGREEN(0, 255, 0);
const color color::kBLUE(0, 0, 255);
const color color::kMAGENTA(255, 0, 255);
const color color::kCYAN(0, 255, 255);
const color color::kYELLOW(255, 255, 0);
const color color::kORANGE(255, 140, 0);
const color color::kBROWN(165, 42, 42);
const color color::kPURPLE(160, 32, 240);
const color color::kGRAY10(26, 26, 26);
const color color::kGRAY20(51, 51, 51);
const color color::kGRAY30(77, 77, 77);
const color color::kGRAY40(102, 102, 102);
const color color::kGRAY50(127, 127, 127);
const color color::kGRAY60(153, 153, 153);
const color color::kGRAY70(179, 179, 179);
const color color::kGRAY80(204, 204, 204);
const color color::kGRAY90(229, 229, 229);

RCPPSW_WARNING_DISABLE_POP()

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
std::string color::to_str(void) const {
  if (*this == color::kBLACK) {
    return "BLACK";
  } else if (*this == color::kWHITE) {
    return "WHITE";
  } else {
    return "(" +
        rcppsw::to_string(static_cast<int>(m_channels[0])) + "," +
        rcppsw::to_string(static_cast<int>(m_channels[1])) + "," +
        rcppsw::to_string(static_cast<int>(m_channels[2])) + "," +
        rcppsw::to_string(static_cast<int>(m_channels[3])) +
        ")";
  }
} /* to_str() */

NS_END(utils, rcppsw);
