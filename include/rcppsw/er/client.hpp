/**
 * \file client.hpp
 *
 * Interface for classes that want to be able to use the ER Server.
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

#ifndef INCLUDE_RCPPSW_ER_CLIENT_HPP_
#define INCLUDE_RCPPSW_ER_CLIENT_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/er/er.hpp"

#if (RCPPSW_ER == RCPPSW_ER_ALL)
#include <string>
#include <memory>
#include <log4cxx/consoleappender.h>
#include <log4cxx/fileappender.h>
#include <log4cxx/logger.h>
#include <log4cxx/ndc.h>
#include <log4cxx/patternlayout.h>
#include <log4cxx/xml/domconfigurator.h>
#endif


#include "rcppsw/rcppsw.hpp"
#include "rcppsw/er/macros.hpp"

/*******************************************************************************
 * Macros
 ******************************************************************************/
#if (RCPPSW_ER == RCPPSW_ER_NONE)

#define ER_CLIENT_INIT(name) rer::client<typename std::remove_reference<decltype(*this)>::type>()
#define ER_LOGGING_INIT(fname)
#define ER_LOGFILE_SET(logger, fname)
#define ER_NDC_PUSH(s)
#define ER_NDC_POP(...)
#define ER_MDC_ADD(key, value)
#define ER_MDC_RM(key)
#define ER_ENV_VERIFY(...)

#elif (RCPPSW_ER == RCPPSW_ER_FATAL)

#define ER_CLIENT_INIT(name) rer::client<typename std::remove_reference<decltype(*this)>::type>()
#define ER_LOGGING_INIT(fname)
#define ER_LOGFILE_SET(logger, fname)
#define ER_NDC_PUSH(s)
#define ER_NDC_POP(...)
#define ER_MDC_ADD(key, value)
#define ER_MDC_RM(key)
#define ER_ENV_VERIFY(...)


#elif (RCPPSW_ER == RCPPSW_ER_ALL)

/**
 * \def ER_CLIENT_INIT(name)
 *
 * Initialize a logging client with the specified name (easier to do a macro
 * than to have to try do the casting every single time).
 */
#define ER_CLIENT_INIT(name) \
  rcppsw::er::client<typename std::remove_reference_t<decltype(*this)>>(name)

/**
 * \def ER_LOGGING_INIT(fname)
 *
 * Initialize logging by specifying the log4cxx configuration file.
 */
#define ER_LOGGING_INIT(fname) \
  rcppsw::er::client<          \
      typename std::remove_reference_t<decltype(*this)>>::logging_init(fname)

/**
 * \def ER_LOGFILE_SET(logger, fname)
 *
 * Set the logfile for the specified logger. Idempotent.
 */
#define ER_LOGFILE_SET(logger, fname)                                             \
  rcppsw::er::client<                                                             \
      typename std::remove_reference_t<decltype(*this)>>::logfile_set(logger, \
                                                                          fname)

/**
 * \def ER_NDC_PUSH(s)
 *
 * Push the specified NDC context (prepended to every message).
 */
#define ER_NDC_PUSH(s) \
  rcppsw::er::client<  \
      typename std::remove_reference_t<decltype(*this)>>::ndc_do_push(s)

/**
 * \def ER_NDC_POP()
 *
 * Pop the last pushed NDC context.
 */
#define ER_NDC_POP(...) \
  rcppsw::er::client<   \
      typename std::remove_reference_t<decltype(*this)>>::ndc_do_pop()

/**
 * \def ER_MDC_ADD(key, value)
 *
 * Add the specified mdc context (prepended to every message).
 */
#define ER_MDC_ADD(key, value)                  \
  rer::client<  \
                typename std::remove_reference_t<decltype(*this)>>::mdc_add(key, value)

/**
 * \def ER_MDC_RM(key)
 *
 * Remove the specified pushed NDC context.
 */
#define ER_MDC_RM(key) \
  rer::client<   \
      typename std::remove_reference_t<decltype(*this)>>::mdc_rm(key)

/**
 * \def ER_ENV_VERIFY()
 *
 * Verify the correct environment variables were set up for event reporting
 * before the application was launched.
 */
#define ER_ENV_VERIFY(...)                                              \
  rcppsw::er::client<                                                   \
                           typename std::remove_reference_t<decltype(*this)>>::env_verify()

#endif

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, er);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class client
 * \ingroup er
 *
 * \brief A class that can connect to a logging server for logging of important
 * events. Basically a thin wrapper around log4cxx. If ER_NDEBUG is defined,
 * then this class will mostly compile away to nothing, and most member
 * functions will not be defined.
 */
#if (RCPPSW_ER == RCPPSW_ER_ALL)
template <typename T>
class client {
 public:
  /**
   * \brief Initialize logging by specifying the path to the log4cxx
   * configuration file.
   */
  static void logging_init(const std::string& fpath) {
    /*
     * Multiple initializations will cause duplicate messages to show up in
     * logfiles.
     */
    if (!m_initialized) {
      log4cxx::xml::DOMConfigurator::configure(fpath);
      m_initialized = true;
    }
  }

  /**
   * \brief Set the log file for the specified logger. Idempotent. If the
   * logfile currently exists, it will be truncated.
   *
   * Logfile is an appender, which is given the same name as the logfile
   * itself.
   */
  static void logfile_set(const log4cxx::LoggerPtr& logger,
                          const std::string& name) {
    for (auto& a : logger->getAllAppenders()) {
      if (a->getName() == name) {
        return;
      }
    } /* for(&a..) */

    auto layout = std::make_shared<log4cxx::PatternLayout>(kFileLayout);
    auto appender = std::make_shared<log4cxx::FileAppender>(layout,
                                                            name,
                                                            false);
    appender->setName(name);
    logger->addAppender(appender);
  }

  /**
   * \brief Push a log4cxx NDC context.
   *
   * \param s The context.
   */
  static void ndc_do_push(const std::string& s) { log4cxx::NDC::push(s); }

  /**
   * \brief Pop the top of the log4cxx NDC stack.
   */
  static void ndc_do_pop(void) { log4cxx::NDC::pop(); }

  /**
   * \brief Add a log4cxx MDC context.
   *
   * \param key The context key.
   *
   * \param value The context.
   */
  static void mdc_add(const std::string& key,
                       const std::string& value) {
    log4cxx::MDC::put(key, value);
  }

  /**
   * \brief Remove a log4cxx MDC context.
   */
  static void mdc_rm(const std::string& key) {
    log4cxx::MDC::remove(key);
  }

  /**
   * \param name Name of client/new logger.
   */
  explicit client(const std::string& name)
      : m_logger(log4cxx::Logger::getLogger(name)) {
    /*
     * DON'T add the appender here--results in multiple copies of some messages
     * for reasons I can't understand. Doing it in the config file works though.
     */
    /* if (0 == m_logger->getAllAppenders().size()) { */
    /*   auto layout = std::make_shared<log4cxx::PatternLayout>(kConsoleLayout); */
    /*   auto appender = std::make_shared<log4cxx::ConsoleAppender>(layout); */
    /*   appender->setName(name); */
    /*   logger()->addAppender(appender); */
    /* } */
  }

  virtual ~client(void) = default;

  client(const client&) = default;
  client& operator=(const client&) = default;

  /**
   * \brief Set the logfile of the logger with the specified name. Not
   * idempotent.
   *
   * This is not done during construction because you often want to direct
   * entire namespaces of loggers to a single output file (e.g.,
   * rcppsw.patterns).
   */
  void logfile_set(const std::string& name) {
    auto layout = std::make_shared<log4cxx::PatternLayout>(kFileLayout);
    auto appender = std::make_shared<log4cxx::FileAppender>(layout, name);
    logger()->addAppender(appender);
  }

  /**
   * \brief Get current logger name.
   */
  std::string logger_name(void) const {
    std::string name;
    m_logger->getName(name);
    return name;
  }

  /**
   * \brief Get a reference to the ER logger.
   */
  log4cxx::LoggerPtr logger(void) const { return m_logger; }

  /**
   * \brief Verify that the execution environment was properly set up for
   * logging, and abort the program if it was not.
   */
  void env_verify(void) {
    if (const char* env_p = std::getenv("LOG4CXX_CONFIGURATION")) {
      ER_LOGGING_INIT(std::string(env_p));
    } else {
      std::cerr << "LOG4CXX_CONFIGURATION not defined" << std::endl;
      std::exit(EXIT_FAILURE);
    }
  }


 private:
  /* clang-format off */
  static inline const std::string kConsoleLayout = "%X{time} %x %Y[%-5p]%y %c - %m%n";
  static inline const std::string kFileLayout = "%X{time} %x %Y[%-5p]%y %c %l - %m%n";

  static inline bool       m_initialized{false};

  log4cxx::LoggerPtr       m_logger{};
  /* clang-format on */
};

#else
template<typename T>
class client {
 public:
  virtual ~client(void) = default;
};
#endif

NS_END(rcppsw, er);

#endif /* INCLUDE_RCPPSW_ER_CLIENT_HPP_ */
