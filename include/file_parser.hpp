/*******************************************************************************
 * Name            : file_parser.hpp
 * Project         : rcppsw
 * Module          : utils
 * Description     : File parsing class using template design pattern
 * Creation Date   : 02/01/17
 * Copyright       : Copyright 2017 NAME, All rights reserved
 *
 ******************************************************************************/

#ifndef INCLUDE_FILE_PARSER_HPP_
#define INCLUDE_FILE_PARSER_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <string>

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace rcppsw {

/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class file_parser {
 public:
  /* constructors */
  explicit file_parser(const std::string& fname): fname_(fname) {}

  /* member functions */
  template <typename T> std::vector<std::vector<T>> parse_file(
      const std::string& delimiters = " ", bool trim_empty = false);

 private:
  /* member functions */
  template <typename T> std::vector<T> parse_line(
      const std::string& line,
      const std::string& delimiters, bool trim_empty);

  /* data members */
  const std::string& fname_;
};

} /* namespace rcppsw */

#endif /* INCLUDE_FILE_PARSER_HPP_ */
