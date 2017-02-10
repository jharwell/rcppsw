/*******************************************************************************
 * Name            : er_frmwk_mod.hpp
 * Project         : rcppsw
 * Module          : erf
 * Description     : Header file for Event Reporting Framework Module class
 * Creation Date   : 6/24/15
 * Copyright       : Copyright 2016 John Harwell, All rights reserved
 *
 ******************************************************************************/

#ifndef INCLUDE_RCPPSW_ER_FRMWK_MOD_HPP_
#define INCLUDE_RCPPSW_ER_FRMWK_MOD_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <iostream>
#include <string>
#include "rcsw/al/altypes.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace rcppsw {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class erf_lvl {
 public:
  enum value { OFF, ERR, WARN, NOM, DIAG, VER };
};

class er_frmwk_mod {
 public:
  /* data members */
  boost::uuids::uuid id;
  std::string name;

  /* member functions */
  er_frmwk_mod(const boost::uuids::uuid& id_, const erf_lvl::value& loglvl_,
               const erf_lvl::value& dbglvl_, const std::string& name_);
  er_frmwk_mod(const boost::uuids::uuid& id_, const std::string& name);
  void set_loglvl(const erf_lvl::value& lvl);
  void set_dbglvl(const erf_lvl::value& lvl);
  void logmsg(const std::string& msg, const erf_lvl::value& lvl,
              std::ofstream& file) const;
  void dbgmsg(const std::string& msg, const erf_lvl::value& lvl) const;
  bool operator==(const er_frmwk_mod& rhs);

 private:
  erf_lvl::value loglvl;
  erf_lvl::value dbglvl;
};

} /* namespace rcppsw */

/*******************************************************************************
 * Operator Definitions
 ******************************************************************************/
std::ostream& operator<<(std::ostream& os, const rcppsw::er_frmwk_mod& mod);

#endif /* INCLUDE_RCPPSW_ER_FRMWK_MOD_HPP_ */
