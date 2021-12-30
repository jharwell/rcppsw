/**
 * \file macros.hpp
 * \ingroup common
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

#ifndef INCLUDE_RCPPSW_COMMON_MACROS_HPP_
#define INCLUDE_RCPPSW_COMMON_MACROS_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcsw/common/common.h"

/*******************************************************************************
 * Macros
 ******************************************************************************/
/**
 * \def NS_START_(ns)
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
 * \def RCPPSW_PTRREF_DECLDEF_CONST(Func, Member, ...)
 *
 * Expose a pointer reference for an instance member \p Member named \p
 * Func. This is the const member function version.
 */
#define RCPPSW_PTRREF_DECLDEF_CONST(Func, Member)                       \
  std::add_pointer<const decltype(Member)>::type Func(void) const {           \
    return &Member;                                                     \
  }

/**
 * \def RCPPSW_PTRREF_DECLDEF(Func, Member, ...)
 *
 * Expose a pointer reference for an instance member \p Member named \p
 * Func. The variable argument list is to allow specification of 'const' as part
 * of the function return type. This is the non-const member function version.
 */
#define RCPPSW_PTRREF_DECLDEF(Func, Member, ...)                       \
  std::add_pointer<__VA_ARGS__ decltype(Member)>::type Func(void) {     \
    return &Member;                                                     \
  }

/**
 * \def RCPPSW_WRAP_DECLDEF(Func, Callable, ...)
 *
 * Wrap a public function, member variable (can't be a pointer type), or even
 * another member function that returns an object that contains the function you
 * want to wrap). The variable argument list is to allow specification of
 * 'const' as part of the function definition. Wrapped functions can take any
 * number of arguments of any type.
 *
 * Cannot be used to wrap overriden functions.
 */
#define RCPPSW_WRAP_DECLDEF(Func, Callable, ...)                                \
  RCPPSW_WRAP_DECLDEF_AS(Func, Callable, Func, __VA_ARGS__)

/**
 * \def RCPPSW_WRAP_DECLDEF_AS(Func, Callable, NewName, ...)
 *
 * Same as \ref RCPPSW_WRAP_DECLDEF, but renames the function wrapper.
 */

#define RCPPSW_WRAP_DECLDEF_AS(Func, Callable, NewName, ...)            \
  template <typename... Args>                                           \
  auto NewName(Args&&... args)                                          \
      __VA_ARGS__->decltype(std::declval<decltype(Callable)>().Func(args...)) { \
    return (Callable).Func(std::forward<Args>(args)...);                \
  }

/**
 * \def RCPPSW_WRAP_DECLDEF_OVERRIDE(Func, Callable,...)
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

#define RCPPSW_WRAP_DECLDEF_OVERRIDE(Func, Callable, ...)                 \
  auto Func(void)                                                       \
      __VA_ARGS__->decltype(std::declval<decltype(Callable)>().Func()) override { \
    return (Callable).Func();                                             \
  }

/**
 * \def RCPPSW_WRAP_DECL(Ret, Func, ...)
 *
 * Readability-enhancing macro for declaring that you are wrapping a function
 * provided by a member variable/parent class/etc. You don't HAVE to use this
 * macro, but doing so generally saves some typing, and makes your code more
 * self-documenting.
 *
 * The variable argument list is to allow specification of 'const' as
 * part of the function declaration.
 */
#define RCPPSW_WRAP_DECL(Ret, Func, ...) Ret Func(void) __VA_ARGS__

/**
 * \def RCPPSW_WRAP_DEF(Class, Func, Handle, ...)
 *
 * Readability-enhancing macro for defining the body of a function which wraps
 * \p Func provided by \p Handle. You don't HAVE to use this macro, but doing so
 * generally saves some typing, and makes your code more self-documenting.
 *
 * The variable argument list is to allow specification of 'const' as
 * part of the function definition.
 */
#define RCPPSW_WRAP_DEF(Class, Func, Handle, ...)                      \
  auto Class::Func(void)                                               \
      __VA_ARGS__->decltype(std::declval<decltype(Handle)>().Func()) { \
    return (Handle).Func();                                            \
  }

/**
 * \def RCPPSW_WRAP_DEFP(Class, Func, Handle, ...)
 *
 * Same as \ref RCPPSW_WRAP_DEF, but for \p Handle instances which are
 * pointers. Requires an additional specification of what to return if the \p
 * Handle is NULL.
 */
#define RCPPSW_WRAP_DEFP(Class, Func, Handle, NullRet, ...)             \
  auto Class::Func(void)                                                \
      __VA_ARGS__->decltype(std::declval<decltype(*Handle)>().Func()) { \
    if (nullptr == Handle) {                                            \
      return NullRet;                                                   \
    }                                                                   \
    return (Handle)->Func();                                            \
  }

/**
 * \def RCPPSW_WRAP_DECL_OVERRIDE(Ret, Func, ...)
 *
 * Declare a "simple" overrnide of an inherited function with the __pure__
 * attribute. Should be *NOT* be used if the override is complex to implement
 * (i.e. for every instance of this macro in a header file there should be an
 * instance of \ref RCPPSW_WRAP_DEF_OVERRIDE() in the corresponding source file
 * for a class).
 */
#define RCPPSW_WRAP_DECL_OVERRIDE(Ret, Func, ...) \
  Ret Func(void) __VA_ARGS__ override RCPPSW_PURE

/**
 * \def RCPPSW_WRAP_DEF_OVERRIDE(Ret, Func, ...)
 *
 * Define a "simple" override of an inherited function with the __pure__
 * attribute in which the corresponding function on the handle is called and the
 * result returned.
 */
#define RCPPSW_WRAP_DEF_OVERRIDE(Class, Func, Handle, ...) \
  RCPPSW_WRAP_DEF(Class, Func, Handle, __VA_ARGS__)

/**
 * \def RCPPSW_WRAP_DEFP_OVERRIDE(Class, Func, Handle, ...)
 *
 * Same as \ref RCPPSW_WRAP_DEF_OVERRIDE, but for \p Handle instances which are
 * pointers. Requires an additional specification of what to return if the \p
 * Handle is NULL.
 */
#define RCPPSW_WRAP_DEFP_OVERRIDE(Class, Func, Handle, NullRet, ...) \
  RCPPSW_WRAP_DEFP(Class, Func, Handle, NullRet, __VA_ARGS__)

#define RCPPSW_IS_ODD(n) RCSW_IS_ODD(n)

/*******************************************************************************
 * Compiler Macros
 ******************************************************************************/
#if defined(__INTEL_COMPILER)
#define RCPPSW_STRUCT_DOT_INITIALIZER(name, value) value
#else
/**
 * \def RCPPSW_STRUCT_DOT_INITIALIZER(name, value)
 *
 * Initialize a member of a struct which is not POD using the dot ('.')
 * initializer syntax. GCC and clang handle this for things using
 * std::bind/member function pointers, but the Intel compiler does not. Using
 * the dot syntax is nice, because if you have multiple members of the same type
 * in the same struct, the intent of the programmer is clear.
 */
#define RCPPSW_STRUCT_DOT_INITIALIZER(name, value) .name = value
#endif

#define RCPPSW_CONST RCSW_CONST
#define RCPPSW_COLD RCSW_COLD
#define RCPPSW_PURE RCSW_PURE
#define RCPPSW_DEAD RCSW_DEAD
#define RCPPSW_UNUSED RCSW_UNUSED

/**
 * \def RCPPSW_NODISCARD
 *
 * Mark a function result as no-discard, so that a compiler warning is issued if
 * this happens.
 */
#define RCPPSW_NODISCARD [[nodiscard]]

#define RCPPSW_ATTR(...) RCSW_ATTR(__VA_ARGS__)
#define RCPPSW_CHECK(cond) RCSW_CHECK(cond)
#define RCPPSW_IS_BETWEEN(n, lb, ub) RCSW_IS_BETWEEN(n, lb, ub)
#define RCPPSW_LIKELY(cond) RCSW_LIKELY(cond)
#define RCPPSW_UNLIKELY(cond) RCSW_UNLIKELY(cond)
#define RCPPSW_FPC_RET_V(cond) RCSW_FPC_RET_V(cond)
#define RCPPSW_IS_EVEN(n) RCSW_IS_EVEN(n)

/*******************************************************************************
 * Warning Disable Macros
 ******************************************************************************/
/**
 * \def RCPPSW_WARNING_DISABLE_PUSH(...)
 *
 * Alias for \ref RCSW_WARNING_DISABLE_PUSH, a compiler-agnostic way to push
 * warning ignores onto the stack.
 *
 * Very useful for disabling warnings from headers/frameworks which you have no
 * control over.
 */
#define RCPPSW_WARNING_DISABLE_PUSH(...) RCSW_WARNING_DISABLE_PUSH(__VA_ARGS__)

/**
 * \def RCPPSW_WARNING_DISABLE_POP(...)
 *
 * Alias for \ref RCSW_WARNING_DISABLE_POP, a compiler-agnostic way to pop
 * warning ignores from the stack.
 *
 * Very useful for disabling warnings from headers/frameworks which you have no
 * control over.
 */
#define RCPPSW_WARNING_DISABLE_POP(...) RCSW_WARNING_DISABLE_POP(__VA_ARGS__)

/**
 * \def RCPPSW_WARNING_DISABLE(...)
 *
 * Alias for \ref RCSW_WARNING_DISABLE, a compiler-agnostic way to ignore
 * compiler warnings within a given diagnostic context.
 */
#define RCPPSW_WARNING_DISABLE(...) RCSW_WARNING_DISABLE(__VA_ARGS__)

/* clang-format off */

#if defined(__INTEL_COMPILER)

/**
 * \def RCPPSW_WARNING_DISABLE_MISSING_VAR_DECL(...)
 *
 * Not needed by intel compiler.
 */
#define RCPPSW_WARNING_DISABLE_MISSING_VAR_DECL(...)

/**
 * \def RCPPSW_WARNING_DISABLE_MISSING_PROTOTYPE(...)
 *
 * Warning 1418.
 */
#define RCPPSW_WARNING_DISABLE_MISSING_PROTOTYPE(...) \
  RCPPSW_WARNING_DISABLE(1418)

/**
 * \def RCPPSW_WARNING_DISABLE_GLOBAL_CTOR(...)
 *
 * Not needed by intel compiler.
 */
#define RCPPSW_WARNING_DISABLE_GLOBAL_CTOR(...)

/**
 * \def RCPPSW_WARNING_DISABLE_SUGGEST_OVERRIDE(...)
 *
 * Not needed by intel compiler.
 */
#define RCPPSW_WARNING_DISABLE_SUGGEST_OVERRIDE(...)

/**
 * \def RCPPSW_WARNING_DISABLE_USELESS_CAST(...)
 *
 * Not needed by intel compiler.
 */
#define RCPPSW_WARNING_DISABLE_USELESS_CAST(...)

/**
 * \def RCPPSW_WARNING_DISABLE_OLD_STYLE_CAST(...)
 *
 * Not needed by intel compiler.
 */
#define RCPPSW_WARNING_DISABLE_OLD_STYLE_CAST(...)

#elif defined(__clang__)

/**
 * \def RCPPSW_WARNING_DISABLE_MISSING_VAR_DECL(...)
 *
 * -Wmissing-variable-declarations.
 */
#define RCPPSW_WARNING_DISABLE_MISSING_VAR_DECL(...) \
  RCPPSW_WARNING_DISABLE(-Wmissing-variable-declarations)

/**
 * \def RCPPSW_WARNING_DISABLE_MISSING_PROTOTYPE(...)
 *
 * -Wmissing-prototypes.
 */
#define RCPPSW_WARNING_DISABLE_MISSING_PROTOTYPE(...) \
  RCPPSW_WARNING_DISABLE(-Wmissing-prototypes)

/**
 * \def RCPPSW_WARNING_DISABLE_GLOBAL_CTOR(...)
 *
 * -Wglobal-constructors
 */
#define RCPPSW_WARNING_DISABLE_GLOBAL_CTOR(...) \
  RCPPSW_WARNING_DISABLE(-Wglobal-constructors)

/**
 * \def RCPPSW_WARNING_DISABLE_OVERLOADED_VIRTUAL(...)
 *
 * Not needed by clang.
 */
#define RCPPSW_WARNING_DISABLE_OVERLOADED_VIRTUAL(...)

/**
* \def RCPPSW_WARNING_DISABLE_EFFCXX(...)
*
* -Weffc++
*/
#define RCPPSW_WARNING_DISABLE_EFFCXX(...)      \
  RCPPSW_WARNING_DISABLE(-Weffc++)

/**
 * \def RCPPSW_WARNING_DISABLE_SUGGEST_OVERRIDE(...)
 *
 * Not needed by clang.
 */
#define RCPPSW_WARNING_DISABLE_SUGGEST_OVERRIDE(...)

/**
 * \def RCPPSW_WARNING_DISABLE_USELESS_CAST(...)
 *
 * Not needed by clang.
 */
#define RCPPSW_WARNING_DISABLE_USELESS_CAST(...)

/**
 * \def RCPPSW_WARNING_DISABLE_OLD_STYLE_CAST(...)
 *
 * Not needed by clang.
 */
#define RCPPSW_WARNING_DISABLE_OLD_STYLE_CAST(...)

#elif defined(__GNUC__)

/**
 * \def RCPPSW_WARNING_DISABLE_MISSING_VAR_DECL(...)
 *
 * Not needed by gcc.
 */
#define RCPPSW_WARNING_DISABLE_MISSING_VAR_DECL(...)

/**
 * \def RCPPSW_WARNING_DISABLE_MISSING_PROTOTYPE(...)
 *
 * Not needed by gcc.
 */
#define RCPPSW_WARNING_DISABLE_MISSING_PROTOTYPE(...)

/**
 * \def RCPPSW_WARNING_DISABLE_GLOBAL_CTOR(...)
 *
 * Not needed by gcc.
 */
#define RCPPSW_WARNING_DISABLE_GLOBAL_CTOR(...)

/**
 * \def RCPPSW_WARNING_DISABLE_OVERLOADED_VIRTUAL(...)
 *
 * -Woverloaded-virtual
 */
#define RCPPSW_WARNING_DISABLE_OVERLOADED_VIRTUAL(...) \
  RCPPSW_WARNING_DISABLE(-Woverloaded-virtual)

/**
 * \def RCPPSW_WARNING_DISABLE_EFFCXX(...)
 *
 * -Weffc++
 */
#define RCPPSW_WARNING_DISABLE_EFFCXX(...) \
  RCPPSW_WARNING_DISABLE(-Weffc++)

/**
 * \def RCPPSW_WARNING_DISABLE_SUGGEST_OVERRIDE(...)
 *
 * -Wsuggest-override
 */
#define RCPPSW_WARNING_DISABLE_SUGGEST_OVERRIDE(...) \
  RCPPSW_WARNING_DISABLE(-Wsuggest-override)

/**
 * \def RCPPSW_WARNING_DISABLE_USELESS_CAST(...)
 *
 * -Wuseless-cast
 */
#define RCPPSW_WARNING_DISABLE_USELESS_CAST(...) \
  RCPPSW_WARNING_DISABLE(-Wuseless-cast)

/**
 * \def RCPPSW_WARNING_DISABLE_OLD_STYLE_CAST(...)
 *
 * -Wold-style-cast
 */
#define RCPPSW_WARNING_DISABLE_OLD_STYLE_CAST(...) \
  RCPPSW_WARNING_DISABLE(-Wold-style-cast)

#endif /* __INTEL_COMPILER__ */
/* clang-format on */

#endif /* INCLUDE_RCPPSW_COMMON_MACROS_HPP_ */
