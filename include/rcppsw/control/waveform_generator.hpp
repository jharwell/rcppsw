/**
 * @file waveform_generator.hpp
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

#ifndef INCLUDE_RCPPSW_CONTROL_WAVEFORM_GENERATOR_HPP_
#define INCLUDE_RCPPSW_CONTROL_WAVEFORM_GENERATOR_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include <memory>

#include "rcppsw/patterns/factory/factory.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, control);
class waveform;
struct waveform_params;

/*******************************************************************************
 * Classes
 ******************************************************************************/
/**
 * @class waveform_generator
 * @ingroup control
 *
 * @brief Factory to create waveforms of different types given the name of a
 * waveform. Valid names are:
 *
 * - Sine (periodic)
 * - Square (periodic)
 * - Sawtooth (periodic)
 * - Constant (aperiodic)
 * - Null (aperiodic)
 */
class waveform_generator
    : public patterns::factory::releasing_factory<waveform,
                                                  const waveform_params*> {
 public:
  static constexpr char kSine[] = "Sine";
  static constexpr char kSquare[] = "Square";
  static constexpr char kSawtooth[] = "Sawtooth";
  static constexpr char kConstant[] = "Constant";
  static constexpr char kNull[] = "Null";

  waveform_generator(void);

  std::unique_ptr<waveform> operator()(const std::string& name,
                                       const waveform_params* params);
};

NS_END(control, rcppsw);

#endif // INCLUDE_RCPPSW_CONTROL_WAVEFORM_GENERATOR_HPP_
