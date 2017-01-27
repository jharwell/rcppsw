/*******************************************************************************
 * Name            : er_frmwk.hpp
 * Project         : rcppsw
 * Module          : erf
 * Description     : Header file for Event Reporting Framework (ERF) base class
 * Creation Date   : Wed Jun 24 14:42:12 2015
 * Original Author : jharwell
 *
 ******************************************************************************/

#ifndef ER_FRMWK_HPP
#define ER_FRMWK_HPP

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <fstream>
#include <thread>
#include <mutex>

#include "include/al/altypes.h"
#include "include/er_frmwk_mod.hpp"
#include "include/shared_queue.hpp"
#include "include/threadable.hpp"

/*******************************************************************************
 * Macros
 ******************************************************************************/
/*
 * Reporting events. This needs to be a macro, instead of a function call so
 * I can get the line # and function from the preprocessor/compiler.
 *
 * This macro requires that:
 *
 * (1) You have a variable called erf_handle defined in the current scope that
 *     is of type rcppsw::er_rfmwk
 * (2) You have a variable called erf_id defined in the current scope that is of
 *     type boost::uuids::uuid for the module you want to report for.
 *
 */
#define ER_REPORT(lvl,msg, ...) {                                       \
    char _str[1000];                                                    \
    sprintf(_str,"%s:%d:%s: " msg "\n",__FILE__,__LINE__,__FUNCTION__,  \
            ##__VA_ARGS__);                                             \
    erf_handle.report(erf_id,lvl,std::string(_str));                    \
  }


/*
 * Like report, but only reports errors and goes to the error/bailout section
 * of a function only if a condition is false.
 */
#define ER_CHECK(cond,msg,...) {                \
    if(!(cond)) {                               \
      REPORT(erf_lvl::err,msg,##__VA_ARGS__);   \
      goto error;                               \
    }                                           \
  }
#define ER_SENTINEL(msg,...) {                  \
    REPORT(erf_lvl::err,msg,##__VA_ARGS__);     \
    goto error;                                 \
  }

#define ER_ASSERT(cond,msg,...)  if(!(cond)) {          \
    ER_REPORT(erf_lvl::err, msg, ##__VA_ARGS__);        \
    assert(0);                                          \
  }

#define CHECK(cond) {                           \
    if(!(cond)) {                               \
      goto error;                               \
    }                                           \
  }

#define CHECK_PTR(ptr) if (nullptr == (ptr)) { goto error; }

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace rcppsw {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class er_frmwk : public threadable
{
 public:

  struct erf_msg {
    explicit erf_msg(
        const boost::uuids::uuid& id,
        const erf_lvl::value& lvl,
        const std::string& str) :
        id_(id),
        lvl_(lvl),
        str_(str) {}
    boost::uuids::uuid id_;
    erf_lvl::value lvl_;
    std::string str_;
  };

  /* constructors */
  er_frmwk(
      const std::string& logfile_fname_="logfile",
      const erf_lvl::value& dbglvl_= erf_lvl::nom,
      const erf_lvl::value& loglvl_= erf_lvl::nom);

  /* destructor */
  ~er_frmwk(void);

  /* member functions */
  void self_dbg_en(void) {
    insmod(erf_id_,"ERF");
    mod_dbglvl(erf_id_,erf_lvl::nom);
  }
  status_t insmod(
      const boost::uuids::uuid& mod_id,
      const erf_lvl::value& loglvl,
      const erf_lvl::value& dbglvl,
      const std::string& mod_name);
  status_t insmod(
      const boost::uuids::uuid& id,
      const std::string& name);
  status_t rmmod(
      const boost::uuids::uuid& id);
  status_t mod_dbglvl(
      const boost::uuids::uuid& id,
      const erf_lvl::value& lvl);
  status_t mod_loglvl(
      const boost::uuids::uuid& id,
      const erf_lvl::value& lvl);
  int flush(void);
  status_t recv(
      const boost::uuids::uuid& id,
      const erf_lvl::value& lvl,
      const std::string& str);
  boost::uuids::uuid idgen(void) { return gen_(); }
  void thread_main(void);
  erf_lvl::value loglvl(void) { return loglvl_dflt_; }
  erf_lvl::value dbglvl(void) { return dbglvl_dflt_; }
  void loglvl(
      const erf_lvl::value& lvl) { loglvl_dflt_ = lvl; }
  void dbglvl(
      const erf_lvl::value& lvl) { dbglvl_dflt_ = lvl; }
  void msg_report(
      const erf_msg& msg);
  char* hostname(void) { return hostname_; }

  void report(
      const boost::uuids::uuid& erf_id,
      const erf_lvl::value& lvl,
      const std::string& str) {
    erf_msg msg(erf_id,lvl,str);
    msg_report(msg);
  }

 private:
  /* data members */
  char hostname_[32];
  std::vector<er_frmwk_mod> modules_;
  shared_queue<erf_msg> queue_;
  std::string logfile_fname_;
  std::ofstream logfile_;
  erf_lvl::value loglvl_dflt_;
  erf_lvl::value dbglvl_dflt_;
  boost::uuids::random_generator gen_;
  boost::uuids::uuid erf_id_;
};

} /* namespace rcppsw */

#endif /* ER_FRMWK_HPP */
