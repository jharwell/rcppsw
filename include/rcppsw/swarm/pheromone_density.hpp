/**
 * @file pheromone_density.hpp
 *
 * @copyright 2017 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_SWARM_PHEROMONE_DENSITY_HPP_
#define INCLUDE_RCPPSW_SWARM_PHEROMONE_DENSITY_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <algorithm>
#include "rcppsw/math/expression.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, swarm);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class pheromone_density
 * @ingroup swarm
 *
 * @brief Calculates the pheromone density associated with something,
 * which decays over time on its, but can be reinforced by additional entities
 * other than the current one reporting the same thing and reinforcing the
 * density/information relevance.
 *
 * Depends on:
 *
 * - The pheromone decay parameter.
 * - The previous value of the pheromone density.
 */
class pheromone_density : public math::expression<double> {
 public:
  /**
   * @brief Convenience constant for use it adding pheromones to a density.
   */
  static constexpr double kUNIT_QUANTITY = 1.0;

  pheromone_density(void) : pheromone_density{0.0} {}
  explicit pheromone_density(double rho)
      : expression(), m_delta(0), m_rho(rho) {}

  void rho(double rho) { m_rho = rho; }

  void reset(void) {
    set_result(0.0);
    m_delta = 0.0;
  }

  /**
   * @brief Calculates the new pheromone density based on:
   *
   * - The current density
   * - How many unit deposits have been made since the last calculation
   * - The decay rate.
   *
   * @return The new density.
   */
  double update(void) {
    double res = std::max<double>((1.0 - m_rho) * last_result() + m_delta, 0.0);
    m_delta = 0;
    return set_result(res);
  }

  /**
   * @brief Add a deposit of pheromone. Does not update the current
   * value--that must be done separately, so that multiple deposits are batched
   * together for a single value update.
   *
   * @param val The amount of the pheromone deposit. Should pretty much always
   * be 1.0, unless there is a good reason not to do so.
   */
  void pheromone_add(double val) { m_delta += val; }

  /**
   * @brief Set the pheromone density to the specified value. This is useful
   * when repeated pheromone deposits are not desired, but you want to have a
   * way to reset the density of something to a maximum value (e.g. seeing the
   * same block on subsequent timesteps).
   *
   * Also sets the batched/pending updates to 0.
   *
   * @param val The value to set.
   */
  void pheromone_set(double val) { set_result(val); m_delta = 0; }

  /**
   * @brief Subtract two pheromone density objects. Only subtracts the current
   * values, ignoring the current deltas for each object.
   */
  pheromone_density operator-(const pheromone_density& other) const {
    pheromone_density res(*this);
    res -= other;
    return res;
  }

  /**
   * @brief Subtract one pheromone density object from another. Only subtracts
   * the the current values, ignored the current deltas for each object.
   */
  pheromone_density& operator-=(const pheromone_density& other) {
    this->set_result(this->last_result() - other.last_result());
    return *this;
  }

 private:
  /* clang-format off */
  double m_delta;
  double m_rho;
  /* clang-format on */
};

NS_END(swarm, rcppsw);

#endif /* INCLUDE_RCPPSW_SWARM_PHEROMONE_DENSITY_HPP_ */
