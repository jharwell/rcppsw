/**
 * \file rng.hpp
 *
 * \copyright 2019 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/rcppsw.hpp"
#include "rcppsw/math/range.hpp"
#include "rcppsw/patterns/pimpl/pimpl.hpp"

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
