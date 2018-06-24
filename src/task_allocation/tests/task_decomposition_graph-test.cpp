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
#include "rcppsw/er/server.hpp"
#include "rcppsw/task_allocation/executable_task.hpp"
#include "rcppsw/task_allocation/task_decomposition_graph.hpp"
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
class test_task : public ta::executable_task {
public:
  test_task(const std::string &name, const struct ta::task_params *c_params)
      : executable_task(name, c_params) {}

  double calc_abort_prob(void) override { return 0.0; }
  double calc_interface_time(double start_time) override { return 0.0; }
  double current_time(void) const override { return 0.0; }
  void task_execute(void) override {}
};

/*******************************************************************************
 * Test Functions
 ******************************************************************************/
CATCH_TEST_CASE("sanity-test", "[task_decomposition_graph]") {
  ta::task_decomposition_graph g(er::g_server);
}
CATCH_TEST_CASE("build-test", "[task_decomposition_graph]") {
  ta::task_decomposition_graph g(er::g_server);
  ta::task_params params;
  CATCH_REQUIRE(OK == g.set_root(ta::make_task_graph_vertex<test_task>(
                          "root_task", &params)));
  CATCH_REQUIRE(g.root()->name() == "root_task");

  auto subtask1 = ta::make_task_graph_vertex<test_task>("subtask1", &params);
  auto subtask2 = ta::make_task_graph_vertex<test_task>("subtask2", &params);
  auto subtask3 = ta::make_task_graph_vertex<test_task>("subtask3", &params);
  auto subtask4 = ta::make_task_graph_vertex<test_task>("subtask4", &params);
  CATCH_REQUIRE(OK ==
                g.set_children("root_task", std::list<ta::task_graph_vertex>(
                                                {subtask1, subtask2})));
  CATCH_REQUIRE(OK ==
                g.set_children("subtask1", std::list<ta::task_graph_vertex>(
                                               {subtask3, subtask4})));
  CATCH_REQUIRE(g.root()->name() == "root_task");
  CATCH_REQUIRE(
      ta::task_decomposition_graph::vertex_parent(g, subtask1)->name() ==
      "root_task");
  CATCH_REQUIRE(
      ta::task_decomposition_graph::vertex_parent(g, subtask2)->name() ==
      "root_task");
  CATCH_REQUIRE(
      ta::task_decomposition_graph::vertex_parent(g, subtask3)->name() ==
      "subtask1");
  CATCH_REQUIRE(
      ta::task_decomposition_graph::vertex_parent(g, subtask4)->name() ==
      "subtask1");
}
