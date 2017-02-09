/*******************************************************************************
 * Name            : erf_client.hpp
 * Project         : rcppsw
 * Module          : rcppsw
 * Description     : Interface for classes that want to be able to use the ERF
 * Creation Date   : Sat 04/9/16
 * Copyright       : Copyright 2016 John Harwell, All rights reserved
  *
 ******************************************************************************/

#ifndef INCLUDE_ERF_CLIENT_HPP_
#define INCLUDE_ERF_CLIENT_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
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
  erf_client(er_frmwk& erf_handle)
      : erf_handle_(erf_handle), erf_id_(erf_handle_.idgen()) {}

  /* destructor */
  virtual ~erf_client(void) {}

 protected:
  er_frmwk& erf_handle_;
  boost::uuids::uuid erf_id_;
};

} /* namespace rcppsw */

/*******************************************************************************
 * Operater Definitions
 ******************************************************************************/

#endif /* INCLUDE_ERF_CLIENT_HPP_ */
