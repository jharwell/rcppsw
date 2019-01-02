/**
 * @file type_map.hpp
 *
 * @copyright 2019 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_DS_TYPE_MAP_HPP_
#define INCLUDE_RCPPSW_DS_TYPE_MAP_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <boost/variant.hpp>
#include <boost/container/map.hpp>
#include <typeindex>
#include <utility>

#include "rcppsw/common/common.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ds);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class type_map
 * @ingroup ds
 * @brief A map of a set of (possibly incomplete) types, keyed by
 * std::type_index, with the value being a boost variant. Extremely useful to
 * emulate reflection in C++.
 */

template<typename ...Types>
class type_map : public boost::container::map<std::type_index,
                                              boost::variant<Types...>> {
 public:
  using value_type = boost::variant<Types...>;
  using key_type = std::type_index;
  using map_type = boost::container::map<key_type, value_type>;
  using typename map_type::map;
};

NS_END(ds, rcppsw);

#endif /* INCLUDE_RCPPSW_DS_TYPE_MAP_HPP_ */
