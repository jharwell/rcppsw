/**
 * \file waveform_config.hpp
 *
 * \copyright 2018 John Harwell/Anthony Chen, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
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
namespace rcppsw::control::config {

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

} /* namespace rcppsw::control::config */

