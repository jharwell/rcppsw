/**
 * \file type_map.hpp
 *
 * \copyright 2019 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <boost/container/map.hpp>
#include <boost/variant.hpp>
#include <typeindex>

#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces/Decls/Decls
 ******************************************************************************/
NS_START(rcppsw, ds);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class type_map
 * \ingroup ds
 *
 * \brief A map of a set of (possibly incomplete) types, keyed by
 * std::type_index, with the value being a boost::variant. Extremely useful to
 * emulate reflection in C++ (e.g. to map a type to a variant containing actions
 * to take depending on what the actual type in the variant is).
 */
template <typename Typelist>
class type_map
    : public boost::container::
          map<std::type_index, typename boost::make_variant_over<Typelist>::type> {
 public:
  using value_type = typename boost::make_variant_over<Typelist>::type;
  using key_type = std::type_index;
  using map_type = boost::container::map<key_type, value_type>;
  using typename map_type::map;
};

NS_END(ds, rcppsw);
