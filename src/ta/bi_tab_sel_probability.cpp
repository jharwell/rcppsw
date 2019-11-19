/**
 * \file bi_tab_sel_probability.cpp
 *
 * \copyright 2018 John Harwell, All rights reserved.
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
#include "rcppsw/ta/bi_tab_sel_probability.hpp"

#include <cassert>
#include <cmath>

#include "rcppsw/ta/config/src_sigmoid_sel_config.hpp"
#include "rcppsw/ta/ds/bi_tab.hpp"
#include "rcppsw/ta/polled_task.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ta);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
bi_tab_sel_probability::bi_tab_sel_probability(const std::string& method)
    : ER_CLIENT_INIT("rcppsw.ta.bi_tab_sel_prob"), mc_method(method) {
  if (kMethodHarwell2019 == method) {
    sigmoid::init(kHARWELL2019_REACTIVITY,
                  kHARWELL2019_OFFSET,
                  kHARWELL2019_GAMMA);
  } else if (kMethodRandom == method) {
  }
  ER_FATAL_SENTINEL("Bad method '%s' selected", method.c_str());
}

bi_tab_sel_probability::bi_tab_sel_probability(
    const config::src_sigmoid_sel_config* const config)
    : ER_CLIENT_INIT("rcppsw.ta.bi_tab_sel_prob"),
      sigmoid(&config->sigmoid.sigmoid),
      mc_method(config->sigmoid.method) {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

double bi_tab_sel_probability::calc_random(math::rng* rng) {
  return eval(rng->uniform(0.0, 1.0));
} /* calc_random() */

double bi_tab_sel_probability::calc_harwell2019(const ds::bi_tab& tab1,
                                                const ds::bi_tab& tab2) {
  auto t1r_est = tab1.root()->task_exec_estimate();
  auto t1c1_est = tab1.child1()->task_exec_estimate();
  auto t1c2_est = tab1.child2()->task_exec_estimate();

  auto t2r_est = tab2.root()->task_exec_estimate();
  auto t2c1_est = tab2.child1()->task_exec_estimate();
  auto t2c2_est = tab2.child2()->task_exec_estimate();

  /*
   * No information available, apply L'Hospital's rule to obtain new ratio terms
   * that ARE defined.
   */
  double ratio1, ratio2;
  if (0 == t1r_est && 0 == t2r_est) {
    ratio1 = (t1c1_est + t1c2_est).v();
    ratio2 = (t2c1_est + t2c2_est).v();
  } else if (0 == t1r_est || 0 == t2r_est) {
    /* info on one tab root only--explore! */
    return 1.0;
  } else { /* general case--have info on both TAB roots */
    ratio1 = std::abs(((t1r_est - (t1c1_est + t1c2_est)) / t1r_est).v());
    ratio2 = std::abs(((t2r_est - (t2c1_est + t2c2_est)) / t2r_est).v());
  }

  return eval(calc_sigmoid(ratio1, ratio2));
} /* calc_harwell2019() */

double bi_tab_sel_probability::calc_sigmoid(double ratio1, double ratio2) {
  double theta = reactivity() * (ratio1 / ratio2 - offset());
  return 1.0 / (1 + std::exp(-theta)) * gamma();
} /* calc_sigmoid() */

double bi_tab_sel_probability::operator()(const ds::bi_tab* const tab1,
                                          const ds::bi_tab* const tab2,
                                          math::rng* rng) {
  if (kMethodHarwell2019 == mc_method) {
    return calc_harwell2019(*tab1, *tab2);
  } else if (kMethodRandom == mc_method) {
    return calc_random(rng);
  }
  ER_FATAL_SENTINEL("Bad method '%s' selected", mc_method.c_str());
  return 0.0;
} /* operator() */

NS_END(ta, rcppsw);
