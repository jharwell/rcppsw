/**
 * \file hgrid3D_spec.hpp
 *
 * \copyright 2021 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <boost/graph/filtered_graph.hpp>
#include <boost/graph/adjacency_list.hpp>

#include "rcppsw/rcppsw.hpp"
#include "rcppsw/ds/graph/hgrid3D_vertex_property.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace rcppsw::ds::graph {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
template<typename TVertexPropertyType, typename TEdgePropertyType>
struct hgrid3D_spec {
  static_assert(std::is_base_of<hgrid3D_vertex_property,
                TVertexPropertyType>::value,
                "TVertexPropertyType is not derived from vertex_property_type");

  /* The type of the (X,Y,Z) coordinates attached to each vertex */
  using vertex_coord_type = decltype(hgrid3D_vertex_property::coord);

  /* Container type for the edge-list for each vertex */
  using vertex_edge_list_type = boost::vecS;

  /* Container type for the vertex-list of the graph*/
  using vertex_list_type = boost::vecS;

  /* The directedness of the graph */
  using directedness_type = boost::undirectedS;

  /* Vertex properties type */
  using vertex_property_type = TVertexPropertyType;

  /* Edge properties type  */
  using edge_property_type = TEdgePropertyType;

  /* Graph-level properties type */
  using graph_property_type = boost::no_property;

  /* Container type  the edge-list for the graph */
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

  template<typename TEdgePredicateType, typename TVertexPredicateType>
  using bgl_view_impl_type = boost::filtered_graph<
    bgl_impl_type,
    TEdgePredicateType,
    TVertexPredicateType
    >;
};

} /* namespace rcppsw::ds::graph */

