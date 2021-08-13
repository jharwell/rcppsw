/**
 * @file types-spatial_dist-utest.cpp
 *
 * @copyright 2021 John Harwell, All rights reserved.
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
#include "rcppsw/types/spatial_dist.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/

/*******************************************************************************
 * Test Cases
 ******************************************************************************/
CATCH_TEST_CASE("Sanity", "[rtypes::spatial_dist]") {
  rtypes::spatial_dist d1(0);
  CATCH_REQUIRE(0 == d1.v());

  auto d2 = rtypes::spatial_dist::make(-3);
  CATCH_REQUIRE(3 == d2.v());
}

CATCH_TEST_CASE("Operations", "[rtypes::spatial_dist]") {
  rtypes::spatial_dist d1(2);
  d1 += rtypes::spatial_dist(3);


  rtypes::spatial_dist d2(2);
  rtypes::spatial_dist d3(2);

  CATCH_REQUIRE(d1 >= d3);
  CATCH_REQUIRE(d2 - 1.0 <= 2.0);

  CATCH_REQUIRE(d2 >= d2);
  CATCH_REQUIRE(d2 - 1 < d2);
}
