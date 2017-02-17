/*******************************************************************************
 * Name            : er_server.hpp
 * Project         : rcppsw
 * Module          : erf
 * Description     : Header file for Event Reporting Server
 * Creation Date   : 06/24/15
 * Copyright       : Copyright 2015 John Harwell, All rights reserved
 *
 ******************************************************************************/

#ifndef INCLUDE_RCPPSW_ER_SERVER_HPP_
#define INCLUDE_RCPPSW_ER_SERVER_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <fstream>
#include <mutex>
#include <string>
#include <thread>
#include <vector>
#include "rcsw/al/altypes.h"
#include "rcppsw/er_server_mod.hpp"
#include "rcppsw/multithread/mt_queue.hpp"
#include "rcppsw/multithread/threadable.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace rcppsw {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class er_server : public threadable {
 public:
  struct erf_msg {
    explicit erf_msg(const boost::uuids::uuid& id, const er_lvl::value& lvl,
                     const std::string& str)
        : id_(id), lvl_(lvl), str_(str) {}
    boost::uuids::uuid id_;
    er_lvl::value lvl_;
    std::string str_;
  };

  /* constructors */
  er_server(const std::string& logfile_fname_ = "logfile",
            const er_lvl::value& dbglvl_ = er_lvl::NOM,
            const er_lvl::value& loglvl_ = er_lvl::NOM);

  /* destructor */
  ~er_server(void) { logfile_.close(); }

  /* member functions */
  void self_dbg_en(void) {
    insmod(erf_id_, "ERF");
    mod_dbglvl(erf_id_, er_lvl::NOM);
  }
  status_t insmod(const boost::uuids::uuid& mod_id,
                  const er_lvl::value& loglvl, const er_lvl::value& dbglvl,
                  const std::string& mod_name);
  status_t insmod(const boost::uuids::uuid& id, const std::string& name);
  status_t rmmod(const boost::uuids::uuid& id);
  status_t mod_dbglvl(const boost::uuids::uuid& id, const er_lvl::value& lvl);
  status_t mod_loglvl(const boost::uuids::uuid& id, const er_lvl::value& lvl);
  int flush(void);
  boost::uuids::uuid idgen(void) { return gen_(); }
  void* thread_main(void* arg);
  er_lvl::value loglvl(void) { return loglvl_dflt_; }
  er_lvl::value dbglvl(void) { return dbglvl_dflt_; }
  void loglvl(const er_lvl::value& lvl) { loglvl_dflt_ = lvl; }
  void dbglvl(const er_lvl::value& lvl) { dbglvl_dflt_ = lvl; }
  void msg_report(const erf_msg& msg);
  char* hostname(void) { return hostname_; }

  void report(const boost::uuids::uuid& erf_id, const er_lvl::value& lvl,
              const std::string& str) {
    erf_msg msg(erf_id, lvl, str);
    msg_report(msg);
    /* queue_.enqueue(msg); */
  }

 private:
  /* data members */
  char hostname_[32];
  std::vector<er_server_mod> modules_;
  mt_queue<erf_msg> queue_;
  std::string logfile_fname_;
  std::ofstream logfile_;
  er_lvl::value loglvl_dflt_;
  er_lvl::value dbglvl_dflt_;
  boost::uuids::random_generator gen_;
  boost::uuids::uuid erf_id_;
};

} /* namespace rcppsw */

#endif /* INCLUDE_RCPPSW_ER_SERVER_HPP_ */
