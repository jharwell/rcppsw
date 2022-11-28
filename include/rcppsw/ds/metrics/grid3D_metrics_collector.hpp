/**
 * \file grid3D_metrics_collector.hpp
 *
 * \copyright 2019 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <memory>
#include <utility>

#include "rcppsw/metrics/base_collector.hpp"
#include "rcppsw/ds/metrics/grid3D_metrics_data.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, ds, metrics);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class grid3D_metrics_collector
 * \ingroup ds metrics
 *
 * \brief Base class for collectors using a 3D grid to fill with counts of
 * SOMETHING, to be averaged over the entire simulation. Each line of the
 * resulting .csv file corresponds to an XY plane for a value of Z in the grid.
 */
class grid3D_metrics_collector : public rmetrics::base_collector {
 public:
  /**
   * \param sink The metrics sink to use.
   * \param dims Dimensions of grid.
   */
  grid3D_metrics_collector(std::unique_ptr<rmetrics::base_sink> sink,
                           const math::vector3z& dims)
      : base_collector(std::move(sink)),
        m_data(dims) {}

 protected:
  const rmetrics::base_data* data(void) const override {
    return &m_data;
  }

  void inc_cell_count(const math::vector3z& c, size_t count = 1) {
    m_data.grid.access(c) += count;
  }
  void inc_total_count(size_t count = 1) { m_data.total_count += count; }

 private:
  /* clang-format off */
  grid3D_metrics_data m_data;
  /* clang-format on */

 public:
  RCPPSW_WRAP_DECLDEF(xsize, m_data.grid);
  RCPPSW_WRAP_DECLDEF(ysize, m_data.grid);
  RCPPSW_WRAP_DECLDEF(zsize, m_data.grid);
};

NS_END(metrics, ds, rcppsw);

