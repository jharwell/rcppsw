/**
 * @file aperiodic_waveform.hpp
 *
 * @copyright 2018 John Harwell.
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

#ifndef INCLUDE_RCPPSW_CONTROL_APERIODIC_WAVEFORM_HPP_
#define INCLUDE_RCPPSW_CONTROL_APERIODIC_WAVEFORM_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/control/waveform.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, control);

/*******************************************************************************
 * Classes
 ******************************************************************************/
class constant_waveform : public waveform {
 public:
  explicit constant_waveform(const struct waveform_params* const params)
      : waveform(params) {}

  double value(double) override {
    return amplitude();
  }
};

class null_waveform : public waveform {
 public:
  explicit null_waveform(const struct waveform_params* const params)
      : waveform(params) {}

  double value(double) override { return 0.0; }
};

NS_END(control, rcppsw);

#endif  // INCLUDE_RCPPSW_CONTROL_APERIODIC_WAVEFORM_HPP_
