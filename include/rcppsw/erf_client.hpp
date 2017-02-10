/*******************************************************************************
 * Name            : erf_client.hpp
 * Project         : rcppsw
 * Module          : rcppsw
 * Description     : Interface for classes that want to be able to use the ERF
 * Creation Date   : Sat 04/9/16
 * Copyright       : Copyright 2016 John Harwell, All rights reserved
  *
 ******************************************************************************/

#ifndef INCLUDE_RCPPSW_ERF_CLIENT_HPP_
#define INCLUDE_RCPPSW_ERF_CLIENT_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include <boost/uuid/uuid.hpp>
#include "rcppsw/er_frmwk.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace rcppsw {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class erf_client {
 public:
  /* constructors */
  explicit erf_client(er_frmwk* const erf_handle)
      : erf_handle_(erf_handle), erf_id_(erf_handle_->idgen()) {}

  status_t insmod(const erf_lvl::value& loglvl, const erf_lvl::value& dbglvl,
                  const std::string& mod_name) {
    return erf_handle_->insmod(erf_id_, loglvl, dbglvl, mod_name); }
  status_t insmod(const std::string& mod_name) {
    return erf_handle_->insmod(erf_id_, mod_name); }
  er_frmwk * erf_handle(void) { return erf_handle_; }
  boost::uuids::uuid erf_id(void) {return erf_id_; }
  /* destructor */
  virtual ~erf_client(void) {}

 private:
  er_frmwk* const erf_handle_;
  boost::uuids::uuid erf_id_;
  erf_client* operator=(const erf_client&) = delete;
  erf_client(const erf_client& other) = delete;
};

} /* namespace rcppsw */

/*******************************************************************************
 * Operater Definitions
 ******************************************************************************/

#endif /* INCLUDE_RCPPSW_ERF_CLIENT_HPP_ */
