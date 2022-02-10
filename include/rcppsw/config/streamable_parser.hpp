/**
 * \file streamable_parser.hpp
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

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>

#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, config);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class streamable_parser
 * \ingroup config
 *
 * \brief Mixin to add pretty printing capabilities to parsers.
 */
class streamable_parser {
  virtual ~streamable_parser(void) = default;

  static constexpr size_t kColumnWidth = 100;
  static constexpr size_t kHeader1 = 1;
  static constexpr size_t kHeader2 = 2;
  static constexpr size_t kHeader3 = 3;
  static constexpr size_t kHeader4 = 4;

  explicit streamable_parser(size_t level) : m_level(level) {}

  /**
   * \brief Dump the parsed (or possibly unparsed, but that's kind of useless)
   * parameters to the specified stream.
   */
  virtual void show(std::ostream&) const = 0;

  /**
   * \brief Build a header suitable for inclusion in dumping parsed parameters
   * to a stream.
   *
   * \return The constructed header.
   */
  std::string header_build(const std::string& xml_root) const;

  /**
   * \brief Build a footer suitable for inclusion in dumping parsed parameters
   * to a stream.
   *
   * \return The constructed footer.
   */
  std::string footer_build(const std::string& xml_root) const;

  size_t level(void) const { return m_level; }

  friend std::ostream& operator<<(std::ostream& stream,
                                  const streamable_parser& parser) {
    parser.show(stream);
    return stream;
  } /* operator<<() */

 private:
  /* clang-format off */
  size_t m_level;
  /* clang-format on */
};

NS_END(config, rcppsw);

