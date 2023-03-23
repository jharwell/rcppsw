/**
 * \file base_metrics.hpp
 *
 * \copyright 2017 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace rcppsw::metrics {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \interface base_metrics
 * \ingroup metrics
 *
 * \brief Base class for all collected metrics in RCPPSW.
 */
class base_metrics {
 public:
  base_metrics(void) = default;
  virtual ~base_metrics(void) = default;
  base_metrics(const base_metrics&) = default;
  base_metrics& operator=(const base_metrics&) = default;

  /**
   * \brief Reset gathered metrics to their initial state, if needed. By default
   * it does nothing.
   */
  virtual void reset_metrics(void) {}
};

} /* namespace rcppsw::metrics */

