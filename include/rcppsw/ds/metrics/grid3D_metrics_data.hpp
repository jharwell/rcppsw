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
#include "rcppsw/ds/grid3D.hpp"
#include "rcppsw/al/multithread.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace rcppsw::ds::metrics {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \interface grid3D_metrics_data
 * \ingroup ds metrics
 *
 * \brief Container for basic metrics gather from \ref rds::grid3D.
 */
struct grid3D_metrics_data : public rmetrics::base_data {
  explicit grid3D_metrics_data(const math::vector3z& dims) :
      grid(dims.x(), dims.y(), dims.z()) {}

  rcppsw::ds::grid3D<ral::mt_size_t> grid;
  ral::mt_size_t                     total_count{0};
};

} /* namespace rcppsw::ds::metrics */

