/**
 * \file xml_config_parser.hpp
 *
 * \copyright 2017 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <ticpp/ticpp.h>

#include "rcppsw/er/client.hpp"
#include "rcppsw/config/base_parser.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, config);
struct base_config;

NS_START(xml);

/*******************************************************************************
 * Macros
 ******************************************************************************/
/**
 * \def XML_PARSE_ATTR(node, container, name)
 *
 * Parse the attribute \p name from the parent \p node, and place the result
 * into \p container, which \a MUST have a field named \p name or a compilation
 * error will result.
 *
 * If \p name does not exist in \p node, then an exception will be thrown.
 */
#define XML_PARSE_ATTR(node, container, name) \
  this->node_attr_get((node), #name, (container)->name)

/**
 * \def XML_PARSE_ATTR_DFLT(node, container, name, dflt)
 *
 * Same as \ref XML_PARSE_ATTR_DFLT, but provide a default value in case \p name
 * is not found in \p node.
 */
#define XML_PARSE_ATTR_DFLT(node, container, name, dflt) \
  this->node_attr_get((node), #name, (container)->name, dflt)

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class xml_config_parser
 * \ingroup config xml
 *
 * \brief Interface specifying functionality for parsing XML into a \ref
 * base_config derived parameter structure.
 */
class xml_config_parser : public rer::client<xml_config_parser>,
                          public rconfig::base_parser {
 public:
  /**
   * \brief A sentinel value for XML fields which are strings, for indicating
   * that the field is set to NOTHING (as opposed to being omitted, which could
   * result in a default which is different than the desired NOTHING).
   */
  static inline const std::string kNone = "none";

  xml_config_parser(void);
  ~xml_config_parser(void) override = default;

  /**
   * \brief Return the root XML tag that all parameters for the specified parser
   * should be found/placed under.
   */
  virtual std::string xml_root(void) const = 0;

  /**
   * \brief Parse the provided XML node into an internal representation (should
   * be a class/struct derived from \ref base_config).
   *
   * \param node The XML tag that the root (i.e. the value returned by
   * \ref xml_root()) for the parser can be found under.
   */
  virtual void parse(const ticpp::Element& node) = 0;

  /**
   * \brief Get the node that is inside the specified one, designated by the
   * specified tag.
   *
   * If no such node exists, an assertion halts the program.
   */
  ticpp::Element& node_get(const ticpp::Element& node,
                           const std::string& tag) const RCPPSW_COLD;

  /**
   * \brief Get an attribute inside a node.
   *
   * \param node The node to search.
   * \param attr The attribute name.
   * \param buf  The result buffer.
   */
  template <typename T>
  RCPPSW_COLD void node_attr_get(const ticpp::Element& node,
                     const std::string& attr,
                     T& buf) const {
    node.GetAttribute(attr, &buf, true);
  }

  /**
   * \brief Get a boolean attribute inside a node (bools have to be handed
   * specially, or at least I can't figure out how to make them also work the
   * template version).
   */
   void node_attr_get(const ticpp::Element& node,
                     const std::string& attr,
                     bool& buf) const RCPPSW_COLD;

  /**
   * \brief Get an attribute inside a node, or substitute a default value if the
   * attribute does not exist.
   *
   * \param node The node to search.
   * \param attr The attribute name.
   * \param buf  The result buffer.
   * \param dflt The default value to use if the attribute does not exist.
   */
  template <typename T,
            typename U = T,
            RCPPSW_SFINAE_DECLDEF(!std::is_same<T, bool>::value)>
  RCPPSW_COLD void node_attr_get(const ticpp::Element& node,
                     const std::string& attr,
                     T& buf,
                     const T& dflt) const {
    node.GetAttributeOrDefault(attr, &buf, dflt);
  }

  /**
   * \brief Get a boolean attribute inside a node (bools have to be handed
   * specially, or at least I can't figure out how to make them also work in the
   * template version).
   */
  template <typename T,
            typename U = T,
            RCPPSW_SFINAE_DECLDEF(std::is_same<U, bool>::value)>
  RCPPSW_COLD void node_attr_get(const ticpp::Element& node,
                     const std::string& attr,
                     T& buf,
                     const T& dflt) const {
    if (!node.HasAttribute(attr)) {
      buf = dflt;
      return;
    }
    node_attr_get(node, attr, buf);
  }
};

NS_END(xml, config, rcppsw);
