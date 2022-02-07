/**
 * \file fs_output_manager.cpp
 *
 * \copyright 2020 John Harwell, All rights reserved.
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

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/metrics/fs_output_manager.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, metrics);

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/
fs_output_manager::fs_output_manager(
    const rmconfig::metrics_config* const mconfig,
    const fs::path& output_root)
    : ER_CLIENT_INIT("rcppsw.metrics.fs_output_manager"),
      m_metrics_path(output_root / mconfig->metrics_path) {
  if (!fs::exists(m_metrics_path)) {
    fs::create_directories(m_metrics_path);
  } else {
    ER_WARN("Output metrics path '%s' already exists", m_metrics_path.c_str());
  }
}

NS_END(metrics, rcppsw);
