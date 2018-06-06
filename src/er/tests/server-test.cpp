/**
 * @file server-test.cpp
 *
 * @copyright 2018 John Harwell, All rights reserved.
 *
 * This file is part of RCPPSW.
 *
 * RCPPSW is free software: you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 *
 * RCPPSW is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 * A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * RCPPSW.  If not, see <http://www.gnu.org/licenses/
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#define CATCH_CONFIG_PREFIX_ALL
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "rcppsw/er/client.hpp"
#include "rcppsw/er/server.hpp"

/*******************************************************************************
 * Test Classes
 ******************************************************************************/
class test_client : public rcppsw::er::client {
 public:
  test_client(std::shared_ptr<rcppsw::er::server> handle)
      : client(handle) {
    server_handle()->insmod(er_id(), "test_module");
    server_handle()->mod_dbglvl(er_id(), rcppsw::er::er_lvl::NOM);

    /* Test if you get anything */
    ER_REPORT(rcppsw::er::er_lvl::ERR, "This is an error");
    ER_REPORT(rcppsw::er::er_lvl::WARN, "This is a warning");
    ER_REPORT(rcppsw::er::er_lvl::NOM, "This is nominal");
    ER_REPORT(rcppsw::er::er_lvl::DIAG, "This is a diagnostic");
    ER_REPORT(rcppsw::er::er_lvl::VER, "This is verbose");
  }
};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/
CATCH_TEST_CASE("ER Test", "[ER]") {
  rcppsw::er::server handle;
  test_client client(std::make_shared<rcppsw::er::server>());
  CATCH_REQUIRE(1);
}
