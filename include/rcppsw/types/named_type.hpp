/**
 * \file named_type.hpp
 *
 * \copyright 2019 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include <utility>

#include "rcppsw/rcppsw.hpp"
#include "rcppsw/er/stringizable.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace rcppsw::types {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class named_type
 * \ingroup types
 *
 * \brief A strong typing wrapper to be used around POD types to make implicit
 * conversions impossible (ESPECCIALLY when the necessary compiler warnings are
 * disabled), and force the user to be explicit about converting.
 */
template <typename T, typename Parameter>
class named_type : public er::stringizable {
 public:
  explicit named_type(T const& value) noexcept : m_value(value) {}
  ~named_type(void) override = default;

  const T& v(void) const { return m_value; }
  T& set(const T& value) { return m_value = value; }

  friend std::ostream& operator<<(std::ostream& stream,
                                  const named_type& c_type) {
    stream << c_type.to_str();
    return stream;
  }
  std::string to_str(void) const override { return std::to_string(m_value); }

  friend std::istream& operator>>(std::istream& stream, named_type& n) {
    stream >> n.m_value;
    return stream;
  }

 private:
  /* clang-format off */
  T m_value;
  /* clang-format on */
};

} /* namespace rcppsw::types */

