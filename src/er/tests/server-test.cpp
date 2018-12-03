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
#include <log4cxx/basicconfigurator.h>

/*******************************************************************************
 * Test Classes
 ******************************************************************************/
class test_client : public rcppsw::er::client<test_client> {
 public:
  explicit test_client(const std::string &er_parent)
      : ER_CLIENT_INIT(er_parent) {
    /* Test if you get anything */
    ER_FATAL("This is fatal");
    ER_ERR("This is an error");
    ER_WARN("This is a warning");
    ER_INFO("This is nominal");
    ER_DEBUG("This is a diagnostic");
    ER_TRACE("This is verbose");
  }
};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/
CATCH_TEST_CASE("ER Test", "[ER]") {
  test_client client("foobar");
  client.set_logfile("mine.log");
  test_client client2("foobar.test_client");
  CATCH_REQUIRE(1);
}
