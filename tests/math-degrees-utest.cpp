/**
 * @file math-degrees-test.cpp
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

/*******************************************************************************
 * Test Cases
 ******************************************************************************/
CATCH_TEST_CASE("Conversion test", "[rmath::degrees]") {
  rmath::degrees t0(90);
  rmath::degrees t1(180);
  rmath::degrees t2(to_degrees(rmath::radians(M_PI/2)));
  rmath::degrees t3(rmath::radians(M_PI));

  CATCH_REQUIRE(90 == t0.v());
  CATCH_REQUIRE(M_PI/2 == to_radians(t0).v());

  CATCH_REQUIRE(M_PI/2 == to_radians(t2).v());
  CATCH_REQUIRE(M_PI == to_radians(t3).v());
}

CATCH_TEST_CASE("stdout Test", "[rmath::degrees]") {
  rmath::degrees t0(0);
  std::stringstream out;
  out << t0;

  CATCH_REQUIRE("deg(0.000000) -> rad(0.000000)" == out.str());
}
CATCH_TEST_CASE("Math Test", "[rmath::degrees]") {
  rmath::degrees t0(90);
  rmath::degrees t1(180);
  rmath::degrees t2(90);
  rmath::degrees t3(180);
  rmath::degrees t4(-60);
  rmath::degrees t5(800);

  CATCH_REQUIRE(t1 - t0 == t0);
  CATCH_REQUIRE(t3 - t2 == t2);
  CATCH_REQUIRE(t1 + t0 == rmath::degrees(270));
  CATCH_REQUIRE(t3 + t2 == rmath::degrees(270));

  CATCH_REQUIRE((t0 += t0) == t3);
  CATCH_REQUIRE((t1 -= t2) == t2);
  CATCH_REQUIRE(300 == t4.unsigned_normalize().v());
  CATCH_REQUIRE(-60 == t4.signed_normalize().v());
  CATCH_REQUIRE(80 == t5.unsigned_normalize().v());
  CATCH_REQUIRE(80 == t5.signed_normalize().v());
}

CATCH_TEST_CASE("Normalized Diff", "[rmath::degrees]") {
  rmath::degrees d0(0);
  rmath::degrees d90(90);
  rmath::degrees d180(180);
  rmath::degrees d270(270);
  rmath::degrees d360(360);

  CATCH_REQUIRE(RCPPSW_IS_BETWEEN(rmath::normalized_diff(d90, d180), -d180, d180));
  CATCH_REQUIRE(RCPPSW_IS_BETWEEN(rmath::normalized_diff(d90, d270), -d180, d180));
  CATCH_REQUIRE(RCPPSW_IS_BETWEEN(rmath::normalized_diff(d270, d360), -d180, d180));

  CATCH_REQUIRE(-d90 == rmath::normalized_diff(d90, d180));
  CATCH_REQUIRE(-d180 == rmath::normalized_diff(d90, d270));
  CATCH_REQUIRE(d0 == rmath::normalized_diff(d0, d360));
  CATCH_REQUIRE(d0 == rmath::normalized_diff(d360, d0));

}
