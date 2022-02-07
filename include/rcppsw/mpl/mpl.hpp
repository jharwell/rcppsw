/**
 * \file mpl.hpp
 *
 * \copyright 2020 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_MPL_MPL_HPP_
#define INCLUDE_RCPPSW_MPL_MPL_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/common/macros.hpp"
#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Macros
 ******************************************************************************/
/**
 * \def RCPPSW_SFINAE_DECLDEF(...)
 *
 * Specify the condition to enable a function for SFINAE.
 *
 * It turns out that in C++14, a default template type parameter (e.g. typename
 * = std::enable_if<...>::value)is NOT considered part of a function's signature
 * for the purposes of SFINAE, so functions with 100% identical signatures
 * except for such a parameter will cause a compilation error.
 *
 * However, a template non-type parameter (e.g. a template parameter that is an
 * integer) that is defaulted (i.e. have a default value specified) IS
 * considered part of a function's signature for the purposes of SFINAE, so two
 * functions that differ only in the value of the defaulted non-type parameter
 * in their template argument lists will be considered distinct and trigger
 * SFINAE as expected.
 *
 * This macro ONLY works for inline functions specified in the header file.
 */
#ifndef DOXYGEN_DOCUMENTATION_BUILD
#define RCPPSW_SFINAE_DECLDEF(...) \
  typename std::enable_if<__VA_ARGS__, int>::type = 0
#endif /* DOXYGEN_DOCUMENTATION_BUILD */

/**
 * \def RCPPSW_SFINAE_DECL(...)
 *
 * Specify the condition to enable a function for SFINAE, where the declaration
 * and definition are separated (requiring manual template instantiation in the
 * source file).
 *
 * Doing this is usually more trouble than its worth, but you CAN do it if
 * needed.
 */
#ifndef DOXYGEN_DOCUMENTATION_BUILD
#define RCPPSW_SFINAE_DECL(...) \
  typename std::enable_if<__VA_ARGS__, int>::type = 0
#endif /* DOXYGEN_DOCUMENTATION_BUILD */

/**
 * \def RCPPSW_SFINAE_DEF(...)
 *
 * Specify the condition to enable a function for SFINAE, where the declaration
 * and definition are separated (requiring manual template instantiation in the
 * source file).
 *
 * Doing this is usually more trouble than its worth, but you CAN do it if
 * needed.
 */
#ifndef DOXYGEN_DOCUMENTATION_BUILD
#define RCPPSW_SFINAE_DEF(...)                  \
  typename std::enable_if<__VA_ARGS__, int>::type
#endif /* DOXYGEN_DOCUMENTATION_BUILD */

#define RCPPSW_SFINAE_TYPE(...) typename std::enable_if<__VA_ARGS__>::value

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, mpl);

/*******************************************************************************
 * Trait Detection Templates
 ******************************************************************************/
NS_START(detail);

/**
 * \struct detector
 * \ingroup mpl
 *
 * \brief If the specified function \p TFuncDecltype taking the specified \p
 * Args is not well formed, then SFINAE and partial template specialization will
 * select this template, indicating unsuccessful detection.
 *
 * \tparam TFailType The default type to select upon unsuccessful
 * detection.
 *
 * \tparam TFuncDecltype The decltype() of the function to detect.
 *
 * \tparam Args The types of the arguments to the function to detect.
 */
template <class TFailType,
          class AlwaysVoid,
          template <class...>
          class TFuncDecltype,
          class... Args>
struct detector {
  /**
   * Always \a FALSE for unsuccessful detection.
   */
  using value = std::false_type;

  /**
   * Captures \p TFailType for future use.
   */
  using type = TFailType;
};

/**
 * \struct detector
 * \ingroup mpl
 *
 * \brief If the specified function \p TFuncDecltype taking the specified \p
 * Args is well formed, then SFINAE and partial template specialization will
 * select this template, indicating successful detection.
 *
 * \tparam TFailType The default type to select upon unsuccessful
 * detection. Unused in this version of the detector.
 *
 * \tparam TFuncDecltype The decltype() of the function to detect.
 *
 * \tparam Args The types of the arguments to the function to detect.
 */
template <class TFailType, template <class...> class TFuncDecltype, class... Args>
struct detector<TFailType,
                std::void_t<TFuncDecltype<Args...>>,
                TFuncDecltype,
                Args...> {
  /**
   * Always \a TRUE for successful detection.
   */
  using value = std::true_type;

  /**
   * Captures \p TFuncDeclType argument for future use.
   */
  using type = TFuncDecltype<Args...>;
};

NS_END(detail);

/**
 * \struct no_such_trait
 * \ingroup mpl
 *
 * \brief Sentinel type to indicate that the specified trait was not detected.
 */
struct no_such_trait {
  no_such_trait() = delete;
  ~no_such_trait() = delete;
  no_such_trait(no_such_trait const&) = delete;
  void operator=(no_such_trait const&) = delete;
};

/**
 * \typedef is_detected
 * \ingroup mpl
 *
 * \brief Type trait to detect whether a function taking the specified \p Args
 * exists for the specified type. Suitable for use in SFINAE.
 *
 * \tparam TFuncDecltype Should be a decltype(), something like
 * `decltype(std::declval<T>().foo())` to detect the presence of a function
 * named `foo()` for a type `T`.
 *
 * \tparam Args The argument types for the function to detect (if any).
 */
template <template <class...> class TFuncDecltype, class... Args>
using is_detected =
    typename detail::detector<no_such_trait, void, TFuncDecltype, Args...>::value;

/**
 * \typedef detected_t
 * \ingroup mpl
 *
 * \brief Same as \ref is_detected, but will return the decltype itself, rather
 * than just if it is well formed or not.
 */
template <template <class...> class TFuncDecltype, class... Args>
using detected_t =
    typename detail::detector<no_such_trait, void, TFuncDecltype, Args...>::type;

/**
 * \typedef detected_or
 * \ingroup mpl
 *
 * \brief Same as \ref is_detected, but allows for a user specified type \p
 * TFailType to be selected if detection fails.
 */
template <class TFailType, template <class...> class TFuncDecltype, class... Args>
using detected_or = detail::detector<TFailType, void, TFuncDecltype, Args...>;

template <typename T, typename U, typename = void>
struct can_static_cast : std::false_type {};

/**
 * \struct can_static_cast
 * \ingroup mpl
 *
 * \brief Determine if \p T can be cast to \p U via static_cast<>.
 */
template <typename T, typename U>
struct can_static_cast<T,
                       U,
                       std::void_t<decltype(static_cast<U>(std::declval<T>()))>>
    : std::true_type {};


template <class T, template <class...> class Template>
struct is_specialization : std::false_type {};

/**
 * \struct is_specialization
 * \ingroup mpl
 *
 * \brief Determine if a class Template<SomeType> is a specialization of \p
 * Template.
 */

template <template <class...> class Template, class... Args>
struct is_specialization<Template<Args...>, Template> : std::true_type {};

NS_END(mpl, rcppsw);

#endif /* INCLUDE_RCPPSW_INCLUDE_MPL_MPL_HPP_ */
