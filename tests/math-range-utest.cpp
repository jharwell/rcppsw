/**
 * @file math-range-test.cpp
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
#include "rcppsw/math/range.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace math = rcppsw::math;

/*******************************************************************************
 * Test Cases
 ******************************************************************************/
CATCH_TEST_CASE("Sanity test", "[rmath::range]") {
  math::rangei t0(0, 1);
  CATCH_REQUIRE(0 == t0.lb());
  CATCH_REQUIRE(1 == t0.ub());
  CATCH_REQUIRE(1 == t0.span());

  t0.ub(2);
  CATCH_REQUIRE(2 == t0.ub());
  CATCH_REQUIRE(2 == t0.span());

  t0.lb(-1);
  CATCH_REQUIRE(-1 == t0.lb());
  CATCH_REQUIRE(3 == t0.span());

  t0.lb(-2);
  CATCH_REQUIRE(-2 == t0.lb());
  CATCH_REQUIRE(4 == t0.span());
}

CATCH_TEST_CASE("overlap test", "[rmath::range]") {
  math::rangei t0(2, 3);
  math::rangei t1(3, 4);
  math::rangei t2(0, 4);

  CATCH_REQUIRE(t0.contains(2));
  CATCH_REQUIRE(t0.contains(3));
  CATCH_REQUIRE(!t0.contains(4));
  CATCH_REQUIRE(!t0.contains(1));
  CATCH_REQUIRE(t2.overlaps_with(t1));
  CATCH_REQUIRE(t1.overlaps_with(t2));
  CATCH_REQUIRE(t0.overlaps_with(t2));
  CATCH_REQUIRE(t2.overlaps_with(t0));

  CATCH_REQUIRE(t0.overlaps_with(t1));
  CATCH_REQUIRE(t1.overlaps_with(t0));
  CATCH_REQUIRE(!t0.contains(t1));
  CATCH_REQUIRE(!t1.contains(t0));
  t1.lb(2);
  CATCH_REQUIRE(t1.contains(t0));
}

CATCH_TEST_CASE("manipulation test", "[rmath::range]") {
  math::rangei t0(2, 6);

  CATCH_REQUIRE(t0.center() == 4);

  auto t1 = t0.translate(1);
  CATCH_REQUIRE(t0.center() == 4);
  CATCH_REQUIRE(t1.center() == 5);

  auto t2 = t0.recenter(9);
  CATCH_REQUIRE(t0.center() == 4);
  CATCH_REQUIRE(t2.center() == 9);
  CATCH_REQUIRE(t2.lb() == 7);
  CATCH_REQUIRE(t2.ub() == 11);
}
