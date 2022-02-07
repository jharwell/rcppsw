/**
 * \file graphml.hpp
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

#ifndef INCLUDE_RCPPSW_DS_GRAPH_GRAPHML_HPP_
#define INCLUDE_RCPPSW_DS_GRAPH_GRAPHML_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <boost/graph/graphml.hpp>
#include <boost/property_map/dynamic_property_map.hpp>
#include <filesystem>
#include <fstream>

#include "rcppsw/ds/graph/graph.hpp"
#include "rcppsw/patterns/decorator/decorator.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ds, graph, detail);


/*******************************************************************************
 * Templates
 ******************************************************************************/
/**
 * \brief Determine if \tparam T is derived from \ref rpdecorator::decorator.
 */
template<typename T, typename = void>
struct is_decorator : std::false_type {};

template <typename T>
struct is_decorator<
  T,
  std::void_t<decltype(std::declval<T>().decoratee())>
  > : std::true_type {};


NS_END(detail);

namespace fs = std::filesystem;

/**
 * \brief Generate a property map of arbitrary type over a decorated BGL graph.
 */
template<typename TMapType,
         typename TGraphType,
         RCPPSW_SFINAE_DECLDEF(detail::is_decorator<TGraphType>::value)>
static inline TMapType property_map_gen(
    TGraphType& g,
    std::function<void(TMapType& map,
                       typename TGraphType::decoratee_type& g)> cb) {
  return property_map_gen(g.decoratee(), cb);
}

/**
 * \brief Generate a property map of arbitrary type over a BGL graph.
 */
template<typename TMapType,
         typename TBGLGraphType>
static inline TMapType property_map_gen(
    TBGLGraphType& g,
    std::function<void(TMapType& map, TBGLGraphType& g)> cb) {
  TMapType map;
  cb(map, g);
  return map;
}

/**
 * \brief Read the the contents of a decorated BGL graph from a GraphML file.
 */
template <typename TDecoratorType,
          RCPPSW_SFINAE_DECLDEF(detail::is_decorator<TDecoratorType>::value)>
static inline void read_graphml(const fs::path& path,
                                TDecoratorType& g,
                                boost::dynamic_properties& dp) {
  read_graphml(path, g.decoratee(), dp);
}

/**
 * \brief Read the the contents of a BGL graph from a GraphML file.
 */
template <typename TBGLGraphType,
          RCPPSW_SFINAE_DECLDEF(!detail::is_decorator<TBGLGraphType>::value)>
static inline void read_graphml(const fs::path& path,
                                TBGLGraphType& g,
                                boost::dynamic_properties& dp) {
  auto file = std::ifstream(path, std::ios_base::in);
  boost::read_graphml(file, g, dp);
}

NS_END(graph, ds, rcppsw);

#endif /* INCLUDE_RCPPSW_DS_GRAPH_GRAPHML_HPP_ */
