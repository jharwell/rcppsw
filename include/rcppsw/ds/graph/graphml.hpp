/**
 * \file graphml.hpp
 *
 * \copyright 2021 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

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
namespace rcppsw::ds::graph::detail {


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


} /* namespace detail */

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

} /* namespace rcppsw::ds::graph */

