/**
 * \file client.hpp
 *
 * Interface for classes that want to be able to use the ER Server.
 *
 * \copyright 2017 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <typeindex>

#include "rcppsw/er/er.hpp"
#include "rcppsw/er/plugin/plugin.hpp"
#include "rcppsw/er/macros.hpp"
#include "rcppsw/abi/abi.hpp"

/*******************************************************************************
 * Macros
 ******************************************************************************/
#if (RCPPSW_ERL == RCPPSW_ERL_NONE)

#define ER_CLIENT_INIT(name) rer::client<typename std::remove_reference<decltype(*this)>::type>()
#define ER_LOGGING_INIT(fname)
#define ER_LOGFILE_SET(logger, fname)
#define ER_NDC_PUSH(s)
#define ER_NDC_POP(...)
#define ER_MDC_ADD(key, value)
#define ER_MDC_RM(key)
#define ER_ENV_VERIFY(...)

#elif (RCPPSW_ERL == RCPPSW_ERL_FATAL)

#define ER_CLIENT_INIT(name) rer::client<typename std::remove_reference<decltype(*this)>::type>()
#define ER_LOGGING_INIT(fname)
#define ER_LOGFILE_SET(logger, fname)
#define ER_NDC_PUSH(s)
#define ER_NDC_POP(...)
#define ER_MDC_ADD(key, value)
#define ER_MDC_RM(key)
#define ER_ENV_VERIFY(...)


#elif (RCPPSW_ERL == RCPPSW_ERL_ALL)

/**
 * \def ER_CLIENT_INIT(name)
 *
 * Initialize a logging client with the specified name (easier to do a macro
 * than to have to try do the casting every single time).
 */
#define ER_CLIENT_INIT()                                                \
  rcppsw::er::client<                                                   \
                     typename std::remove_reference_t<decltype(*this)>  \
                     >                                                  \
  (rcppsw::abi::demangle(std::type_index(typeid(*this)).name()))

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
      typename std::remove_reference_t<decltype(*this)>>::ndc_push(s)

/**
 * \def ER_NDC_POP()
 *
 * Pop the last pushed NDC context.
 */
#define ER_NDC_POP(...) \
  rcppsw::er::client<   \
      typename std::remove_reference_t<decltype(*this)>>::ndc_pop()

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
namespace rcppsw::er {

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
#if (RCPPSW_ERL == RCPPSW_ERL_ALL)
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
#if defined(RCPPSW_ER_OLD_LOG4CXX)
    log4cxx::LayoutPtr layout = new log4cxx::PatternLayout(kFileLayout);
        log4cxx::AppenderPtr appender =
            new log4cxx::FileAppender(layout, name, false);
        appender->setName(name);
        logger->addAppender(appender);
#else
    auto layout = std::make_shared<log4cxx::PatternLayout>(kFileLayout);
    auto appender = std::make_shared<log4cxx::FileAppender>(layout,
                                                            name,
                                                            false);
    appender->setName(name);
    logger->addAppender(appender);
#endif
  }

  /**
   * \brief Push a log4cxx NDC context.
   *
   * \param s The context.
   */
  static void ndc_push(const std::string& s) { log4cxx::NDC::push(s); }

  /**
   * \brief Pop the top of the log4cxx NDC stack.
   */
  static void ndc_pop(void) { log4cxx::NDC::pop(); }

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
   * \param abiname The demangled ABI name of the client class.
   */
  explicit client(const char* abiname)
      : m_logger(log4cxx::Logger::getLogger(abi_name_to_logger_name(abiname))) {
    /*
     * DON'T add the appender here--results in multiple copies of some messages
     * for reasons I can't understand. Doing it in the config file works though.
     */
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
#if defined(RCPPSW_ER_OLD_LOG4CXX)
    log4cxx::LayoutPtr layout = new log4cxx::PatternLayout(kFileLayout);
    log4cxx::AppenderPtr appender = new log4cxx::FileAppender(layout, name);
#else
    auto layout = std::make_shared<log4cxx::PatternLayout>(kFileLayout);
    auto appender = std::make_shared<log4cxx::FileAppender>(layout, name);
#endif
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
  /**
   * \brief Convert the demangled ABI name for a class to the log4cxx fully
   * qualified path for the class.
   *
   * - Convert all \code :: \endcode -> \c .
   *
   * - Remove all templated types from the name: \code <...> \endcode -> ''.
   */
  static std::string abi_name_to_logger_name(const char* name) {
    std::string tmp = name;
    auto index1 = tmp.find("::");

    /* replace all occurences of '::' with '.' */
    while (index1 != tmp.npos) {
      tmp = tmp.replace(index1, 2, ".");
      index1 = tmp.find("::");
    } /* while() */

    /* remove all <..> in the typeid */
    index1 = tmp.find("<");
    while (index1 != tmp.npos) {
      auto index2 = tmp.find(">");
      tmp = tmp.erase(index1, index2 - index1 + 1);
      index1 = tmp.find("<");
    } /* while() */
    return tmp;
  }
  /* clang-format off */
  static inline const std::string kConsoleLayout = "%X{time} %x [%-5p] %c - %m%n";
  static inline const std::string kFileLayout = "%X{time} %x [%-5p] %c %l - %m%n";

  static inline bool       m_initialized{false};

  log4cxx::LoggerPtr       m_logger{};
  /* clang-format on */
};

#else
template<typename T>
class client {
 public:
  client(void) = default;

  /* So that client objects can be constructed outside of class contexts */
  explicit client(const std::string& ) {}
  virtual ~client(void) = default;
};
#endif

} /* namespace rcppsw::er */