/**
 * \file grid_index_map.hpp
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

#ifndef INCLUDE_RCPPSW_DS_GRAPH_GRID_INDEX_MAP_HPP_
#define INCLUDE_RCPPSW_DS_GRAPH_GRID_INDEX_MAP_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <map>
#include <functional>

#include "rcppsw/patterns/decorator/decorator.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ds, graph);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class grid_index_map
 * \ingroup graph ds
 *
 * \brief Maps a coordinate (e.g., XYZ tuple) to a vertex property. Used for
 * fast queries of "Does this graph contain this vertex", because in general
 * there is no way to answer that query other than to search the whole graph.
 */
template <typename TGrid,
          typename TVertex,
          typename TCompare = std::less<TGrid>>
class grid_index_map : public rpdecorator::decorator<
  std::map<TGrid, TVertex, TCompare>
  > {
 public:
  using decorator_type = typename rpdecorator::decorator<
   std::map<TGrid, TVertex, TCompare>
   >::decorator_type;
  using decoratee_type = typename decorator_type::decoratee_type;

  using decorator_type::decoratee;

  RCPPSW_DECORATE_CT();

  RCPPSW_DECORATE_DECLDEF(insert);
  RCPPSW_DECORATE_DECLDEF(operator[]);
  RCPPSW_DECORATE_DECLDEF(find, const);
  RCPPSW_DECORATE_DECLDEF(find);
  RCPPSW_DECORATE_DECLDEF(begin);
  RCPPSW_DECORATE_DECLDEF(end);
  RCPPSW_DECORATE_DECLDEF(begin, const);
  RCPPSW_DECORATE_DECLDEF(end, const);
  RCPPSW_DECORATE_DECLDEF(size, const);
};

NS_END(graph, ds, rcppsw);

#endif /* INCLUDE_RCPPSW_DS_GRAPH_GRID_INDEX_MAP_HPP_ */
