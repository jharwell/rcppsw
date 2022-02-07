/**
 * \file distance_measure.hpp
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

#ifndef INCLUDE_RCPPSW_TYPES_DISTANCE_MEASURE_HPP_
#define INCLUDE_RCPPSW_TYPES_DISTANCE_MEASURE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/er/client.hpp"
#include "rcppsw/types/named_type.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, types);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class distance_measure
 * \ingroup types
 *
 * \brief Specifies a distance between two points.
 */
template<typename T, typename Tag>
class distance_measure : public named_type<T, Tag>,
                         public er::client<distance_measure<T, Tag>> {
 public:
  using value_type = T;
  using named_type<T, Tag>::v;
  using named_type<T, Tag>::set;
  using named_type<T, Tag>::to_str;

  explicit distance_measure(const T& value, bool check_psd = true)
      : named_type<T, Tag>(value),
        ER_CLIENT_INIT("rcppsw.types.distance_measure") {
    ER_ASSERT(!(check_psd && v() < T{0}),
              "Distance should be positive semi-definite: %s < 0",
              rcppsw::to_string(v()).c_str());
  }

  ~distance_measure(void) override = default;
  distance_measure(const distance_measure&) = default;


  bool operator<(const distance_measure& rhs) const { return v() < rhs.v(); }
  bool operator>(const distance_measure& rhs) const { return v() > rhs.v(); }
  bool operator>=(const distance_measure& rhs) const { return v() >= rhs.v(); }
  bool operator>=(T rhs) const { return v() >= rhs; }
  bool operator<=(const distance_measure& rhs) const { return v() <= rhs.v(); }
  bool operator<=(T rhs) const { return v() <= rhs; }
  bool operator>(T rhs) const { return v() > rhs; }
};

NS_END(types, rcppsw);

#endif /* INCLUDE_RCPPSW_TYPES_DISTANCE_MEASURE_HPP_ */
