/**
 * @file bi_tab_sel_probability.hpp
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

#ifndef INCLUDE_RCPPSW_TA_BI_TAB_SEL_PROBABILITY_HPP_
#define INCLUDE_RCPPSW_TA_BI_TAB_SEL_PROBABILITY_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <random>
#include <string>

#include "rcppsw/er/client.hpp"
#include "rcppsw/math/sigmoid.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ta);
class bi_tab;

namespace config {
struct src_sigmoid_sel_config;
} /* namespace config */

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class bi_tab_sel_probability
 * @ingroup rcppsw ta
 *
 * @brief Calculates the probability that a robot selects a given TAB or its
 * child/parent TAB (depending on whether the most recently finished/aborted
 * task is a child or the root of the current TAB).
 *
 * Let the current TAB be TAB i, and the child/parent TAB be TAB j. We compute
 * how balanced/unbalanced the execution time estimates of root vs (child1 +
 * child2) for both TABs. If the resulting ratios are equal (or very close),
 * then there is probably a good distribution of controller executing tasks from
 * each TAB, and the execution estimates are probably fairly reliable, and you
 * should not switch TABs.
 *
 * Assume the ratio for TAB j (the other TAB) is 1.0. Then, as the TAB i ratio
 * goes to 0 or infinity, the probability of switching to TAB j goes to 1.0.
 *
 * Depends on:
 *
 * - The robot's time estimates of how long it takes to complete task in each
     TAB.
 *
 * - The reactivity parameter: How quickly should the increase in sel
 *   probability be for an increasing difference between TAB balance ratios.
 *
 * - The offset parameter: What is the threshold beneath which differences in
 *   the TAB balance ratios are not considered consequential, and above which
 *   controller should prefer to switch TABs with quickly increasing probability.
 *
 * - reactivity > 0.
 * - offset > 1.
 * - 0 < gamma < 1.
*/
class bi_tab_sel_probability : public er::client<bi_tab_sel_probability>,
                               public math::sigmoid {
 public:
  static constexpr double kHARWELL2019_REACTIVITY = 8.0;
  static constexpr double kHARWELL2019_OFFSET = 1.25;
  static constexpr double kHARWELL2019_GAMMA = 1.0;

  static constexpr char kMethodHarwell2019[] = "harwell2019";
  static constexpr char kMethodRandom[] = "random";

  /**
   * @brief Initialize subtask sel probability with default values, based
   * on whatever the selected method is.
   */
  explicit bi_tab_sel_probability(const std::string& method);

  /**
   * @brief Initialize subtask sel probability with method + parameter
   * values.
   */
  explicit bi_tab_sel_probability(const config::src_sigmoid_sel_config* config);

  const std::string& method(void) const { return mc_method; }

  /**
   * @brief Calculate the sel probability based on the configured method,
   * using the most recent time estimates of tasks in each TAB.
   */
  double operator()(const bi_tab* tab1,
                    const bi_tab* tab2,
                    std::default_random_engine& rng);

 private:
  /**
   * @brief Random TAB sel, regardless of time estimates.
   */
  double calc_random(std::default_random_engine& rng);

  /**
   * @brief Calculate the probability of switching from TAB 1 to TAB 2
   * using the piecewise method described in Harwell2019.
   *
   * @param bi_tab1 Current TAB.
   * @param bi_tab2 Other TAB to consider switching to.
   *
   * @return Probability of switching.
   */
  double calc_harwell2019(const bi_tab& tab1,
                          const bi_tab& tab2,
                          std::default_random_engine& rng);

  /**
   * @brief Calculate the sigmoid activation for a pair of time estimates using
   * time estimates.
   *
   * @param ratio1 Specifies how balanced the exec estimates are in the
   *               current TAB. [0,1].
   * @param ratio2 Specifies how balanced the exec estimates are in the
   *               other TAB. [0,1].
   *
   * @return Sigmoid value.
   */
  double calc_sigmoid(double ratio1,
                      double ratio2,
                      std::default_random_engine& rng);

  /* clang-format off */
  const std::string mc_method;
  /* clang-format on */
};

NS_END(ta, rcppsw);

#endif /* INCLUDE_RCPPSW_TA_BI_TAB_SEL_PROBABILITY_HPP_ */
