/**
 * @file vector2-test.cpp
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
#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_PREFIX_ALL
#include "catch.hpp"
#include "rcppsw/math/vector2.hpp"
#include "rcppsw/math/angles.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace math = rcppsw::math;

/*******************************************************************************
 * Test Cases
 ******************************************************************************/
CATCH_TEST_CASE("Init test", "[vector2]") {
  math::vector2i t0;
  CATCH_REQUIRE(0 == t0.x());
  CATCH_REQUIRE(0 == t0.y());

  math::vector2i t1(1, 2);
  CATCH_REQUIRE(1 == t1.x());
  CATCH_REQUIRE(2 == t1.y());

  math::vector2i t2(1, math::radians(M_PI));
  CATCH_REQUIRE(-1 == t2.x());
  CATCH_REQUIRE(0 == t2.y());
}

CATCH_TEST_CASE("Length test", "[vector2]") {
  math::vector2d t0(2, 2);
  math::vector2d t1(4, 4);
  CATCH_REQUIRE(std::sqrt(8) == t0.length());
  CATCH_REQUIRE(8 == t0.square_length());
  CATCH_REQUIRE(std::sqrt(32) == t1.length());
  CATCH_REQUIRE(32 == t1.square_length());
  CATCH_REQUIRE(8 == math::vector2d::square_distance(t0, t1));
  CATCH_REQUIRE(std::sqrt(8) == math::vector2d::distance(t0, t1));
  CATCH_REQUIRE((t0 - t1).length() == std::sqrt(8));
}

CATCH_TEST_CASE("Normalize test", "[vector2]") {
  math::vector2d t0(3, 4);
  t0.normalize();
  CATCH_REQUIRE(3/5.0 == t0.x());
  CATCH_REQUIRE(4/5.0 == t0.y());
}
CATCH_TEST_CASE("Scale test", "[vector2]") {
  math::vector2d t0(3, 4);
  t0.scale(0.5);
  CATCH_REQUIRE(1.5 == t0.x());
  CATCH_REQUIRE(2.0 == t0.y());
}
CATCH_TEST_CASE("Angle test", "[vector2]") {
  math::vector2d t0(1, 1);
  CATCH_REQUIRE(45 == to_degrees(t0.angle()).value());
  math::vector2d t1(-1, -1);
  CATCH_REQUIRE(225 == to_degrees(t1.angle()).unsigned_normalize().value());
  math::vector2d t2(-1, 0);
  CATCH_REQUIRE(180 == to_degrees(t2.angle()).unsigned_normalize().value());
}

CATCH_TEST_CASE("Operator test", "[vector2]") {
  math::vector2d t0(0.0, 0.0);
  math::vector2d t1(0, 1.5);
  math::vector2d t2(1, 1);

  CATCH_REQUIRE(t0 != t1);
  CATCH_REQUIRE(t0 == t0);
  CATCH_REQUIRE(t1 == t1);
  CATCH_REQUIRE(t2 == t2);

  CATCH_REQUIRE(t2 - t1 == math::vector2d(1, -0.5));
  CATCH_REQUIRE(t2 + t1 == math::vector2d(1, 2.5));
  CATCH_REQUIRE(t0 * 3 == t0);
  CATCH_REQUIRE(t2 / 2 == math::vector2d(0.5, 0.5));
  CATCH_REQUIRE(t0 < t1);
  CATCH_REQUIRE(!(t1 < t0));
  CATCH_REQUIRE(t1 < t2);
}
