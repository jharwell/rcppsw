/**
 * @file waveform-test.cpp
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

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/control/periodic_waveform.hpp"
#include <vector>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace ct = rcppsw::control;

/*******************************************************************************
 * Global Variables
 ******************************************************************************/
ct::config::waveform_config config{
  "unused",
      0.01,
      0,
      10,
      0
      };


/*******************************************************************************
 * Test Cases
 ******************************************************************************/
TEST_CASE("Sine Waveform", "[periodic]") {
  ct::sine_waveform s1(&config);
  std::vector<double> values;
  for (size_t i = 0; i < 1000; ++i) {
    values.push_back(s1.value(i));
  } /* for(i..) */

  std::ofstream f("sine_s1", std::ios_base::trunc | std::ios_base::out);
  f << "timestep; value;" << std::endl;
  for (size_t i = 0; i < values.size(); ++i) {
    f << i << ";" << values[i] << ";" << std::endl;
  } /* for(i..) */
}

TEST_CASE("Square Waveform", "[periodic]") {
  ct::square_waveform s1(&config);
  std::vector<double> values;
  for (size_t i = 0; i < 1000; ++i) {
    values.push_back(s1.value(i));
  } /* for(i..) */

  std::ofstream f("square_s1", std::ios_base::trunc | std::ios_base::out);
  f << "timestep; value;" << std::endl;
  for (size_t i = 0; i < values.size(); ++i) {
    f << i << ";" << values[i] << ";" << std::endl;
  } /* for(i..) */
}
TEST_CASE("Sawtooth Waveform", "[periodic]") {
  ct::sawtooth_waveform s1(&config);
  std::vector<double> values;
  for (size_t i = 0; i < 1000; ++i) {
    values.push_back(s1.value(i));
  } /* for(i..) */

  std::ofstream f("sawtooth_s1", std::ios_base::trunc | std::ios_base::out);
  f << "timestep; value;" << std::endl;
  for (size_t i = 0; i < values.size(); ++i) {
    f << i << ";" << values[i] << ";" << std::endl;
  } /* for(i..) */
}
