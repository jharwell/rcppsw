/**
 * \file stringizable.hpp
 *
 * \copyright 2021 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>

#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace rcppsw::er {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class stringizable
 * \ingroup er
 *
 * Interface for converting classes to string representations.
 */
class stringizable {
 public:
  stringizable(void) = default;
  virtual ~stringizable(void) = default;

  /**
   * \brief Return a string representation of a class.
   */
  virtual std::string to_str(void) const { return "to_str() not defined"; }
};

} /* namespace rcppsw::er */

