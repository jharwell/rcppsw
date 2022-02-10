/**
 * \file aperiodic_waveform.hpp
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
class constant_waveform : public base_waveform {
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
class null_waveform : public base_waveform {
 public:
  explicit null_waveform(const struct config::waveform_config* const config)
      : base_waveform(config) {}

  double value(double) override { return 0.0; }
};

NS_END(control, rcppsw);

