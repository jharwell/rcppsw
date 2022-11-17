/**
 * \file mt_fsm.hpp
 *
 * \copyright 2017 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
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

