/**
 * \file base_cli.hpp
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
#include <boost/program_options.hpp>
#include <string>

#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace bpo = boost::program_options;
NS_START(rcppsw, utils);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class base_cli
 * \ingroup utils
 *
 * \brief Base class for command line interfaces. Uses boost to do the actual
 * parsing.
 */
class base_cli {
 public:
  explicit base_cli(const std::string& mnemonic = "");
  virtual ~base_cli(void) = default;

  /**
   * \brief Parse command line options.
   *
   * \param argc The argc from main().
   * \param argv The argv from main().
   *
   * \return \ref status_t.
   */
  status_t parse(int argc, char** argv);

  /**
   * \brief Determine if parameters passed are valid, by some criterion.
   *
   * \return \c TRUE if the condition is met, and \c FALSE otherwise.
   */

  virtual bool validate(void) { return true; }

  /**
   * \brief Print all options and their help to stdout.
   */
  void print(void);

  /**
   * \brief Get a handle on the variables map.
   *
   * \return The variables map handle.
   */
  const bpo::variables_map& vm(void) { return m_vm; }

  /**
   * \brief Get a handle on the options description.
   *
   * \return The variables map handle.
   */
  bpo::options_description* desc(void) { return &m_desc; }

  /**
   * \brief Get the program name.
   *
   * \return The program name.
   */
  const std::string& prog_name(void) { return m_prog_name; }

 private:
  /* clang-format off */
  bpo::variables_map       m_vm{};
  bpo::options_description m_desc;
  std::string              m_prog_name{};
  std::string              m_base_output_dir{};
  /* clang-format on */
};

NS_END(utils, rcppsw);

