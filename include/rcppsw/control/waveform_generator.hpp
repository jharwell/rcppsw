/**
 * \file waveform_generator.hpp
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

#ifndef INCLUDE_RCPPSW_CONTROL_WAVEFORM_GENERATOR_HPP_
#define INCLUDE_RCPPSW_CONTROL_WAVEFORM_GENERATOR_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <memory>
#include <string>

#include "rcppsw/patterns/factory/factory.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, control);
class base_waveform;
namespace config {
struct waveform_config;
} /* namespace config */

/*******************************************************************************
 * Classes
 ******************************************************************************/
/**
 * \class waveform_generator
 * \ingroup control
 *
 * \brief Factory to create waveforms of different types given the name of a
 * waveform. Valid names are:
 *
 * - \ref kSine (periodic)
 * - \ref kSquare (periodic)
 * - \ref kSawtooth (periodic)
 * - \ref kConstant (aperiodic)
 * - \ref kNull (aperiodic)
 */
class waveform_generator
    : public patterns::factory::releasing_factory<base_waveform,
                                                  std::string,
                                                  const config::waveform_config*> {
 public:
  /**
   * \brief Generate a \ref sine_waveform.
   */
  static inline const std::string kSine = "Sine";

  /**
   * \brief Generate a \ref square_waveform.
   */
  static inline const std::string kSquare = "Square";

  /**
   * \brief Generate a \ref sawtooth_waveform.
   */
  static inline const std::string kSawtooth = "Sawtooth";

  /**
   * \brief Generate a \ref constant_waveform.
   */
  static inline const std::string kConstant = "Constant";

  /**
   * \brief Generate a \ref null_waveform.
   */
  static inline const std::string kNull = "Null";

  waveform_generator(void);

  std::unique_ptr<base_waveform>
  operator()(const std::string& name, const config::waveform_config* config);
};

NS_END(control, rcppsw);

#endif // INCLUDE_RCPPSW_CONTROL_WAVEFORM_GENERATOR_HPP_
