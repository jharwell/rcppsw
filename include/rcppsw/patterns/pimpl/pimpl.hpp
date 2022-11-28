/**
 * \file pimpl.hpp
 *
 * \copyright 2019 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <memory>
#include <utility>

#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, patterns, pimpl);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class pimpl
 * \ingroup pimpl
 *
 * \brief Super-simple templated implementation of the PIMPL idiom. Does not
 * exist in boost, and the boost candidate I found had subtle memory issues when
 * optimizations were on.
 *
 * \tparam TImpl The type of the implementation you wish to hide.
 */
template<typename TImpl>
struct pimpl {
  template<typename ...Args>
  explicit pimpl(Args&&... args) :
      impl(std::make_unique<TImpl>(std::forward<Args>(args)...)) {}
  virtual ~pimpl(void) = default;

  std::unique_ptr<TImpl> impl;
};

NS_END(pimpl, patterns, rcppsw);
