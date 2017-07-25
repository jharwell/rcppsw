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

#ifndef INCLUDE_RCPPSW_MAX_SUBARRAY_FINDER_HPP_
#define INCLUDE_RCPPSW_MAX_SUBARRAY_FINDER_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <algorithm>
#include <vector>
#include "rcppsw/include/al/altypes.h"
#include "rcppsw/include/common/fpc.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace rcppsw {

/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
template <typename T>
class max_subarray_finder {
 public:
  max_subarray_finder(const std::vector<T>& arr) : arr_(arr) {}

  /**
   * @brief Find the maximal subarray using Kadane's algorithm, which is O(n).
   *
   * @param res The maximal subarray, to be filled.
   *
   * @return OK if successful, ERROR otherwise.
   */
  status_t find(std::vector<int>* const res) {
    FPC_CHECK(ERROR, arr_.size() > 0);
    T max_sum = arr_[0];
    T current_sum = arr_[0];
    int start_index = 0;
    int end_index = 0;

    /* Kadane's algorithm - O(n) */
    for (int i = 0; i < arr_.size(); ++i) {
      current_sum += arr_[i];
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
  const std::vector<T>& arr_;
};

} /* namespace rcppsw */

#endif /* INCLUDE_RCPPSW_MAX_SUBARRAY_FINDER_HPP_ */
