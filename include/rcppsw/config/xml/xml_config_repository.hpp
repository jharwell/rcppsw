/**
 * \file xml_config_repository.hpp
 *
 * \copyright 2017 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <map>
#include <string>
#include <typeindex>

#include "rcppsw/rcppsw.hpp"
#include "rcppsw/config/xml/xml_config_parser.hpp"
#include "rcppsw/patterns/factory/factory.hpp"
#include "rcppsw/er/client.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, config, xml);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class xml_config_repository
 * \ingroup config xml
 *
 * \brief A repository for multiple \ref xml_config_parser objects and their
 * parsed results; allows collective operations on multiple parsers.
 *
 * Utilizes factory pattern for parser creation. Does not create any parsers on
 * its own (how could it know which ones to create?). All created parsers must
 * derive from \ref xml_config_parser, and have a constructor with the same
 * signature as the constructor for that class available, or cryptic compile
 * errors will result.
 */
class xml_config_repository : public er::client<xml_config_repository> {
 public:
  xml_config_repository(void)
      : ER_CLIENT_INIT("rcppsw.config.xml.repository") {}

  /**
   * \brief Call the \ref xml_config_parser::parse() function on all parsers
   * in the repository, passing all parsers the same XML node.
   */
  void parse_all(const ticpp::Element& node) RCPPSW_COLD;

  /**
   * \brief Call the \ref xml_config_parser::validate() function on all parsers
   * in the repository, and return whether or not \a ALL parsers report valid
   * configuration.
   *
   * \return \c TRUE iff ALL parsers report valid configuration, and \c FALSE
   * otherwise.
   */
  bool validate_all(void) RCPPSW_COLD;

  /**
   * \brief Get the parsed configuration associated with the parser of the
   * specified type (note that the name that the parser was registered with is
   * not needed in this formulation).
   *
   * \return The parsed configuration (non-owning), or NULL if an invalid type
   * of configuration was requested.
   */
  template <typename T>
  RCPPSW_COLD const T* config_get(void) const {
    std::type_index i(typeid(T));
    auto it = m_parsers.find(m_config_types.find(i)->second);
    if (m_parsers.end() != it) {
      return config_get<T>(it->first);
    }
    return nullptr;
  }

  /**
   * \brief Get the parsed configuration associated with the parser of the
   * specified name.
   *
   * \return The parsed configuration (non-owning).
   */
  template <typename T>
  RCPPSW_COLD const T* config_get(const std::string& name) const {
    auto it = m_parsers.find(name);
    if (m_parsers.end() != it) {
      return it->second->config_get<T>();
    }
    return nullptr;
  }

  /**
   * \brief Get a registered parser by name (non-owning).
   *
   * \param name The name of the parser.
   *
   * \return Non-owning pointer to the requested parser, or NULL if no such
   * parser was registered.
   */
  template <typename T>
  RCPPSW_COLD T* parser_find(const std::string& name) {
    auto it = m_parsers.find(name);
    if (m_parsers.end() != it) {
      return static_cast<T*>(it->second);
    }
    return nullptr;
  }

  /**
   * \brief Register a parser of a given type (must be derived from \ref
   * xml_config_parser) and associate it with the specified name.
   *
   * \tparam T The parser type.
   * \tparam S The type of the configuration that the parser produces when
   *           parse() is called on it.
   */
  template <typename T, typename S>
  RCPPSW_COLD void parser_register(const std::string& name) {
    m_factory.register_type<T>(name);
    m_parsers[name] = m_factory.create(name).get();
    std::type_index i(typeid(S));
    m_config_types[i] = name;
  }

  /**
   * \brief Register a parser of a given type (must be derived from \ref
   * xml_config_parser) and associate it with the specified name.
   *
   * \tparam T The parser type.
   * \tparam S The type of the configuration that the parser produces when
   *           parse() is called on it.
   */
  template <typename T, typename S>
  RCPPSW_COLD void parser_unregister(const std::string& name) {
    m_factory.unregister_type<T>(name);

    std::type_index i(typeid(S));
    auto it = m_config_types.find(i);
    if (m_config_types.end() != it) {
      m_config_types.erase(i);
    }
  }

  /**
   * \brief Register a parser of a given type (must be derived from
   * \ref xml_config_parser) and associate it with the specified name.
   *
   * If you use this function, then you will have to refer to the parse results
   * by type + name, rather than just by type.
   *
   * \tparam T The parser type.
   */
  template <typename T>
  RCPPSW_COLD void parser_register(const std::string& name) {
    m_factory.register_type<T>(name);
    m_parsers[name] = m_factory.create(name).get();
  }

 private:
  /* clang-format off */
  std::map<std::string, xml_config_parser*>       m_parsers{};
  std::map<std::type_index, std::string>          m_config_types{};
  patterns::factory::sharing_factory<xml_config_parser,
                                     std::string> m_factory{};
  /* clang-format on */
};

NS_END(xml, config, rcppsw);
