/**
 * @file math-radians-test.cpp
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
#include "rcppsw/math/radians.hpp"
#include "rcppsw/math/angles.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace math = rcppsw::math;

/*******************************************************************************
 * Test Cases
 ******************************************************************************/
CATCH_TEST_CASE("Conversion test", "[rmath::radians]") {
  math::radians t0(M_PI/2);
  math::radians t1(M_PI);
  math::radians t2(to_radians(math::degrees(90)));
  math::radians t3(math::degrees(180));

  CATCH_REQUIRE(M_PI/2 == t0.v());
  CATCH_REQUIRE(90 == to_degrees(t0).v());

  CATCH_REQUIRE(90 == to_degrees(t2).v());
  CATCH_REQUIRE(180 == to_degrees(t3).v());
}

CATCH_TEST_CASE("stdout Test", "[rmath::radians]") {
  rmath::radians t0(0);
  std::stringstream out;
  out << t0;

  CATCH_REQUIRE("rad(0.000000) -> deg(0.000000)" == out.str());
}

CATCH_TEST_CASE("Math Test", "[rmath::radians]") {
  math::radians t0(M_PI/2);
  math::radians t1(M_PI);
  math::radians t2(M_PI/2);
  math::radians t3(M_PI);

  CATCH_REQUIRE(t1 - t0 == t0);
  CATCH_REQUIRE(t3 - t2 == t2);
  CATCH_REQUIRE(t1 + t0 == math::radians(3 * M_PI/2));
  CATCH_REQUIRE(t3 + t2 == math::radians(3 * M_PI/2));

  CATCH_REQUIRE((t0 += t0) == t3);
  CATCH_REQUIRE((t1 -= t2) == t2);
}

CATCH_TEST_CASE("Normalized Diff", "[rmath::radians]") {
  rmath::radians r0(0);
  rmath::radians r90(M_PI/2);
  rmath::radians r180(M_PI);
  rmath::radians r270(3 * M_PI / 2);
  rmath::radians r360(2 * M_PI);

  CATCH_REQUIRE(RCPPSW_IS_BETWEEN(rmath::normalized_diff(r90, r180), -r180, r180));
  CATCH_REQUIRE(RCPPSW_IS_BETWEEN(rmath::normalized_diff(r90, r270), -r180, r180));
  CATCH_REQUIRE(RCPPSW_IS_BETWEEN(rmath::normalized_diff(r270, r360), -r180, r180));

  CATCH_REQUIRE(-r90 == rmath::normalized_diff(r90, r180));
  CATCH_REQUIRE(-r180 == rmath::normalized_diff(r90, r270));
  CATCH_REQUIRE(r0 == rmath::normalized_diff(r0, r360));
  CATCH_REQUIRE(r0 == rmath::normalized_diff(r360, r0));

}
