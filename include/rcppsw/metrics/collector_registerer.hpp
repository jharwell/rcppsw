/**
 * \file collector_registerer.hpp
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

#ifndef INCLUDE_RCPPSW_METRICS_COLLECTOR_REGISTERER_HPP_
#define INCLUDE_RCPPSW_METRICS_COLLECTOR_REGISTERER_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <filesystem>
#include <string>
#include <utility>
#include <memory>
#include <tuple>

#include "rcppsw/er/client.hpp"
#include "rcppsw/mpl/identity.hpp"
#include "rcppsw/types/timestep.hpp"
#include "rcppsw/utils/maskable_enum.hpp"
#include "rcppsw/metrics/csv_sink.hpp"
#include "rcppsw/mpl/typelist.hpp"

#include "rcppsw/rcppsw.hpp"
#include "rcppsw/metrics/base_metrics_manager.hpp"
#include "rcppsw/metrics/creatable_collector_set.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, metrics, detail);
namespace fs = std::filesystem;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class register_by_sink
 * \ingroup metrics detail
 *
 * \brief After enabled collectors have been parsed from an XML input file,
 * register the enabled collectors with a \ref rcppsw_metrics_manager or a
 * class derived from it.
 *
 * This class is a partial specialization which specializes the generic
 * collector_registerer_impl, which can take an arbitrary # of types, to take a
 * std::tuple which in turn takes an arbitrary # of types. This is a better
 * design than simply having a class that takes an arbitrary # of types, because
 * it makes it clearer that the template parameters are considered a single
 * unit, and are NOT part of the constructor arguments for the class.
 */
template <typename TExtraArgsType = void>
class register_by_sink : public rer::client<register_by_sink<TExtraArgsType>> {
 public:
  template<typename T>
  using no_extra_args = typename std::is_same<T, void>;

  using extra_args_type = typename std::conditional<
   std::is_same<TExtraArgsType, void>::value,
   std::tuple<int>,
   TExtraArgsType>::type;

  /**
   * \brief Initialize the registerer.
   *
   * \param manager The metrics manager to register the collectors with.
   *
   * \param create_set Definitions for all the possible collectors to create.
   */
  register_by_sink(const creatable_collector_set& set,
                   base_metrics_manager* const manager,
                   const extra_args_type& extra_args = {})
      : ER_CLIENT_INIT("rcppsw.metrics.collector_registerer"),
        mc_create_set(set),
        m_extra_args(extra_args),
        m_manager(manager) {}

  register_by_sink& operator=(const register_by_sink&) = default;
  register_by_sink(const register_by_sink&) = default;

 protected:
  base_metrics_manager* manager(void) const { return m_manager; }
  const creatable_collector_set& creatable_set(void) const { return mc_create_set; }

  template <typename TCollector,
            typename U = TExtraArgsType,
            RCPPSW_SFINAE_DECLDEF(!no_extra_args<U>::value)>
  bool do_register(const std::string& scoped_name,
                   collector_registration_spec&& spec)  {
    m_manager->collector_preregister(scoped_name, spec.sink->output_mode());
    auto extra_args = m_extra_args;
    auto lambda = [&](auto&&... args) {
                    return m_manager->collector_register<TCollector>(scoped_name,
                                                                     std::move(spec.sink),
                                                                     std::forward<decltype(args)>(args)...);;
                  };
    /*
     * The std::move() is 100% necessary here, because (I think) types in the
     * extra arguments tuple are rvalues, but the values are (probably) lvalues,
     * and if you don't do this you get an error regarding rvalue->lvalue
     * binding.
     */
    return std::apply(lambda, std::move(extra_args));
  }

  template <typename TCollector,
            typename U = TExtraArgsType,
            RCPPSW_SFINAE_DECLDEF(no_extra_args<U>::value)>
  bool do_register(const std::string& scoped_name,
                   collector_registration_spec&& spec)  {
    m_manager->collector_preregister(scoped_name, spec.sink->output_mode());
    return m_manager->collector_register<TCollector>(scoped_name,
                                                     std::move(spec.sink));
  }

 private:
  /* clang-format off */
  const creatable_collector_set mc_create_set;

  extra_args_type               m_extra_args;
  base_metrics_manager* const   m_manager;
  /* clang-format on */
};

NS_END(detail);

/**
 * \class register_with_csv_sink
 * \ingroup metrics detail
 *
 * \brief Register all collectors configured with \ref rmetrics::csv_sink with a
 * \ref base_metrics_manager or a class derived from it.
 *
 */
template <typename TExtraArgsType = void>
class register_with_csv_sink : public detail::register_by_sink<TExtraArgsType>,
                               public rer::client<register_with_csv_sink<TExtraArgsType>> {
 public:
  using detail::register_by_sink<TExtraArgsType>::creatable_set;
  using detail::register_by_sink<TExtraArgsType>::manager;

  /**
   * \brief Initialize the registerer for collectors configured with \ref
   * rmetrics::csv_sinks.
   *
   * \param config Metrics configuration.
   * \param create_set Definitions for all the possible collectors to create.
   * \param manager The metrics manager to register the collectors with.
   *
   * We use a variadic template here to handle collectors which need extra args
   * and those that don't transparently.
   */
  template<typename ...Args>
  register_with_csv_sink(
      const rmconfig::csv_sink_config* const config,
      const creatable_collector_set& set,
      base_metrics_manager* const m,
      Args&&... extra_args)
      : detail::register_by_sink<TExtraArgsType>(set, m, std::forward<Args>(extra_args)...),
        ER_CLIENT_INIT("rcppsw.metrics.detail.register_csv_sinks"),
        mc_config(config) {}

  register_with_csv_sink& operator=(const register_with_csv_sink&) = default;
  register_with_csv_sink(const register_with_csv_sink&) = default;

  template <typename TSinkTypeWrapped>
  void operator()(const TSinkTypeWrapped&) {
    using TSinkType = typename TSinkTypeWrapped::type;
    using TCollectorType = typename TSinkType::collector_type;

    std::type_index id(typeid(typename TSinkType::collector_type));

    auto key = creatable_collector_spec{
      id,
      "",
      "",
      rmetrics::output_mode::ekNONE
    };
    auto range = creatable_set().equal_range(key);

    ER_ASSERT(creatable_set().end() != creatable_set().find(key),
              "Unknown collector: type_index='%s'",
              id.name());

    /*
     * Multiple collectors of the same type can be registered as different
     * scoped/runtime names, so we need to iterate.
     */
    for (auto it = range.first; it != range.second; ++it) {
      auto spec = calc_registration_spec<TSinkType>(it->input_name,
                                                    it->valid_modes);
      if (!spec.is_enabled) {
           ER_DEBUG("Metrics with xml_name=%s disabled", it->input_name.c_str());
           continue;
      }
      ER_INFO("Metrics enabled: "
              "xml_name='%s',scoped_name='%s',fpath=%s,output_interval=%lu,"
              "mode=%x",
              it->input_name.c_str(),
              it->scoped_name.c_str(),
              spec.sink->fpath().c_str(),
              spec.sink->output_interval().v(),
              rcppsw::as_underlying(spec.sink->output_mode()));
      auto ret = this->template do_register<TCollectorType>(it->scoped_name,
                                                              std::move(spec));

      if (!ret) {
        ER_WARN("Collector with scoped_name='%s' already exists!",
                it->scoped_name.c_str());
      }
    } /* for(it..) */
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
  collector_registration_spec
  calc_registration_spec(const std::string& xml_name,
                         const rmetrics::output_mode& allowed) const {
    auto append_it = mc_config->append.enabled.find(xml_name);
    auto truncate_it = mc_config->truncate.enabled.find(xml_name);
    auto create_it = mc_config->create.enabled.find(xml_name);
    size_t sum =
        static_cast<size_t>(append_it != mc_config->append.enabled.end()) +
        static_cast<size_t>(truncate_it != mc_config->truncate.enabled.end()) +
        static_cast<size_t>(create_it != mc_config->create.enabled.end());
    ER_ASSERT(sum <= 1,
              "Collector '%s' present in more than 1 CSV sink collector group in XML file",
              xml_name.c_str());

     collector_registration_spec ret;
    if (append_it != mc_config->append.enabled.end()) {
      ER_ASSERT(allowed & rmetrics::output_mode::ekAPPEND,
                "Output mode %d for collector '%s' does not contain ekAPPEND",
                rcppsw::as_underlying(allowed),
                xml_name.c_str());
      ret.is_enabled = true;
      ret.sink = std::make_unique<TSink>(manager()->metrics_path() / append_it->second,
                                         rmetrics::output_mode::ekAPPEND,
                                         mc_config->append.output_interval);
    } else if (truncate_it != mc_config->truncate.enabled.end()) {
      ER_ASSERT(allowed & rmetrics::output_mode::ekTRUNCATE,
                "Output mode %d for collector '%s' does not contain ekTRUNCATE",
                rcppsw::as_underlying(allowed),
                xml_name.c_str());

      ret.is_enabled = true;
      ret.sink = std::make_unique<TSink>(manager()->metrics_path() / truncate_it->second,
                                         rmetrics::output_mode::ekTRUNCATE,
                                         mc_config->truncate.output_interval);
    } else if (create_it != mc_config->create.enabled.end()) {
      ER_ASSERT(allowed & rmetrics::output_mode::ekCREATE,
                "Output mode %d for collector '%s' does not contain ekCREATE",
                rcppsw::as_underlying(allowed),
                xml_name.c_str());
      /* Give them their own directory to output stuff into for cleanliness */
      auto dirpath = manager()->metrics_path() / create_it->second;
      fs::create_directories(dirpath);

      ret.is_enabled = true;
      ret.sink = std::make_unique<TSink>(dirpath / create_it->second,
                                         rmetrics::output_mode::ekCREATE,
                                         mc_config->create.output_interval);
    }
    return ret;
  }

  /* clang-format off */
  const rmconfig::csv_sink_config* const mc_config;
  /* clang-format on */
};

/**
 * \class collector_registerer
 * \ingroup metrics
 *
 * \brief After enabled collectors have been parsed from an XML input file,
 * register the enabled collectors with a \ref base_metrics_manager or a
 * class derived from it.
 *
 * This is a separate class from \ref collector_registerer_impl so you don't
 * ALWAYS have to pass it a list of extra arguments for building some finicky
 * metrics collectors.
 */
template <typename TSinkRegisterer>
class collector_registerer {
 public:
  explicit collector_registerer(const TSinkRegisterer&& registerer)
      : m_registerer(std::move(registerer)) {}

  collector_registerer& operator=(const collector_registerer&) = default;
  collector_registerer(const collector_registerer&) = default;

  template <typename TPair>
  void operator()(const TPair& pair) {
    m_registerer(pair);
  }

 private:
  /* clang-format off */
  TSinkRegisterer m_registerer;
  /* clang-format on */
};

NS_END(metrics, rcppsw);

#endif /* INCLUDE_RCPPSW_METRICS_COLLECTOR_REGISTERER_HPP_ */
