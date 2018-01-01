/**
 * @file decorator.hpp
 * @ingroup patterns decorator
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

#ifndef INCLUDE_RCPPSW_PATTERNS_DECORATOR_DECORATOR_HPP_
#define INCLUDE_RCPPSW_PATTERNS_DECORATOR_DECORATOR_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/common/common.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, patterns, decorator);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class decorator
 *
 * @brief The base class for the object decorator design pattern.
 *
 * D - The type of the decorated object.
 */
template <class D>
class decorator {
 public:
  template <typename... Args>
  decorator(Args&&... args) : m_decoratee(std::forward<Args>(args)...) {}
  virtual ~decorator(void) {}

  /**
   * @brief Get a reference to the decorated type.
   *
   * @return The reference.
   */
  D& decoratee(void) { return m_decoratee; }
  const D& decoratee(void) const { return m_decoratee; }

  /**
   * @brief Replace the current instance of the decorated type with a new one
   * constructed from the passed arguments.
   *
   * @param args The arguments to a decoratee constructor.
   */
  template <typename... Args>
  void redecorate(Args&&... args) {
    m_decoratee = D(std::forward<Args>(args)...);
  }

  /**
   * @brief Replace the current decoratee instance with another existing
   * instance.
   *
   * @param d The new decoratee.
   */
  void change_decoratee(const D& d) { m_decoratee = d; }

 private:
  D m_decoratee;
};

/**
 * @brief The base class for the ptr-to-object decorator design pattern.
 *
 * D - The type of the decorated object.
 */
template <class D>
class ptr_decorator {
 public:
  template <typename... Args>
  ptr_decorator(Args&&... args) :
      m_decoratee(rcppsw::make_unique<D>(std::forward<Args>(args)...)) {}
  virtual ~ptr_decorator(void) {}

  /**
   * @brief Replace the current instance of the decorated type with a new one
   * constructed from the passed arguments.
   *
   * @param args The arguments to a decoratee constructor.
   */
  template <typename... Args>
  void redecorate(Args&&... args) {
    m_decoratee = rcppsw::make_unique<D>(std::move(m_decoratee),
                                         std::forward<Args>(args)...);
  }

  /**
   * @brief Replace the current decoratee instance with another existing
   * instance.
   *
   * @param d The new decoratee.
   */
  void change_decoratee(D * const d) { m_decoratee.reset(d); }

  /**
   * @brief Get a reference to the decorated type.
   *
   * @return The reference.
   */
  D* decoratee(void) const { return m_decoratee.get(); }

 private:
  std::unique_ptr<D> m_decoratee;
};

NS_END(rcppsw, patterns, decorator);

#endif /* INCLUDE_RCPPSW_PATTERNS_DECORATOR_DECORATOR_HPP_ */
