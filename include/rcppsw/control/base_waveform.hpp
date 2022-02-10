/**
 * \file base_waveform.hpp
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
#include "rcppsw/control/config/waveform_config.hpp"
#include "rcppsw/math/radians.hpp"
#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, control);

/*******************************************************************************
 * Classes
 ******************************************************************************/
/**
 * \class base_waveform
 * \ingroup control
 *
 * \brief Base class for all types of waveforms (in the control theory
 * sense). All waveforms have [frequency, phase, amplitude, offset] components.
 */
class base_waveform {
 public:
  explicit base_waveform(const struct config::waveform_config* const config)
      : m_frequency(config->frequency),
        m_amplitude(config->amplitude),
        m_offset(config->offset),
        m_phase(rmath::radians(config->phase)) {}

  virtual ~base_waveform(void) = default;

  /**
   * \brief Get the current value of the waveform at time \p t.
   */
  virtual double value(double time) = 0;

  /**
   * \brief Get the frequency of the waveform.
   */
  double frequency(void) const { return m_frequency; }

  /**
   * \brief Get the phase of the waveform in radians.
   */
  const math::radians& phase(void) const { return m_phase; }

  /**
   * \brief Get the amplitude of the waveform.
   */
  double amplitude(void) const { return m_amplitude; }

  /**
   * \brief Get the offset of the waveform.
   */
  double offset(void) const { return m_offset; }

 private:
  /* clang-format off */
  double        m_frequency;
  double        m_amplitude;
  double        m_offset;
  math::radians m_phase;
  /* clang-format on */
};

NS_END(control, rcppsw);

