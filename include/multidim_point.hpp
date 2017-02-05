/*******************************************************************************
 * Name            : multidim_point.hpp
 * Project         : rcppsw
 * Module          : algorithm
 * Description     : Representation of multidimensional data
 * Creation Date   : 02/04/17
 * Copyright       : Copyright 2017 John Harwell, All rights reserved
 *
 ******************************************************************************/

#ifndef INCLUDE_MULTIDIM_POINT_HPP_
#define INCLUDE_MULTIDIM_POINT_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <numeric>
#include <algorithm>

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace rcppsw {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
template <typename T>
class multidim_point : public std::vector<T>  {
  multidim_point& operator+=(const multidim_point& rhs) {
        for (std::size_t i = 0; i < this->size(); ++i) {
          this->at(i) += rhs[i];
        } /* for(i..) */
        return this;
  }
  void average(void) {
    T sum = std::accumulate(this->begin(), this->end(), T());
    std::for_each(this->begin(), this->end(), [&](const T& e){
        e/sum;
      });
  }
  /* data members */
};

} /* namespace rcppsw */

#endif INCLUDE_/* MULTIDIM_POINT_HPP_ */
