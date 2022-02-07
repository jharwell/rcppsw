/**
 * \file register_using_config.hpp
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

#ifndef INCLUDE_RCPPSW_METRICS_REGISTER_USING_CONFIG_HPP_
#define INCLUDE_RCPPSW_METRICS_REGISTER_USING_CONFIG_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <utility>

#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, metrics);

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
  explicit register_using_config(const TSinkRegisterer&& registerer,
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

NS_END(metrics, rcppsw);

#endif /* INCLUDE_RCPPSW_METRICS_REGISTER_USING_CONFIG_HPP_ */
