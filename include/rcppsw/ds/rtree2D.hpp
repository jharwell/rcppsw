/**
 * \file rtree2D.hpp
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

#ifndef INCLUDE_RCPPSW_DS_RTREE2D_HPP_
#define INCLUDE_RCPPSW_DS_RTREE2D_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <algorithm>
#include <boost/geometry.hpp>
#include <boost/geometry/index/rtree.hpp>
#include <utility>
#include <vector>

#include "rcppsw/math/vector2.hpp"
#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ds);

namespace bg = boost::geometry;
namespace bgi = bg::index;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class rtree2D
 * \ingroup ds
 *
 * \brief Wrapper around boost::geometry::index::rtree2D to provide very fast
 * queries of the form "How many things are in this 2D area", and reasonably
 * fast tree build times as well. That is, this class is intended for
 * applications in which large trees are built, queried frequently and updated
 * relatively infrequently.
 *
 * \tparam TCoord The type of the coordinate used to define the corners and 2D
 * shapes contained in the tree.
 *
 * \tparam TKey The type of the class/object/etc which has a representation
 * projectable onto the 2D plane, which are returned by queries.
 */
template <typename TCoord, typename TKey, size_t MAXELTS>
class rtree2D {
 public:
  /**
   * \brief Type of the points used to represent the rectangles managed by the tree.
   */
  using point_type = bg::model::point<TCoord, 2, bg::cs::cartesian>;

  /**
   * \brief Representation of 2D rectangles in the tree.
   */
  using box_type = bg::model::box<point_type>;

  /**
   * \brief Type of the elements in the tree.
   */
  using value_type = std::pair<box_type, TKey>;

  /**
   * \brief The templated type of the underlying boost tree that does all the work.
   */
  using tree_type = bgi::rtree<value_type, bgi::rstar<MAXELTS>>;

  rtree2D(void) = default;

  /* Not move/copy constructable/assignable by default */
  rtree2D(const rtree2D&) = delete;
  const rtree2D& operator=(const rtree2D&) = delete;
  rtree2D(rtree2D&&) = delete;
  rtree2D& operator=(rtree2D&&) = delete;

  /**
   * \brief Query the tree to figure out how many objects of type \p TKey are
   * contained in the tree.
   */
  std::vector<TKey> query(const math::vector2<TCoord>& ll,
                          const math::vector2<TCoord>& ur) const {
    std::vector<value_type> res1;
    res1.reserve(MAXELTS); /* good a guess as any */
    box_type query(point_type(ll.x(), ll.y()), point_type(ur.x(), ur.y()));
    m_impl.query(bgi::intersects(query), std::back_inserter(res1));

    std::vector<TKey> res2;
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
  bool query(const TKey& key) const {
    auto it =
        std::find_if(m_impl.begin(), m_impl.end(), [key](const value_type& pair) {
          return key == pair.second;
        });
    return m_impl.end() != it;
  }

  /**
   * \brief Insert the \p key into the tree, which will be placed into the tree
   * according to its rectangle defined by \p ll, \p ur.
   */
  void insert(const TKey& key,
              const math::vector2<TCoord>& ll,
              const math::vector2<TCoord>& ur) {
    box_type value(point_type(ll.x(), ll.y()), point_type(ur.x(), ur.y()));
    m_impl.insert(std::make_pair(value, key));
  }

  /**
   * \brief Remove the \p key and its associated rectangle from the tree.
   *
   * \return The # of items removed (0 or 1).
   */
  size_t remove(const TKey& key) {
    std::vector<value_type> victims;
    std::copy_if(m_impl.begin(),
                 m_impl.end(),
                 std::back_inserter(victims),
                 [key](const value_type& pair) { return key == pair.second; });
    if (victims.empty()) {
      return 0;
    }
    return m_impl.remove(victims.begin(), victims.end());
  }

 private:
  /* clang-format off */
  tree_type m_impl{};
  /* clang-format on */

 public:
  RCPPSW_WRAP_DECLDEF(insert, m_impl);
  RCPPSW_WRAP_DECLDEF(begin, m_impl, const);
  RCPPSW_WRAP_DECLDEF(end, m_impl, const);
  RCPPSW_WRAP_DECLDEF(size, m_impl, const);
};

NS_END(ds, rcppsw);

#endif /* INCLUDE_RCPPSW_DS_RTREE2D_HPP_ */
