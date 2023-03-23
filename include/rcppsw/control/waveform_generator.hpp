/**
 * \file waveform_generator.hpp
 *
 * \copyright 2018 John Harwell/Anthony Chen, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <memory>
#include <string>

#include "rcppsw/patterns/factory/factory.hpp"
#include "rcppsw/control/config/waveform_config.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace rcppsw::control {

class base_waveform;

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
 * - \ref kNone (no waveform)
 */
class waveform_generator
    : public patterns::factory::releasing_factory<base_waveform,
                                                  std::string,
                                                  const config::waveform_config*> {
 public:
  /**
   * \brief Generate a \ref sine_waveform.
   */
  static inline const std::string kSine = "sine";

  /**
   * \brief Generate a \ref square_waveform.
   */
  static inline const std::string kSquare = "square";

  /**
   * \brief Generate a \ref sawtooth_waveform.
   */
  static inline const std::string kSawtooth = "sawtooth";

  /**
   * \brief Generate a \ref constant_waveform.
   */
  static inline const std::string kConstant = "constant";

  /**
   * \brief Generate a \ref null_waveform.
   */
  static inline const std::string kNone = rconfig::constants::kNoValue;

  waveform_generator(void);

  std::unique_ptr<base_waveform>
  operator()(const std::string& name, const config::waveform_config* config);
};

} /* namespace rcppsw::control */
