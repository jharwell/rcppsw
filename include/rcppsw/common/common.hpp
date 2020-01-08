/**
 * \file common.hpp
 * \ingroup common
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

#ifndef INCLUDE_RCPPSW_COMMON_COMMON_HPP_
#define INCLUDE_RCPPSW_COMMON_COMMON_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <memory>
#include <string>
#include <tuple>
#include <utility>

#include "rcsw/common/common.h"

/*******************************************************************************
 * Macros
 ******************************************************************************/
/**
 * \def NS_START(ns)
 *
 * Callback macro for recursive macro expansion for nested namespace start
 * pasting. \c ns is the namespace to paste.
 */
#define NS_START_(ns) namespace ns {
/**
 * \def NS_END_(ns)
 *
 * Callback macro for recursive macro expansion for nested namespace end
 * pasting. \c ns is the namespace to paste. Note that it is not strictly
 * necessary to pass the namespace name to this macro, as it only pastes a
 * single bracket; it is more self documenting to do so, however.
 */
#define NS_END_(ns) }

/**
 * \def NS_START(...)
 *
 * Declare a nested namespace, with each successive token in the comma-separated
 * argument list being declared inside the namespace of the previous token.
 */
#define NS_START(...) RCSW_XFOR_EACH1(NS_START_, __VA_ARGS__)

/**
 * \def NS_END(...)
 *
 * Close a previously declared nested namespace. Tokens should be passed to this
 * macro in the reverse order they were declared in (not actually necessary for
 * valid code, but it is more self documentating to do so).
 */
#define NS_END(...) RCSW_XFOR_EACH1(NS_END_, __VA_ARGS__)

/**
 * \def RCPPSW_DECLDEF_WRAP(Func, member,...)
 *
 * Wrap a public function from a member variable (or even another member
 * function that returns an object that contains the function you want to
 * wrap). The variable argument list is to allow specification of 'const' as
 * part of the function definition. Wrapped functions can take any number of
 * arguments of any type.
 *
 * Cannot be used to wrap overriden functions.
 */
#define RCPPSW_DECLDEF_WRAP(Func, Member, ...)                                \
  template <typename... Args>                                                 \
  auto Func(Args&&... args)                                                   \
      __VA_ARGS__->decltype(std::declval<decltype(Member)>().Func(args...)) { \
    return Member.Func(std::forward<Args>(args)...);                          \
  }

/**
 * \def RCPPSW_DECLDEF_OVERRIDE_WRAP(Func, member,...)
 *
 * Wrap a public function from a member variable (or even another member
 * function that returns an object that contains the function you want to
 * wrap). The variable argument list is to allow specification of 'const' as
 * part of the function definition. Wrapped functions must take 0 arguments
 * (can't do anything other than that for a general macro that works with
 * virtual functions).
 *
 * Should be used to wrap overriden functions in the current class (e.g the
 * enclosing class implements the same interface as a member variable).
 */

#define RCPPSW_DECLDEF_OVERRIDE_WRAP(Func, Member, ...)                         \
  auto Func(void)                                                               \
      __VA_ARGS__->decltype(std::declval<decltype(Member)>().Func()) override { \
    return Member.Func();                                                       \
  }

#define RCPPSW_WRAP_DECL(Ret, Func, ...) Ret Func(void) __VA_ARGS__ h

#define RCPPSW_WRAP_DEF(Class, Func, Handle, ...)                      \
  auto Class::Func(void)                                               \
      __VA_ARGS__->decltype(std::declval<decltype(Handle)>().Func()) { \
    return (Handle).Func();                                            \
  }

#define RCPPSW_WRAP_DEFP(Class, Func, Handle, NullRet, ...)             \
  auto Class::Func(void)                                                \
      __VA_ARGS__->decltype(std::declval<decltype(*Handle)>().Func()) { \
    if (nullptr == Handle) {                                            \
      return NullRet;                                                   \
    }                                                                   \
    return (Handle)->Func();                                            \
  }

/**
 * \def RCPPSW_WRAP_OVERRIDE_DECL(Ret, Func, ...)
 *
 * Declare a "simple" overrnide of an inherited function with the __pure_
 * attribute. Should be *NOT* be used if the override is complex to implement
 * (i.e. for every instance of this macro in a header file there should be an
 * instance of \ref RCPPSW_WRAP_OVERRIDE_DEF() in the corresponding source file
 * for a class).
 */
#define RCPPSW_WRAP_OVERRIDE_DECL(Ret, Func, ...) \
  Ret Func(void) __VA_ARGS__ override RCSW_PURE

/**
 * \def RCPPSW_WRAP_OVERRIDE_DEF(Ret, Func, ...)
 *
 * Define a "simple" override of an inherited function with the __pure__
 * attribute in which the corresponding function on the handle is called and the
 * result returned.
 */
#define RCPPSW_WRAP_OVERRIDE_DEF(Class, Func, Handle, ...) \
  RCSW_PURE RCPPSW_WRAP_DEF(Class, Func, Handle, __VA_ARGS__)

#define RCPPSW_WRAP_OVERRIDE_DEFP(Class, Func, Handle, NullRet, ...) \
  RCSW_PURE RCPPSW_WRAP_DEFP(Class, Func, Handle, NullRet, __VA_ARGS__)

/**
 * \def RCPPSW_SFINAE_FUNC(...)
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
 */
#define RCPPSW_SFINAE_FUNC(...) \
  typename std::enable_if<__VA_ARGS__, int>::type = 0

#if defined(__INTEL_COMPILER)
/**
 * \def RCPPSW_STRUCT_DOT_INITIALIZER(name, value)
 *
 * Initialize a member of a struct which is not POD using the dot ('.')
 * initializer syntax. GCC and clang handle this for things using
 * std::bind/member function pointers, but the Intel compiler does not. Using
 * the dot syntax is nice, because if you have multiple members of the same type
 * in the same struct, the intent of the programmer is clear.
 */

#define RCPPSW_STRUCT_DOT_INITIALIZER(name, value) value
#else
#define RCPPSW_STRUCT_DOT_INITIALIZER(name, value) .name = value
#endif

/*******************************************************************************
 * Warning Disable Macros
 ******************************************************************************/
#define RCPPSW_WARNING_DISABLE_PUSH(...) RCSW_WARNING_DISABLE_PUSH(__VA_ARGS__)
#define RCPPSW_WARNING_DISABLE_POP(...) RCSW_WARNING_DISABLE_POP(__VA_ARGS__)

#if defined(__INTEL_COMPILER)

#define RCPPSW_WARNING_DISABLE_MISSING_VAR_DECL(...)
#define RCPPSW_WARNING_DISABLE_MISSING_PROTOTYPE(...) RCSW_WARNING_DISABLE(1418)
#define RCPPSW_WARNING_DISABLE_GLOBAL_CTOR(...)

#elif defined(__clang__)

/* clang-format off */
#define RCPPSW_WARNING_DISABLE_MISSING_VAR_DECL(...) \
  RCSW_WARNING_DISABLE(-Wmissing-variable-declarations)
#define RCPPSW_WARNING_DISABLE_MISSING_PROTOTYPE(...) \
  RCSW_WARNING_DISABLE(-Wmissing-prototypes)
#define RCPPSW_WARNING_DISABLE_GLOBAL_CTOR(...) \
  RCSW_WARNING_DISABLE(-Wglobal-constructors)
/* clang-format on */

#elif defined(__GNUC__)

#define RCPPSW_WARNING_DISABLE_MISSING_VAR_DECL(...)
#define RCPPSW_WARNING_DISABLE_MISSING_PROTOTYPE(...)
#define RCPPSW_WARNING_DISABLE_GLOBAL_CTOR(...)

#endif /* __INTEL_COMPILER__ */

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw);

/*******************************************************************************
 * Trait Detection Templates
 ******************************************************************************/
NS_START(detail);

/**
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
          template <class...> class TFuncDecltype,
          class... Args>
struct detector {
  using value = std::false_type;
  using type = TFailType;
};

/**
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
struct detector<TFailType, std::void_t<TFuncDecltype<Args...>>, TFuncDecltype, Args...> {
  using value = std::true_type;
  using type = TFuncDecltype<Args...>;
};

NS_END(detail);

/**
 * \brief Sentinel type to indicate that the specified trait was not detected.
 */
struct no_such_trait {
  no_such_trait() = delete;
  ~no_such_trait() = delete;
  no_such_trait(no_such_trait const&) = delete;
  void operator=(no_such_trait const&) = delete;
};

/**
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
 * \brief Same as \ref is_detected, but will return the decltype itself, rather
 * than just if it is well formed or not.
 */
template <template <class...> class TFuncDecltype, class... Args>
using detected_t =
    typename detail::detector<no_such_trait, void, TFuncDecltype, Args...>::type;

/**
 * \brief Same as \ref is_detected_t, but allows for a user specified type \p
 * TFailType to be selected if detection fails.
 */

template <class TFailType, template <class...> class TFuncDecltype, class... Args>
using detected_or = detail::detector<TFailType, void, TFuncDecltype, Args...>;

/*******************************************************************************
 * String Conversion Templates
 ******************************************************************************/
NS_START(detail);

/**
 * \brief Predicate for detecting if a type \p T defines `to_str()`.
 *
 * \tparam T The type to check.
 */
template <class T>
using to_str_type = decltype(std::declval<T>().to_str());

NS_END(detail);

/**
 * @brief If a class/type defines a to_str() method, then it can use
 * rcppsw::to_string() in cases where rcppsw::to_string() does not work.
 */
template <class T, RCPPSW_SFINAE_FUNC(is_detected<detail::to_str_type, T>::value)>
std::string to_string(const T& obj) {
  return obj.to_str();
}

/**
 * @brief Adaptor func for types where rcppsw::to_string() works so you can
 * ALWAYS use rcppsw::to_string().
 */
template <typename T,
          RCPPSW_SFINAE_FUNC(!is_detected<detail::to_str_type, T>::value)>
std::string to_string(const T& obj) {
  return std::to_string(obj);
}

/*******************************************************************************
 * Misc. Templates
 ******************************************************************************/

template <typename TEnum>
constexpr typename std::underlying_type<TEnum>::type as_underlying(
    const TEnum& e) noexcept {
  return static_cast<typename std::underlying_type<TEnum>::type>(e);
}

NS_END(rcppsw);

#endif /* INCLUDE_RCPPSW_COMMON_COMMON_HPP_ */
