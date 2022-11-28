/**
 * \file transform.hpp
 *
 * \copyright 2020 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, algorithm);

/*******************************************************************************
 * Templates
 ******************************************************************************/
/**
 * \brief Given an input range defined by (\p first, \p last), and a filtering
 * predicate \p pred, apply \p f to all elements from the input range that
 * satisfy \p pred and write them to the output range \p result.
 */
template <class InputIterator,
          class OutputIterator,
          class Predicate,
          class UnaryFunction>
OutputIterator transform_if(InputIterator first,
                            InputIterator last,
                            OutputIterator result,
                            const Predicate& pred,
                            const UnaryFunction& f) {
  for (; first != last; ++first) {
    if (pred(*first)) {
      *result++ = f(*first);
    }
  } /* for(...) */
  return result;
}

NS_END(algorithm, rcppsw);

