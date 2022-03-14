/**
 * \file periodic_waveform.hpp
 *
 * \copyright 2018 John Harwell.
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

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <cmath>

#include "rcppsw/control/base_waveform.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, control);

/*******************************************************************************
 * Classes
 ******************************************************************************/

/**
 * \class sine_waveform
 * \ingroup control
 *
 * Given the current time, outputs the current value of a sine wave according to
 * configured parameters:
 *
 * value = amplitude * ( sin(2pi* frequency * time + phase)) + offset.
 *
 */
class sine_waveform final : public base_waveform {
 public:
  explicit sine_waveform(const struct config::waveform_config* const config)
      : base_waveform(config) {}

  double value(double time) override {
    double t = frequency() * time;
    double v = std::sin(2 * M_PI * t + phase().v());
    return amplitude() * v + offset();
  }
};

/**
 * \class square_waveform
 * \ingroup control
 *
 * Given the current time, outputs the current value of a square wave according
 * to configured parameters:
 *
 * value = amplitude * signof(sin(2pi* frequency * time + phase)) + offset.
 *
 * Can be used to create step functions as well.
 *
 */
class square_waveform final : public base_waveform {
 public:
  explicit square_waveform(const struct config::waveform_config* const config)
      : base_waveform(config) {}

  double value(double time) override {
    double t = frequency() * time;
    return amplitude() *
               std::copysign(1.0, std::sin(2 * M_PI * t + phase().v())) +
           offset();
  }
};

/**
 * \class sawtooth_waveform
 * \ingroup control
 *
 * Given the current time, outputs the current value of a sawtooth wave
 * according to configured parameters:
 *
 * value = amplitude * ( 2 * (t - floor(time + 0.5) + phase)) + offset.
 */
class sawtooth_waveform : public base_waveform {
 public:
  explicit sawtooth_waveform(const struct config::waveform_config* const config)
      : base_waveform(config) {}

  double value(double time) override {
    double t = frequency() * time;
    double v = 2.0 * (t - std::floor(t + 0.5) + phase().v());
    return amplitude() * v + offset();
  }
};

NS_END(control, rcppsw);

