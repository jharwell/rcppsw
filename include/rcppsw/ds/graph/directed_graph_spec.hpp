/**
 * \file directed_graph_spec.hpp
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

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <boost/graph/adjacency_list.hpp>

#include "rcppsw/rcppsw.hpp"
#include "rcppsw/ds/graph/base_vertex_property.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ds, graph);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
template<typename TVertexPropertyType, typename TEdgePropertyType>
struct directed_graph_spec {
  static_assert(std::is_base_of<base_vertex_property,
                TVertexPropertyType>::value,
                "TVertexPropertyType is not derived from base_vertex_property");

  /* Container type for the edge-list for each vertex */
  using vertex_edge_list_type = boost::vecS;

  /* Container type for the vertex-list of the graph*/
  using vertex_list_type = boost::listS;

  /* The directedness of the graph */
  using directedness_type = boost::directedS;

  /* Vertex properties type */
  using vertex_property_type = TVertexPropertyType;

  /* Edge properties type  */
  using edge_property_type = TEdgePropertyType;

  /* Graph-level properties type */
  using graph_property_type = boost::no_property;

  /* Container type the edge-list for the graph */
  using graph_edge_list_type = boost::listS;

  using bgl_impl_type = boost::adjacency_list<
    vertex_edge_list_type,
    vertex_list_type,
    directedness_type,
    vertex_property_type,
    edge_property_type,
    graph_property_type,
    graph_edge_list_type
    >;
};

NS_END(graph, ds, rcppsw);
