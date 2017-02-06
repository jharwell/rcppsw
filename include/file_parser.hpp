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
#include <fstream>
#include <sstream>
#include <iostream>
#include <iterator>
#include <algorithm>

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
template <typename T> class file_parser {
 public:
  /* constructors */
  explicit file_parser(const std::string& fname): fname_(fname) {}

  /* member functions */
  /**
   * file_parser::parse_file() - Parse a file into a vector of sets of tokens,
   *
   * std::vector<std::vector<T>> - The results of parsing
   **/
  std::vector<T> parse_file(void) {
    std::vector<T> tokens_set;
    std::string line;
    std::ifstream infile(fname_);

    while (std::getline(infile, line)) {
      tokens_set.push_back(parse_line(line));
    } /* while() */

    return tokens_set;
  } /* file_parser::parse_file() */

  /**
   * file_parser::parse_line() - Parse a line into a set of tokens, using a
   * specified delimiter (space by default). Also it allows you to trim empty
   * tokens from the results via the last parameter.
   *
   * T - The parsed token set
   **/
  T parse_line(const std::string& line) {
    T tokens;
    std::istringstream iss(line);

    // Iterate over the istream, using >> to grab floats
    // and push_back to store them in the vector
    std::copy(std::istream_iterator<float>(iss),
              std::istream_iterator<float>(),
              std::back_inserter(tokens));
    return tokens;
  } /* file_parser::parse_line() */

 private:
  /* data members */
  const std::string& fname_;
};

} /* namespace rcppsw */

#endif /* INCLUDE_FILE_PARSER_HPP_ */
