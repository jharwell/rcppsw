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
#include "rcppsw/er_frmwk.hpp"
#include "rcppsw/erf_client.hpp"

/*******************************************************************************
 * Test Classes
 ******************************************************************************/
class test_client: public rcppsw::erf_client {
 public:
  test_client(rcppsw::er_frmwk* handle) : erf_client(handle) {
    erf_handle()->insmod(erf_id(),"test_module");
    erf_handle()->mod_dbglvl(erf_id(),rcppsw::erf_lvl::NOM);

    /* Test if you get anything */
    ER_REPORT(rcppsw::erf_lvl::ERR,"This is an error");
    ER_REPORT(rcppsw::erf_lvl::WARN,"This is a warning");
    ER_REPORT(rcppsw::erf_lvl::NOM,"This is nominal");
    ER_REPORT(rcppsw::erf_lvl::DIAG,"This is a diagnostic");
    ER_REPORT(rcppsw::erf_lvl::VER,"This is verbose");
  }
};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/
TEST_CASE("ERF Test","[ERF]") {
  rcppsw::er_frmwk handle;
  handle.start(NULL);
  test_client client(&handle);
  sleep(1);
  handle.term();
  REQUIRE(1);
}
