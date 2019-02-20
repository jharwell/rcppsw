/**
 * @file waveform.hpp
 *
 * @copyright 2018 John Harwell.
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

#ifndef INCLUDE_RCPPSW_CONTROL_WAVEFORM_HPP_
#define INCLUDE_RCPPSW_CONTROL_WAVEFORM_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <cmath>
#include "rcppsw/common/common.hpp"
#include "rcppsw/control/waveform_params.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, control);

/*******************************************************************************
 * Classes
 ******************************************************************************/
/**
 * @class waveform
 * @ingroup control
 *
 * @brief Base class for all types of waveforms (in the control theory
 * sense). All waveforms have [frequency, phase, amplitude, offset] components.
 */
class waveform {
 public:
  explicit waveform(const struct waveform_params* const params)
      : m_frequency(params->frequency),
        m_phase(params->phase),
        m_amplitude(params->amplitude),
        m_offset(params->offset) {}

  virtual ~waveform(void) = default;

  /**
   * @brief Get the current value of the variance function, given the current
   * time as input.
   */
  virtual double value(double time) = 0;

  double frequency(void) const { return m_frequency; }
  double phase(void) const { return m_phase; }
  double amplitude(void) const { return m_amplitude; }
  double offset(void) const { return m_offset; }

 private:
  /* clang-format off */
  double m_frequency;
  double m_phase;
  double m_amplitude;
  double m_offset;
  /* clang-format on */
};

NS_END(control, rcppsw);

#endif // INCLUDE_RCPPSW_CONTROL_WAVEFORM_HPP_
