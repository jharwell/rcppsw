/*******************************************************************************
 * Name            : er_server-test.cpp
 * Project         : rcppsw
 * Module          : ERF
 * Description     : Test er_server module
 * Creation Date   : Tue Dec 13 14:54:27 2016
 * Original Author : jharwell
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "rcppsw/er_server.hpp"
#include "rcppsw/er_client.hpp"

/*******************************************************************************
 * Test Classes
 ******************************************************************************/
class test_client: public rcppsw::er_client {
 public:
  test_client(rcppsw::er_server* handle) : er_client(handle) {
    er_handle()->insmod(er_id(),"test_module");
    er_handle()->mod_dbglvl(er_id(),rcppsw::er_lvl::NOM);

    /* Test if you get anything */
    ER_REPORT(rcppsw::er_lvl::ERR,"This is an error");
    ER_REPORT(rcppsw::er_lvl::WARN,"This is a warning");
    ER_REPORT(rcppsw::er_lvl::NOM,"This is nominal");
    ER_REPORT(rcppsw::er_lvl::DIAG,"This is a diagnostic");
    ER_REPORT(rcppsw::er_lvl::VER,"This is verbose");
  }
};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/
TEST_CASE("ER Test","[ER]") {
  rcppsw::er_server handle;
  handle.start(NULL);
  test_client client(&handle);
  sleep(1);
  handle.term();
  REQUIRE(1);
}
