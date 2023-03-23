/**
 * \file creatable_collector_set.hpp
 *
 * \copyright 2021 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

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
namespace rcppsw::metrics {

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
 *
 * - Which sink the collector is associated with (only necessary if the same
 *   collector will be used with multiple sinks). If omitted for a single
 *   collector which has multiple sinks, the behavior is undefined.
 */
struct creatable_collector_spec {
  creatable_collector_spec(const std::type_index& collector_id_in,
                           const std::string& input_name_in,
                           const std::string& scoped_name_in,
                           const rmetrics::output_mode& valid_modes_in,
                           std::type_index sink_id_in = std::type_index(typeid(nullptr)))
      : collector_id(collector_id_in),
        input_name(input_name_in),
        scoped_name(scoped_name_in),
        valid_modes(valid_modes_in),
        sink_id(sink_id_in) {}

  explicit creatable_collector_spec(const std::type_index& collector_id_in)
      : collector_id(collector_id_in) {}

  /* clang-format off */
  std::type_index       collector_id;
  std::string           input_name{};
  std::string           scoped_name{};
  rmetrics::output_mode valid_modes{rmetrics::output_mode::ekNONE};
  std::type_index       sink_id{typeid(nullptr)};
  /* clang-format on */
};

namespace detail {

/**
 * \brief Comparator for \ref set_value_type objects within the \ref
 * creatable_collector_set.
 */
struct creatable_collector_set_comparator {
  bool operator()(const creatable_collector_spec& lhs,
                  const creatable_collector_spec& rhs) const {
    return lhs.collector_id < rhs.collector_id;
  }
};

} /* namespace detail */

/**
 * \brief Set of \ref set_value_type in which duplicates are allowed, because
 * when we compare elements, we only use the typeid as the key, which can be
 * the same between collectors, even if the other parts of each element are
 * different.
 */
using creatable_collector_set = std::multiset<creatable_collector_spec,
                                              detail::creatable_collector_set_comparator>;

} /* namespace rcppsw::metrics */
