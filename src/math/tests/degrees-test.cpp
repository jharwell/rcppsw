/**
 * @file degrees-test.cpp
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
#include "rcppsw/math/degrees.hpp"
#include "rcppsw/math/radians.hpp"
#include "rcppsw/math/angles.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace math = rcppsw::math;

/*******************************************************************************
 * Test Cases
 ******************************************************************************/
CATCH_TEST_CASE("Conversion test", "[degrees]") {
  math::degrees t0(90);
  math::degrees t1(180);
  math::degrees t2(to_degrees(math::radians(M_PI/2)));
  math::degrees t3(to_degrees(math::radians(M_PI)));

  CATCH_REQUIRE(90 == t0());
  CATCH_REQUIRE(M_PI/2 == to_radians(t0).value());

  CATCH_REQUIRE(M_PI/2 == to_radians(t2)());
  CATCH_REQUIRE(M_PI == to_radians(t3)());
}

CATCH_TEST_CASE("Math Test", "[degrees]") {
  math::degrees t0(90);
  math::degrees t1(180);
  math::degrees t2(90);
  math::degrees t3(180);

  CATCH_REQUIRE(t1 - t0 == t0);
  CATCH_REQUIRE(t3 - t2 == t2);
  CATCH_REQUIRE(t1 + t0 == math::degrees(270));
  CATCH_REQUIRE(t3 + t2 == math::degrees(270));

  CATCH_REQUIRE((t0 += t0) == t3);
  CATCH_REQUIRE((t1 -= t2) == t2);
}
