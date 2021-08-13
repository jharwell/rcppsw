/**
 * \file rtree.hpp
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

#ifndef INCLUDE_RCPPSW_DS_RTREE_HPP_
#define INCLUDE_RCPPSW_DS_RTREE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <algorithm>
#include <boost/geometry.hpp>
#include <boost/geometry/index/rtree.hpp>
#include <utility>
#include <vector>

#include "rcppsw/math/vector2.hpp"
#include "rcppsw/math/vector3.hpp"
#include "rcppsw/patterns/decorator/decorator.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ds);

namespace bg = boost::geometry;
namespace bgi = bg::index;

/**
 * \brief A 2D or 3D geometrical point, as defined by boost. Loose adaptor to
 * \ref rmath::vector2 or \ref rmath::vector3.
 */
template <typename TCoordType>
using rtree_point = bg::model::point<typename TCoordType::value_type,
                                     TCoordType::kDIMENSIONALITY,
                                     bg::cs::cartesian>;

/**
 * \brief Representation of rectangles in the rtree.
 */
template <typename TCoordType>
using rtree_box = bg::model::box<rtree_point<TCoordType>>;

template<typename TCoordType,
         typename TGeometryType,
         typename TValueType,
         size_t MAXELTS = 16>
struct rtree_spec {
  static constexpr const size_t kMAXELTS = 16;

  using coord_type = TCoordType;

  /**
   * \brief The type of geometry that the rtree will be built from (e.g.,
   * points, rectangles, etc.).
   */
  using geometry_type = TGeometryType;

  /**
   * \brief The type of the thing you want to track with the rtree (i.e., what
   * is associated with each rectangle).
   */
  using value_type = TValueType;

  /**
   * \brief Type of the elements in the tree.
   */
  using element_type = std::pair<geometry_type, value_type>;

  /**
   * \brief The templated type of the underlying boost tree that does all the
   * work.
   */
  using tree_type = bgi::rtree<element_type, bgi::rstar<MAXELTS>>;
};

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class rtree
 * \ingroup ds
 *
 * \brief Wrapper around boost::geometry::index::rtree to provide very fast
 * queries of the form "How many things are in this  area", and reasonably
 * fast tree build times as well. That is, this class is intended for
 * applications in which large trees are built, queried frequently and updated
 * relatively infrequently.
 *
 * \tparam TSpecType The specification for the rtree of type \ref rtree_spec.
 */
template <typename TSpecType>
class rtree : rpdecorator::decorator<typename TSpecType::tree_type> {
 public:
  using spec_type = TSpecType;
  using value_type = typename spec_type::value_type;
  using element_type = typename spec_type::element_type;
  using geometry_type = typename spec_type::geometry_type;
  using coord_type = typename spec_type::coord_type;
  using rpdecorator::decorator<typename spec_type::tree_type>::decoratee;

  rtree(void) = default;

  /* Not move/copy constructable/assignable by default */
  rtree(const rtree&) = delete;
  const rtree& operator=(const rtree&) = delete;
  rtree(rtree&&) = delete;
  rtree& operator=(rtree&&) = delete;

  /**
   * \brief Query the tree to figure out how many objects intersect the
   * rectangle \p query.
   */
  std::vector<value_type> intersections(const rtree_box<coord_type>& query) const {
    std::vector<element_type> res1;
    res1.reserve(spec_type::kMAXELTS); /* good a guess as any */
    decoratee().query(bgi::intersects(query), std::back_inserter(res1));

    std::vector<value_type> res2;
    res2.reserve(res1.size());
    std::transform(res1.begin(),
                   res1.end(),
                   std::back_inserter(res2),
                   [res2](const auto& pair) { return pair.second; });
    return res2;
  }

  /**
   * \brief Query the tree to find the \p k nearest objects to \p point.
   */
  std::vector<value_type> nearest(const rtree_point<coord_type>& query,
                                  size_t k) const {
    std::vector<element_type> res1;
    res1.reserve(spec_type::kMAXELTS); /* good a guess as any */
    decoratee().query(bgi::nearest(query, k), std::back_inserter(res1));

    std::vector<value_type> res2;
    res2.reserve(res1.size());
    std::transform(res1.begin(),
                   res1.end(),
                   std::back_inserter(res2),
                   [res2](const auto& pair) { return pair.second; });
    return res2;
  }

  /**
   * \brief Query the tree to see if \p key is found in the tree. This query
   * does not take advantage of tree properties, and is O(N).
   */
  bool contains(const value_type& key) const {
    auto it =
        std::find_if(decoratee().begin(), decoratee().end(), [key](const auto& pair) {
          return key == pair.second;
        });
    return decoratee().end() != it;
  }

  /**
   * \brief Insert the \p key into the tree, which will be placed into the tree
   * according to its rectangle defined by \p ll, \p ur.
   */
  void insert(const value_type& value, const geometry_type& key) {
    decoratee().insert(element_type(key, value));
  }

  /**
   * \brief Remove the \p key and its associated rectangle from the tree. Does
   * not take advantage of tree properties, and therefore is O(N).
   *
   * \return The # of items removed (0 or 1).
   */
  size_t remove(const value_type& value) {
    std::vector<element_type> victims;
    std::copy_if(decoratee().begin(),
                 decoratee().end(),
                 std::back_inserter(victims),
                 [value](const auto& pair) { return value == pair.second; });
    return decoratee().remove(victims.begin(), victims.end());
  }
  /**
   * \brief Remove the \p key and its associated rectangle from the tree.
   *
   * \return The # of items removed (0 or 1).
   */
  size_t remove(const value_type& value, const geometry_type& key) {
    return decoratee().remove(element_type(key, value));
  }

  RCPPSW_DECORATE_DECLDEF(insert);
  RCPPSW_DECORATE_DECLDEF(begin, const);
  RCPPSW_DECORATE_DECLDEF(end, const);
  RCPPSW_DECORATE_DECLDEF(size, const);
};

/*******************************************************************************
 * Free Functions
 ******************************************************************************/
template <typename TCoordType,
          RCPPSW_SFINAE_DECLDEF(rmpl::is_specialization<TCoordType,
                                rmath::vector2>::value)>
rtree_point<TCoordType> make_rtree_point(const TCoordType& c) {
  return rtree_point<TCoordType>(c.x(), c.y());
}

template <typename TCoordType,
          RCPPSW_SFINAE_DECLDEF(rmpl::is_specialization<TCoordType,
                                rmath::vector3>::value)>
rtree_point<TCoordType> make_rtree_point(const TCoordType& c) {
  return rtree_point<TCoordType>(c.x(), c.y(), c.z());
}

template <typename TCoordType,
          RCPPSW_SFINAE_DECLDEF(rmpl::is_specialization<TCoordType,
                                rmath::vector2>::value)>
rtree_box<TCoordType> make_rtree_box(const TCoordType& ll,
                                     const TCoordType& ur) {
  return rtree_box<TCoordType>(rtree_point<TCoordType>(ll.x(),
                                                       ll.y()),
                               rtree_point<TCoordType>(ur.x(),
                                                       ur.y()));
}

template <typename TCoordType,
          RCPPSW_SFINAE_DECLDEF(rmpl::is_specialization<TCoordType,
                                rmath::vector3>::value)>
rtree_box<TCoordType> make_rtree_box(const TCoordType& ll,
                                     const TCoordType& ur) {
  return rtree_box<TCoordType>(rtree_point<TCoordType>(ll.x(),
                                                       ll.y(),
                                                       ll.z()),
                               rtree_point<TCoordType>(ur.x(),
                                                       ur.y(),
                                                       ur.z()));
}

NS_END(ds, rcppsw);

#endif /* INCLUDE_RCPPSW_DS_RTREE_HPP_ */
