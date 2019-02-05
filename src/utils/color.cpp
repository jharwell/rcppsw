/**
 * @file color.cpp
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
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
color color::kBLACK(0, 0, 0);
color color::kWHITE(255, 255, 255);
color color::kRED(255, 0, 0);
color color::kGREEN(0, 255, 0);
color color::kBLUE(0, 0, 255);
color color::kMAGENTA(255, 0, 255);
color color::kCYAN(0, 255, 255);
color color::kYELLOW(255, 255, 0);
color color::kORANGE(255, 140, 0);
color color::kBROWN(165, 42, 42);
color color::kPURPLE(160, 32, 240);
color color::kGRAY10(26, 26, 26);
color color::kGRAY20(51, 51, 51);
color color::kGRAY30(77, 77, 77);
color color::kGRAY40(102, 102, 102);
color color::kGRAY50(127, 127, 127);
color color::kGRAY60(153, 153, 153);
color color::kGRAY70(179, 179, 179);
color color::kGRAY80(204, 204, 204);
color color::kGRAY90(229, 229, 229);
#pragma clang diagnostic pop

NS_END(utils, rcppsw);
