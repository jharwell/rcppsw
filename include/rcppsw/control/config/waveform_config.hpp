/**
 * \file waveform_config.hpp
 *
 * \copyright 2018 John Harwell/Anthony Chen, All rights reserved.
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
#include <string>
#include "rcppsw/config/base_config.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, control, config);

/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/
/**
 * \struct waveform_config
 * \ingroup control config
 *
 * Parameters for \ref base_waveform derived classes. Not all parameters are
 * applicable to all waveform types.
 */
struct waveform_config final : public rcppsw::config::base_config {
  waveform_config(void) = default;

  /* constructor needed for aggregate initialization because of base class */
  waveform_config(const std::string& type_in,
                  double freq_in,
                  double phase_in,
                  double amp_in,
                  double offset_in) :
      type(type_in),
      frequency(freq_in),
      phase(phase_in),
      amplitude(amp_in),
      offset(offset_in) {}

  std::string type{};
  double frequency{0.0};
  double phase{0.0};
  double amplitude{0.0};
  double offset{0.0};
};

NS_END(config, control, rcppsw);

