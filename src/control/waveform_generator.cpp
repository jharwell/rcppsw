/**
 * @file waveform_generator.cpp
 *
 * @copyright 2018 John Harwell, All rights reserved.
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
#include "rcppsw/control/waveform_generator.hpp"
#include "rcppsw/control/aperiodic_waveform.hpp"
#include "rcppsw/control/periodic_waveform.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, control);

/*******************************************************************************
 * Class Constants
 ******************************************************************************/
constexpr char waveform_generator::kSine[];
constexpr char waveform_generator::kSquare[];
constexpr char waveform_generator::kSawtooth[];
constexpr char waveform_generator::kConstant[];
constexpr char waveform_generator::kNull[];

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/
waveform_generator::waveform_generator(void) {
  register_type<sine_waveform>(kSine);
  register_type<square_waveform>(kSquare);
  register_type<sawtooth_waveform>(kSawtooth);
  register_type<constant_waveform>(kConstant);
  register_type<null_waveform>(kNull);
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
std::unique_ptr<waveform> waveform_generator::
operator()(const std::string &name, const waveform_params *params) {
  return create(name, params);
} /* operator() */

NS_END(control, rcppsw);
