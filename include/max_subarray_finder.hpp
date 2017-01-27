/*******************************************************************************
 * Name            : max_subarray_finder.hpp
 * Project         : rcppsw
 * Module          : algorithm
 * Description     : Find the maximal subarray of an array
 * Creation Date   : 01/26/17
 * Copyright       : Copyright 2017 John Harwell, All rights reserved
 *
 ******************************************************************************/

#ifndef INCLUDE_MAX_SUBARRAY_FINDER_HPP_
#define INCLUDE_MAX_SUBARRAY_FINDER_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <algorithm>
#include <vector>
#include "include/al/altypes.h"
#include "include/common/fpc.h"

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
  /* constructors */
  max_subarray_finder(const std::vector<T>& arr) : arr_(arr) {}

  /* member functions */
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
  /* data members */
  const std::vector<T>& arr_;
};

} /* namespace rcppsw */

#endif /* INCLUDE_MAX_SUBARRAY_FINDER_HPP_ */
