/**
 * @file types-timestep-test.cpp
 *
 * @copyright 2021 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_PREFIX_ALL
#include "catch.hpp"
#include "rcppsw/types/timestep.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/

/*******************************************************************************
 * Test Cases
 ******************************************************************************/
CATCH_TEST_CASE("Sanity", "[rtypes::timestep]") {
  rtypes::timestep t(0);
  CATCH_REQUIRE(0 == t.v());

  t = rtypes::timestep(4);
  CATCH_REQUIRE(4 == t.v());

  rtypes::timestep t2(t);
  CATCH_REQUIRE(4 == t.v());

  t = rtypes::timestep(-1);
  CATCH_REQUIRE(t.v() > 0);
}

CATCH_TEST_CASE("Operations", "[rtypes::timestep]") {
  rtypes::timestep t(2);
  t += 3;
  CATCH_REQUIRE(rtypes::timestep(5) == t);

  t += rtypes::timestep(3);

  CATCH_REQUIRE(rtypes::timestep(8) == t);
  CATCH_REQUIRE(rtypes::timestep(5) == t - 3);
  CATCH_REQUIRE(rtypes::timestep(0) == t - rtypes::timestep(8));
  CATCH_REQUIRE((rtypes::timestep(8) % rtypes::timestep(2)) == 0UL);


  rtypes::timestep t1(2);
  rtypes::timestep t2(2);

  CATCH_REQUIRE(t1 == t2);
  CATCH_REQUIRE(t1 == 2);
  CATCH_REQUIRE(t1 - 1 < 2.0);
  CATCH_REQUIRE(t1 + 1 > 2.0);

  CATCH_REQUIRE(t1 >= t2);
  CATCH_REQUIRE(t1 + 1 > t2);
  CATCH_REQUIRE(t1 - 1 < t2);

  CATCH_REQUIRE(++t1 == 3);
  CATCH_REQUIRE(t1 == 3);
}
