/**
 * \file register_with_sink.hpp
 *
 * \copyright 2021 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include <utility>
#include <tuple>

#include "rcppsw/rcppsw.hpp"
#include "rcppsw/er/client.hpp"
#include "rcppsw/metrics/base_manager.hpp"
#include "rcppsw/metrics/creatable_collector_set.hpp"
#include "rcppsw/common/abi.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, metrics);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class register_with_sink
 * \ingroup metrics detail
 *
 * \brief After enabled collectors have been parsed from an XML input file,
 * register the enabled collectors with a \ref base_manager or a
 * class derived from it.
 *
 * This class is a partial specialization which specializes the generic
 * collector_registerer_impl, which can take an arbitrary # of types, to take a
 * std::tuple which in turn takes an arbitrary # of types. This is a better
 * design than simply having a class that takes an arbitrary # of types, because
 * it makes it clearer that the template parameters are considered a single
 * unit, and are NOT part of the constructor arguments for the class.
 */
template <typename TMetricsManager,
          typename TSinkMixin,
          typename TExtraArgsType = void>
class register_with_sink : public rer::client<
  register_with_sink<TMetricsManager,
                    TSinkMixin,
                    TExtraArgsType>
  >,
                          public TSinkMixin {
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
  register_with_sink(TMetricsManager* const manager,
                    const creatable_collector_set& set,
                    const extra_args_type& extra_args = {})
      : ER_CLIENT_INIT("rcppsw.metrics.register_with_sink"),
        mc_create_set(set),
        m_extra_args(extra_args),
        m_manager(manager) {}

  register_with_sink& operator=(const register_with_sink&) = default;
  register_with_sink(const register_with_sink&) = default;

  template <typename TSinkTypeWrapped, typename TConfig>
  void operator()(const TSinkTypeWrapped&, const TConfig* config) {
    using TSinkType = typename TSinkTypeWrapped::type;
    using TCollectorType = typename TSinkType::collector_type;

    std::type_index collector_id(typeid(TCollectorType));
    std::type_index sink_id(typeid(TSinkType));

    auto key = creatable_collector_spec{ collector_id };
    auto range = creatable_set().equal_range(key);

    ER_ASSERT(std::distance(range.first, range.second) > 0,
              "Unknown collector %s: not in creatable set?",
              rabi::demangle(collector_id.name()));

    ER_DEBUG("%zu %s instances configured",
             std::distance(range.first, range.second),
             rabi::demangle(collector_id.name()));

    /*
     * Multiple collectors of the same type can be registered as different
     * scoped/runtime names, so we need to iterate.
     */
    for (auto it = range.first; it != range.second; ++it) {
      /*
       * Avoid duplicate registration if the same collector is used with
       * multiple sinks.
       */
      if (it->sink_id != sink_id) {
        continue;
      }
      auto spec = this->template calc_registration_spec<TSinkType>(
          m_manager,
          config,
          it->input_name,
          it->valid_modes);
      if (!spec.is_enabled) {
           ER_DEBUG("Metrics with xml_name='%s' disabled",
                    it->input_name.c_str());
           continue;
      }
      this->template emit_diagnostic(it, spec);
      auto ret = this->template do_register<TCollectorType, TSinkType>(
          it->scoped_name,
          std::move(spec));

      if (!ret) {
        ER_WARN("Collector with scoped_name='%s' already exists!",
                it->scoped_name.c_str());
      }
    } /* for(it..) */
  }

 protected:
  TMetricsManager* manager(void) const { return m_manager; }
  const creatable_collector_set& creatable_set(void) const {
    return mc_create_set;
  }

  template <typename TCollector,
            typename TSink,
            typename U = TExtraArgsType,
            RCPPSW_SFINAE_DECLDEF(!no_extra_args<U>::value)>
  bool do_register(const std::string& scoped_name,
                   collector_registration_spec<TSink>&& spec)  {
    m_manager->collector_preregister(scoped_name, spec.sink->output_mode());
    auto extra_args = m_extra_args;
    auto lambda = [&](auto&&... args) {
                    return m_manager->template collector_register<TCollector>(
                        scoped_name,
                        std::move(spec.sink),
                        std::forward<decltype(args)>(args)...);
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
            typename TSink,
            typename U = TExtraArgsType,
            RCPPSW_SFINAE_DECLDEF(no_extra_args<U>::value)>
  bool do_register(const std::string& scoped_name,
                   collector_registration_spec<TSink>&& spec)  {
    m_manager->collector_preregister(scoped_name, spec.sink->output_mode());
    return m_manager->template collector_register<TCollector>(scoped_name,
                                                              std::move(spec.sink));
  }

 private:
  /* clang-format off */
  const creatable_collector_set mc_create_set;

  extra_args_type               m_extra_args;
  TMetricsManager* const        m_manager;
  /* clang-format on */
};

NS_END(metrics, rcppsw);
