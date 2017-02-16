/*******************************************************************************
 * Name            : er_server_mod.hpp
 * Project         : rcppsw
 * Module          : erf
 * Description     : Header file for Event Reporting Server Module class
 * Creation Date   : 6/24/15
 * Copyright       : Copyright 2016 John Harwell, All rights reserved
 *
 ******************************************************************************/

#ifndef INCLUDE_RCPPSW_ER_SERVER_MOD_HPP_
#define INCLUDE_RCPPSW_ER_SERVER_MOD_HPP_

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
class er_lvl {
 public:
  enum value { OFF, ERR, WARN, NOM, DIAG, VER };
};

class er_server_mod {
 public:
  /* data members */
  boost::uuids::uuid id;
  std::string name;

  /* member functions */
  er_server_mod(const boost::uuids::uuid& id_, const er_lvl::value& loglvl_,
               const er_lvl::value& dbglvl_, const std::string& name_);
  er_server_mod(const boost::uuids::uuid& id_, const std::string& name);
  void set_loglvl(const er_lvl::value& lvl);
  void set_dbglvl(const er_lvl::value& lvl);
  void logmsg(const std::string& msg, const er_lvl::value& lvl,
              std::ofstream& file) const;
  void dbgmsg(const std::string& msg, const er_lvl::value& lvl) const;
  bool operator==(const er_server_mod& rhs);

 private:
  er_lvl::value loglvl;
  er_lvl::value dbglvl;
};

} /* namespace rcppsw */

/*******************************************************************************
 * Operator Definitions
 ******************************************************************************/
std::ostream& operator<<(std::ostream& os, const rcppsw::er_server_mod& mod);

#endif /* INCLUDE_RCPPSW_ER_SERVER_MOD_HPP_ */
