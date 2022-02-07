/**
 * \file hgrid3D.hpp
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

#ifndef INCLUDE_RCPPSW_DS_GRAPH_HGRID3D_HPP_
#define INCLUDE_RCPPSW_DS_GRAPH_HGRID3D_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <boost/graph/depth_first_search.hpp>
#include <boost/graph/filtered_graph.hpp>
#include <boost/property_map/dynamic_property_map.hpp>
#include <vector>
#include <utility>

#include "rcppsw/ds/graph/graph.hpp"
#include "rcppsw/math/vector3.hpp"
#include "rcppsw/patterns/decorator/decorator.hpp"
#include "rcppsw/ds/graph/hgrid3D_spec.hpp"
#include "rcppsw/ds/graph/hgrid3D_view.hpp"
#include "rcppsw/ds/graph/hgrid3D_view_filter.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ds, graph);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class hgrid3D
 * \ingroup ds graph
 *
 * \brief A heterogeneous gridded graph (i.e., a basic grid graph with some
 * vertices missing) where edge lengths have structural relevance; that is, if
 * two vertices (u,v) are 3 units apart, then there are two vertices along the
 * path (u,v) which would be present in a basic grid graph which are missing
 * here. Useful for representing distances and such in the real world.
 */
template<typename TSpecType>
class hgrid3D : public rpdecorator::decorator<typename TSpecType::bgl_impl_type> {
 public:
  using spec_type = TSpecType;
  using bgl_impl_type = typename spec_type::bgl_impl_type;
  using vertex_coord_type = typename spec_type::vertex_coord_type;

  using decorator_type = typename rpdecorator::decorator<bgl_impl_type>::decorator_type;
  using decoratee_type = typename rpdecorator::decorator<bgl_impl_type>::decoratee_type;
  using decorator_type::decoratee;

  /* for use in creating graph views */
  using view_type = hgrid3D_view<spec_type>;

  RCPPSW_DECORATE_DECL(vertex_descriptor);
  RCPPSW_DECORATE_DECL(edge_descriptor);
  RCPPSW_DECORATE_DECL(directed_category);
  RCPPSW_DECORATE_DECL(edge_parallel_category);
  RCPPSW_DECORATE_DECL(traversal_category);
  RCPPSW_DECORATE_DECL(vertex_iterator);

  using vertex_property_type = typename spec_type::vertex_property_type;
  using edge_property_type = typename spec_type::edge_property_type;

  hgrid3D(void) = default;
  hgrid3D(const hgrid3D&) = default;

  RCPPSW_DECORATE_DECLDEF(operator[], const);
  RCPPSW_DECORATE_DECLDEF_STATIC(rdgraph, find, const);
  RCPPSW_DECORATE_DECLDEF_STATIC(rdgraph, contains, const);
  RCPPSW_DECORATE_DECLDEF_STATIC(rdgraph, vertices, const);
  RCPPSW_DECORATE_DECLDEF_STATIC(rdgraph, adjacent_vertices, const);
  RCPPSW_DECORATE_DECLDEF_STATIC(rdgraph, out_edges, const);
  RCPPSW_DECORATE_DECLDEF_STATIC(rdgraph, out_degree, const);
  RCPPSW_DECORATE_DECLDEF_STATIC(rdgraph, target, const);
  RCPPSW_DECORATE_DECLDEF_STATIC(rdgraph, n_vertices, const);

  RCPPSW_DECORATE_DECLDEF(operator[]);
  RCPPSW_DECORATE_DECLDEF_STATIC(rdgraph, find);
  RCPPSW_DECORATE_DECLDEF_STATIC(rdgraph, vertices);
  RCPPSW_DECORATE_DECLDEF_STATIC(rdgraph, adjacent_vertices);
  RCPPSW_DECORATE_DECLDEF_STATIC(rdgraph, target);

  view_type subgraph(const vertex_descriptor& start,
                     const rtypes::manhattan_dist& max_dist,
                     boost::optional<rmath::vector3z> axis = boost::none) const {
    auto filter_data = detail::hgrid3D_view_filter<spec_type>()(decoratee(),
                                                                start,
                                                                max_dist,
                                                                axis);
    /*
     * Predicates MUST be default constructible, so we wrap the actual predicate
     * functor which takes arguments here.
     */
    auto vertex_filter = std::bind(&hgrid3D_view_filter_data<spec_type>::vertex_filter,
                                   filter_data.get(),
                                   std::placeholders::_1);

    auto edge_filter = std::bind(&hgrid3D_view_filter_data<spec_type>::edge_filter,
                                 filter_data.get(),
                                 std::placeholders::_1);

    using view_impl_type = typename spec_type::template bgl_view_impl_type<
      std::function<bool(typename TSpecType::bgl_impl_type::edge_descriptor)>,
      std::function<bool(typename TSpecType::bgl_impl_type::vertex_descriptor)>
      >;

    auto view = view_impl_type(decoratee(), edge_filter, vertex_filter);
    return view_type(view, std::move(filter_data));
  }
};


NS_END(graph, ds, rcppsw);

#endif /* INCLUDE_RCPPSW_DS_GRAPH_HGRID3D_HPP_ */
