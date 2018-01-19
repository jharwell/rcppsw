/*******************************************************************************
 * Name            : algorithm-test.cpp
 * Project         : rcppsw
 * Module          : ERF
 * Description     : Test algorithm module
 * Creation Date   : Tue Dec 13 14:54:27 2016
 * Original Author : jharwell
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include "include/max_subarray_finder.hpp"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

/*******************************************************************************
 * Test Cases
 ******************************************************************************/
TEST_CASE("Maximum Subarray Finder", "[algorithm]") {
  std::vector<int> data = {0, 1, 2, 3, 4, 5, 6, 0, 0, 0};
  rcppsw::max_subarray_finder<int> finder(data);
  std::vector<int> res;
  REQUIRE(OK == finder.find(&res));
  REQUIRE(res[0] == 21);
  REQUIRE(res[1] == 0);
  REQUIRE(res[2] == 6);
}
