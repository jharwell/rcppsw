/*******************************************************************************
 * Name            : er_frmwk-test.cpp
 * Project         : rcppsw
 * Module          : ERF
 * Description     : Test er_frmwk module
 * Creation Date   : Tue Dec 13 14:54:27 2016
 * Original Author : jharwell
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "er_frmwk.hpp"

/*******************************************************************************
 * Test Cases
 ******************************************************************************/
TEST_CASE("ERF Test","[ERF]") {
  rcppsw::er_frmwk erf_handle;
  boost::uuids::uuid erf_id = erf_handle.idgen();
  erf_handle.insmod(erf_id,"test_module");
  erf_handle.mod_dbglvl(erf_id,rcppsw::erf_lvl::nom);

  /* Test if you get anything */
  er_report(rcppsw::erf_lvl::err,"This is an error");
  er_report(rcppsw::erf_lvl::warn,"This is a warning");
  er_report(rcppsw::erf_lvl::nom,"This is nominal");
  er_report(rcppsw::erf_lvl::diag,"This is a diagnostic");
  er_report(rcppsw::erf_lvl::ver,"This is verbose");
}
