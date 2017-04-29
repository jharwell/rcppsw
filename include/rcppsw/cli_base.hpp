/*******************************************************************************
 * Name            : cli_base.hpp
 * Project         : rcppsw
 * Module          : cli
 * Description     : Base CLI.
 * Creation Date   : 06/19/16
 * Copyright       : Copyright 2016 John Harwell, All rights reserved.
 *
 ******************************************************************************/

#ifndef INCLUDE_RCPPSW_CLI_BASE_HPP_
#define INCLUDE_RCPPSW_CLI_BASE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include <boost/program_options.hpp>
#include "rcsw/common/common.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace bpo = boost::program_options;
namespace rcppsw {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class cli_base {
 public:
  explicit cli_base(const std::string& mnemonic = "");
  virtual ~cli_base() {}

  /**
   * @brief Parse command line options.
   *
   * @param argc The argc from main().
   * @param argv The argv from main().
   *
   * @return OK if successful, ERROR otherwise.
   */
  status_t parse(int argc, char** argv);

  /**
   * @brief Determine if parameters passed are valid, by some criterion.
   *
   * @return TRUE if the condition is met, and FALSE otherwise.
   */

  virtual bool validate(void) { return OK; }

  /**
   * @brief Print all options and their help to stdout.
   */
  void print(void);

  /**
   * @brief Get a handle on the variables map.
   *
   * @return The variables map handle.
   */
  const bpo::variables_map& vm(void) { return vm_; }

  /**
   * @brief Get a handle on the options description.
   *
   * @return The variables map handle.
   */
  bpo::options_description* desc(void) { return &desc_; }

  /**
   * @brief Get the program name.
   *
   * @return The program name.
   */
  const std::string& prog_name(void) { return prog_name_; }

 private:
  bpo::variables_map vm_;
  bpo::options_description desc_;
  std::string prog_name_;
  std::string output_dir_base_;  /// The root directory for program outputs.
};

} /* namespace rcppsw */

#endif /* INCLUDE_RCPPSW_CLI_BASE_HPP_ */
