/**
 * @file tdgraph-test.cpp
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
#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_PREFIX_ALL
#include "rcppsw/task_allocation/polled_task.hpp"
#include "rcppsw/task_allocation/tdgraph.hpp"
#include "rcppsw/task_allocation/task_params.hpp"
#include <catch.hpp>

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace ta = rcppsw::task_allocation;
namespace er = rcppsw::er;

/*******************************************************************************
 * Test Classes
 ******************************************************************************/
class test_task : public ta::polled_task {
 public:
  test_task(const std::string &name, const struct ta::task_params *c_params)
      : polled_task(name, c_params, nullptr) {}

  double calc_abort_prob(void) override { return 0.0; }
  double calc_interface_time(double start_time) override { return 0.0; }
  double current_time(void) const override { return 0.0; }
  void task_execute(void) override {}
  void task_start(const ta::taskable_argument*) override {}
};

/*******************************************************************************
 * Test Functions
 ******************************************************************************/
CATCH_TEST_CASE("sanity-test", "[tdgraph]") {
  ta::tdgraph g;
}
CATCH_TEST_CASE("build-test", "[tdgraph]") {
  ta::tdgraph g;
  ta::task_params params;
  CATCH_REQUIRE(OK == g.set_root(new test_task("root_task", &params)));
  CATCH_REQUIRE(g.root()->name() == "root_task");

  auto subtask1 = new test_task("subtask1", &params);
  auto subtask2 = new test_task("subtask2", &params);
  auto subtask3 = new test_task("subtask3", &params);
  auto subtask4 = new test_task("subtask4", &params);
  CATCH_REQUIRE(OK ==
                g.set_children("root_task", std::vector<ta::polled_task*>(
                                                {subtask1, subtask2})));
  CATCH_REQUIRE(OK ==
                g.set_children("subtask1", std::vector<ta::polled_task*>(
                                               {subtask3, subtask4})));
  CATCH_REQUIRE(g.root()->name() == "root_task");
  CATCH_REQUIRE(ta::tdgraph::vertex_parent(g, subtask1)->name() ==
                "root_task");
  CATCH_REQUIRE(ta::tdgraph::vertex_parent(g, subtask2)->name() ==
                "root_task");
  CATCH_REQUIRE(ta::tdgraph::vertex_parent(g, subtask3)->name() ==
                "subtask1");
  CATCH_REQUIRE(ta::tdgraph::vertex_parent(g, subtask4)->name() ==
                "subtask1");
}
