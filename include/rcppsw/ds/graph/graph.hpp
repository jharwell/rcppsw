/**
 * \file graph.hpp
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

#ifndef INCLUDE_RCPPSW_DS_GRAPH_GRAPH_HPP_
#define INCLUDE_RCPPSW_DS_GRAPH_GRAPH_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <boost/graph/adjacency_list.hpp>
#include <boost/optional.hpp>
#include <boost/range/adaptor/transformed.hpp>

#include "rcppsw/rcppsw.hpp"
#include "rcppsw/math/vector3.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ds, graph, detail);

template <typename TBGLGraphType>
using find_result_type = typename std::add_pointer<
  decltype(std::declval<TBGLGraphType>().operator[](std::declval<typename TBGLGraphType::vertex_descriptor>()))
  >::type;

NS_END(detail);

/*******************************************************************************
 * Templates
 ******************************************************************************/

/**
 * \brief Get the vertices in the specified graph, as an iterator range.
 *
 * \note We can't use boost::make_iterator_range here, because that doesn't work
 * with filtered_graph types, for whatever reason.
 */
template <typename TBGLGraphType>
static inline auto vertices(const TBGLGraphType& g) -> decltype(boost::vertices(std::declval<const TBGLGraphType>())) {
  return boost::vertices(g);
}

template <typename TBGLGraphType>
static inline auto vertex_properties(const TBGLGraphType& g) {
  auto bundle_map = boost::get(boost::vertex_bundle, g);
  auto accessor = [&bundle_map](typename TBGLGraphType::vertex_descriptor vd) -> auto&{
                    return bundle_map[vd];
                  };
  return boost::vertices(g) | boost::adaptors::transformed(accessor);
}

template <typename TBGLGraphType>
static inline auto out_edges(const TBGLGraphType& g,
                             const typename TBGLGraphType::vertex_descriptor& v) {
  return boost::out_edges(v, g);
}

template <typename TBGLGraphType>
static inline auto out_degree(const TBGLGraphType& g,
                              const typename TBGLGraphType::vertex_descriptor& v) {
  return boost::out_degree(v, g);
}

template <typename TBGLGraphType>
static inline auto target(const TBGLGraphType& g,
                          const typename TBGLGraphType::edge_descriptor& e) {
  return boost::target(e, g);
}

template <typename TBGLGraphType>
static inline auto adjacent_vertices(const TBGLGraphType& g,
                                     typename TBGLGraphType::vertex_descriptor v) {
  return boost::adjacent_vertices(v, g);
}

template <typename TBGLGraphType>
static inline auto add_vertex(TBGLGraphType& g) {
  return boost::add_vertex(g);
}
template <typename TBGLGraphType>
static inline auto remove_vertex(TBGLGraphType& g,
                                 typename TBGLGraphType::vertex_descriptor v) {
  return boost::remove_vertex(v, g);
}

template <typename TBGLGraphType>
static inline auto add_edge(TBGLGraphType& g,
                            typename TBGLGraphType::vertex_descriptor u,
                            typename TBGLGraphType::vertex_descriptor v) {
  return boost::add_edge(u, v, g);
}

/**
 * \brief Search for the vertex with coordinates \p c in \p g.
 *
 * \return The descriptor of the matching vertex, or -1 if not found.
 */
template <typename TBGLGraphType, typename TCoordType>
static inline boost::optional<typename TBGLGraphType::vertex_descriptor> find(
    const TBGLGraphType& g, const TCoordType& c) {

  auto [v_i, v_end] = boost::vertices(g);

  /* std::find_if does not seem to work with filtered_graph objects... */
  for (auto it = v_i; it != v_end; ++it) {
    if (g[*it].coord == c) {
      return boost::make_optional(*it);
    }
  } /* (it...) */
  return boost::none;
}

/**
 * \brief Determine if \p g contains a vertex with coordinates \p c.
 */
template <typename TBGLGraphType>
static inline bool contains(const TBGLGraphType& g, const rmath::vector3z& c) {
  return boost::none != rdgraph::find(g, c);
}

/**
 * \brief Get the # of vertices in \p g.
 */
template <typename TBGLGraphType>
static inline size_t n_vertices(const TBGLGraphType& g) {
  return boost::num_vertices(g);
}

NS_END(graph, ds, rcppsw);

#endif /* INCLUDE_RCPPSW_DS_GRAPH_GRAPH_HPP_ */
