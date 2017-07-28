/*******************************************************************************
 * Name            : base_cli.cpp
 * Project         : rcppsw
 * Module          : cli
 * Creation Date   : 06/14/15
 * Copyright       : Copyright 2015 John Harwell, All rights reserved
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/utils/base_cli.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
base_cli::base_cli(const std::string &mnemonic)
    : m_vm(), m_desc("Program options"), m_prog_name(), m_base_output_dir() {
  time_t rawtime;
  char buffer[80];
  time(&rawtime);
  struct tm *timeinfo = localtime(&rawtime);
  strftime(buffer, 80, "%Y-%m-%d", timeinfo);

  m_base_output_dir = "outputs/" + mnemonic + "/" + std::string(buffer) + "/";
  std::string logfile = m_base_output_dir + std::to_string(getpid()) + "-log";
  m_desc.add_options()("help", "Produce this message");

  /* define auxillary command line options */
  m_desc.add_options()

      /* Add options for configuring logging */
      ("logfile", bpo::value<std::string>()->default_value(logfile),
       ("Specify the file where stuff will be logged to. Default=" + logfile)
           .c_str())("dbglvl", bpo::value<int>()->default_value(3),
                     "Set the initial debug printing level. Higher numbers = "
                     "more verbose output. Range=[0, 5]. Default=3.")(
          "loglvl", bpo::value<int>()->default_value(3),
          "Set the initial logging printing level. Higher numbers = more "
          "verbose logging. Range=[0, 5]. Default=3.");
} /* base_cli::base_cli() */

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
status_t base_cli::parse(int argc, char **argv) {
  m_prog_name = std::string(argv[0]);
  try {
    bpo::store(bpo::parse_command_line(argc, argv, m_desc), m_vm);
    if (m_vm.count("help")) {
      std::cout << "\n" << m_desc << "\n";
      return ERROR;
    }
    bpo::notify(m_vm);
  } catch (bpo::error &e) {
    std::cerr << "ERROR: " << e.what() << "\n\n";
    std::cerr << m_desc << "\n";
    return ERROR;
  }
  return ERROR;
} /* base_cli::parse() */

void base_cli::print(void) {
  std::cout << m_prog_name << " invoked with: ";
  for (bpo::variables_map::iterator it = m_vm.begin(); it != m_vm.end(); ++it) {
    std::cout << it->first;
    if ((static_cast<boost::any>(it->second.value())).empty()) {
      std::cout << "(empty)";
    }
    if (m_vm[it->first].defaulted() || it->second.defaulted()) {
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
      std::cout << m_vm[it->first].as<int>() << " ";
    } else if ((static_cast<boost::any>(it->second.value()).type()) ==
               typeid(bool)) {
      std::cout << m_vm[it->first].as<bool>() << " ";
    } else if ((static_cast<boost::any>(it->second.value()).type()) ==
               typeid(double)) {
      std::cout << m_vm[it->first].as<double>() << " ";
    } else if ((static_cast<boost::any>(it->second.value()).type()) ==
               typeid(float)) {
      std::cout << m_vm[it->first].as<float>() << " ";
    } else if (is_char) {
      std::cout << m_vm[it->first].as<const char *>() << " ";
    } else if (is_str) {
      std::string temp = m_vm[it->first].as<std::string>();
      if (temp.size()) {
        std::cout << temp << " ";
      } else {
        std::cout << "true"
                  << " ";
      }
    } else {  // Assumes that the only remainder is vector<string>
      try {
        std::vector<std::string> vect =
            m_vm[it->first].as<std::vector<std::string> >();
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
} /* base_cli::print() */

NS_END(rcppsw);
