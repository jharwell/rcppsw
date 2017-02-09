/*******************************************************************************
 * Name            : cli_base.cpp
 * Project         : rcppsw
 * Module          : cli
 * Description     : CLI base class
 * Creation Date   : 06/14/15
 * Copyright       : Copyright 2015 John Harwell, All rights reserved
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/cli_base.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
using namespace rcppsw;

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
cli_base::cli_base(const std::string &mnemonic)
    : vm_(), desc_("Program options"), prog_name_(), output_dir_base_() {
  time_t rawtime;
  char buffer[80];
  time(&rawtime);
  struct tm *timeinfo = localtime(&rawtime);
  strftime(buffer, 80, "%Y-%m-%d", timeinfo);

  output_dir_base_ = "outputs/" + mnemonic + "/" + std::string(buffer) + "/";
  std::string logfile = output_dir_base_ + std::to_string(getpid()) + "-log";
  desc_.add_options()("help", "Produce this message");

  /* define auxillary command line options */
  desc_.add_options()

      /* Add options for configuring logging */
      ("logfile", bpo::value<std::string>()->default_value(logfile),
       ("Specify the file where stuff will be logged to. Default=" + logfile)
           .c_str())("dbglvl", bpo::value<int>()->default_value(3),
                     "Set the initial debug printing level. Higher numbers = "
                     "more verbose output. Range=[0, 5]. Default=3.")(
          "loglvl", bpo::value<int>()->default_value(3),
          "Set the initial logging printing level. Higher numbers = more "
          "verbose logging. Range=[0, 5]. Default=3.");
} /* cli_base::cli_base() */

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
/**
 * cli_base::parse() - Parse command line options
 *
 * RETURN:
 *     int - 0 successful, non-zero otherwise
 *
 **/
int cli_base::parse(int argc, char **argv) {
  prog_name_ = std::string(argv[0]);
  try {
    bpo::store(bpo::parse_command_line(argc, argv, desc_), vm_);
    if (vm_.count("help")) {
      std::cout << "\n" << desc_ << "\n";
      return 1;
    }
    bpo::notify(vm_);
  } catch (bpo::error &e) {
    std::cerr << "ERROR: " << e.what() << "\n\n";
    std::cerr << desc_ << "\n";
    return -1;
  }
  return 0;
} /* cli_base::parse() */

/**
 * cli_base::print() - Print all options that were passed to stdout
 *
 * RETURN:
 *     N/A
 *
 **/
void cli_base::print(void) {
  std::cout << prog_name_ << " invoked with: ";
  for (bpo::variables_map::iterator it = vm_.begin(); it != vm_.end(); ++it) {
    std::cout << it->first;
    if ((static_cast<boost::any>(it->second.value())).empty()) {
      std::cout << "(empty)";
    }
    if (vm_[it->first].defaulted() || it->second.defaulted()) {
      std::cout << "(default)";
    }
    std::cout << "=";

    bool is_char;
    try {
      boost::any_cast<const char *>(it->second.value());
      is_char = true;
    } catch (const boost::bad_any_cast &) {
      is_char = false;
    }
    bool is_str;
    try {
      boost::any_cast<std::string>(it->second.value());
      is_str = true;
    } catch (const boost::bad_any_cast &) {
      is_str = false;
    }

    if ((static_cast<boost::any>(it->second.value()).type()) == typeid(int)) {
      std::cout << vm_[it->first].as<int>() << " ";
    } else if ((static_cast<boost::any>(it->second.value()).type()) ==
               typeid(bool)) {
      std::cout << vm_[it->first].as<bool>() << " ";
    } else if ((static_cast<boost::any>(it->second.value()).type()) ==
               typeid(double)) {
      std::cout << vm_[it->first].as<double>() << " ";
    } else if ((static_cast<boost::any>(it->second.value()).type()) ==
               typeid(float)) {
      std::cout << vm_[it->first].as<float>() << " ";
    } else if (is_char) {
      std::cout << vm_[it->first].as<const char *>() << " ";
    } else if (is_str) {
      std::string temp = vm_[it->first].as<std::string>();
      if (temp.size()) {
        std::cout << temp << " ";
      } else {
        std::cout << "true"
                  << " ";
      }
    } else {  // Assumes that the only remainder is vector<string>
      try {
        std::vector<std::string> vect =
            vm_[it->first].as<std::vector<std::string> >();
        uint i = 0;
        for (std::vector<std::string>::iterator oit = vect.begin();
             oit != vect.end(); ++oit, ++i) {
          std::cout << "\r> " << it->first << "[" << i << "]=" << (*oit)
                    << std::endl;
        }
      } catch (const boost::bad_any_cast &) {
        std::cout << "UnknownType("
                  << (static_cast<boost::any>(it->second.value()).type()).name()
                  << ")" << std::endl;
      }
    }
  } /* for() */
  std::cout << "\n";
} /* cli_base::print() */
