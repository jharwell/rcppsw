/**
 * @file periodic_waveform.hpp
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

#ifndef INCLUDE_RCPPSW_CONTROL_PERIODIC_WAVEFORM_HPP_
#define INCLUDE_RCPPSW_CONTROL_PERIODIC_WAVEFORM_HPP_

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
class sine_waveform : public waveform {
 public:
  explicit sine_waveform(const struct waveform_params* const params)
      : waveform(params) {}

  double value(double time) override {
    double t = frequency() * time + phase();
    double v = std::sin(2*M_PI * t);
    printf("value: %f v: %f amp: %f\n", amplitude()*v, v, amplitude());
    return amplitude() * v + offset();
  }
};

class square_waveform : public waveform {
 public:
  explicit square_waveform(const struct waveform_params* const params)
      : waveform(params) {}

  double value(double time) override {
    double t = frequency() * time + phase();
    return amplitude() * std::copysign(1.0, std::sin(2*M_PI * t))+ offset();
  }
};

class sawtooth_waveform : public waveform {
 public:
  explicit sawtooth_waveform(const struct waveform_params* const params)
      : waveform(params) {}

    double value(double time) override {
    double t = frequency() * time + phase();
    double v = 2.0 * (t - std::floor(t + 0.5));
    return amplitude() * v + offset();
  }
};

NS_END(control, rcppsw);

#endif  // INCLUDE_RCPPSW_CONTROL_PERIODIC_WAVEFORM_HPP_
