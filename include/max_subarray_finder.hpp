/*******************************************************************************
 * Name            : max_subarray_finder.hpp
 * Project         : rcppsw
 * Module          : algorithm
 * Description     : Find the maximal subarray of an array
 * Creation Date   : Thu Jan 26 17:37:56 2017
 * Original Author : jharwell
 *
 ******************************************************************************/

#ifndef INCLUDE_MAX_SUBARRAY_FINDER_HPP_
#define INCLUDE_MAX_SUBARRAY_FINDER_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <algorithm>
#include <vector>
#include <limits>

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
template<typename T> class max_subarray_finder {
 public:
  /* constructors */
  max_subarray_finder(
      const std::vector<T>& arr) :
      arr_(arr) {}

  /* member functions */
  std::vector<int> find(void) {
    T max_sum = std::numeric_limits<T>::min();
    T current_sum = std::numeric_limits<T>::min();
    int start_index = 0;
    int end_index = 0;
    for (int i = 0; i < arr_.size(); ++i) {
          current_sum += arr_[i];
          if (current_sum > max_sum) {
            max_sum = current_sum;
            start_index = end_index;
            end_index = i;
          } else if (current_sum < 0) {
            start_index = i + 1;
            current_sum = 0;
          }
    } /* for(i..) */

    return {max_sum, start_index, end_index};
  } /* find() */

 private:
  /* member functions */

  /* data members */
  const std::vector<T> &arr_;
};

}  /* namespace rcppsw */

#endif /* INCLUDE_MAX_SUBARRAY_FINDER_HPP_ */
