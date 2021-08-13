/**
 * \file poisson_queue.hpp
 *
 * \copyright 2020 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_DS_POISSON_QUEUE_HPP_
#define INCLUDE_RCPPSW_DS_POISSON_QUEUE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <boost/optional.hpp>
#include <deque>

#include "rcsw/common/fpc.h"

#include "rcppsw/math/rng.hpp"
#include "rcppsw/rcppsw.hpp"
#include "rcppsw/types/timestep.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ds);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class poisson_queue
 * \ingroup ds
 *
 * \brief A wrapper around std::queue to make it more amenable to queueing
 * theoretic analysis by tracking queue state.
 */
template <typename T>
class poisson_queue {
 public:
  /**
   * \brief Metadata for tracking enqueue_queue/dequeue operations.
   */
  struct op_metadata {
    /**
     * \brief The # of operations since the last reset.
     */
    size_t count{ 0 };

    /**
     * \brief The # of operations since the beginning of time.
     */
    size_t total_count{ 0 };

    /**
     * \brief The accumulated time between operations since the last reset.
     */
    types::timestep interval_accum{ 0 };

    /**
     * \brief The accumulated time between operations since the beginning of
     * time.
     */
    types::timestep total_interval_accum{ 0 };
  };

  /**
   * \param lambda The enqueue rate for the queue.
   * \param mu The dequeue rate for the queue.
   */
  poisson_queue(double lambda, double mu, math::rng* rng)
      : mc_lambda(lambda), mc_mu(mu), m_rng(rng) {}

  /* not assignable or copy-constructible by default */
  poisson_queue(const poisson_queue&) = delete;
  const poisson_queue& operator=(const poisson_queue&) = delete;

  /**
   * \brief Get the current enqueue data.
   */
  op_metadata enqueue_data(void) const { return m_enqueue.md; }

  /**
   * \brief Get the current dequeue data.
   */
  op_metadata dequeue_data(void) const { return m_dequeue.md; }

  double lambda(void) const { return mc_lambda; }
  double mu(void) const { return mc_mu; }

  /**
   * \brief Check if the conditions are ready for enqueueing into the queue as
   * part of a poisson process. Does not perform the enqueue operation.
   *
   * \return \c TRUE if an event has been triggered for enqueueing, \c FALSE
   * otherwise.
   */
  bool enqueue_check(const types::timestep& t) {
    RCSW_FPC_NV(false, mc_lambda > 0.0);
    if (!m_enqueue.op_set) {
      double val = m_rng->exponential(mc_lambda);

      m_enqueue.next_op_time = m_enqueue.last_op_time + static_cast<uint>(val);
      m_enqueue.op_set = true;
    }
    return t >= m_enqueue.next_op_time;
  }

  /**
   * \brief Check if the conditions are ready for dequeue at time \p t from the
   * queue as part of a poisson process. Does not perform the dequeue operation.
   *
   * \return \c TRUE if an event has been triggered for dequeueing, \c FALSE
   * otherwise.
   */
  bool dequeue_check(const types::timestep& t) {
    RCSW_FPC_NV(false, mc_mu > 0.0);
    if (!m_dequeue.op_set) {
      double val = m_rng->exponential(mc_mu);
      m_dequeue.next_op_time = m_dequeue.last_op_time + static_cast<uint>(val);
      m_dequeue.op_set = true;
    }
    return t >= m_dequeue.next_op_time;
  }

  /**
   * \brief Add an item to the queue after an event has been triggered at time
   * \p t. This is a separate function from checking for the event because it
   * may be that generating the items to enqueue is a non-trivial and/or
   * non-reversible task, and we only want to force the caller to do that when
   * necessary.
   */
  void enqueue(const T& item, const types::timestep& t) {
    ++m_enqueue.md.total_count;
    ++m_enqueue.md.count;
    m_enqueue.md.interval_accum += types::timestep(t - m_enqueue.last_op_time);
    m_enqueue.md.total_interval_accum +=
        types::timestep(t - m_enqueue.last_op_time);

    m_enqueue.last_op_time = t;
    m_enqueue.op_set = false;
    m_queue.push_back(item);
  }

  /**
   * \brief Remove an item from the queue after an event has been
   * triggered. This is a separate function from checking for the event for
   * symmetry with the enqueue operation.
   *
   * \param fake Allow for a fake dequeue in which nothing is returned but the
   * metadata for dequeueing is still updated as if there was something in the
   * queue. Useful for simulating queues of infinite size/queues where the
   * objects to dequeue cannot be put into the queue a priori.
   *
   * \param t The current timestep.
   */
  boost::optional<T> dequeue(const types::timestep& t, bool fake) {
    ++m_dequeue.md.count;
    ++m_dequeue.md.total_count;
    m_dequeue.md.interval_accum += types::timestep(t - m_dequeue.last_op_time);
    m_dequeue.md.total_interval_accum +=
        types::timestep(t - m_dequeue.last_op_time);

    m_dequeue.last_op_time = t;
    m_dequeue.op_set = false;

    if (fake || m_queue.empty()) {
      return boost::none;
    }
    auto val = m_queue.front();
    m_queue.pop_front();
    return boost::make_optional(val);
  }

  void reset_metrics(void) {
    m_enqueue.md.count = 0;
    m_enqueue.md.interval_accum = types::timestep(0);

    m_dequeue.md.count = 0;
    m_dequeue.md.interval_accum = types::timestep(0);
  }

  /**
   * \brief Determine if \p key is currently contained in the queue.
   */
  bool contains(const T& key) const {
    return m_queue.end() != std::find_if(m_queue.begin(),
                                         m_queue.end(),
                                         [&](const auto& a) { return a == key; });
  }

 private:
  struct op_data {
    struct op_metadata md;
    bool op_set{ false };
    types::timestep last_op_time{ 0 };
    types::timestep next_op_time{ 0 };
  };

  /* clang-format off */
  const double    mc_lambda;
  const double    mc_mu;

  math::rng*      m_rng;
  struct op_data  m_enqueue{};
  struct op_data  m_dequeue{};
  std::deque<T>   m_queue{};
  /* clang-format on */

 public:
  RCPPSW_WRAP_DECLDEF(size, m_queue, const);
  RCPPSW_WRAP_DECLDEF(size, m_queue);
};

NS_END(ds, rcppsw);

#endif /* INCLUDE_RCPPSW_DS_POISSON_QUEUE_HPP_ */
