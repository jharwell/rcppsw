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
#include "rcppsw/er/client.hpp"
#include "rcppsw/math/expression.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, swarm);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class pheromone_density
 * @ingroup rcppsw swarm
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
class pheromone_density final : public math::expression<double>,
                                public er::client<pheromone_density> {
 public:
  /**
   * @brief Convenience constant for use it adding pheromones to a density.
   */
  static constexpr double kUNIT_QUANTITY = 1.0;

  pheromone_density(void) : pheromone_density{-1.0} {}

  explicit pheromone_density(double rho)
      : ER_CLIENT_INIT("rcppsw.swarm.pheromone"), m_delta(0), m_rho(rho) {}

  void rho(double rho) { m_rho = rho; }

  void reset(void) {
    eval(0.0);
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
    ER_ASSERT(m_rho > 0, "Bad rho: %f", m_rho);
    double res = std::max<double>((1.0 - m_rho) * v() + m_delta, 0.0);
    m_delta = 0;
    return eval(res);
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
  void pheromone_set(double val) {
    eval(val);
    m_delta = 0;
  }

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
   * the the current values, ignoring the current deltas for each object.
   */
  pheromone_density& operator-=(const pheromone_density& other) {
    this->eval(this->v() - other.v());
    return *this;
  }

  /**
   * @brief Add two pheromone density objects. Only adds the current values,
   * ignoring the current deltas for each object.
   */
  pheromone_density operator+(const pheromone_density& other) const {
    pheromone_density res(*this);
    res += other;
    return res;
  }

  /**
   * @brief Add one pheromone density to another. Only adds the the current
   * values, ignoring the current deltas for each object.
   */
  pheromone_density& operator+=(const pheromone_density& other) {
    this->eval(this->v() + other.v());
    return *this;
  }
  /**
   * @brief Divides a density by a constant factor, ignoring current deltas for
   * the object.
   */
  pheromone_density operator/(double div) const {
    pheromone_density res(*this);
    res.eval(this->v() / div);
    return res;
  }

 private:
  /* clang-format off */
  double m_delta;
  double m_rho;
  /* clang-format on */
};

NS_END(swarm, rcppsw);

#endif /* INCLUDE_RCPPSW_SWARM_PHEROMONE_DENSITY_HPP_ */
