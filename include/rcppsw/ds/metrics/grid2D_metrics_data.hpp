/**
 * \file grid3D_metrics_data.hpp
 *
 * \copyright 2017 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/metrics/base_data.hpp"
#include "rcppsw/ds/grid2D.hpp"
#include "rcppsw/al/multithread.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ds, metrics);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \interface grid2D_metrics_data
 * \ingroup ds metrics
 *
 * \brief Container for basic metrics gather from \ref rds::grid2D.
 */
struct grid2D_metrics_data : public rmetrics::base_data {
  explicit grid2D_metrics_data(const math::vector2z& dims) :
      grid(dims.x(), dims.y()) {}

  rcppsw::ds::grid2D<ral::mt_size_t> grid;
  ral::mt_size_t                     total_count{0};

};

NS_END(metrics, ds, rcppsw);

