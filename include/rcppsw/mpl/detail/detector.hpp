/**
 * \file detector.hpp
 *
 * RESTRICTED RIGHTS
 *
 * Contract No. 9700-1100-001-009
 *
 * Smart Information Flow Technologies
 *
 * 319 1st Ave N, Suite 400
 * Minneapolis, MN 55401-1689
 *
 * The Government's rights to use, modify, reproduce, release, perform, display,
 * or disclose this software are restricted by paragraph (b)(3) of the Rights in
 * Noncommercial Computer Software and Noncommercial Computer Software
 * Documentation clause contained in the above identified contract. Any
 * reproduction of computer software or portions thereof marked with this legend
 * must also reproduce the markings. Any person, other than the Government, who
 * has been provided access to such software must promptly notify the above
 * named Contractor.
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace rcppsw::mpl::detail {

/*******************************************************************************
 * Trait Detection Templates
 ******************************************************************************/
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
template <class TFailType,
          template <class...>
          class TFuncDecltype,
          class... Args>
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

template <class T, std::size_t = sizeof(T)>
std::true_type is_complete_impl(T *);

std::false_type is_complete_impl(...);

} /* namespace rcppsw::mpl::detail */
