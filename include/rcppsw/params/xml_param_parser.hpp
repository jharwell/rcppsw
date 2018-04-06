/**
 * @file xml_param_parser.hpp
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

#ifndef INCLUDE_RCPPSW_PARAMS_XML_PARAM_PARSER_HPP_
#define INCLUDE_RCPPSW_PARAMS_XML_PARAM_PARSER_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iosfwd>
#include <string>
#include "rcsw/common/fpc.h"
#include "rcppsw/common/common.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace ticpp { class Element; }

NS_START(rcppsw, params);
struct base_params;

/*******************************************************************************
 * Macros
 ******************************************************************************/
#define XML_PARAM_STR(container, name) std::string(#name) << "=" << container.name
#define XML_PARSE_PARAM(node, container, name)                          \
  argos::GetNodeAttribute(node,                                         \
                          #name,                                        \
                          container.name)

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class xml_param_parser
 * @ingroup params
 *
 * @brief Interface specifying functionality for parsing XML into a
 * \ref base_params derived parameter structure.
 *
 */
class xml_param_parser {
 public:
  explicit xml_param_parser(uint level) : m_level(level) {}

  virtual ~xml_param_parser(void) = default;

  static constexpr uint kColumnWidth = 100;
  static constexpr uint kHeader1 = 1;
  static constexpr uint kHeader2 = 2;
  static constexpr uint kHeader3 = 3;
  static constexpr uint kHeader4 = 4;

  /**
   * @brief Return the root XML tag that all parameters for the specified parser
   * should be found/placed under.
   */
  virtual std::string xml_root(void) const = 0;

  /**
   * @brief Build a header suitable for inclusion in dumping parsed parameters
   * to a stream.
   *
   * @param level The level of the header to build. Root level headers (level=1)
   * will get headers of width \ref kColumnWidth. For all other values > 0, the
   * width of the header emitted is \ref kColumnWidth/level.
   *
   * @return The constructed header.
   */
  std::string build_header(void) const {
    FPC_CHECK("", level() > 0, level() <= kHeader4);
    int width = kColumnWidth  - level() * 20;
    std::string prettiness(width, '=');
    std::string spaces(width/2 - xml_root().size()/2 - 1, ' ');
    return prettiness + "\n"
        + spaces + "<" + xml_root() + ">" +
        "\n" + prettiness + "\n";
  }

  /**
   * @brief Build a footer suitable for inclusion in dumping parsed parameters
   * to a stream.
   *
   * @param level The level of the footer to build. Root level footer (level=1)
   * will get footer of width \ref kColumnWidth. For all other values > 0, the
   * width of the footer emitted is \ref kColumnWidth/level.
   *
   * @return The constructed footer.
   */
  std::string build_footer(void) const {
    FPC_CHECK("", level() > 0, level() <= kHeader4);
    int width = kColumnWidth - level() * 20;
    std::string prettiness(width, '=');
    std::string spaces(width/2 - xml_root().size()/2 - 1, ' ');
    return prettiness + "\n"
        + spaces + "</" + xml_root() + ">" +
        "\n" + prettiness + "\n";
  }

  /**
   * @brief Parse the provided XML node into an internal representation (should
   * be a class/struct derived from \ref base_params).
   *
   * @param node The XML tag that the root (i.e. the value returned by
   * \ref xml_root()) for the parser can be found under.
   */
  virtual void parse(const ticpp::Element& node) = 0;

  /**
   * @brief Validate the range, value, etc. of all parsed parameters. As such,
   * don't call this unless the parameters have already been parsed.
   *
   * @return \c TRUE if all parameters are valid, \c FALSE otherwise.
   */
  virtual bool validate(void) const { return true; }

  /**
   * @brief Get the results of parameter parse.
   */
  virtual const struct base_params* parse_results(void) const = 0;

  friend std::ostream& operator<<(std::ostream& stream,
                                  const xml_param_parser& parser) {
    parser.show(stream);
    return stream;
  } /* operator<<() */

  uint level(void) const { return m_level; }
  void level(uint level) { m_level = level; }

 private:
  /**
   * @brief Dump the parsed (or possibly unparsed, but that's kind of useless)
   * parameters to the specified stream.
   */
  virtual void show(std::ostream&) const {}

  uint m_level;
};

NS_END(params, rcppsw);

#endif /* INCLUDE_RCPPSW_PARAMS_XML_PARAM_PARSER_HPP_ */
