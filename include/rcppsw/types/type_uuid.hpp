/**
 * \file type_uuid.hpp
 *
 * \copyright 2019 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/rcppsw.hpp"
#include "rcppsw/types/named_type.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace rcppsw::types {

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
class type_uuid final : public rtypes::named_type<int, struct type_uuid_tag> {
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

namespace constants {

/**
 * \brief Null identifier to indicate an entity does not have an ID associated
 * with it.
 */
extern type_uuid kNoUUID;

} /* namespace constants */

} /* namespace rcppsw::types::constants */
