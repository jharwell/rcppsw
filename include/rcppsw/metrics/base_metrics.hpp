/**
 * @file base_metrics.hpp
 *
 * @copyright 2017 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_METRICS_BASE_METRICS_HPP_
#define INCLUDE_RCPPSW_METRICS_BASE_METRICS_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/common/common.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, metrics);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class base_metrics
 * @ingroup rcppsw metrics
 *
 * @brief Base class for all collected metrics in RCPPSW.
 */
class base_metrics {
 public:
  base_metrics(void) = default;
  virtual ~base_metrics(void) = default;
  base_metrics(const base_metrics&) = default;
  base_metrics& operator=(const base_metrics&) = default;

  /**
   * @brief Reset gathered metrics to their initial state.
   */
  virtual void reset_metrics(void) {}
};

NS_END(metrics, rcppsw);

#endif /* INCLUDE_RCPPSW_METRICS_BASE_METRICS_HPP_ */
