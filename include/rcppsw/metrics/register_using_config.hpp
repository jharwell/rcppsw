/**
 * \file register_using_config.hpp
 *
 * \copyright 2019 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <utility>

#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace rcppsw::metrics {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

/**
 * \class register_using_config
 * \ingroup metrics
 *
 * \brief After enabled collectors have been parsed from an XML input file,
 * register the enabled collectors with a \ref base_manager or a
 * class derived from it.
 *
 * This is a separate class from \ref register_by_sink so you don't ALWAYS have
 * to pass it a list of extra arguments for building some finicky metrics
 * collectors.
 */
template <typename TSinkRegisterer, typename TConfig>
class register_using_config {
 public:
  register_using_config(const TSinkRegisterer&& registerer,
                        const TConfig* config)
      : mc_config(config),
        m_registerer(std::move(registerer)) {}

  register_using_config& operator=(const register_using_config&) = default;
  register_using_config(const register_using_config&) = default;

  template <typename TPair>
  void operator()(const TPair& pair) {
    m_registerer(pair, mc_config);
  }

 private:
  /* clang-format off */
  const TConfig*  mc_config;

  TSinkRegisterer m_registerer;
  /* clang-format on */
};

} /* namespace rcppsw::metrics */
