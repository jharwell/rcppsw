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

#ifndef INCLUDE_RCPPSW_COMMON_ER_CLIENT_HPP_
#define INCLUDE_RCPPSW_COMMON_ER_CLIENT_HPP_

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
#define ER_ERR(...) ER_REPORT(rcppsw::common::er_lvl::ERROR, __VA_ARGS__)
#define ER_WARN(...) ER_REPORT(rcppsw::common::er_lvl::WARN, __VA_ARGS__)
#define ER_NOM(...) ER_REPORT(rcppsw::common::er_lvl::NOM, __VA_ARGS__)
#define ER_DIAG(...) ER_REPORT(rcppsw::common::er_lvl::DIAG, __VA_ARGS__)
#define ER_VER(...) ER_REPORT(rcppsw::common::er_lvl::VER, __VA_ARGS__)

/* -------- Debug statements with level parameter (Don't use these) -------- */
#define ER_REPORT(lvl, msg, ...)                                        \
  {                                                                     \
    char _str[1000];                                                    \
    snprintf((char*)_str, sizeof(_str), "%s:%d:%s: " msg "\n", __FILE__, __LINE__, \
             __FUNCTION__, ##__VA_ARGS__);                              \
    rcppsw::common::er_client::server_handle()->report(rcppsw::common::er_client::er_id(), \
                                               lvl,                     \
                                               std::string(_str));      \
  }

#else
#define ER_REPORT(lvl, msg, ...)
#define ER_ERR(...)
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
      REPORT(rcppsw::common::er_lvl::ERR, msg, ##__VA_ARGS__); \
      goto error;                               \
    }                                           \
  }

/**
 * @brief Mark a place in the code as being universally bad. If execution ever
 * reaches this spot, report a message and error out.
 */
#define ER_SENTINEL(msg, ...)                   \
  {                                             \
    REPORT(rcppsw::common::er_lvl::ERR, msg, ##__VA_ARGS__);   \
    goto error;                                 \
  }

/**
 * @brief Check a condition in a function, halting the program if the condition
 * is not true. Like assert(), but allows for an additional custom message.
 */
#define ER_ASSERT(cond, msg, ...)                       \
  if (!(cond)) {                                        \
    ER_REPORT(rcppsw::common::er_lvl::ERR, msg, ##__VA_ARGS__);         \
    assert(cond);                                                       \
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
  er_client(void) : m_server_handle(), m_er_id() {}
  explicit er_client(std::shared_ptr<er_server> server_handle)
      : m_server_handle(server_handle), m_er_id(m_server_handle->idgen()) {}

  void deferred_init(std::shared_ptr<er_server> server_handle) {
    m_server_handle = server_handle;
    m_er_id = m_server_handle->idgen();
  }
  void change_id(boost::uuids::uuid old_id, boost::uuids::uuid new_id) {
    m_server_handle->change_id(old_id, new_id);
  }

  /**
   * @brief Add a module to the active list (long version).
   *
   * @param loglvl The initial logging level for the module.
   * @param dbglvl The initial debug printing level for the module.
   * @param mod_name The name of the module, which will be prepended to all
   * debugging/logging statements.
   * @return OK if successful, ERROR otherwise.
   */
  status_t insmod(const std::string& mod_name,
                  const er_lvl::value& loglvl = er_lvl::NOM,
                  const er_lvl::value& dbglvl = er_lvl::NOM) {
    return m_server_handle->insmod(m_er_id, loglvl, dbglvl, mod_name); }

  /**
   * @brief Get a reference to the ER server.
   *
   * @return A reference to the server handle.
   */
  er_server* server_handle(void) const { return m_server_handle.get(); }

 protected:
  const std::shared_ptr<er_server>& server_ref(void) const { return m_server_handle; }

  /**
   * @brief Get a reference to the UUID for the module. Should not be called
   * directly by the application (why would you even need this?).
   *
   * @return The UUID.
   */
  boost::uuids::uuid er_id(void) const { return m_er_id; }

  virtual ~er_client(void) {}

 private:
  std::shared_ptr<er_server> m_server_handle;
  boost::uuids::uuid m_er_id;
};

NS_END(rcppsw, common);

#endif /* INCLUDE_RCPPSW_COMMON_ER_CLIENT_HPP_ */
