/**
 * \file reflectable.hpp
 *
 * \copyright 2020 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <typeindex>

#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, mpl);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class reflectable
 * \ingroup mpl
 *
 * \brief Interface for classes wishing to employ pseudo-reflection in C++.
 */
class reflectable {
 public:
  virtual ~reflectable(void) = default;

  /**
   * \brief Return the \ref std::type_index of the derived class. This is useful
   * in conjunction with \ref std::variant and \ref std::visit, as
   * it allows for run-time reflection based on the actual type of the derived
   * class.
   */
  virtual std::type_index type_index(void) const = 0;
};

NS_END(mpl, rcppsw);
