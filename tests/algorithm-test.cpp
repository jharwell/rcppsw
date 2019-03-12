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
#include <vector>
#include <cmath>
#include <functional>

#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_PREFIX_ALL
#include "catch.hpp"

#include "rcppsw/algorithm/max_subarray_finder.hpp"
#include "rcppsw/algorithm/closest_pair2D.hpp"
#include "rcppsw/math/vector2.hpp"
#include "rcppsw/algorithm/clustering/entropy.hpp"
#include "rcppsw/algorithm/clustering/kmeans.hpp"
#include "rcppsw/swarm/convergence/positional_entropy.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace math = rcppsw::math;
namespace clustering = rcppsw::algorithm::clustering;
namespace swarm = rcppsw::swarm;

/*******************************************************************************
 * Test Cases
 ******************************************************************************/
CATCH_TEST_CASE("Maximum Subarray Finder", "[algorithm]") {
  std::vector<int> data = {0, 1, 2, 3, 4, 5, 6, 0, 0, 0};
  rcppsw::algorithm::max_subarray_finder<int> finder(data);
  std::vector<int> res;
  CATCH_REQUIRE(OK == finder.find(&res));
  CATCH_REQUIRE(res[0] == 21);
  CATCH_REQUIRE(res[1] == 0);
  CATCH_REQUIRE(res[2] == 6);
}

CATCH_TEST_CASE("Closest Pair", "[algorithm]") {
  std::vector<rcppsw::math::vector2i> data = {{4, 3}, {0, 2}, {0, 1}, {2, 10}, {5, 8}, {4, 1}};
  /* for (size_t i = 0; i < 1000; ++i) { */
  /*   for (size_t j = 0; j < 1000; ++j) { */
  /*     data.push_back({std::rand() % 1000, std::rand() % 1000}); */
  /*   } /\* for(j..) *\/ */
  /* } /\* for(i..) *\/ */

  auto dist_func = std::bind(&math::vector2i::distance,
                             std::placeholders::_1,
                             std::placeholders::_2);
  auto res = rcppsw::algorithm::closest_pair<math::vector2i>()("brute_force",
                                                                       data,
                                                                       dist_func);
  CATCH_REQUIRE((res.p1 == math::vector2i(0, 2) || res.p1 == math::vector2i(0, 1)));
  CATCH_REQUIRE((res.p2 == math::vector2i(0, 2) || res.p2 == math::vector2i(0, 1)));
  CATCH_REQUIRE(res.dist == 1.0);

  res = rcppsw::algorithm::closest_pair<math::vector2i>()("recursive",
                                                                  data,
                                                                  dist_func);
  CATCH_REQUIRE((res.p1 == math::vector2i(0, 2) || res.p1 == math::vector2i(0, 1)));
  CATCH_REQUIRE((res.p2 == math::vector2i(0, 2) || res.p2 == math::vector2i(0, 1)));
  CATCH_REQUIRE(res.dist == 1.0);
}

CATCH_TEST_CASE("Kmeans", "[clustering]") {
  std::vector<double> data = {1.0, 2.0, 2.3, 1.8, 0.5, 9.8, 7.6, 8.4, 9.1, 6.4};
  /* std::vector<double> data; */
  /* for (size_t i = 0; i < 100000000; ++i) { */
  /*   data.push_back(i % 10); */
  /* } /\* for(i..) *\/ */

  auto impl = std::make_unique<clustering::detail::kmeans_impl<double>>(4);
  clustering::kmeans<double> alg(data,
                                 std::move(impl),
                                 2,
                                 10);
  auto res = alg.run([](double a, double b) { return std::fabs(a - b); });
  CATCH_REQUIRE(10 == res.size());

  for (size_t i = 0; i < res.size(); ++i) {
    if (i < 5) {
      CATCH_REQUIRE(res[i] == 0);
    } else {
      CATCH_REQUIRE(res[i] == 1);
    }
  } /* for(i..) */
}

CATCH_TEST_CASE("entropy", "[clustering]") {
  std::vector<double> data = {0, 1.0, 2.0, 3.0};
  /* std::vector<double> data; */
  /* for (size_t i = 0; i < 10000; ++i) { */
  /*   data.push_back(i % 10); */
  /* } /\* for(i..) *\/ */

  auto impl = std::make_unique<clustering::detail::entropy_impl<double>>(4);
  clustering::entropy_balch2000<double> alg(std::move(impl),
                                            math::ranged(1.0, 2.0),
                                            1.0);
  double res = alg.run(data,
                       [](double a, double b) { return std::fabs(a - b); });

  CATCH_REQUIRE(static_cast<int>((res * 100.0)) / 100.0 == 2.24);
}
