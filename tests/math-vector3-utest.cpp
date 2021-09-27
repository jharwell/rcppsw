/**
 * @file math-vector3-test.cpp
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
#include "rcppsw/math/vector3.hpp"
#include "rcppsw/math/angles.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/

/*******************************************************************************
 * Test Cases
 ******************************************************************************/
CATCH_TEST_CASE("Init test", "[rmath::vector3]") {
  /* default constructor */
  rmath::vector3i t0;
  CATCH_REQUIRE(0 == t0.x());
  CATCH_REQUIRE(0 == t0.y());
  CATCH_REQUIRE(0 == t0.z());

  /* cartesian coord constructor */
  rmath::vector3i t1(1, 2, 3);
  CATCH_REQUIRE(1 == t1.x());
  CATCH_REQUIRE(2 == t1.y());
  CATCH_REQUIRE(3 == t1.z());
}

CATCH_TEST_CASE("Length test", "[rmath::vector3]") {
  rmath::vector3d t0(2, 2, 2);
  rmath::vector3d t1(4, 4, 4);

  CATCH_REQUIRE(std::sqrt(12) == t0.length());
  CATCH_REQUIRE(12 == t0.square_length());

  CATCH_REQUIRE(std::sqrt(48) == t1.length());
  CATCH_REQUIRE(48 == t1.square_length());

  CATCH_REQUIRE(std::sqrt(12) == rmath::l2norm(t0, t1));
  CATCH_REQUIRE((t0 - t1).length() == std::sqrt(12));
}

CATCH_TEST_CASE("Normalize test", "[rmath::vector3]") {
  rmath::vector3d t0(3, 4, 5);
  t0.normalize();
  CATCH_REQUIRE(3/std::sqrt(50) == t0.x());
  CATCH_REQUIRE(4/std::sqrt(50) == t0.y());
  CATCH_REQUIRE(5/std::sqrt(50) == t0.z());
}
CATCH_TEST_CASE("Scale test", "[rmath::vector3]") {
  rmath::vector3d t0(3, 4, 5);
  t0.scale(0.5);
  CATCH_REQUIRE(1.5 == t0.x());
  CATCH_REQUIRE(2.0 == t0.y());
  CATCH_REQUIRE(2.5 == t0.z());
}
CATCH_TEST_CASE("Angle test", "[rmath::vector3]") {
  rmath::vector3d t0(1, 1, 1);
  CATCH_REQUIRE(45 == to_degrees(t0.xangle()).v());
  CATCH_REQUIRE(45 == to_degrees(t0.yangle()).v());
  CATCH_REQUIRE(45 == to_degrees(t0.zangle()).v());

  rmath::vector3d t1(-1, -1, -1);
  CATCH_REQUIRE(225 == to_degrees(t1.xangle()).unsigned_normalize().v());
  CATCH_REQUIRE(225 == to_degrees(t1.yangle()).unsigned_normalize().v());
  CATCH_REQUIRE(225 == to_degrees(t1.zangle()).unsigned_normalize().v());
}

CATCH_TEST_CASE("Operator test", "[rmath::vector3]") {
  rmath::vector3d t0(0.0, 0.0, 0.0);
  rmath::vector3d t1(0, 1.5, 1);
  rmath::vector3d t2(1, 1, 1);

  CATCH_REQUIRE(t0 != t1);
  CATCH_REQUIRE(t0 == t0);
  CATCH_REQUIRE(t1 == t1);
  CATCH_REQUIRE(t2 == t2);

  CATCH_REQUIRE(t2 - t1 == rmath::vector3d(1, -0.5, 0));
  CATCH_REQUIRE(t2 + t1 == rmath::vector3d(1, 2.5, 2));
  CATCH_REQUIRE(t0 * 3 == t0);
  CATCH_REQUIRE(t2 / 2 == rmath::vector3d(0.5, 0.5, 0.5));
  CATCH_REQUIRE(rmath::vector3d::key_compare()(t0, t1));
  CATCH_REQUIRE(!rmath::vector3d::key_compare()(t1, t0));
  CATCH_REQUIRE(rmath::vector3d::key_compare()(t1, t2));
}
