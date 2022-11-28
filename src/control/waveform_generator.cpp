/**
 * \file waveform_generator.cpp
 *
 * \copyright 2018 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
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
std::unique_ptr<base_waveform>
waveform_generator::operator()(const std::string& name,
                               const config::waveform_config* config) {
  return create(name, config);
} /* operator() */

NS_END(control, rcppsw);
