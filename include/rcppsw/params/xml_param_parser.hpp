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
#include <ext/ticpp/ticpp.h>
#include <iosfwd>
#include <string>
#include "rcppsw/common/common.hpp"
#include "rcppsw/er/client.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace ticpp {
class Element;
}

NS_START(rcppsw, params);
struct base_params;

/*******************************************************************************
 * Macros
 ******************************************************************************/
#define XML_ATTR_STR(container, name) \
  std::string(#name) << "=" << (container)->name
#define XML_PARSE_ATTR(node, container, name) \
  this->node_attr_get((node), #name, (container)->name)

#define XML_PARSE_ATTR_DFLT(node, container, name, dflt) \
  this->node_attr_get((node), #name, (container)->name, dflt)

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
class xml_param_parser : public er::client<xml_param_parser> {
 public:
  explicit xml_param_parser(uint level);
  ~xml_param_parser(void) override = default;

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
   * @return The constructed header.
   */
  std::string build_header(void) const;

  /**
   * @brief Build a footer suitable for inclusion in dumping parsed parameters
   * to a stream.
   *
   * @return The constructed footer.
   */
  std::string build_footer(void) const;

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
   * @brief Get the results of parameter parse. This is the front end of the
   * non-virtual interface to getting the results of a parameter parse, so that
   * covariance with smart pointer return types will work.
   */
  template <typename T>
  std::shared_ptr<T> parse_results(void) const {
    static_assert(std::is_base_of<base_params, T>::value,
                  "Parameters must be derived from base_params!");
    return std::static_pointer_cast<T>(parse_results_impl());
  }

  friend std::ostream& operator<<(std::ostream& stream,
                                  const xml_param_parser& parser) {
    parser.show(stream);
    return stream;
  } /* operator<<() */

  uint level(void) const { return m_level; }
  void level(uint level) { m_level = level; }

  /**
   * @brief Get the node that is inside the specified one, designated by the
   * specified tag.
   *
   * If no such node exists, an assertion halts the program.
   */
  ticpp::Element& node_get(ticpp::Element& node, const std::string& tag);

  /**
   * @brief Get an attribute inside a node.
   *
   * @param node The node to search.
   * @param attr The attribute name.
   * @param buf  The result buffer.
   */
  template <typename T>
  void node_attr_get(ticpp::Element& node, const std::string& attr, T& buf) {
    node.GetAttribute(attr, &buf, true);
  }

  /**
   * @brief Get a boolean attribute inside a node (bools have to be handed
   * specially, or at least I can't figure out how to make them also work the
   * template version).
   */
  void node_attr_get(ticpp::Element& node, const std::string& attr, bool& buf);

  /**
   * @brief Get an attribute inside a node, or substitute a default value if the
   * attribute does not exist.
   *
   * @param node The node to search.
   * @param attr The attribute name.
   * @param buf  The result buffer.
   * @param dflt The default value to use if the attribute does not exist.
   */
  template <typename T>
  void node_attr_get(ticpp::Element& node,
                     const std::string& attr,
                     T& buf,
                     const T& dflt) {
    node.GetAttributeOrDefault(attr, &buf, dflt);
  }

  virtual bool parsed(void) const { return true; }

 private:
  /**
   * @brief Implementation (back end) of how to get the results of a parameter
   * parse using covariance. This is to make parameter parsing easy when you
   * only have a handle on THIS class, even if the object is actually a derived
   * class parameter parser.
   */
  virtual std::shared_ptr<base_params> parse_results_impl(void) const = 0;

  /**
   * @brief Dump the parsed (or possibly unparsed, but that's kind of useless)
   * parameters to the specified stream.
   */
  virtual void show(std::ostream&) const {}

  uint m_level;
};

NS_END(params, rcppsw);

#endif /* INCLUDE_RCPPSW_PARAMS_XML_PARAM_PARSER_HPP_ */
