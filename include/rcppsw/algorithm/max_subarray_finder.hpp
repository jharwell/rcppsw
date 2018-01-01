/**
 * @file max_subarray_finder.hpp
 *
 * @copyright 2017 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_ALGORITHM_MAX_SUBARRAY_FINDER_HPP_
#define INCLUDE_RCPPSW_ALGORITHM_MAX_SUBARRAY_FINDER_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <algorithm>
#include <vector>
#include "rcppsw/common/common.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, algorithm);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class max_subarray_finder
 *
 * @brief Find the maximal subarray using Kadane's algorithm, which is O(n).
 */
template <typename T>
class max_subarray_finder {
 public:
  explicit max_subarray_finder(const std::vector<T>& arr) : m_arr(arr) {}

  /**
   * @brief Find the maximal subarray.
   *
   * @param res The maximal subarray, to be filled.
   *
   * @return \c OK if successful, \c ERROR otherwise.
   */
  status_t find(std::vector<int>* const res) {
    FPC_CHECK(ERROR, m_arr.size() > 0);
    T max_sum = m_arr[0];
    T current_sum = m_arr[0];
    int start_index = 0;
    int end_index = 0;

    /* Kadane's algorithm - O(n) */
    for (int i = 0; i < m_arr.size(); ++i) {
      current_sum += m_arr[i];
      if (current_sum > max_sum) {
        max_sum = current_sum;
        end_index = i;
      } else if (current_sum < 0) {
        start_index = i + 1;
        current_sum = 0;
      }
    } /* for(i..) */

    res->push_back(max_sum);
    res->push_back(start_index);
    res->push_back(end_index);
    return OK;
  } /* find() */

 private:
  const std::vector<T>& m_arr;
};

NS_END(algorithm, rcppsw);

#endif /* INCLUDE_RCPPSW_ALGORITHM_MAX_SUBARRAY_FINDER_HPP_ */
