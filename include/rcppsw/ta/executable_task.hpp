/**
 * @file executable_task.hpp
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

#ifndef INCLUDE_RCPPSW_TA_EXECUTABLE_TASK_HPP_
#define INCLUDE_RCPPSW_TA_EXECUTABLE_TASK_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include <vector>

#include "rcppsw/er/client.hpp"
#include "rcppsw/metrics/tasks/execution_metrics.hpp"
#include "rcppsw/ta/abort_probability.hpp"
#include "rcppsw/ta/logical_task.hpp"
#include "rcppsw/ta/time_estimate.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw);
namespace math { namespace config {
struct ema_config;
}} /* namespace math::config */

NS_START(ta);

namespace config {
struct src_sigmoid_sel_config;
} /* namespace config */

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class executable_task
 * @ingroup rcppsw ta
 *
 * @brief Represents the executable concept of a task, which encompasses:
 *
 * - A possibly updated estimate of the time it takes to do a task. If a task is
 *   only made to be executed once, then this field is unused.

 * - A possibly updated estimate of the interface time for the task. If a task
 *   is only made to be executed once, then this field is unused.
 *
 * - A method of decomposing this (possibly decomposable) task into a sequence
 *   of simpler tasks. Each "simpler" task can have a parent.
 *
 * - Metrics that can be collected on a task as it runs.
 */
class executable_task : public logical_task,
                        public metrics::tasks::execution_metrics,
                        public er::client<executable_task> {
 public:
  /*
   * For now...
   */
  static constexpr uint kMAX_INTERFACES = 1;
  static constexpr char kAbortSrcExec[] = "exec";
  static constexpr char kAbortSrcInterface[] = "interface";

  executable_task(const std::string& name,
                  const config::src_sigmoid_sel_config* abort,
                  const math::config::ema_config* estimation);

  ~executable_task(void) override = default;

  /* execution metrics */
  types::timestep task_last_exec_time(void) const override {
    return m_last_exec_time;
  }
  types::timestep task_last_interface_time(uint i) const override {
    return m_last_interface_times[i];
  }
  bool task_aborted(void) const override final { return m_task_aborted; }
  const time_estimate& task_exec_estimate(void) const override final {
    return m_exec_estimate;
  }
  const time_estimate& task_interface_estimate(uint i) const override final {
    return m_interface_estimates[i];
  }
  bool task_at_interface(void) const override {
    return -1 != active_interface();
  }

  /**
   * @brief Update the calculated interface time for the task if the current
   * task has been marked as being at (one of) its task interface(s).
   *
   * This is needed for accurate task abort calculations.
  */
  void interface_time_update(void) {
    if (-1 != active_interface()) {
      m_interface_times[active_interface()] =
          interface_time_calc(active_interface(),
                              m_interface_start_times[active_interface()]);
    }
  }

  /**
   * @brief Get the ID of the active interface.
   *
   * @return The ID, or -1 if there is not currently an active interface.
   */
  int active_interface(void) const RCSW_PURE;

  /**
   * @brief Get the ID of the last active interface.
   *
   * @return The ID, or -1 if an interface has not yet been completed.
   */
  int task_last_active_interface(void) const override final {
    return m_last_active_interface;
  }

  /**
   * @brief Because tasks can have multiple interfaces, they need a way to reset
   * their interface time upon leaving/entering an interface.
   */
  void interface_time_reset(void) {
    if (-1 != active_interface()) {
      m_interface_times[active_interface()] = types::timestep(0);
    }
  }

  /**
   * @brief Update the calculated abort probability for the task. This should be
   * done every timestep, even if there are logical "gates" that will only
   * result in a non-zero abort probability on some timesteps.
   */
  void abort_prob_update(void) {
    if (kAbortSrcExec == mc_abort_src) {
      m_abort_prob.calc(m_exec_time, m_exec_estimate);
      return;
    } else if (kAbortSrcInterface == mc_abort_src) {
      if (-1 != active_interface()) {
        m_abort_prob.calc(m_interface_times[active_interface()],
                          m_interface_estimates[active_interface()]);
        return;
      }
    } else {
      ER_FATAL_SENTINEL("Bad abort source '%s'", mc_abort_src.c_str());
    }
  }

  /**
   * @brief Update the calculated execution time for the task
   *
   * This is needed for accurate task abort calculations.
   */
  types::timestep exec_time_update(void) {
    return m_exec_time = current_time() - m_exec_start_time;
  }

  /**
   * @brief Reset the execution time for the task.
   */
  void exec_time_reset(void) {
    m_last_exec_time = m_exec_time;
    m_exec_start_time = current_time();
  }

  /**
   * @brief Update the current estimate of the task interface time by using a
   * weighted sum of the previous \ref time_estimate and the new value.
   *
   * @param i The interface ID.
   * @param last_measure The last measured time.
   */
  void interface_estimate_update(uint i, const types::timestep& last_measure) {
    m_interface_estimates[i](last_measure.v());
  }

  /**
   * @brief Update the current estimate of the task execution time by using a
   * weighted sum of the previous \ref time_estimate and the new value.
   *
   * @param last_measure The last measured time.
   */
  void exec_estimate_update(const types::timestep& last_measure) {
    m_exec_estimate(last_measure.v());
  }

  /**
   * @brief Initialize the execution time estimate for the task. This ignores
   * the value of the alpha parameter for updating estimates.
   *
   * @param init_measure Initial execution estimate.
   */
  void exec_estimate_init(const types::timestep& init_measure) {
    m_exec_estimate.eval(init_measure.v());
  }

  /**
   * @brief The method that all tasks must define that specifies how to execute
   * the task.
   */
  virtual void task_execute(void) = 0;

  /**
   * @brief Get the probability of aborting an executable task.
   *
   * Even though this class also has public functions for updating the
   * internally maintained abort probability, this function is still needed in
   * order to provide "gated" abort probabilities (i.e. abort probabilities that
   * are only active when certain conditions are met).
   */
  virtual double abort_prob_calc(void) = 0;

  /**
   * @brief (Possibly) update/change which interface is currently active.
   *
   * @param i The currently active interface, -1 if none active.
   */
  virtual void active_interface_update(int i) = 0;

  /**
   * @brief Get the current interface time of the task for the specified
   * interface.
   *
   * @param i The interface ID.
   */
  types::timestep interface_time(uint i) const { return m_interface_times[i]; }

  /**
   * @brief Get the current abort probability at the specified interface.
   *
   */
  double abort_prob(void) const { return m_abort_prob.v(); }

  /**
   * @brief Get the current execution time of the task.
   */
  types::timestep exec_time(void) const { return m_exec_time; }

  /**
   * @brief Get if a task is currently atomic (i.e. not abortable).
   */
  bool is_atomic(void) const { return m_is_atomic; }

  /**
   * @brief Set a task as atomic, meaning that it cannot be aborted during
   * execution.
   */
  void set_atomic(bool b) { m_is_atomic = b; }

  /**
   * @brief Get if a task is partitionable.
   */
  bool is_partitionable(void) const { return m_is_partitionable; }

  /**
   * @brief Set a task as partitionable.
   */
  void set_partitionable(bool b) { m_is_partitionable = b; }

  void task_aborted(bool task_aborted) { m_task_aborted = task_aborted; }

 protected:
  /**
   * @brief Calculate the interface time of the current task for use in abort
   * calculations.
   *
   * @param i The interface ID.
   * @param start_time The timestep upon which the task entered the interface.
   */
  virtual types::timestep interface_time_calc(
      uint i,
      const types::timestep& start_time) = 0;

  /**
   * @brief Get the current time
   */
  virtual types::timestep current_time(void) const = 0;

  void interface_time_mark_finish(uint i) {
    m_last_interface_times[i] = m_interface_times[i];
  }

  /**
   * @brief Mark the current timestep as the begin of a task's interface.
   */
  void interface_time_mark_start(uint i) {
    m_interface_start_times[i] = current_time();
  }
  bool interface_in_prog(uint i) const { return m_interface_in_prog[i]; }
  void interface_enter(uint i) {
    m_interface_in_prog[i] = true;
    last_active_interface_reset();
  }
  void interface_exit(uint i) {
    m_interface_in_prog[i] = false;
    m_last_active_interface = i;
  }

 private:
  void last_active_interface_reset(void) { m_last_active_interface = -1; }

  /* clang-format off */
  const std::string            mc_abort_src;

  bool                         m_is_atomic{false};
  bool                         m_is_partitionable{false};
  std::vector<bool>            m_interface_in_prog;
  int                          m_last_active_interface{-1};

  std::vector<types::timestep> m_interface_times;
  std::vector<types::timestep> m_last_interface_times;
  std::vector<types::timestep> m_interface_start_times;
  std::vector<time_estimate>   m_interface_estimates;

  types::timestep              m_exec_time{0};
  types::timestep              m_last_exec_time{0};
  types::timestep              m_exec_start_time{0};
  time_estimate                m_exec_estimate;

  bool                         m_task_aborted{false};
  abort_probability            m_abort_prob;
  /* clang-format on */
};

NS_END(ta, rcppsw);

#endif /* INCLUDE_RCPPSW_TA_EXECUTABLE_TASK_HPP_ */
