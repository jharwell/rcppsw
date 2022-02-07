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
#include "rcppsw/algorithm/convex_hull2D.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace clustering = rcppsw::algorithm::clustering;

/*******************************************************************************
 * Test Cases
 ******************************************************************************/
CATCH_TEST_CASE("Maximum Subarray Finder", "[ralgorithm]") {
  std::vector<int> data = {0, 1, 2, 3, 4, 5, 6, 0, 0, 0};
  ralgorithm::max_subarray_finder<int> finder;
  auto res = finder(data);
  CATCH_REQUIRE(21 == std::get<0>(*res));
  CATCH_REQUIRE(0 == std::get<1>(*res));
  CATCH_REQUIRE(6 == std::get<2>(*res));
}

CATCH_TEST_CASE("Closest Pair", "[ralgorithm]") {
  std::vector<rmath::vector2i> data = {{4, 3}, {0, 2}, {0, 1}, {2, 10}, {5, 8}, {4, 1}};
  /* for (size_t i = 0; i < 1000; ++i) { */
  /*   for (size_t j = 0; j < 1000; ++j) { */
  /*     data.push_back({std::rand() % 1000, std::rand() % 1000}); */
  /*   } /\* for(j..) *\/ */
  /* } /\* for(i..) *\/ */

  auto calculator = ralgorithm::closest_pair2D<rmath::vector2i>();
  auto res = calculator.operator()<decltype(rmath::l2norm<rmath::vector2i>)>(
      "brute_force",
      data,
      rmath::l2norm);
  CATCH_REQUIRE((res.p1 == rmath::vector2i(0, 2) || res.p1 == rmath::vector2i(0, 1)));
  CATCH_REQUIRE((res.p2 == rmath::vector2i(0, 2) || res.p2 == rmath::vector2i(0, 1)));
  CATCH_REQUIRE(res.dist == 1.0);

  res = calculator.operator()<decltype(rmath::l2norm<rmath::vector2i>)>(
      "recursive",
      data,
      rmath::l2norm);
  CATCH_REQUIRE((res.p1 == rmath::vector2i(0, 2) || res.p1 == rmath::vector2i(0, 1)));
  CATCH_REQUIRE((res.p2 == rmath::vector2i(0, 2) || res.p2 == rmath::vector2i(0, 1)));
  CATCH_REQUIRE(res.dist == 1.0);
}

CATCH_TEST_CASE("Kmeans", "[ralg::clustering]") {
  std::vector<double> data = {1.0, 2.0, 2.3, 1.8, 0.5, 9.8, 7.6, 8.4, 9.1, 6.4};
  /* std::vector<double> data; */
  /* for (size_t i = 0; i < 100000000; ++i) { */
  /*   data.push_back(i % 10); */
  /* } /\* for(i..) *\/ */

  auto impl = std::make_unique<clustering::kmeans_omp<double>>(4);
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
CATCH_TEST_CASE("Convex Hull Square", "[ralg::convex_hull]") {
  /* target hull: A square */
  std::vector<rmath::vector2z> hull = {
    {0, 3},
    {3, 3},
    {3, 0},
    {0, 0},
  };
  /* 1st case: no interior points */
  std::vector<rmath::vector2z> data = {
    {0, 0},
    {0, 3},
    {3, 3},
    {3, 0},
  };

  auto calculator = ralgorithm::convex_hull2D<rmath::vector2z>();
  auto points = calculator(std::move(data));
  auto it = points->begin();

  CATCH_REQUIRE(4 == points->size());

  while (it != points->end()) {
    CATCH_REQUIRE(*it == hull[std::distance(points->begin(), it)]);
    ++it;
  } /* while() */

  /* 2nd case: with interior points */
  data = {
    {0, 0},
    {0, 3},
    {3, 3},
    {3, 0},
    {1, 1},
    {2, 2},
    {1, 2},
    {2, 1}
  };

  points = calculator(std::move(data));
  it = points->begin();

  CATCH_REQUIRE(4 == points->size());

  while (it != points->end()) {
    CATCH_REQUIRE(*it == hull[std::distance(points->begin(), it)]);
    ++it;
  } /* while() */
}

CATCH_TEST_CASE("Convex Hull Pentagon", "[ralg::convex_hull]") {
  /* target hull: A pentagon */
  std::vector<rmath::vector2z> hull = {
    {0, 2},
    {2, 4},
    {4, 2},
    {3, 0},
    {1, 0}
  };
  /* 1st case: no interior points */
  std::vector<rmath::vector2z> data = {
    {1, 0},
    {0, 2},
    {2, 4},
    {4, 2},
    {3, 0}
  };

  auto calculator = ralgorithm::convex_hull2D<rmath::vector2z>();
  auto points = calculator(std::move(data));
  auto it = points->begin();

  CATCH_REQUIRE(5 == points->size());

  CATCH_REQUIRE(*it == hull[0]);
  CATCH_REQUIRE(*std::next(it, 1) == hull[1]);
  CATCH_REQUIRE(*std::next(it, 2) == hull[2]);
  CATCH_REQUIRE(*std::next(it, 3) == hull[3]);
  CATCH_REQUIRE(*std::next(it, 4) == hull[4]);

  /* 2nd case: with interior points */
  data = {
    {1, 0},
    {0, 2},
    {2, 4},
    {4, 2},
    {3, 0},
    {2, 1},
    {2, 2},
    {2, 3},
    {3, 1},
    {1, 1},
    {1, 2},
    {1, 3},
    {3, 1},
    {3, 2}
  };

  points = calculator(std::move(data));
  it = points->begin();

  CATCH_REQUIRE(5 == points->size());
  CATCH_REQUIRE(*it == hull[0]);
  CATCH_REQUIRE(*std::next(it, 1) == hull[1]);
  CATCH_REQUIRE(*std::next(it, 2) == hull[2]);
  CATCH_REQUIRE(*std::next(it, 3) == hull[3]);
  CATCH_REQUIRE(*std::next(it, 4) == hull[4]);
}
