/**
 * \file aperiodic_waveform.hpp
 *
 * \copyright 2018 John Harwell.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/control/base_waveform.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, control);

/*******************************************************************************
 * Classes
 ******************************************************************************/

/**
 * \class constant_waveform
 * \ingroup control
 *
 * \brief A special waveform that always returns a constant value: the amplitude
 * of the waveform config it was passed during construction. All other
 * parameters are ignored.
 */
class constant_waveform final : public base_waveform {
 public:
  explicit constant_waveform(const struct config::waveform_config* const config)
      : base_waveform(config) {}

  double value(double) override { return amplitude(); }
};

/**
 * \class null_waveform
 * \ingroup control
 *
 * \brief A special waveform that always returns 0.0, indicating that there is
 * no waveform/nothing. All parameters are ignored during initialization.
 */
class null_waveform final : public base_waveform {
 public:
  explicit null_waveform(const struct config::waveform_config* const config)
      : base_waveform(config) {}

  double value(double) override { return 0.0; }
};

NS_END(control, rcppsw);
