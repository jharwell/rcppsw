/**
 * @file math-radians-test.cpp
 *
 * @copyright 2018 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_PREFIX_ALL
#include "catch.hpp"
#include "rcppsw/math/rng.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace math = rcppsw::math;

/*******************************************************************************
 * Test Cases
 ******************************************************************************/
CATCH_TEST_CASE("Sanity", "[math::rng]") {
  math::rng r1(0);
  CATCH_REQUIRE(0 == r1.seed());
}

CATCH_TEST_CASE("Uniform", "[math::rng]") {
  math::rng r1(0);
  math::rng r2(0);

  std::vector<double> res1;
  std::vector<double> res2;

  for (size_t i = 0; i < 100; ++i) {
    res1.push_back(r1.uniform(rmath::range(0, 10)));
    res2.push_back(r2.uniform(rmath::range(0, 10)));
  } /* for(i..) */

  CATCH_REQUIRE(res1 == res2);
}

CATCH_TEST_CASE("Guassian", "[math::rng]") {
  math::rng r1(0);
  math::rng r2(0);

  std::vector<double> res1;
  std::vector<double> res2;

  for (size_t i = 0; i < 100; ++i) {
    res1.push_back(r1.gaussian(0.0, 1.0));
    res2.push_back(r2.gaussian(0.0, 1.0));
  } /* for(i..) */

  CATCH_REQUIRE(res1 == res2);
}

CATCH_TEST_CASE("Exponential", "[math::rng]") {
  math::rng r1(0);
  math::rng r2(0);

  std::vector<double> res1;
  std::vector<double> res2;

  for (size_t i = 0; i < 100; ++i) {
    res1.push_back(r1.exponential(0.0));
    res2.push_back(r2.exponential(0.0));
  } /* for(i..) */
  CATCH_REQUIRE(res1 == res2);
}

CATCH_TEST_CASE("Bernoulli", "[math::rng]") {
  math::rng r1(0);
  math::rng r2(0);

  std::vector<double> res1;
  std::vector<double> res2;

  for (size_t i = 0; i < 100; ++i) {
    res1.push_back(r1.bernoulli(0.2));
    res2.push_back(r2.bernoulli(0.2));
  } /* for(i..) */
  CATCH_REQUIRE(res1 == res2);
}
