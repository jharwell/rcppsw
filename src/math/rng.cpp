/**
 * \file rng.cpp
 *
 * \copyright 2019 John Harwell, All rights reserved.
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
#include "rcppsw/math/rng.hpp"

#include <random>

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, math, detail);

struct rng_impl {
  explicit rng_impl(uint seed) : engine(seed) {}
  std::default_random_engine engine;
};

NS_END(detail);

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/
rng::rng(size_t seed) : pimpl(seed), m_seed(seed) {}

rng::~rng(void) = default;

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
template <typename T>
T rng::uniform(const T& lb, const T& ub) {
  using uniform_distribution_type =
      typename std::conditional<std::is_floating_point<T>::value,
                                std::uniform_real_distribution<T>,
                                std::uniform_int_distribution<T>>::type;

  uniform_distribution_type dist(lb, ub);
  return dist(this->impl->engine);
} /* uniform() */

double rng::gaussian(double mean, double std_dev) {
  std::normal_distribution<double> dist(mean, std_dev);
  return dist(this->impl->engine);
} /* guassian() */

double rng::exponential(double lambda) {
  std::exponential_distribution<double> dist(lambda);
  return dist(this->impl->engine);
} /* exponential() */

bool rng::bernoulli(double p) {
  std::bernoulli_distribution dist(p);
  return dist(this->impl->engine);
} /* bernoulli() */

/*******************************************************************************
 * Template Instantiations
 ******************************************************************************/
template int rng::uniform(const int& lb, const int& ub);
template size_t rng::uniform(const size_t& lb, const size_t& ub);
template double rng::uniform(const double& lb, const double& ub);

NS_END(math, rcppsw);
