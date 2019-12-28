/**
 * \file type_uuid.hpp
 *
 * \copyright 2019 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_TYPES_TYPE_UUID_HPP_
#define INCLUDE_RCPPSW_TYPES_TYPE_UUID_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/rcppsw.hpp"
#include "rcppsw/types/named_type.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, types);

/*******************************************************************************
 * Type Definitions
 ******************************************************************************/
/**
 * \class type_uuid
 * \ingroup types
 *
 * \brief A UUID class for uniquely identifying instances of a specific type. No
 * guarantees should be made between the uniqueness of UUIDs between entities of
 * different types, hence the "type" part of the name. Also forces comparisons
 * between IDs for different instances of the same type to be explicit, AND
 * disallows arbitrary/implicit manipulations of integer instance IDs.
 *
 * This class is constructable, assignable, and comparable.
 */
class type_uuid : public rtypes::named_type<int, struct type_uuid_tag> {
 public:
  using named_type<int, type_uuid_tag>::named_type;

  type_uuid(const type_uuid&) = default;
  type_uuid& operator=(const type_uuid& other) {
    set(other.v());
    return *this;
  }

  /* to enable use in \ref std::map and the like */
  bool operator<(const type_uuid& other) const { return v() < other.v(); }
  bool operator==(const type_uuid& other) const { return v() == other.v(); }
  bool operator!=(const type_uuid& other) const { return v() != other.v(); }
};

NS_START(constants);

/**
 * \brief Null identifier to indicate an entity does not have an ID associated
 * with it.
 */
static type_uuid kNoUUID = type_uuid(-1);

NS_END(constants, types, rcppsw);

#endif /* INCLUDE_RCPPSW_TYPES_TYPE_UUID_HPP_ */
