/**
 * @file waveform_params.hpp
 *
 * @copyright 2018 John Harwell/Anthony Chen, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_CONTROL_WAVEFORM_PARAMS_HPP_
#define INCLUDE_RCPPSW_CONTROL_WAVEFORM_PARAMS_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "rcppsw/params/base_params.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, control);

/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/
/**
 * @struct waveform_params
 * @ingroup control
 *
 * Not all parameters are applicable to all waveform types.
 */
struct waveform_params : public rcppsw::params::base_params {
  waveform_params(std::string type_,
                  double freq_,
                  double phase_,
                  double amp_,
                  double offset_)
      : type(std::move(type_)),
        frequency(freq_),
        phase(phase_),
        amplitude(amp_),
        offset(offset_) {}
  waveform_params(void) = default;

  std::string type{""};
  double frequency{0};
  double phase{0};
  double amplitude{0};
  double offset{0};
};

NS_END(control, rcppsw);

#endif // INCLUDE_RCPPSW_CONTROL_WAVEFORM_PARAMS_HPP_
