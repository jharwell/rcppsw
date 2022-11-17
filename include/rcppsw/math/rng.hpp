/**
 * \file rng.hpp
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

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/rcppsw.hpp"
#include "rcppsw/math/range.hpp"
#include "rcppsw/patterns/pimpl/pimpl.hpp"
#include "rcppsw/math/probability.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace rcppsw::math {

namespace detail {
struct rng_impl;
} /* namespace detail */

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class rng
 * \ingroup math
 *
 * \brief Random number generator class using the PIMPL pattern in order to not
 * have to include \c \<random\>.
 */
class rng final : public patterns::pimpl::pimpl<detail::rng_impl> {
 public:
  explicit rng(size_t seed);
  ~rng(void) override;

  /**
   * \brief Get the current seed.
   */
  size_t seed(void) const { return m_seed; }

  /**
   * \brief Return a uniform selection in the range [lb, ub].
   */
  template <typename T>
  T uniform(const T& lb, const T& ub);

  /**
   * \brief Return a uniform selection in the range specified by \p c_range.
   */
  template <typename T>
  T uniform(const range<T>& c_range) {
    return uniform(c_range.lb(), c_range.ub());
  }

  /**
   * \brief Return a selection according to the Gaussian distribution \f$G(\mu,
   * \sigma)\f$.
   */
  double gaussian(double mean, double std_dev);

  /**
   * \brief Return a selection according to the exponential distribution
   * \f$1 - e ^(-lambda)\f$.
   */
  double exponential(double lambda);

  /**
   * \brief Return a selection according to a Bernoulli distribution with
   * parameter \p p.
   */
  bool bernoulli(double p);

 private:
  /* clang-format off */
  size_t m_seed;
  /* clang-format on */
};

} /* namespace rcppsw::math */
