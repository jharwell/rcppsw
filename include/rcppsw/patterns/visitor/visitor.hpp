/**
 * @file visitor.hpp
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

#ifndef INCLUDE_RCPPSW_PATTERNS_VISITOR_VISITOR_HPP_
#define INCLUDE_RCPPSW_PATTERNS_VISITOR_VISITOR_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/common/common.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, patterns, visitor);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The base visitor class from which all other classes wishing to employ
 * the visit()/accept() paradigm inherit.
 */
class visitor {
 public:
  virtual ~visitor(void) {}
};

/**
 * @brief Visitor classes should also derive from can_visit<T> for each derived
 * visitable type they want to visit.
 */
template<class T, typename R = int>
class can_visit {
 public:
  virtual R visit(T& visitee) = 0;
  virtual ~can_visit(void) {}
};

NS_END(rcppsw, patterns, visitor);

#endif /* INCLUDE_RCPPSW_PATTERNS_VISITOR_VISITOR_HPP_ */
