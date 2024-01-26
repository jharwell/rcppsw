/**
 * \file measurement.hpp
 *
 * \copyright 2019 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/er/client.hpp"
#include "rcppsw/types/named_type.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace rcppsw::spatial {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class measurement
 * \ingroup spatial
 *
 * \brief The result of a measurement between elements of a spatial space.
 *
 * It should always be >= 0.
 */
template<typename T, typename Tag>
class measurement : public rtypes::named_type<T, Tag>,
                         public er::client<measurement<T, Tag>> {
 public:
  using value_type = T;
  using rtypes::named_type<T, Tag>::v;
  using rtypes::named_type<T, Tag>::set;
  using rtypes::named_type<T, Tag>::to_str;

  explicit measurement(const T& value, bool check_psd = true)
      : rtypes::named_type<T, Tag>(value),
        ER_CLIENT_INIT() {
    ER_ASSERT(!(check_psd && v() < T{0}),
              "Distance should be positive semi-definite: %s < 0",
              rcppsw::to_string(v()).c_str());
  }

  ~measurement(void) override = default;
  measurement(const measurement&) = default;


  bool operator<(const measurement& rhs) const { return v() < rhs.v(); }
  bool operator>(const measurement& rhs) const { return v() > rhs.v(); }
  bool operator>=(const measurement& rhs) const { return v() >= rhs.v(); }
  bool operator>=(T rhs) const { return v() >= rhs; }
  bool operator<=(const measurement& rhs) const { return v() <= rhs.v(); }
  bool operator<=(T rhs) const { return v() <= rhs; }
  bool operator>(T rhs) const { return v() > rhs; }
};

} /* namespace rcppsw::spatial */
