/**
 * \file context.hpp
 *
 * \copyright 2022 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/types/named_type.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace rcppsw::metrics {

/*******************************************************************************
 * Type Definitions
 ******************************************************************************/
/**
 * \class context
 * \ingroup metrics
 *
 * \brief A context associated with some metrics.
 *
 * Collecting the same metrics from the same objects in different contexts
 * (e.g., doing thing A and doing thing B) and reporting the results separately
 * may be desirable.
 */
class context : public rtypes::named_type<int, struct context_tag> {
 public:
  using named_type<int, context_tag>::named_type;

  context(const context&) = default;

  context& operator=(const context& other) {
    set(other.v());
    return *this;
  }

  bool operator!=(const context& other) const { return v() != other.v(); }
  bool operator==(const context& other) const { return v() == other.v(); }

 private:
  /* clang-format off */
  /* clang-format on */
};

namespace constants {
/**
 * \brief Null identifier to indicate an unset value.
 */
extern context kNoContext;
} /* namespace constants */

} /* namespace rcppsw::metrics */
