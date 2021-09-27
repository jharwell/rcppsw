/**
 * @file math-vector2-test.cpp
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

/*******************************************************************************
 * Test Cases
 ******************************************************************************/
CATCH_TEST_CASE("Init test", "[rmath::vector2]") {
  rmath::vector2i t0;
  CATCH_REQUIRE(0 == t0.x());
  CATCH_REQUIRE(0 == t0.y());

  rmath::vector2i t1(1, 2);
  CATCH_REQUIRE(1 == t1.x());
  CATCH_REQUIRE(2 == t1.y());

  rmath::vector2d t2(1.0, rmath::radians(M_PI));
  CATCH_REQUIRE(-1.0 == t2.x());
  CATCH_REQUIRE(t2.y() <= RCSW_DOUBLE_EPSILON);
}

CATCH_TEST_CASE("Length test", "[rmath::vector2]") {
  rmath::vector2d t0(2, 2);
  rmath::vector2d t1(4, 4);
  CATCH_REQUIRE(std::fabs(std::sqrt(8) - t0.length()) <= RCSW_DOUBLE_EPSILON);
  CATCH_REQUIRE(std::fabs(8 - t0.square_length()) <= RCSW_DOUBLE_EPSILON);
  CATCH_REQUIRE(std::fabs(std::sqrt(32) - t1.length()) <= RCSW_DOUBLE_EPSILON);
  CATCH_REQUIRE(std::fabs(32 - t1.square_length()) <= RCSW_DOUBLE_EPSILON);
  CATCH_REQUIRE(std::fabs(std::sqrt(8) - rmath::l2norm(t0, t1)) <= RCSW_DOUBLE_EPSILON);;
  CATCH_REQUIRE(std::fabs((t0 - t1).length() - std::sqrt(8) <= RCSW_DOUBLE_EPSILON));
}

CATCH_TEST_CASE("Normalize test", "[rmath::vector2]") {
  rmath::vector2d t0(3, 4);
  t0.normalize();
  CATCH_REQUIRE(3/5.0 == t0.x());
  CATCH_REQUIRE(4/5.0 == t0.y());
}
CATCH_TEST_CASE("Scale test", "[rmath::vector2]") {
  rmath::vector2d t0(3, 4);
  t0.scale(0.5);
  CATCH_REQUIRE(1.5 == t0.x());
  CATCH_REQUIRE(2.0 == t0.y());
}
CATCH_TEST_CASE("Angle test", "[rmath::vector2]") {
  rmath::vector2d t0(1, 1);
  CATCH_REQUIRE(45 == to_degrees(t0.angle()).v());
  rmath::vector2d t1(-1, -1);
  CATCH_REQUIRE(225 == to_degrees(t1.angle()).unsigned_normalize().v());
  rmath::vector2d t2(-1, 0);
  CATCH_REQUIRE(180 == to_degrees(t2.angle()).unsigned_normalize().v());
}

CATCH_TEST_CASE("Operator test", "[rmath::vector2]") {
  rmath::vector2i t0(0, 0);
  rmath::vector2i t1(0, 2);
  rmath::vector2i t2(1, 1);

  CATCH_REQUIRE(t0 != t1);
  CATCH_REQUIRE(t0 == t0);
  CATCH_REQUIRE(t1 == t1);
  CATCH_REQUIRE(t2 == t2);

  CATCH_REQUIRE(t2 - t1 == rmath::vector2i(1, -1));
  CATCH_REQUIRE(t2 + t1 == rmath::vector2i(1, 3));
  CATCH_REQUIRE(t0 * 3 == t0);
  CATCH_REQUIRE(t2 / 2 == rmath::vector2i(0, 0));
  CATCH_REQUIRE(rmath::vector2i::key_compare()(t0, t1));
  CATCH_REQUIRE(!rmath::vector2i::key_compare()(t1, t0));
  CATCH_REQUIRE(rmath::vector2i::key_compare()(t1, t2));
}
