/**
 * \file transform.hpp
 *
 * \copyright 2020 John Harwell, All rights reserved.
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

