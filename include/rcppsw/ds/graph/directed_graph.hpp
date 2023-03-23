/**
 * \file directed_graph.hpp
 *
 * \copyright 2022 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "rcppsw/ds/graph/graph.hpp"
#include "rcppsw/ds/graph/directed_graph_spec.hpp"
#include "rcppsw/patterns/decorator/decorator.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace rcppsw::ds::graph {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class directed_graph
 * \ingroup ds graph
 *
 * \brief A simple directed (not necessarily acyclic) graph. Uses boost::graph
 * adjacency list representation.
 */
template <typename TSpecType>
class directed_graph : public rpdecorator::decorator<
  typename TSpecType::bgl_impl_type
  > {
 public:
  using spec_type = TSpecType;
  using bgl_impl_type = typename spec_type::bgl_impl_type;

  using decorator_type = typename rpdecorator::decorator<
    bgl_impl_type>::decorator_type;
  using decoratee_type = typename rpdecorator::decorator<
    bgl_impl_type>::decoratee_type;
  using decorator_type::decoratee;

  RCPPSW_DECORATE_DECL(vertex_descriptor);
  RCPPSW_DECORATE_DECL(edge_descriptor);
  RCPPSW_DECORATE_DECL(directed_category);
  RCPPSW_DECORATE_DECL(edge_parallel_category);
  RCPPSW_DECORATE_DECL(traversal_category);
  RCPPSW_DECORATE_DECL(vertex_iterator);

  using vertex_property_type = typename spec_type::vertex_property_type;
  using edge_property_type = typename spec_type::edge_property_type;

  directed_graph(void) = default;
  directed_graph(const directed_graph&) = default;

  RCPPSW_DECORATE_DECLDEF(operator[], const);
  RCPPSW_DECORATE_DECLDEF_STATIC(rdgraph, vertices, const);
  RCPPSW_DECORATE_DECLDEF_STATIC(rdgraph, find, const);
  RCPPSW_DECORATE_DECLDEF_STATIC(rdgraph, adjacent_vertices, const);
  RCPPSW_DECORATE_DECLDEF_STATIC(rdgraph, out_edges, const);
  RCPPSW_DECORATE_DECLDEF_STATIC(rdgraph, target, const);
  RCPPSW_DECORATE_DECLDEF_STATIC(rdgraph, n_vertices, const);

  RCPPSW_DECORATE_DECLDEF(operator[]);
  RCPPSW_DECORATE_DECLDEF_STATIC(rdgraph, add_vertex);
  RCPPSW_DECORATE_DECLDEF_STATIC(rdgraph, remove_vertex);
  RCPPSW_DECORATE_DECLDEF_STATIC(rdgraph, add_edge);
  RCPPSW_DECORATE_DECLDEF_STATIC(rdgraph, find);
  RCPPSW_DECORATE_DECLDEF_STATIC(rdgraph, vertices);
  RCPPSW_DECORATE_DECLDEF_STATIC(rdgraph, adjacent_vertices);
  RCPPSW_DECORATE_DECLDEF_STATIC(rdgraph, target);
};

} /* namespace rcppsw::ds::graph */
