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
#include "rcppsw/common/er_server_mod.hpp"

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
    snprintf(static_cast<char*>(_str), sizeof(_str), "%s:%d:%s: " msg "\n", __FILE__, __LINE__, \
             __FUNCTION__, ##__VA_ARGS__);                              \
    __er_report__(rcppsw::common::er_client::server_handle(),          \
                   rcppsw::common::er_client::er_id(),                  \
                   lvl,                                                 \
                   std::string(_str));                                  \
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
    ER_REPORT(rcppsw::common::er_lvl::ERR, msg, ##__VA_ARGS__);    \
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
 * Class Decls
 ******************************************************************************/
namespace rcppsw { namespace common { class er_server; class global_server;} }

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, common);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class er_client {
 public:
  er_client(void);
  explicit er_client(const std::shared_ptr<er_server>& server_handle);
  virtual ~er_client(void);

  /**
   * @brief Initialize the er_client in cases where it was not possible to due
   * so in the initialization list in the class constructor. If the default
   * constructor for er_client is used, things will segfault/go badly if any
   * debugging statements are encountered in the client before this function is
   * called.
   *
   * @param server_handle The er_server to attach to.
   */
  void deferred_init(const std::shared_ptr<er_server>& server_handle);
  void change_id(boost::uuids::uuid old_id, boost::uuids::uuid new_id);

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
                  const er_lvl::value& dbglvl = er_lvl::NOM);
  /**
   * @brief Uninstall the module for this client. This function is called
   * automatically in the destructor, but can be called explicitly as well.
   *
   * @return OK if the remove was successful, ERROR otherwise.
   */
  status_t rmmod(void);

  /**
   * @brief Attach to an EXISTING module within the server by name. If the
   * module exists, the UUID for this client is set to the UUID of the
   * module. If no module with the given name exists, no action is performed.
   *
   * @param mod_name Name of the module to attach to.
   *
   * @return OK if a module was attached to, ERROR otherwise.
   */
  status_t attmod(const std::string& mod_name);

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

 private:
  std::shared_ptr<er_server> m_server_handle;
  boost::uuids::uuid m_er_id;
};


/*******************************************************************************
 * Global Variables
 ******************************************************************************/
/**
 * @brief A common, global server that all applications utilizing rcppsw have
 * access to. Handy in cases where you don't want to pass the server handle down
 * through unrelated constructors until you get to the class you actually want
 * to enable debug printing/logging for.
 */
extern std::shared_ptr<global_server> g_server;

/*******************************************************************************
 * Forward Declarations
 ******************************************************************************/
void __er_report__(er_server* server,
                   const boost::uuids::uuid& er_id, const er_lvl::value& lvl,
                   const std::string& str);
NS_END(rcppsw, common);


#endif /* INCLUDE_RCPPSW_COMMON_ER_CLIENT_HPP_ */
