/**
 * @file convergence_calculator.cpp
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

/*******************************************************************************
 * Includes
 ******************************************************************************/
/*
 * This is needed because without it boost instantiates static assertions that
 * verify that every possible handler<measure> instantiation is valid. These
 * will not happen in reality (or shouldn't), and if they do it's 100% OK to
 * crash with an exception.
 */
#define BOOST_VARIANT_USE_RELAXED_GET_BY_DEFAULT
#include "rcppsw/swarm/convergence/convergence_calculator.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, swarm, convergence);
namespace rcluster = algorithm::clustering;

/*******************************************************************************
 * Type Definitions
 ******************************************************************************/
/**
 * @struct convergence_measure_updater
 * @ingroup rcppsw swarm convergence
 *
 * @brief Visitor class for mapping a given convergence measure to the actions
 * necessary to update it. Needed because not all convergence measures take the
 * same number/type of parameters. This could also be solved with a parameter
 * base class/derived classes and dynamic casting, but I think this is cleaner.
 *
 * It is passed the callbacks from the calculator, rather than the results, so
 * that it is only if a specific type of convergence calculation is enabled that
 * the necessary input data is generated, as this may be as expensive as the
 * actual convergence calculation itself.
 */
struct convergence_measure_updater : boost::static_visitor<void> {
  convergence_measure_updater(
      uint n,
      convergence_calculator::swarm_headings_calc_ftype headings_calc,
      convergence_calculator::swarm_nn_calc_ftype nn_calc,
      convergence_calculator::swarm_pos_calc_ftype pos_calc,
      convergence_calculator::swarm_tasks_calc_ftype tasks_calc)
      : n_threads(n),
        swarm_headings_calc(std::move(headings_calc)),
        swarm_nn_calc(std::move(nn_calc)),
        swarm_pos_calc(std::move(pos_calc)),
        swarm_tasks_calc(std::move(tasks_calc)) {}
  void operator()(interactivity& i) { i(swarm_nn_calc(n_threads)); }
  void operator()(angular_order& ang) {
    ang(swarm_headings_calc(n_threads), n_threads);
  }

  void operator()(positional_entropy& pos) { pos(swarm_pos_calc(n_threads)); }

  void operator()(task_dist_entropy& tdist) {
    tdist(swarm_tasks_calc(n_threads));
  }

  uint n_threads;
  convergence_calculator::swarm_headings_calc_ftype swarm_headings_calc;
  convergence_calculator::swarm_nn_calc_ftype swarm_nn_calc;
  convergence_calculator::swarm_pos_calc_ftype swarm_pos_calc;
  convergence_calculator::swarm_tasks_calc_ftype swarm_tasks_calc;
};

/**
 * @struct convergence_status_updater
 * @ingroup rcppsw swarm convergence
 *
 * @brief Visitor class for gather the convergence status of each enabled type
 * of convergence calculation.
 */
struct convergence_status_collator : boost::static_visitor<bool> {
  bool operator()(const interactivity& i) const { return i.converged(); }
  bool operator()(const angular_order& ang) const { return ang.converged(); }
  bool operator()(const positional_entropy& pos) const {
    return pos.converged();
  }
  bool operator()(const task_dist_entropy& dist) const {
    return dist.converged();
  }
};

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/
convergence_calculator::convergence_calculator(
    const config::convergence_config* const config,
    swarm_headings_calc_ftype headings_calc,
    swarm_nn_calc_ftype nn_calc,
    swarm_pos_calc_ftype pos_calc)
    : ER_CLIENT_INIT("rcppsw.swarm.convergence.calculator"),
      mc_config(*config),
      m_swarm_headings_calc(std::move(headings_calc)),
      m_swarm_nn_calc(std::move(nn_calc)),
      m_swarm_pos_calc(std::move(pos_calc)) {
  if (config->interactivity.enable) {
    ER_ASSERT(nullptr != m_swarm_nn_calc,
              "NULL swarm nn cb with interactivity convergence enabled");
    m_measures.emplace(typeid(interactivity), interactivity(config->epsilon));
  }
  if (config->ang_order.enable) {
    ER_ASSERT(nullptr != m_swarm_headings_calc,
              "NULL swarm headings cb with angular order convergence enabled");
    m_measures.emplace(typeid(angular_order), angular_order(config->epsilon));
  }

  if (config->pos_entropy.enable) {
    ER_ASSERT(
        nullptr != m_swarm_pos_calc,
        "NULL swarm positions cb with positional entropy convergence enabled");
    m_measures.emplace(
        typeid(positional_entropy),
        positional_entropy(
            config->epsilon,
            std::make_unique<rcluster::detail::entropy_impl<math::vector2d>>(
                mc_config.n_threads),
            &mc_config.pos_entropy));
  }
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void convergence_calculator::task_dist_init(
    const swarm_tasks_calc_ftype& tasks_calc) {
  m_swarm_tasks_calc = tasks_calc;
  if (mc_config.task_dist_entropy.enable) {
    ER_ASSERT(nullptr != m_swarm_tasks_calc,
              "NULL swarm tasks cb with task distribution entropy convergence "
              "enabled");
    m_measures.emplace(typeid(task_dist_entropy),
                       task_dist_entropy(mc_config.epsilon));
  }
} /* task_dist_init() */

void convergence_calculator::update(void) {
  convergence_measure_updater u{mc_config.n_threads,
                                m_swarm_headings_calc,
                                m_swarm_nn_calc,
                                m_swarm_pos_calc,
                                m_swarm_tasks_calc};
  for (auto& m : m_measures) {
    boost::apply_visitor(u, m.second);
  } /* for(&m..) */
} /* update() */

bool convergence_calculator::converged(void) const {
  bool ret = false;
  for (const auto& m : m_measures) {
    ret |= boost::apply_visitor(convergence_status_collator(), m.second);
  } /* for(&m..) */
  return ret;
} /* converged() */

convergence_calculator::conv_status_t convergence_calculator::swarm_interactivity(
    void) const {
  if (!mc_config.interactivity.enable) {
    return std::make_tuple(0.0, 0.0, false);
  }
  auto& tmp = boost::get<interactivity>(m_measures.at(typeid(interactivity)));
  return std::make_tuple(tmp.raw(), tmp.v(), tmp.converged());
} /* swarm_interactivity() */

convergence_calculator::conv_status_t convergence_calculator::swarm_angular_order(
    void) const {
  if (!mc_config.ang_order.enable) {
    return std::make_tuple(0.0, 0.0, false);
  }
  auto& tmp = boost::get<angular_order>(m_measures.at(typeid(angular_order)));
  return std::make_tuple(tmp.raw(), tmp.v(), tmp.converged());
} /* swarm_angular_order() */

convergence_calculator::conv_status_t convergence_calculator::
    swarm_positional_entropy(void) const {
  if (!mc_config.pos_entropy.enable) {
    return std::make_tuple(0.0, 0.0, false);
  }
  auto& tmp =
      boost::get<positional_entropy>(m_measures.at(typeid(positional_entropy)));
  return std::make_tuple(tmp.raw(), tmp.v(), tmp.converged());
} /* swarm_positional_entropy() */

convergence_calculator::conv_status_t convergence_calculator::swarm_task_dist_entropy(
    void) const {
  if (!mc_config.task_dist_entropy.enable) {
    return std::make_tuple(0.0, 0.0, false);
  }
  auto& tmp =
      boost::get<task_dist_entropy>(m_measures.at(typeid(task_dist_entropy)));
  return std::make_tuple(tmp.raw(), tmp.v(), tmp.converged());
} /* swarm_task_dist_entropy() */

void convergence_calculator::reset_metrics(void) {
  if (mc_config.interactivity.enable) {
    boost::get<interactivity>(m_measures.at(typeid(interactivity))).reset();
  }
  if (mc_config.ang_order.enable) {
    boost::get<angular_order>(m_measures.at(typeid(angular_order))).reset();
  }
  if (mc_config.pos_entropy.enable) {
    boost::get<positional_entropy>(m_measures.at(typeid(positional_entropy)))
        .reset();
  }
  if (mc_config.task_dist_entropy.enable) {
    boost::get<task_dist_entropy>(m_measures.at(typeid(task_dist_entropy)))
        .reset();
  }
} /* reset_metrics() */

NS_END(convergence, swarm, rcppsw);
