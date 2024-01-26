/**
 * \file network_sink_registerer.hpp
 *
 * \copyright 2021 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <memory>
#include <utility>
#include <string>

#include "rcppsw/metrics/config/network_sink_config.hpp"
#include "rcppsw/metrics/network_output_manager.hpp"
#include "rcppsw/utils/maskable_enum.hpp"
#include "rcppsw/metrics/creatable_collector_set.hpp"
#include "rcppsw/metrics/network_sink.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace rcppsw::metrics {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class network_sink_registerer
 * \ingroup metrics detail
 *
 * \brief Register all collectors configured with \ref rmetrics::network_sink with
 * a \ref base_manager or a class derived from it.
 *
 */
class network_sink_registerer :public rer::client<network_sink_registerer> {
 public:
  network_sink_registerer(void)
      : ER_CLIENT_INIT() {}

  network_sink_registerer& operator=(const network_sink_registerer&) = default;
  network_sink_registerer(const network_sink_registerer&) = default;

  template <typename TIterator, typename TSink>
  void emit_diagnostic(const TIterator& it,
                       const collector_registration_spec<TSink>& spec) {
      ER_INFO("Metrics enabled: "
              "xml_name='%s',scoped_name='%s',dest='%s',output_interval=%lu,"
              "mode=%x",
              it->input_name.c_str(),
              it->scoped_name.c_str(),
              spec.sink->dest().c_str(),
              spec.sink->output_interval().v(),
              rcppsw::as_underlying(spec.sink->output_mode()));
  }

  /**
   * \brief Figure out:
   *
   * - If the selected output mode is valid for the specified collector.
   *
   * - The appropriate network dest for the collector if the output mode is OK.
   *
   * \return \ref collector_register_spec, or empty if the collector fails any
   * pre-initialization checks.
   */
  template<typename TSink>
  collector_registration_spec<TSink>
  calc_registration_spec(network_output_manager* manager,
                         const rmconfig::network_sink_config* const config,
                         const std::string& xml_name,
                         const rmetrics::output_mode& allowed) const {
    auto stream_it = config->stream.enabled.find(xml_name);
    size_t sum =
        static_cast<size_t>(stream_it != config->stream.enabled.end());
    ER_ASSERT(sum <= 1,
              "Collector '%s' present in more than 1 network sink collector group in XML file",
              xml_name.c_str());

    collector_registration_spec<TSink> ret;
    if (stream_it != config->stream.enabled.end()) {
      ER_ASSERT(allowed & rmetrics::output_mode::ekSTREAM,
                "Output mode %d for collector '%s' does not contain ekSTREAM",
                rcppsw::as_underlying(allowed),
                xml_name.c_str());
      ret.is_enabled = true;
      ret.sink = std::make_unique<TSink>(manager->dest_prefix() + stream_it->second,
                                         rmetrics::output_mode::ekSTREAM,
                                         config->stream.output_interval);
    }
    return ret;
  }
};

} /* namespace rcppsw::metrics */
