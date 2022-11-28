/**
 * @file spatial-euclidean_dist-utest.cpp
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
#include "rcppsw/spatial/euclidean_dist.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/

/*******************************************************************************
 * Test Cases
 ******************************************************************************/
CATCH_TEST_CASE("Sanity", "[rspatial::euclidean_dist]") {
  rspatial::euclidean_dist d1(0);
  CATCH_REQUIRE(0 == d1.v());

  auto d2 = rspatial::euclidean_dist::make(-3);
  CATCH_REQUIRE(3 == d2.v());
}

CATCH_TEST_CASE("Operations", "[rspatial::euclidean_dist]") {
  rspatial::euclidean_dist d1(2);
  d1 += rspatial::euclidean_dist(3);


  rspatial::euclidean_dist d2(2);
  rspatial::euclidean_dist d3(2);

  CATCH_REQUIRE(d1 >= d3);
  CATCH_REQUIRE(d2 - 1.0 <= 2.0);

  CATCH_REQUIRE(d2 >= d2);
  CATCH_REQUIRE(d2 - 1 < d2);
}
