/**
 * @file task_decomposition_graph-test.cpp
 *
 * @copyright 2017 John Harwell, All rights reserved.
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
#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_PREFIX_ALL
#include <catch.hpp>
#include "rcppsw/task_allocation/task_decomposition_graph.hpp"
#include "rcppsw/er/server.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace ta = rcppsw::task_allocation;
namespace er = rcppsw::er;

/*******************************************************************************
 * Test Functions
 ******************************************************************************/
CATCH_TEST_CASE("sanity-test", "[task_decomposition_graph]") {
  ta::task_decomposition_graph g(er::g_server);
}
