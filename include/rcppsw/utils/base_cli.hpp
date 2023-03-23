/**
 * \file base_cli.hpp
 *
 * \copyright 2017 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
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
namespace rcppsw::utils {

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

} /* namespace rcppsw::utils */

