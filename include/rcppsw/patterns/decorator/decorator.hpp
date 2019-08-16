/**
 * @file decorator.hpp
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
#include <memory>

#include "rcppsw/common/common.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, patterns, decorator);

/*******************************************************************************
 * Macros
 ******************************************************************************/
/**
 * @def RCPPSW_DECORATE_FUNC(Func)
 *
 * Wraps the declaration/implementation of the decoratee (non-pointer version).
 *
 * Does not work for templated member functions in decorated class.
 */
#define RCPPSW_DECORATE_FUNC(Func, ...) RCPPSW_DECLDEF_WRAP(Func,          \
                                                            decoratee(), \
                                                            __VA_ARGS__)

/**
 * @def RCPPSW_DECORATE_FUNC_TEMPLATE(Type, Func)
 *
 * Wraps the declaration/implementation of the decoratee (non-pointer
 * version). For decoratee types that are themselves templated types.
 */
#define RCPPSW_DECORATE_FUNC_TEMPLATE(Type, Func, ...)                  \
  template<typename... Args>                                            \
  auto Func(Args&&... args) __VA_ARGS__ ->                              \
      decltype(std::declval<decltype(decorator::decorator<Type>::decoratee())>().Func(args...)) { \
    return decorator::decorator<Type>::decoratee().Func( std::forward<Args>(args)...); \
  }

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class decorator
 * @ingroup rcppsw patterns decorator
 *
 * @brief The base class for the object decorator design pattern.
 *
 * @tparam TDecoratee The type of the decorated object.
 */
template <class TDecoratee>
class decorator {
 public:
  template <typename... TArgs>
  explicit decorator(TArgs&&... args)
      : m_decoratee(std::forward<TArgs>(args)...) {}
  virtual ~decorator(void) = default;
  decorator(const decorator&) = default;
  decorator& operator=(const decorator&) = default;

  /**
   * @brief Get a reference to the decorated type.
   *
   * @return The reference.
   */
  TDecoratee& decoratee(void) { return m_decoratee; }
  const TDecoratee& decoratee(void) const { return m_decoratee; }

  /**
   * @brief Replace the current instance of the decorated type with a new one
   * constructed from the passed arguments.
   *
   * @param args The arguments to a decoratee constructor.
   */
  template <typename... TArgs>
  void redecorate(TArgs&&... args) {
    m_decoratee = TDecoratee(std::forward<TArgs>(args)...);
  }

  /**
   * @brief Replace the current decoratee instance with another existing
   * instance.
   *
   * @param d The new decoratee.
   */
  void change_decoratee(const TDecoratee& d) { m_decoratee = d; }

 private:
  TDecoratee m_decoratee;
};

/**
 * @class ptr_decorator
 * @ingroup rcppsw patterns decorator
 *
 * @brief The base class for the ptr-to-object decorator design pattern.
 *
 * @tparam TDecoratee The type of the decorated object.
 */
template <class TDecoratee>
class ptr_decorator {
 public:
  template <typename... Args>
  explicit ptr_decorator(Args&&... args) :
      m_decoratee(std::make_unique<TDecoratee>(std::forward<Args>(args)...)) {}
  virtual ~ptr_decorator(void) {}

  /**
   * @brief Replace the current instance of the decorated type with a new one
   * constructed from the passed arguments.
   *
   * @param args The arguments to a decoratee constructor.
   */
  template <typename... Args>
  void redecorate(Args&&... args) {
    m_decoratee = std::make_unique<TDecoratee>(std::move(m_decoratee),
                                               std::forward<Args>(args)...);
  }

  /**
   * @brief Replace the current decoratee instance with another existing
   * instance.
   *
   * @param d The new decoratee.
   */
  void change_decoratee(TDecoratee * const d) { m_decoratee.reset(d); }

  /**
   * @brief Get a reference to the decorated type.
   *
   * @return The reference.
   */
  TDecoratee* decoratee(void) const { return m_decoratee.get(); }

 private:
  std::unique_ptr<TDecoratee> m_decoratee;
};

NS_END(rcppsw, patterns, decorator);

#endif /* INCLUDE_RCPPSW_PATTERNS_DECORATOR_DECORATOR_HPP_ */
