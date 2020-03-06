/**
 * \file mt_fsm.hpp
 *
 * \copyright 2017 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_MULTITHREAD_MT_FSM_HPP_
#define INCLUDE_RCPPSW_MULTITHREAD_MT_FSM_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <mutex>
#include <string>

#include "rcppsw/common/common.hpp"
#include "rcppsw/patterns/fsm/base_fsm.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, multithread);
namespace sm = patterns::fsm;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class mt_fsm
 * \ingroup multithread
 *
 * \brief Extends \ref base_fsm to be threadsafe.
 */
class mt_fsm : public patterns::fsm::base_fsm {
 public:
  explicit mt_fsm(const types::fsm_state& max_states,
                  types::fsm_state initial_state = types::constants::kDefaultStartState)
      : base_fsm(max_states, initial_state) {}

  ~mt_fsm(void) override = default;

  void init(void) override;

 protected:
  void external_event(const types::fsm_state& new_state,
                      std::unique_ptr<sm::event_data> data) override;

 private:
  /* clang-format off */
  std::mutex m_mutex{};
  /* clang-format on */
};

NS_END(multithread, rcppsw);

#endif /* INCLUDE_RCPPSW_MULTITHREAD_MT_FSM_HPP_ */
