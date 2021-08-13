/**
 * \file hgrid3D_view_builder.hpp
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

#ifndef INCLUDE_RCPPSW_DS_GRAPH_HGRID3D_VIEW_BUILDER_HPP_
#define INCLUDE_RCPPSW_DS_GRAPH_HGRID3D_VIEW_BUILDER_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <boost/graph/depth_first_search.hpp>
#include <boost/graph/filtered_graph.hpp>
#include <boost/optional.hpp>
#include <vector>
#include <algorithm>

#include "rcppsw/ds/graph/graph.hpp"
#include "rcppsw/math/vector3.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ds, graph, detail);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class hgrid3D_view_builder
 * \ingroup ds graph
 *
 * \brief Predicate for filtering \ref hgrid3D into \ref hgrid3D_view objects.
 */
template <typename TSpecType>
struct hgrid3D_view_builder {
 public:
  using bgl_impl_type = typename TSpecType::bgl_impl_type;
  using vertex_descriptor = typename bgl_impl_type::vertex_descriptor;
  using edge_descriptor = typename bgl_impl_type::edge_descriptor;

  struct trace_data {
    rmath::vector3z ll{};
    rmath::vector3z ur{};
  };

  hgrid3D_view_builder(const bgl_impl_type& graph,
                       const vertex_descriptor& start,
                       size_t max_dist,
                       boost::optional<rmath::vector3z> axis)
      : mc_max_dist(max_dist),
        m_distances(max_visited_vertices(max_dist)) {
    std::vector<boost::default_color_type> colormap(max_visited_vertices(max_dist));

    /*
     * Record the LL, UR corners of the bounding box for the subgraph to provide
     * efficient computation of graph geometry/bounding box.
     */
    m_trace.ll = m_trace.ur = graph[start].coord;

    auto stop_when = [&](vertex_descriptor vd, const bgl_impl_type&) {
                       m_trace.ll = std::min(m_trace.ll, graph[vd].coord);
                       m_trace.ur = std::max(m_trace.ur, graph[vd].coord);
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
                       bool included = same_axis &&
                                       rmath::l2norm(graph[vd].coord,
                                                     graph[start].coord) <= max_dist;
                       return !included;
                     };

    boost::depth_first_visit(graph,
                             start,
                             make_dfs_visitor(record_distances(m_distances.data(),
                                                               boost::on_tree_edge())),
                             colormap.data(),
                             stop_when);
  }

  bool operator()(edge_descriptor) const { return true; }
  bool operator()(vertex_descriptor vd) const {
    return m_distances[vd] > -1 && m_distances[vd] <= mc_max_dist;
  }

  const trace_data& trace(void) const { return m_trace; }

 private:
  /**
   * \brief The most vertices that could appear in the induced subgraph is
   * (2*max_dist)^3, assuming a basic grid graph. If there is heterogeneity,
   * there will be less.
   */
  static constexpr size_t max_visited_vertices(size_t max_dist) {
    return static_cast<size_t>(std::pow(2*max_dist, 3));
  }

  /* clang-format off */
  const size_t            mc_max_dist;
  std::vector<double>     m_distances{};
  trace_data              m_trace{};
  /* clang-format on */
};

NS_END(detail, graph, ds, rcppsw);

#endif /* INCLUDE_RCPPSW_DS_GRAPH_HGRID3D_VIEW_BUILDER_HPP_ */
