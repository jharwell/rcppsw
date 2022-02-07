/**
 * \file file_sink_registerer.hpp
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

#ifndef INCLUDE_RCPPSW_METRICS_FILE_SINK_REGISTERER_HPP_
#define INCLUDE_RCPPSW_METRICS_FILE_SINK_REGISTERER_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <memory>
#include <utility>
#include <string>

#include "rcppsw/metrics/config/file_sink_config.hpp"
#include "rcppsw/metrics/fs_output_manager.hpp"
#include "rcppsw/utils/maskable_enum.hpp"
#include "rcppsw/metrics/creatable_collector_set.hpp"
#include "rcppsw/metrics/file_sink.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, metrics);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

/**
 * \class file_sink_registerer
 * \ingroup metrics
 *
 * \brief Register all collectors configured with \ref rmetrics::file_sink with
 * a \ref base_manager or a class derived from it.
 *
 */
class file_sink_registerer : public rer::client<file_sink_registerer> {
 public:
  file_sink_registerer(void)
      : ER_CLIENT_INIT("rcppsw.metrics.detail.file_sink_registerer") {}

  file_sink_registerer& operator=(const file_sink_registerer&) = default;
  file_sink_registerer(const file_sink_registerer&) = default;

  template <typename TIterator, typename TSink>
  void emit_diagnostic(const TIterator& it,
                       const collector_registration_spec<TSink>& spec) {
      ER_INFO("Metrics enabled: "
              "xml_name='%s',scoped_name='%s','fpath=%s',output_interval=%lu,"
              "mode=%x",
              it->input_name.c_str(),
              it->scoped_name.c_str(),
              spec.sink->fpath().c_str(),
              spec.sink->output_interval().v(),
              rcppsw::as_underlying(spec.sink->output_mode()));
  }

  /**
   * \brief Figure out:
   *
   * - If the selected output mode is valid for the specified collector.
   * - The appropriate filename output stem for the collector if the output
   *   mode is OK.
   *
   * \return \ref collector_register_spec, or empty if the collector fails any
   * pre-initialization checks.
   */
  template<typename TSink>
  collector_registration_spec<TSink>
  calc_registration_spec(fs_output_manager* manager,
                         const rmconfig::file_sink_config* const config,
                         const std::string& xml_name,
                         const rmetrics::output_mode& allowed) const {
    auto append_it = config->append.enabled.find(xml_name);
    auto truncate_it = config->truncate.enabled.find(xml_name);
    auto create_it = config->create.enabled.find(xml_name);
    size_t sum =
        static_cast<size_t>(append_it != config->append.enabled.end()) +
        static_cast<size_t>(truncate_it != config->truncate.enabled.end()) +
        static_cast<size_t>(create_it != config->create.enabled.end());
    ER_ASSERT(sum <= 1,
              "Collector '%s' present in more than 1 FILE sink collector group in XML file",
              xml_name.c_str());

    collector_registration_spec<TSink> ret;
    if (append_it != config->append.enabled.end()) {
      ER_ASSERT(allowed & rmetrics::output_mode::ekAPPEND,
                "Output mode %d for collector '%s' does not contain ekAPPEND",
                rcppsw::as_underlying(allowed),
                xml_name.c_str());
      ret.is_enabled = true;
      ret.sink = std::make_unique<TSink>(manager->metrics_path() / append_it->second,
                                         rmetrics::output_mode::ekAPPEND,
                                         config->append.output_interval);
    } else if (truncate_it != config->truncate.enabled.end()) {
      ER_ASSERT(allowed & rmetrics::output_mode::ekTRUNCATE,
                "Output mode %d for collector '%s' does not contain ekTRUNCATE",
                rcppsw::as_underlying(allowed),
                xml_name.c_str());

      ret.is_enabled = true;
      ret.sink = std::make_unique<TSink>(manager->metrics_path() / truncate_it->second,
                                         rmetrics::output_mode::ekTRUNCATE,
                                         config->truncate.output_interval);
    } else if (create_it != config->create.enabled.end()) {
      ER_ASSERT(allowed & rmetrics::output_mode::ekCREATE,
                "Output mode %d for collector '%s' does not contain ekCREATE",
                rcppsw::as_underlying(allowed),
                xml_name.c_str());
      /* Give them their own directory to output stuff into for cleanliness */
      auto file_dir = fs::path(create_it->second);
      file_dir.replace_extension(fs::path());
      auto dirpath = manager->metrics_path() / file_dir;
      fs::create_directories(dirpath);

      ret.is_enabled = true;
      ret.sink = std::make_unique<TSink>(dirpath / create_it->second,
                                         rmetrics::output_mode::ekCREATE,
                                         config->create.output_interval);
    }
    return ret;
  }
};

NS_END(metrics, rcppsw);

#endif /* INCLUDE_RCPPSW_METRICS_FILE_SINK_REGISTERER_HPP_ */
