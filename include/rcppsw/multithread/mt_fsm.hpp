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

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <memory>
#include <mutex>
#include <string>

#include "rcppsw/patterns/fsm/base_fsm.hpp"
#include "rcppsw/rcppsw.hpp"

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
 * \brief Extends \ref patterns::fsm::base_fsm to be threadsafe.
 */
class mt_fsm : public rpfsm::base_fsm {
 public:
  explicit mt_fsm(uint8_t max_states, uint8_t initial_state = 0)
      : base_fsm(max_states, initial_state) {}

  ~mt_fsm(void) override = default;

  void init(void) override;

 protected:
  void external_event(uint8_t new_state,
                      std::unique_ptr<sm::event_data> data) override;

 private:
  /* clang-format on */
  std::mutex m_mutex{};
  /* clang-format off */
};

NS_END(multithread, rcppsw);

