/**
 * \file named_type.hpp
 *
 * \copyright 2019 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_TYPES_NAMED_TYPE_HPP_
#define INCLUDE_RCPPSW_TYPES_NAMED_TYPE_HPP_

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
NS_START(rcppsw, types);

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
  virtual ~named_type(void) = default;

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

NS_END(types, rcppsw);

#endif /* INCLUDE_RCPPSW_TYPES_NAMED_TYPE_HPP_ */
