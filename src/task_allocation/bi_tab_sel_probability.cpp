/**
 * @file bi_tab_sel_probability.cpp
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

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/task_allocation/bi_tab_sel_probability.hpp"
#include <cassert>
#include <cmath>
#include "rcppsw/task_allocation/bi_tab.hpp"
#include "rcppsw/task_allocation/polled_task.hpp"
#include "rcppsw/task_allocation/src_sigmoid_sel_params.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Constants
 ******************************************************************************/
constexpr char bi_tab_sel_probability::kMethodHarwell2019[];
constexpr char bi_tab_sel_probability::kMethodRandom[];

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
bi_tab_sel_probability::bi_tab_sel_probability(const std::string& method)
    : ER_CLIENT_INIT("rcppsw.ta.bi_tab_sel_prob"),
      sigmoid(),
      mc_method(method) {
  if (kMethodHarwell2019 == method) {
    sigmoid::init(kHARWELL2019_REACTIVITY,
                  kHARWELL2019_OFFSET,
                  kHARWELL2019_GAMMA);
  } else if (kMethodRandom == method) {
  }
  ER_FATAL_SENTINEL("Bad method '%s' selected", method.c_str());
}

bi_tab_sel_probability::bi_tab_sel_probability(
    const struct src_sigmoid_sel_params* const params)
    : ER_CLIENT_INIT("rcppsw.ta.bi_tab_sel_prob"),
      sigmoid(&params->sigmoid.sigmoid),
      mc_method(params->sigmoid.method) {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
__rcsw_const double bi_tab_sel_probability::calc_random(void) {
  return 0.5;
} /* calc_random() */

__rcsw_pure double bi_tab_sel_probability::calc_harwell2019(const bi_tab& tab1,
                                                            const bi_tab& tab2) {
  double ratio1 =
      std::fabs(tab1.root()->task_exec_estimate().last_result() -
                (tab1.child1()->task_exec_estimate().last_result() +
                 tab1.child2()->task_exec_estimate().last_result())) /
      tab1.root()->task_exec_estimate().last_result();
  double ratio2 =
      std::fabs(tab2.root()->task_exec_estimate().last_result() -
                (tab2.child1()->task_exec_estimate().last_result() +
                 tab2.child2()->task_exec_estimate().last_result())) /
      tab2.root()->task_exec_estimate().last_result();
  return calc_sigmoid(ratio1, ratio2);
} /* calc_harwell2019() */

__rcsw_pure double bi_tab_sel_probability::calc_sigmoid(double ratio1,
                                                        double ratio2) {
  /*
   * No information available--just pick randomly.
   */
  if (!(ratio1 > 0 && ratio2 > 0)) {
    return 0.5;
  } else if (!(ratio1 > 0)) { /* have info on tab2 only */
    return 0.0;
  } else if (!(ratio2 > 0)) { /* have info on tab1 only */
    return 1.0;
  }
  double theta = reactivity() * (offset() - ratio1 / ratio2);
  return set_result(1.0 / (1 + std::exp(-theta)) * gamma());
} /* calc_sigmoid() */

double bi_tab_sel_probability::operator()(const bi_tab* const tab1,
                                          const bi_tab* const tab2) {
  if (kMethodHarwell2019 == mc_method) {
    return calc_harwell2019(*tab1, *tab2);
  } else if (kMethodRandom == mc_method) {
    return calc_random();
  }
  ER_FATAL_SENTINEL("Bad method '%s' selected", mc_method.c_str());
  return 0.0;
} /* operator() */

NS_END(task_allocation, rcppsw);
