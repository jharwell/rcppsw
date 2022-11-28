/**
 * \file grid_index_map.hpp
 *
 * \copyright 2021 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

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

