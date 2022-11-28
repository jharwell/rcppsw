/**
 * @file ct-waveform-test.cpp
 *
 * @copyright 2018 John Harwell.
 *
 * SPDX-License-Identifier: MIT
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
TEST_CASE("Sine Waveform", "[rct::periodic]") {
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

TEST_CASE("Square Waveform", "[rct::periodic]") {
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
TEST_CASE("Sawtooth Waveform", "[rct::periodic]") {
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
