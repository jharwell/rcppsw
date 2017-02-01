/*******************************************************************************
 * Name            : file_parser.cpp
 * Project         : rcppsw
 * Module          : utils
 * Description     : File parsing class
 * Creation Date   : 02/01/17
 * Copyright       : Copyright 2017 John Harwell, All rights reserved
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "include/file_parser.hpp"
#include <fstream>

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
using namespace rcppsw;

/*******************************************************************************
 * Constant Definitions
 ******************************************************************************/

/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/

/*******************************************************************************
 * Global Variables
 ******************************************************************************/

/*******************************************************************************
 * Forward Declarations
 ******************************************************************************/

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
/**
 * file_parser::parse_file() - Parse a file into a vector of sets of tokens,
 * based on a particular delimiter
 *
 * std::vector<std::vector<T>> - The results of parsing
 **/
template <typename T>
std::vector<std::vector<T>> file_parser::parse_file(
    const std::string& delimiters, bool trim_empty) {
  std::vector<std::vector<T>> tokens_set;
  std::string line;
  std::ifstream infile(fname_);

  while (std::getline(infile, line)) {
    tokens_set.push_back(parse_line<T>(line, delimiters, trim_empty));
  } /* while() */

  return tokens_set;
} /* file_parser::parse_file() */

/**
 * file_parser::parse_line() - Parse a line into a set of tokens, using a
 * specified delimiter (space by default). Also it allows you to trim empty
 * tokens from the results via the last parameter.
 *
 * std::vector<int> - The parsed token set
 **/
template <typename T>
std::vector<T> file_parser::parse_line(const std::string& line,
                                       const std::string& delimiters,
                                       bool trim_empty) {
  std::string::size_type pos;
  std::size_t last_pos = 0;
  std::size_t length = line.length();

  std::vector<T> tokens;
  using value_type = typename T::value_type;
  using size_type  = typename T::size_type;

  while (last_pos < length + 1) {
    pos = line.find_first_of(delimiters, last_pos);
    if (pos == std::string::npos) {
      pos = length;
    }

    if (pos != last_pos || !trim_empty)
      tokens.push_back(value_type(line.data()+last_pos,
                                  (size_type)pos-last_pos));
    last_pos++;
  } /* while() */
} /* file_parser::parse_line() */
