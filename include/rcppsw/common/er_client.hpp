/**
 * @file er_client.hpp
 *
 * Interface for classes that want to be able to use the ER Server.
 *
 * @copyright 2017 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_DBG_ER_CLIENT_HPP_
#define INCLUDE_RCPPSW_DBG_ER_CLIENT_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include <boost/uuid/uuid.hpp>
#include "rcppsw/common/er_server.hpp"

/*******************************************************************************
 * Macros
 ******************************************************************************/
/**
 * @brief Event reporting macros. Use of these macros requires the class you are
 * using it in derives from er_client. You cannot use these macros in a
 * non-class context.
 */
#ifndef NDEBUG
/* ---------- Explicit debug level statements (use these) ---------- */
#define ER_ERROR(...) ER_REPORT(er_lvl::ERROR, __VA_ARGS__)
#define ER_WARN(...) ER_REPORT(er_lvl::WARN, __VA_ARGS__)
#define ER_NOM(...) ER_REPORT(er_lvl::NOM, __VA_ARGS__)
#define ER_DIAG(...) ER_REPORT(er_lvl::DIAG, __VA_ARGS__)
#define ER_VER(...) ER_REPORT(er_lvl::VER, __VA_ARGS__)

/* -------- Debug statements with level parameter (Don't use these) -------- */
#define ER_REPORT(lvl, msg, ...)                                        \
  {                                                                     \
    char _str[1000];                                                    \
    snprintf(_str, sizeof(_str), "%s:%d:%s: " msg "\n", __FILE__, __LINE__, \
             __FUNCTION__, ##__VA_ARGS__);                              \
    rcppsw::er_client::server_handle()->report(rcppsw::er_client::er_id(), \
                                               lvl,                     \
                                               std::string(_str));      \
  }

#else
#define ER_REPORT(lvl, msg, ...)
#define ER_ERROR(...)
#define ER_WARN(...)
#define ER_NOM(...)
#define ER_DIAG(...)
#define ER_VER(...)
#endif /* NDEBUG */

/**
 * @brief Check a condition in a function. If condition is not true, go to the
 * error/bailout section for function (you must have a label called "error" in
 * your function).
 */
#define ER_CHECK(cond, msg, ...)                \
  {                                             \
    if (!(cond)) {                              \
      REPORT(er_lvl::ERR, msg, ##__VA_ARGS__); \
      goto error;                               \
    }                                           \
  }

/**
 * @brief Mark a place in the code as being universally bad. If execution ever
 * reaches this spot, report a message and error out.
 */
#define ER_SENTINEL(msg, ...)                   \
  {                                             \
    REPORT(er_lvl::ERR, msg, ##__VA_ARGS__);   \
    goto error;                                 \
  }

/**
 * @brief Check a condition in a function, halting the program if the condition
 * is not true. Like assert(), but allows for an additional custom message.
 */
#define ER_ASSERT(cond, msg, ...)                       \
  if (!(cond)) {                                        \
    ER_REPORT(er_lvl::ERR, msg, ##__VA_ARGS__);         \
    assert(0);                                          \
  }

/*
 * Define debug macros also in rcsw to eliminate dependencies.
 */
#ifndef CHECK
#define CHECK(cond)                             \
  {                                             \
    if (!(cond)) {                              \
      goto error;                               \
    }                                           \
  }
#endif /* CHECK */

#ifndef CHECK_PTR
#define CHECK_PTR(ptr)                          \
  if (nullptr == (ptr)) {                       \
    goto error;                                 \
  }
#endif /* CHECK_PTR */

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, common);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class er_client {
 public:
  explicit er_client(er_server* const server_handle)
      : server_handle_(server_handle), er_id_(server_handle_->idgen()) {}

  /**
   * @brief Add a module to the active list (long version).
   *
   * @param loglvl The initial logging level for the module.
   * @param dbglvl The initial debug printing level for the module.
   * @param mod_name The name of the module, which will be prepended to all
   * debugging/logging statements.
   * @return OK if successful, ERROR otherwise.
   */
  status_t insmod(const er_lvl::value& loglvl, const er_lvl::value& dbglvl,
                  const std::string& mod_name) {
    return server_handle_->insmod(er_id_, loglvl, dbglvl, mod_name); }

  /**
   * @brief Add a module to the active list (short version). The added module
   * will get the default values for initial logging/debugging levels, according
   * to the current defaults on the ER server.
   *
   * @param mod_name The name of the module, which will be predended to all
   * debugging/logging statements.
   *
   * @return OK if successful, ERROR otherwise.
   */
  status_t insmod(const std::string& mod_name) {
    return server_handle_->insmod(er_id_, mod_name); }

  /**
   * @brief Get a reference to the ER server.
   *
   * @return A reference to the server handle.
   */
  er_server * server_handle(void) { return server_handle_; }

  /**
   * @brief Get a reference to the UUID for the module. Should not be called
   * directly by the application (why would you even need this?).
   *
   * @return The UUID.
   */
  boost::uuids::uuid er_id(void) {return er_id_; }

  virtual ~er_client(void) {}

 private:
  er_server* const server_handle_;
  boost::uuids::uuid er_id_;
  er_client* operator=(const er_client&) = delete;
  er_client(const er_client& other) = delete;
};

NS_END(rcppsw, common);

#endif /* INCLUDE_RCPPSW_DBG_ER_CLIENT_HPP_ */
