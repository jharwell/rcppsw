/*******************************************************************************
 * Name            : cli_base.hpp
 * Project         : rcppsw
 * Module          : cli
 * Description     : Header file for abstract class CLI.
 * Creation Date   : 06/19/16
 * Copyright       : Copyright 2016 John Harwell, All rights reserved
 *
 ******************************************************************************/

#ifndef INCLUDE_CLI_BASE_HPP_
#define INCLUDE_CLI_BASE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include <boost/program_options.hpp>
#include "include/al/altypes.h"

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
  explicit cli_base(
      const std::string& mnemonic = "");
  virtual ~cli_base() {}

  int parse(int argc, char **argv);
  virtual status_t validate(void) { return OK; }
  void print(void);
  const bpo::variables_map& vm(void) { return vm_; }
  bpo::options_description* desc(void) { return &desc_; }
  const std::string& prog_name(void) { return prog_name_; }

 private:
  bpo::variables_map vm_;
  bpo::options_description desc_;
  std::string prog_name_;
  std::string output_dir_base_;
};

} /* namespace rcppsw */

#endif /* INCLUDE_CLI_BASE_HPP_ */
