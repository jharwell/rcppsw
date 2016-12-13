/*******************************************************************************
 * Name            : cli_base.hpp
 * Project         : rcppsw
 * Module          : cli
 * Description     : Header file for abstract class CLI.
 * Creation Date   : Fri Jun 19 16:10:50 2015
 * Original Author : jharwell
 *
 ******************************************************************************/

#ifndef CLI_BASE_HPP_
#define CLI_BASE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <boost/program_options.hpp>
#include "altypes.h"

/*******************************************************************************
 * Namespace Definitions
 ******************************************************************************/
namespace bpo = boost::program_options;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class cli_base {
 public:
  explicit cli_base(
      const std::string& mnemonic = "");
  virtual ~cli_base() {}

  int parse(int argc,char **argv);
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

#endif /* CLI_BASE_HPP_ */
