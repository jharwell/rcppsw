/**
 * \file creatable_collector_set.hpp
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

#ifndef INCLUDE_RCPPSW_METRICS_CREATABLE_COLLECTOR_SET_HPP_
#define INCLUDE_RCPPSW_METRICS_CREATABLE_COLLECTOR_SET_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <tuple>
#include <set>
#include <typeindex>
#include <string>
#include <memory>

#include "rcppsw/metrics/output_mode.hpp"
#include "rcppsw/metrics/base_sink.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, metrics);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \brief The data needed to create an enabled collector.
 */
template<typename TSink>
struct collector_registration_spec {
  bool                   is_enabled{false};
  std::unique_ptr<TSink> sink{};
};

/**
 * \brief Each entry in the set of collectors that CAN be created (if they are
 * actually created dependent on configuration) has:
 *
 * - The typeid of the collector, so that functions templated on collector
 *   type can figure out the correct item in the set to read from.
 *
 * - The name of the collector in the input src (e.g. the XML attribute name).
 *
 * - The scoped name of the collector that will be used to refer to the
 *   created collector during simulation.
 *
 * - The set of output modes that are valid for the collector.
 */
struct creatable_collector_spec {
  std::type_index id;
  std::string input_name{};
  std::string scoped_name{};
  rmetrics::output_mode valid_modes{rmetrics::output_mode::ekNONE};
};

NS_START(detail);

/**
 * \brief Comparator for \ref set_value_type objects within the \ref
 * creatable_collector_set.
 */
struct creatable_collector_set_comparator {
  bool operator()(const creatable_collector_spec& lhs,
                  const creatable_collector_spec& rhs) const {
    return lhs.id < rhs.id;
  }
};

NS_END(detail);

/**
 * \brief Set of \ref set_value_type in which duplicates are allowed, because
 * when we compare elements, we only use the typeid as the key, which can be
 * the same between collectors, even if the other parts of each element are
 * different.
 */
using creatable_collector_set = std::multiset<creatable_collector_spec,
                                              detail::creatable_collector_set_comparator>;

NS_END(metrics, rcppsw);

#endif /* INCLUDE_RCPPSW_METRICS_CREATABLE_COLLECTOR_SET_HPP_ */
