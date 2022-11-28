/**
 * \file max_subarray_finder.hpp
 *
 * \copyright 2017 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <algorithm>
#include <boost/optional.hpp>
#include <tuple>

#include "rcsw/common/fpc.h"

#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, algorithm);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class max_subarray_finder
 * \ingroup algorithm
 *
 * \brief Find the maximal subarray using Kadane's algorithm, which is O(n).
 */
template <typename T>
class max_subarray_finder {
 public:
  /**
   * \brief Find the maximal subarray from the source array.
   *
   * \return (sum, start index (inclusive), end index (inclusive)), if one is found.
   */
  boost::optional<std::tuple<T, int, int>> operator()(const std::vector<T>& arr) const {
    RCSW_FPC_NV(boost::none, arr.size() > 0);

    T max_sum = arr[0];
    T current_sum = arr[0];
    int start_index = 0;
    int end_index = 0;
    std::tuple<T, int, int> res;

    /* Kadane's algorithm - O(n) */
    for (size_t i = 0; i < arr.size(); ++i) {
      current_sum += arr[i];
      if (current_sum > max_sum) {
        max_sum = current_sum;
        end_index = i;
      } else if (current_sum < 0) {
        start_index = i + 1;
        current_sum = 0;
      }
    } /* for(i..) */
    return boost::make_optional(std::make_tuple(max_sum, start_index, end_index));
  }
};

NS_END(algorithm, rcppsw);

