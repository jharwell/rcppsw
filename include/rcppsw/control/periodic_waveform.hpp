/**
 * \file periodic_waveform.hpp
 *
 * \copyright 2018 John Harwell.
 *
 * SPDX-License-Identifier: MIT
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
namespace rcppsw::control {

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

} /* namespace rcppsw::control */

