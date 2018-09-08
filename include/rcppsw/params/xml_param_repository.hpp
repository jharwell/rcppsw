/**
 * @file xml_param_repository.hpp
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

#ifndef INCLUDE_RCPPSW_PARAMS_XML_PARAM_REPOSITORY_HPP_
#define INCLUDE_RCPPSW_PARAMS_XML_PARAM_REPOSITORY_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <map>
#include <string>
#include <typeindex>

#include "rcppsw/common/common.hpp"
#include "rcppsw/params/xml_param_parser.hpp"
#include "rcppsw/patterns/factory/sharing_factory.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, params);
namespace factory = rcppsw::patterns::factory;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class xml_param_repository
 * @ingroup common
 *
 * @brief A repository for multiple \ref xml_param_parser objects and their
 * parsed results; allows collective operations on multiple parsers.
 *
 * Utilizes factory pattern for parser creation. Does not create any parsers on
 * its own (how could it know which ones to create?). All created parsers must
 * derive from \ref xml_param_parser, and have a constructor with the same
 * signature as the constructor for that class available, or cryptic compile
 * errors will result.
 */
class xml_param_repository {
 public:
  explicit xml_param_repository(const std::string& er_parser_parent)
      : mc_er_parser_parent(er_parser_parent), m_parsers(), m_param_types(), m_factory() {}

  /**
   * @brief Call the \ref xml_param_parser::parse() function on all parsers
   * in the repository, passing all parsers the same XML node.
   */
  void parse_all(const ticpp::Element& node);

  /**
   * @brief Call the \ref xml_param_parser::validate() function on all parsers
   * in the repository, and return whether or not \a ALL parsers report valid
   * parameters.
   *
   * @return \c TRUE iff ALL parsers report valid parameters, and \c FALSE
   * otherwise.
   */
  bool validate_all(void);

  /**
   * @brief Get the parsed parameters associated with the parser of the
   * specified type (note that the name that the parser was registered with is
   * not needed in this formulation).
   *
   * @return The parsed parameters (non-owning).
   */
  template<typename T>
  const T* parse_results(void) {
    std::type_index i(typeid(T));
    return m_parsers[m_param_types[i]]->parse_results<T>().get();
  }

  /**
   * @brief Get the parsed parameters associated with the parser of the
   * specified name.
   *
   * @return The parsed parameters (non-owning).
   */
  template<typename T>
  const T* parse_results(const std::string& name) {
    return m_parsers[name]->parse_results<T>().get();
  }

  /**
   * @brief Register a parser of a given type (must be derived from \ref
   * xml_param_parser) and associate it with the specified name.
   *
   * @tparam T The parser type.
   * @tparam S The type of the parameter struct that the parser produces.
   */
  template <typename T, typename S>
  void register_parser(const std::string& name, uint level_in) {
    m_factory.register_type<T, decltype(level_in)>(name);
    m_parsers[name] = m_factory.create(name, mc_er_parser_parent, level_in).get();
    std::type_index i(typeid(S));
    m_param_types[i] = name;
  }

  /**
   * @brief Register a parser of a given type (must be derived from
   * \ref xml_param_parser) and associate it with the specified name.
   *
   * If you use this function, then you will have to refer to the parse results
   * by type + name, rather than just by type.
   *
   * @tparam T The parser type.
   */
  template <typename T>
  void register_parser(const std::string& name, uint level_in) {
    m_factory.register_type<T, decltype(level_in)>(name);
    m_parsers[name] = m_factory.create(name, mc_er_parser_parent, level_in).get();
  }

  /**
   * @brief Dump all parsed (or unparsed, but that would be useless) parameters
   * to the specified stream.
   */
  friend std::ostream& operator<<(std::ostream& stream,
                                  const xml_param_repository& repo);

 private:
  // clang-format off
  const std::string                                mc_er_parser_parent;
  std::map<std::string, xml_param_parser*>         m_parsers;
  std::map<std::type_index, std::string>           m_param_types;
  factory::sharing_factory<xml_param_parser,
                           const std::string&,
                           uint>                   m_factory;
  // clang-format on
};

NS_END(params, rcppsw);

#endif /* INCLUDE_RCPPSW_PARAMS_XML_PARAM_REPOSITORY_HPP_ */
