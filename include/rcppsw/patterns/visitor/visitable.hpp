/**
 * @file visitable.hpp
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

#ifndef INCLUDE_RCPPSW_PATTERNS_VISITOR_VISITABLE_HPP_
#define INCLUDE_RCPPSW_PATTERNS_VISITOR_VISITABLE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/patterns/visitor/visitor.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, patterns, visitor);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * P - The (possibly) parent class of the visitable class which will be passed
 * to the visitor as a reference.
 *
 * T - The type of the visitor.
 */
template<class P>
class visitable {
 public:
  visitable(void) {}
  visitable(__unused const visitable& other) {}
  visitable& operator=(__unused const visitable& other) { return *this; }

  template <typename T>
  void accept(T &visitor) { visitor.visit(static_cast<P&>(*this)); }

  virtual ~visitable(void) {}
};

NS_END(rcppsw, patterns, visitor);

#endif /* INCLUDE_RCPPSW_PATTERNS_VISITOR_VISITABLE_HPP_ */
