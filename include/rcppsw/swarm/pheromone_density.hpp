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
class pheromone_density : public rcppsw::math::expression<double> {
 public:
  pheromone_density(void) : pheromone_density(0.0) {}
  explicit pheromone_density(double rho)
      : expression(), m_delta(0), m_rho(rho) {}

  void rho(double rho) { m_rho = rho; }

  void reset(void) {
    set_result(0.0);
    m_delta = 0.0;
  }
  double calc(void) {
    double res = std::max<double>((1.0 - m_rho) * last_result() + m_delta, 0.0);
    m_delta = 0;
    return set_result(res);
  }
  void pheromone_add(double val) { m_delta += val; }

 private:
  double m_delta;
  double m_rho;
};

NS_END(swarm, rcppsw);

#endif /* INCLUDE_RCPPSW_SWARM_PHEROMONE_DENSITY_HPP_ */
