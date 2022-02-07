/**
 * \file closest_pair2D.hpp
 *
 * \copyright 2018 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_ALGORITHM_CLOSEST_PAIR2D_HPP_
#define INCLUDE_RCPPSW_ALGORITHM_CLOSEST_PAIR2D_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <algorithm>
#include <cassert>
#include <cmath>
#include <functional>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, algorithm);

/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/
/**
 * \struct result_type2D
 * \ingroup algorithm
 *
 * \brief Contains (1) the closest pair of points, (2) the distance between
 * them, (3) comparator functions.
 */
template <typename T>
struct result_type2D {
  T p1{};
  T p2{};
  double dist{ 0.0 };
  bool operator<(double d) const { return dist < d; }
  bool operator<(const result_type2D<T>& other) const {
    return this->dist < other.dist;
  }
};

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class closest_pair2D
 * \ingroup algorithm
 *
 * \brief Calculate the closest two points from a set of 2D points in O(NLogN)
 * (\ref kRecursive).
 *
 * Also has a brute force (O(N^3)) algorithm (\ref kBruteForce) that can be used
 * for comparision.
 *
 * Returns the two closest points, along with the distance between them (\ref
 * result_type2D).
 *
 * \tparam T Type of point in 2D plane. Can be any class, but must provide the
 *           following methods: x(), y(), operator==(). See \ref math::vector2
 *           for example implementation).
 */
template <typename T>
class closest_pair2D {
 public:
  static inline const std::string kBruteForce = "brute_force";

  static inline const std::string kRecursive = "recursive";

  /**
   * \brief Run the calculation algorithm.
   *
   * \param method The method to use: "brute_force" or "recursive".
   * \param points A vector of points through which to search.
   * \param dist_func A function that can be used to calculate the distance
   *                  between two points.
   */
  template<typename TDistFunc>
  result_type2D<T> operator()(const std::string& method,
                              std::vector<T> points,
                              const TDistFunc& dist_func) {
    if (kBruteForce == method) {
      return brute_force(points, dist_func);
    } else if (kRecursive == method) {
      std::sort(points.begin(), points.end(), [](const T& a, const T& b) {
        return a.x() < b.x();
      });
      std::vector<T> strip;
      return recursive(points, strip, dist_func);
    }
    // Should never be hit
    return result_type2D<T>();
  }

  /**
   * \brief Find the closest pair of points using brute force.
   *
   * \param points The set of points to search.
   * \param dist_func The comparision function to use.
   *
   * \return The two closest points, along with the distance between them.
   */
  template <typename TDistFunc>
  result_type2D<T> brute_force(const std::vector<T>& points,
                               const TDistFunc& dist_func) {
    result_type2D<T> r;
    r.dist = std::numeric_limits<double>::max();

    for (size_t i = 0; i < points.size(); ++i) {
      for (size_t j = i + 1; j < points.size(); ++j) {
        if (dist_func(points[i], points[j]) < r.dist) {
          r.dist = dist_func(points[i], points[j]);
          r.p1 = points[i];
          r.p2 = points[j];
        }
      } /* for(j..) */
    } /* for(i..) */
    return r;
  }

  /**
   * \brief Find the closest pair of points using recursion.
   *
   * \param points The set of points to search through.
   * \param strip Space for the strip.
   * \param dist_func The comparision function to use.
   *
   * \return The two closest points, along with the distance between them.
   */
  template <typename TDistFunc>
  result_type2D<T> recursive(const std::vector<T>& points,
                             std::vector<T>& strip,
                             const TDistFunc& dist_func) {
    /* base case */
    if (points.size() <= 3) {
      return brute_force(points, dist_func);
    }

    /* mid point */
    size_t mid = points.size() / 2;
    T mid_point = points[mid];

    /*
     * Calculate the smallest distance
     * dl: left of mid point
     * dr: right side of the mid point
     */
    result_type2D<T> dl = recursive(
        std::vector<T>(points.begin(), points.begin() + mid), strip, dist_func);
    result_type2D<T> dr = recursive(
        std::vector<T>(points.begin() + mid, points.end()), strip, dist_func);
    result_type2D<T> dmin = std::min(dl, dr);

    for (size_t i = 0; i < points.size(); ++i) {
      if (std::fabs(points[i].x() - mid_point.x()) < dmin.dist) {
        strip.push_back(points[i]);
      }
    } /* for(i..) */
    auto res = strip_points(strip, dmin, dist_func);
    strip.clear();
    return res;
  }

 private:
  /**
   * \brief Utility function to find the distance beween the closest points of
   * strip of given size, sorted according to Y.
   *
   * \param strip The points to check.
   * \param dmin Upper bound on minimum distance.
   * \param dist_func The distance function callback to use during calculation.
   *
   * Note that this method seems to be a O(n^2) method, but it's a O(n) method
   * as the inner loop runs at most 6 times.
   */
  template <typename TDistFunc>
  result_type2D<T> strip_points(std::vector<T> strip,
                                const result_type2D<T>& dmin,
                                const TDistFunc& dist_func) {
    result_type2D<T> min = dmin;

    std::sort(strip.begin(), strip.end(), [](const T& a, const T& b) {
      return a.y() < b.y();
    });

    /*
     * Pick all points one by one and try the next points till the difference
     * between y's is smaller than d.
     */
    for (size_t i = 0; i < strip.size(); ++i) {
      for (size_t j = i + 1;
           j < strip.size() && (strip[j].y() - strip[i].y()) < min.dist;
           ++j) {
        if (dist_func(strip[i], strip[j]) < min.dist) {
          min.dist = dist_func(strip[i], strip[j]);
          min.p1 = strip[i];
          min.p2 = strip[j];
        }
      } /* for(i..) */
    } /* for(j..) */
    return min;
  }
};

NS_END(algorithm, rcppsw);

#endif /* INCLUDE_RCPPSW_ALGORITHM_CLOSEST_PAIR2D_HPP_ */
