/*******************************************************************************
 * Name            : er_client.hpp
 * Project         : rcppsw
 * Module          : rcppsw
 * Description     : Interace for classes that want to be able to use the ER
 * Creation Date   : Sat 04/9/16
 * Copyright       : Copyright 2016 John Harwell, All rights reserved
  *
 ******************************************************************************/

#ifndef INCLUDE_RCPPSW_ER_CLIENT_HPP_
#define INCLUDE_RCPPSW_ER_CLIENT_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include <boost/uuid/uuid.hpp>
#include "rcppsw/er_server.hpp"

/*******************************************************************************
 * Macros
 ******************************************************************************/
/*
 * Reporting events. This needs to be a macro, instead of a function call so
 * I can get the line # and function from the preprocessor/compiler.
 *
 * This macro requires that the class you are using it in derives from
 * erf_client.
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

/*
 * Like report, but only reports errors and goes to the error/bailout section
 * of a function only if a condition is false.
 */
#define ER_CHECK(cond, msg, ...)                \
  {                                             \
    if (!(cond)) {                              \
      REPORT(er_lvl::ERR, msg, ##__VA_ARGS__); \
      goto error;                               \
    }                                           \
  }
#define ER_SENTINEL(msg, ...)                   \
  {                                             \
    REPORT(er_lvl::ERR, msg, ##__VA_ARGS__);   \
    goto error;                                 \
  }

#define ER_ASSERT(cond, msg, ...)                       \
  if (!(cond)) {                                        \
    ER_REPORT(er_lvl::ERR, msg, ##__VA_ARGS__);        \
    assert(0);                                          \
  }

#define CHECK(cond)                             \
  {                                             \
    if (!(cond)) {                              \
      goto error;                               \
    }                                           \
  }

#define CHECK_PTR(ptr)                          \
  if (nullptr == (ptr)) {                       \
    goto error;                                 \
  }

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace rcppsw {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class er_client {
 public:
  /* constructors */
  explicit er_client(er_server* const server_handle)
      : server_handle_(server_handle), er_id_(server_handle_->idgen()) {}

  status_t insmod(const er_lvl::value& loglvl, const er_lvl::value& dbglvl,
                  const std::string& mod_name) {
    return server_handle_->insmod(er_id_, loglvl, dbglvl, mod_name); }
  status_t insmod(const std::string& mod_name) {
    return server_handle_->insmod(er_id_, mod_name); }
  er_server * server_handle(void) { return server_handle_; }
  boost::uuids::uuid er_id(void) {return er_id_; }

  /* destructor */
  virtual ~er_client(void) {}

 private:
  er_server* const server_handle_;
  boost::uuids::uuid er_id_;
  er_client* operator=(const er_client&) = delete;
  er_client(const er_client& other) = delete;
};

} /* namespace rcppsw */

/*******************************************************************************
 * Operater Definitions
 ******************************************************************************/

#endif /* INCLUDE_RCPPSW_ER_CLIENT_HPP_ */
