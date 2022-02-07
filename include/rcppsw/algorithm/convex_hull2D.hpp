/**
 * \file convex_hull2D.hpp
 *
 * \copyright 2021 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_ALGORITHM_CONVEX_HULL2D_HPP_
#define INCLUDE_RCPPSW_ALGORITHM_CONVEX_HULL2D_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <list>
#include <algorithm>
#include <utility>
#include <boost/optional.hpp>

#include "rcppsw/math/math.hpp"
#include "rcppsw/er/client.hpp"
#include "rcppsw/math/vector2.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, algorithm);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class convex_hull2D
 * \ingroup algorithm
 *
 * \brief Calculate the convex hull of a set of points in the 2D plane. The
 * resulting list of points will be in counter-clockwise order. Implementation
 * "Graham Scan" algorithm.
 */
template<typename TCoord>
class convex_hull2D : public rer::client<convex_hull2D<TCoord>> {
 public:
  using coord_type = TCoord;
  using coord_value_type = typename coord_type::value_type;

  convex_hull2D(void) : ER_CLIENT_INIT("rcppsw.algorithm.convex_hull2D") {}

  /* Not move/copy constructable/assignable by default */
  convex_hull2D(const convex_hull2D&) = delete;
  convex_hull2D& operator=(const convex_hull2D&) = delete;
  convex_hull2D(convex_hull2D&&) = delete;
  convex_hull2D& operator=(convex_hull2D&&) = delete;

  boost::optional<std::list<coord_type>> operator()(
      std::vector<coord_type>&& points) {
    ER_DEBUG("Calculate convex hull for %zu 2D points", points.size());
    initialize(points);

    /*
     * If two or more points make same angle with p0, Remove all but the one
     * that is farthest from p0. Points that make the same angle and are closer
     * cannot be part of the hull by definition.
     */
    size_t m = 1;
    for (size_t i = 1; i < points.size(); ++i) {
      /* Keep removing i while angle of i and i+1 is same with respect to p0 */
      while (i < points.size() - 1 &&
             orientation::ekCOLLINEAR == orientation(m_p0,
                                                     points[i],
                                                     points[i+1])) {
        ++i;
      } /* while() */

      points[m] = points[i];
      ++m;
    }
    /*
     * We could resize the vector here, but that really doesn't buy us
     * anything, because we already have moved the elements down that we want
     * to keep.
     */
    ER_DEBUG("Have %zu points/%zu total to process after filtering",
             m,
             points.size());

    /*
     * If modified array of points has less than 3 points, convex hull is not
     * possible.
     */
    if (m < 3) {
      return boost::none;
    }

    /* Create an empty stack and push first three points to it */
    std::list<coord_type> hull;
    hull.push_front(points[0]);
    hull.push_front(points[1]);
    hull.push_front(points[2]);

    /* Compute hull */
    for (size_t i = 3; i < m; ++i) {
      /* Keep removing top of stack while the angle formed by points
       * next-to-top, top, and points[i] makes a non-counterclockwise turn.
       */
      while (hull.size() > 1 &&
             orientation::ekCOUNTER_CLOCKWISE != orientation(*std::next(hull.begin()),
                                                             hull.front(),
                                                             points[i])) {
        hull.pop_front();
      } /* while(hull...) */
      hull.push_front(points[i]);
    } /* for(i..) */

    return boost::make_optional(hull);
  } /* operator() */

 private:
  enum orientation {
    ekCOLLINEAR,
    ekCLOCKWISE,
    ekCOUNTER_CLOCKWISE
  };

  /**
   * \brief Find the \ref orientation of the tuple of points in the plane.
   */
  orientation orientation(const coord_type& p_in,
                          const coord_type& q_in,
                          const coord_type& r_in) {
    /*
     * We copy each of the vectors into vector2d so that the orientation is
     * correct for unsigned vectors (e.g., vector2z). If the coord_type is
     * already signed, then this is unecessary, but does not hurt. The compiler
     * will probably optimize it away in such cases.
     */
    rmath::vector2d p(p_in.x(), p_in.y());
    rmath::vector2d q(q_in.x(), q_in.y());
    rmath::vector2d r(r_in.x(), r_in.y());

    auto val = (q.y() - p.y()) * (r.x() - q.x()) -
               (q.x() - p.x()) * (r.y() - q.y());
    if (val > 0) { /* clockwise */
      return orientation::ekCLOCKWISE;
    } else if (val < 0) {  /* counterclockwise */
      return orientation::ekCOUNTER_CLOCKWISE;
    } else {  /* collinear */
      return orientation::ekCOLLINEAR;
    }
  }

  void initialize(std::vector<coord_type>& points) {
    /*
     * First, bind the bottommost point in Y. If there are multiple points with
     * the same minimum in Y, sort by X.
     */
    coord_value_type ymin = points[0].y();
    size_t min = 0;
    for (size_t i = 1; i < points.size(); ++i) {
      auto y = points[i].y();

      if ((y < ymin) ||
          (rmath::is_equal(ymin, y) && points[i].x() < points[min].x())) {
        ymin = points[i].y();
        min = i;
      }
    } /* for(i..) */

    /* Smallest point goes at index 0 */
    std::swap(points[0], points[min]);

    /*
     * Sort all points with respect to the smallest point by polar angle,
     * measured counterclockwise. If there are ties in angle (collinear), then
     * sort by ascending distance from the smallest point.
     */
    m_p0 = points[0];
    std::sort(points.begin() + 1,
              points.end(),
              [this](const coord_type& lhs, const coord_type& rhs) {
                auto o = orientation(m_p0, lhs, rhs);
                if (orientation::ekCOLLINEAR == o) {
                  return (m_p0 - rhs).square_length() >= (m_p0 - lhs).square_length();
                }

                return (orientation::ekCLOCKWISE != o);
              });
  }

  /* clang-format off */
  coord_type m_p0{};
  /* clang-format on */
};

NS_END(algorithm, rcppsw);

#endif /* INCLUDE_RCPPSW_ALGORITHM_CONVEX_HULL2D_HPP_ */
