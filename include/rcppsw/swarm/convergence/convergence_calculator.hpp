/**
 * @file convergence_calculator.hpp
 *
 * @copyright 2019 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_SWARM_CONVERGENCE_CONVERGENCE_CALCULATOR_HPP_
#define INCLUDE_RCPPSW_SWARM_CONVERGENCE_CONVERGENCE_CALCULATOR_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <boost/variant.hpp>
#include <utility>
#include <vector>

#include "rcppsw/swarm/convergence/convergence_params.hpp"
#include "rcppsw/swarm/convergence/interactivity.hpp"
#include "rcppsw/swarm/convergence/angular_order.hpp"
#include "rcppsw/swarm/convergence/positional_entropy.hpp"
#include "rcppsw/swarm/convergence/task_dist_entropy.hpp"
#include "rcppsw/metrics/swarm/convergence_metrics.hpp"
#include "rcppsw/ds/type_map.hpp"
#include "rcppsw/er/client.hpp"
#include "rcppsw/mpl/typelist.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, swarm, convergence);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class convergence_calculator
 * @ingroup swarm convergence
 *
 * @brief Convenience class for managing calculation of swarm convergence using
 * any enabled methods.
 *
 * Takes a set of optional callbacks for during construction for calculating the
 * various quantities needed for convergence calculations (if a specific type of
 * convergence calculation is enabled, then you obviously need to pass a valid
 * callback to calculate the necessary input data).
 */
class convergence_calculator : public metrics::swarm::convergence_metrics,
                               public er::client<convergence_calculator> {
 public:
  /**
   * @brief Callback function that returns a vector of robot headings (1 per
   * robot). Used to calculate swarm angular order.
   *
   * Takes a single integer argument specifying the # OpenMP threads to be
   * used, per configuration.
   */
  using swarm_headings_calc_ftype = std::function<std::vector<math::radians>(uint)>;

  /**
   * @brief Callback function that returns a vector of nearest neighbor
   * distances (1 per robot). Used to calculate swarm interactivity.
   *
   * Takes a single integer argument specifying the # OpenMP threads to be
   * used, per configuration
   */
  using swarm_nn_calc_ftype = std::function<std::vector<double>(uint)>;

  /**
   * @brief Callback function that returns a vector of robot positions (1 per
   * robot). Used to calculate swarm positional entropy.
   *
   * Takes a single integer argument specifying the # OpenMP threads to be
   * used, per configuration.
   */
  using swarm_pos_calc_ftype = std::function<std::vector<math::vector2d>(uint)>;

  /**
   * @brief Callback function that returns a vector of robot tasks (as unique
   * non-negative numbers, 1 per robot). Used to calculate swarm task
   * distribution entropy.
   *
   * Tasks a single integer argument specifying the # OpenMP threads to be used,
   * per configuration.
   */
  using swarm_tasks_calc_ftype = std::function<std::vector<int>(uint)>;

  explicit convergence_calculator(const convergence_params* params,
                                  swarm_headings_calc_ftype headings_calc,
                                  swarm_nn_calc_ftype nn_calc,
                                  swarm_pos_calc_ftype pos_calc);

  /**
   * @brief Not included in the constructor arguments because not all swarms use
   * tasks.
   */
  void task_dist_init(const swarm_tasks_calc_ftype& tasks_calc);

  /* convergence metrics */
  conv_status_t swarm_interactivity(void) const override;
  conv_status_t swarm_angular_order(void) const override;
  conv_status_t swarm_positional_entropy(void) const override;
  conv_status_t swarm_task_dist_entropy(void) const override;
  double swarm_conv_epsilon(void) const override { return mc_params.epsilon; }
  void reset_metrics(void) override;

  /**
   * @brief Return swarm convergence status in an OR fashion (i.e. if ANY of the
   * configured methods say convergence has occured, return \c TRUE).
   */
  bool converged(void) const;

  /**
   * @brief Update convergence calculations for the current timestep
   */
  void update(void);

 private:
  /* clang-format off */
  const convergence_params    mc_params;
  ds::type_map<mpl::typelist<positional_entropy,
                             task_dist_entropy,
                             angular_order,
                             interactivity>> m_measures{};
  swarm_headings_calc_ftype   m_swarm_headings_calc;
  swarm_nn_calc_ftype         m_swarm_nn_calc;
  swarm_pos_calc_ftype        m_swarm_pos_calc;
  swarm_tasks_calc_ftype      m_swarm_tasks_calc{nullptr};
  /* clang-format on */
};

NS_END(convergence, swarm, rcppsw);

#endif /* INCLUDE_RCPPSW_SWARM_CONVERGENCE_CONVERGENCE_CALCULATOR_HPP_ */
