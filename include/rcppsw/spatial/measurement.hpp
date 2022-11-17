/**
 * \file measurement.hpp
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
        ER_CLIENT_INIT("rcppsw.types.measurement") {
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
