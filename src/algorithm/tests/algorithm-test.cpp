/**
 * @file algorithm-test.cpp
 *
 * @copyright 2016 John Harwell.
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
#include "rcppsw/algorithm/max_subarray_finder.hpp"
#include <vector>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

/*******************************************************************************
 * Test Cases
 ******************************************************************************/
TEST_CASE("Maximum Subarray Finder", "[algorithm]") {
  std::vector<int> data = {0, 1, 2, 3, 4, 5, 6, 0, 0, 0};
  rcppsw::algorithm::max_subarray_finder<int> finder(data);
  std::vector<int> res;
  REQUIRE(OK == finder.find(&res));
  REQUIRE(res[0] == 21);
  REQUIRE(res[1] == 0);
  REQUIRE(res[2] == 6);
}
