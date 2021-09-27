/**
 * \file hgrid3D_view_filter_data.hpp
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

#ifndef INCLUDE_RCPPSW_DS_GRAPH_HGRID3D_VIEW_FILTER_DATA_HPP_
#define INCLUDE_RCPPSW_DS_GRAPH_HGRID3D_VIEW_FILTER_DATA_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <algorithm>

#include "rcppsw/rcppsw.hpp"
#include "rcppsw/math/vector3.hpp"
#include "rcppsw/types/manhattan_dist.hpp"
#include "rcppsw/ds/graph/grid_index_map.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ds, graph);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class hgrid3D_view_filter_data
 * \ingroup ds graph
 *
 * \brief The data gathered during building the \ref hgrid3D_view.
 */
template <typename TSpecType>
class hgrid3D_view_filter_data : public rer::client<hgrid3D_view_filter_data<TSpecType>> {
 public:
  using bgl_impl_type = typename TSpecType::bgl_impl_type;
  using vertex_descriptor = typename bgl_impl_type::vertex_descriptor;
  using edge_descriptor = typename bgl_impl_type::edge_descriptor;
  using vertex_property_type = typename bgl_impl_type::vertex_property_type;

  hgrid3D_view_filter_data(const rmath::vector3z& center,
                          const rtypes::manhattan_dist& max_dist,
                          size_t max_vertices)
      : ER_CLIENT_INIT("rcppsw.ds.graph.hgrid3D_view_filter_data"),
        mc_max_dist(max_dist),
        mc_center(center),
        /*
         * Record the LL, UR corners of the bounding box for the subgraph to
         * provide efficient computation of graph geometry/bounding box.
         */
        m_ll(mc_center),
        m_ur(mc_center),
        /*
         * All vertices within range will be marked with distance > 0 during the
         * filter, so set all distances to -1 so that after build excluded
         * vertices can be filtered out.
         */
        m_distances(max_vertices, rtypes::manhattan_dist(-1, false)) {}


  bool edge_filter(edge_descriptor) const { return true; }
  bool vertex_filter(vertex_descriptor vd) const {
    ER_TRACE("Evaluate vertex filter: vd=%zu,dist=%d,max_dist=%d -> %d",
             vd,
             m_distances[vd].v(),
             mc_max_dist.v(),
             m_distances[vd] > -1 && m_distances[vd] <= mc_max_dist);
    return m_distances[vd] > -1 && m_distances[vd] <= mc_max_dist;
  }

  void update(const bgl_impl_type& g,
              vertex_descriptor vd,
              const rtypes::manhattan_dist& dist) {
    m_ll = std::min(m_ll, g[vd].coord, rmath::vector3z::componentwise_compare());
    m_ur = std::max(m_ur, g[vd].coord, rmath::vector3z::componentwise_compare());
    m_ul = rmath::vector3z(m_ll.x(),
                           std::max(m_ul.y(), g[vd].coord.y()),
                           std::max(m_ul.z(), g[vd].coord.z()));
    m_lr = rmath::vector3z(std::max(m_lr.x(), g[vd].coord.x()),
                           m_ll.y(),
                           std::min(m_lr.z(), g[vd].coord.z()));
    m_distances[vd] = dist;
    m_lookup[g[vd].coord] = &g[vd];
  }
  const auto& ll(void) const { return m_ll; }
  const auto& ul(void) const { return m_ul; }
  const auto& ur(void) const { return m_ur; }
  const auto& lr(void) const { return m_lr; }

  size_t n_vertices(void) const { return m_lookup.size(); }

  std::vector<rtypes::manhattan_dist>* distances(void) { return &m_distances; }

  const auto& center(void) const { return mc_center; }
  auto* lookup(void) { return &m_lookup; }
  const auto* lookup(void) const { return &m_lookup; }

 private:
  const rtypes::manhattan_dist        mc_max_dist;
  const rmath::vector3z               mc_center;

  size_t                              m_n_vertices{0};
  rmath::vector3z                     m_ll{};
  rmath::vector3z                     m_ul{};
  rmath::vector3z                     m_ur{};
  rmath::vector3z                     m_lr{};
  std::vector<rtypes::manhattan_dist> m_distances;

  grid_index_map<rmath::vector3z,
                 const vertex_property_type*,
                 rmath::vector3z::key_compare>  m_lookup{};

};

NS_END(graph, ds, rcppsw);

#endif /* INCLUDE_RCPPSW_DS_GRAPH_HGRID3D_VIEW_FILTER_DATA_HPP_ */
