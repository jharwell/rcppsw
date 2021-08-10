/**
 * \file decorator.hpp
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

#ifndef INCLUDE_RCPPSW_PATTERNS_DECORATOR_DECORATOR_HPP_
#define INCLUDE_RCPPSW_PATTERNS_DECORATOR_DECORATOR_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <memory>
#include <utility>

#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, patterns, decorator);

/*******************************************************************************
 * Macros
 ******************************************************************************/
/**
 * \def RCPPSW_DECORATE_DECLDEF(Func)
 *
 * Wraps the declaration/implementation of the decoratee \p Func.
 *
 * Does not work for templated member functions in decorated class. Does not
 * work to wrap functions in the decorated class which are virtual.
 */
#define RCPPSW_DECORATE_DECLDEF(Func, ...) RCPPSW_WRAP_DECLDEF(Func,          \
                                                            decoratee(), \
                                                            __VA_ARGS__)

/**
 * \def RCPPSW_DECORATE_DECLDEF_TEMPLATE(Type, Func)
 *
 * Wraps the declaration/implementation of the decoratee \p Func which is
 * templated on \p Type. For decoratee types that are themselves templated
 * types.
 */
#define RCPPSW_DECORATE_DECLDEF_TEMPLATE(Type, Func, ...)               \
  template<typename... Args>                                            \
  auto Func(Args&&... args) __VA_ARGS__ ->                              \
      decltype(std::declval<decltype(rpdecorator::decorator<Type>::decoratee())>().Func(args...)) { \
    return rpdecorator::decorator<Type>::decoratee().Func( std::forward<Args>(args)...); \
  }

/**
 * \def RCPPSW_DECORATE_DECL(Name)
 *
 * Wraps a using declaration from the decoratee into the derived class.
 */
#define RCPPSW_DECORATE_DECL(Name) \
  using Name = typename decoratee_type::Name

/**
 * \def RCPPSW_DECORATE_CT(...)
 *
 * Exposes tricy constructors from the decoratee in the derived class. Generally
 * only needed if the decoratee is an STL container or similar.
 */
#define RCPPSW_DECORATE_CT(...)                 \
  using rpdecorator::decorator<decoratee_type>::decorator

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class decorator
 * \ingroup patterns decorator
 *
 * \brief The base class for the object decorator design pattern.
 *
 * \tparam TDecoratee The type of the decorated object.
 */
template <class TDecoratee>
class decorator {
 public:
  using decoratee_type = TDecoratee;

  /*
   * Note we DO NOT use &&! If we do, then you can't use this class to decorate
   * STL containers for cryptic reasons...This is at most an extra copy anyway.
   */
  template <typename... TArgs>
  decorator(TArgs... args)
      : m_decoratee{std::move(args)...} {}

  template<typename U = TDecoratee,
           RCPPSW_SFINAE_DECLDEF((sizeof(U::value_type) > 0))>
  decorator(std::initializer_list<U> args)
      : m_decoratee(std::move(args)) {}

  /*
   * These decls are MANDATORY because by also declaring the deconstructor, you
   * lose implicitly-defined move construction which is necessary in the
   * decoratee is a STL container of move-only types.
   */
  decorator(const decorator&) = default;
  decorator& operator=(const decorator&) = default;
  decorator(decorator&&) = default;
  decorator& operator=(decorator&&) = default;

  virtual ~decorator(void) = default;

  /**
   * \brief Get a reference to the decorated type.
   *
   * \return The reference.
   */
  decoratee_type& decoratee(void) { return m_decoratee; }
  const decoratee_type& decoratee(void) const { return m_decoratee; }

  /**
   * \brief Replace the current instance of the decorated type with a new one
   * constructed from the passed arguments.
   *
   * \param args The arguments to a decoratee constructor.
   */
  template <typename... TArgs>
  void redecorate(TArgs&&... args) {
    m_decoratee = decoratee_type(std::forward<TArgs>(args)...);
  }

  /**
   * \brief Replace the current decoratee instance with another existing
   * instance.
   *
   * \param d The new decoratee.
   */
  void redecorate_with(const decoratee_type& d) { m_decoratee = d; }

 private:
  /* clang-format off */
  decoratee_type m_decoratee;
  /* clang-format on */
};

NS_END(rcppsw, patterns, decorator);

#endif /* INCLUDE_RCPPSW_PATTERNS_DECORATOR_DECORATOR_HPP_ */
