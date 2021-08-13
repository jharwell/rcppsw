/**
 * \file hgrid3D_view.hpp
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

#ifndef INCLUDE_RCPPSW_DS_GRAPH_HGRID3D_VIEW_HPP_
#define INCLUDE_RCPPSW_DS_GRAPH_HGRID3D_VIEW_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <boost/graph/filtered_graph.hpp>
#include <memory>
#include <utility>
#include <map>

#include "rcppsw/ds/graph/graph.hpp"
#include "rcppsw/patterns/decorator/decorator.hpp"
#include "rcppsw/ds/graph/hgrid3D_spec.hpp"
#include "rcppsw/ds/graph/hgrid3D_view_filter_data.hpp"
#include "rcppsw/math/bounding_box.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ds, graph);

template <typename TSpecType>
using hgrid3D_view_edge_filter_type = std::function<bool(typename TSpecType::bgl_impl_type::edge_descriptor)>;
template <typename TSpecType>
using hgrid3D_view_vertex_filter_type = std::function<bool(typename TSpecType::bgl_impl_type::vertex_descriptor)>;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class hgrid3D_view
 * \ingroup ds graph
 *
 * \brief A view of a \ref hgrid3D using boost::filtered_graph.
 */
template<typename TSpecType>
class hgrid3D_view : public rpdecorator::decorator<
  typename TSpecType::template bgl_view_impl_type<
    hgrid3D_view_edge_filter_type<TSpecType>,
    hgrid3D_view_vertex_filter_type<TSpecType>
    >
  > {
 public:
  using spec_type = TSpecType;

  using bgl_view_type = typename spec_type::template bgl_view_impl_type<
    hgrid3D_view_edge_filter_type<spec_type>,
    hgrid3D_view_vertex_filter_type<spec_type>
    >;
  using decorator_type = typename rpdecorator::decorator<bgl_view_type>::decorator_type;
  using decoratee_type = typename decorator_type::decoratee_type;
  using decorator_type::decoratee;

  RCPPSW_DECORATE_DECL(vertex_descriptor);
  RCPPSW_DECORATE_DECL(edge_descriptor);
  RCPPSW_DECORATE_DECL(vertex_iterator);

  /* for creating graph view wrapper classes */
  using vertex_coord_type = typename spec_type::vertex_coord_type;
  using vertex_property_type = typename spec_type::vertex_property_type;
  using edge_property_type = typename spec_type::edge_property_type;
  using view_type = bgl_view_type;

  hgrid3D_view(bgl_view_type& view,
               std::unique_ptr<hgrid3D_view_filter_data<spec_type>> data)
      : decorator_type(view),
        mc_bb({std::max(data->ur().x(), data->ul().x())
                - std::min(data->lr().x(), data->ll().x()) + 1,
                std::max(data->ur().y(), data->ul().y())
                - std::min(data->lr().y(), data->ll().y()) + 1,
                std::max(data->ur().z(), data->ul().z())
               - std::min(data->lr().z(), data->ll().z()) + 1},
          data->ll()),
        m_data(std::move(data)) {}

  /* Not copy assignable by default */
  hgrid3D_view(const hgrid3D_view&) = delete;
  hgrid3D_view& operator=(const hgrid3D_view&) = delete;
  hgrid3D_view(hgrid3D_view&& other) = default;

  hgrid3D_view& operator=(hgrid3D_view&&) = delete;

  RCPPSW_DECORATE_DECLDEF(operator[], const);
  RCPPSW_DECORATE_DECLDEF_STATIC(rdgraph, find, const);
  RCPPSW_DECORATE_DECLDEF_STATIC(rdgraph, vertices, const);
  RCPPSW_DECORATE_DECLDEF_STATIC(rdgraph, adjacent_vertices, const);
  RCPPSW_DECORATE_DECLDEF_STATIC(rdgraph, out_edges, const);
  RCPPSW_DECORATE_DECLDEF_STATIC(rdgraph, target, const);

  RCPPSW_DECORATE_DECLDEF(operator[]);
  RCPPSW_DECORATE_DECLDEF_STATIC(rdgraph, find);
  RCPPSW_DECORATE_DECLDEF_STATIC(rdgraph, contains);
  RCPPSW_DECORATE_DECLDEF_STATIC(rdgraph, vertices);
  RCPPSW_DECORATE_DECLDEF_STATIC(rdgraph, adjacent_vertices);
  RCPPSW_DECORATE_DECLDEF_STATIC(rdgraph, out_edges);
  RCPPSW_DECORATE_DECLDEF_STATIC(rdgraph, target);

  const vertex_property_type* lookup(const rmath::vector3z& c) const {
    auto it = m_data->lookup()->find(c);
    if (m_data->lookup()->end() != it) {
      return it->second;
    }
    return nullptr;
  }
  bool contains(const rmath::vector3z& c) const { return nullptr != lookup(c); }

  const auto& bb(void) const { return mc_bb; }
  const auto& central_vertex(void) const { return m_data->center(); }
  size_t n_vertices(void) const { return m_data->n_vertices(); }

 private:
  /* clang-format off */
  const rmath::bounding_box<rmath::vector3z>                 mc_bb;

  /**
   * \brief The view has to own the data that was used to build it, because the
   * boost::filtered_graph filter functions that were passed by using
   * std::bind() during its construction are evaluated later when iterating over
   * vertices, and if the object the bound functions refer to doesn't exist
   * anymore you will get a segfault at best and undefined behavior at worst.
   */
  std::unique_ptr<hgrid3D_view_filter_data<spec_type>>       m_data;
  /* clang-format on */

 public:
  RCPPSW_WRAP_DECLDEF(xsize, mc_bb, const);
  RCPPSW_WRAP_DECLDEF(ysize, mc_bb, const);
  RCPPSW_WRAP_DECLDEF(zsize, mc_bb, const);
  RCPPSW_WRAP_DECLDEF(xspan, mc_bb, const);
  RCPPSW_WRAP_DECLDEF(yspan, mc_bb, const);
  RCPPSW_WRAP_DECLDEF(zspan, mc_bb, const);
  RCPPSW_WRAP_DECLDEF(dims3D, mc_bb, const);
  RCPPSW_WRAP_DECLDEF(center3D, mc_bb, const);
};


NS_END(graph, ds, rcppsw);

#endif /* INCLUDE_RCPPSW_DS_GRAPH_HGRID3D_VIEW_HPP_ */
