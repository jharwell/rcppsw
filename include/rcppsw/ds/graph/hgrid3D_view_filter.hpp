/**
 * \file hgrid3D_view_filter.hpp
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

#ifndef INCLUDE_RCPPSW_DS_GRAPH_HGRID3D_VIEW_FILTER_HPP_
#define INCLUDE_RCPPSW_DS_GRAPH_HGRID3D_VIEW_FILTER_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <boost/graph/depth_first_search.hpp>
#include <boost/graph/filtered_graph.hpp>
#include <boost/optional.hpp>
#include <vector>
#include <algorithm>
#include <memory>

#include "rcppsw/ds/graph/graph.hpp"
#include "rcppsw/math/vector3.hpp"
#include "rcppsw/ds/graph/hgrid3D_view_filter_data.hpp"
#include "rcppsw/types/spatial_dist.hpp"
#include "rcppsw/types/manhattan_dist.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ds, graph, detail);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class hgrid3D_view_filter
 * \ingroup ds graph
 *
 * \brief Predicate for filtering \ref hgrid3D into \ref hgrid3D_view objects.
 */
template <typename TSpecType>
struct hgrid3D_view_filter : public rer::client<hgrid3D_view_filter<TSpecType>> {
 public:
  using bgl_impl_type = typename TSpecType::bgl_impl_type;
  using vertex_descriptor = typename bgl_impl_type::vertex_descriptor;
  using edge_descriptor = typename bgl_impl_type::edge_descriptor;
  using vertex_property_type = typename bgl_impl_type::vertex_property_type;
  using vertex_coord_type = typename TSpecType::vertex_coord_type;

  hgrid3D_view_filter(void)
      : ER_CLIENT_INIT("rcppsw.ds.graph.hgrid3D_view_filter") {}

  std::unique_ptr<hgrid3D_view_filter_data<TSpecType>>
  operator()(const bgl_impl_type& graph,
             const vertex_descriptor& start,
             const rtypes::manhattan_dist& max_dist,
             boost::optional<vertex_coord_type> axis) const {
    auto filter_data = std::make_unique<hgrid3D_view_filter_data<TSpecType>>(
        graph[start].coord,
        max_dist,
        max_visited_vertices(max_dist));

    std::vector<boost::default_color_type> colormap(
        max_visited_vertices(max_dist));
    /*
     * We can't use the same distances vector for the filter data and for boost,
     * because of the way DFS visit works. If a node u is valid for inclusion in
     * the filtered graph, but an adjacent node v is not, then the distance from
     *
     * edge set for the valid node u (a kind of off-by-one issue). This causes
     * problems later when iterating over the filtered graph.
     *
     * Quick solution: keep two separate vectors.
     */
    std::vector<int> distances(max_visited_vertices(max_dist));


    auto stop_when = [&](vertex_descriptor vd, const bgl_impl_type&) {
                       /*
                        * Only vertices that are:
                        *
                        * - Have the same {X,Y,Z} coordinate as the starting
                        *   vertex, depending on the axes (maybe).
                        *
                        * - Are within the max distance from the starting
                        *   vertex.
                        *
                        * Are eligible for inclusion in the filtered graph.
                        */
                       bool same_axis = true;
                       if (axis) {
                         same_axis = graph[vd].coord.mask((*axis)) ==
                                     graph[start].coord.mask((*axis));
                       }
                       auto norm = rmath::l1norm(graph[vd].coord,
                                                 graph[start].coord);
                       bool included = same_axis && norm <= max_dist;
                       if (included) {
                         filter_data->update(graph,
                                             vd,
                                             rtypes::manhattan_dist(norm));
                         ER_TRACE("Add vertex: vd=%zu,coord=%s,dist=%zu",
                                  vd,
                                  rcppsw::to_string(graph[vd].coord).c_str(),
                                  norm);
                       } else {
                         ER_TRACE("Reject vertex: vd=%zu,coord=%s,dist=%zu",
                                vd,
                                rcppsw::to_string(graph[vd].coord).c_str(),
                                norm);
                       }
                       return !included;
                     };

    auto dfs_visitor = boost::make_dfs_visitor(boost::record_distances(
        distances.data(),
        boost::on_tree_edge()));

    boost::depth_first_visit(graph,
                             start,
                             dfs_visitor,
                             colormap.data(),
                             stop_when);
    return filter_data;
  }

 private:
  /**
   * \brief The most vertices that could appear in the induced subgraph is
   * (2*max_dist)^3, assuming a basic grid graph. If there is heterogeneity,
   * there will be less.
   */
  static constexpr size_t max_visited_vertices(
      const rtypes::manhattan_dist& max_dist) {
    return static_cast<size_t>(std::pow(2*max_dist.v(), 3));
  }
};

NS_END(detail, graph, ds, rcppsw);

#endif /* INCLUDE_RCPPSW_DS_GRAPH_HGRID3D_VIEW_FILTER_HPP_ */
