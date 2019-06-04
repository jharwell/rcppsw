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
#include "rcppsw/ta/polled_task.hpp"
#include "rcppsw/ta/tdgraph.hpp"
#include "rcppsw/ta/config/task_alloc_config.hpp"
#include <catch.hpp>

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace ta = rcppsw::ta;
namespace er = rcppsw::er;

/*******************************************************************************
 * Test Classes
 ******************************************************************************/
class test_task : public ta::polled_task {
 public:
  test_task(const std::string &name,
            const struct ta::config::task_alloc_config *c_config)
      : polled_task(name, &c_config->abort, &c_config->exec_est.ema, nullptr) {}

  double current_time(void) const override { return 0.0; }
  void task_start(const ta::taskable_argument*) override {}
  bool task_completed(void) const override { return false; }
  double abort_prob_calc(void) override { return 0.0; }
  double interface_time_calc(uint, double) override { return 0.0; }
  void active_interface_update(int) override {}

};

/*******************************************************************************
 * Test Functions
 ******************************************************************************/
CATCH_TEST_CASE("sanity-test", "[tdgraph]") {
  ta::tdgraph g;
}
CATCH_TEST_CASE("build-test", "[tdgraph]") {
  ta::tdgraph g;
  ta::config::task_alloc_config config;
  CATCH_REQUIRE(OK == g.set_root(rcppsw::make_unique<test_task>("root_task", &config)));
  CATCH_REQUIRE(g.root()->name() == "root_task");

  auto subtask1 = rcppsw::make_unique<test_task>("subtask1", &config);
  auto subtask2 = rcppsw::make_unique<test_task>("subtask2", &config);
  auto subtask3 = rcppsw::make_unique<test_task>("subtask3", &config);
  auto subtask4 = rcppsw::make_unique<test_task>("subtask4", &config);
  ta::tdgraph::vertex_vector vec1;
  vec1.push_back(std::move(subtask1));
  vec1.push_back(std::move(subtask2));
  ta::tdgraph::vertex_vector vec2;
  vec2.push_back(std::move(subtask3));
  vec2.push_back(std::move(subtask4));
  CATCH_REQUIRE(OK == g.set_children("root_task", std::move(vec1)));
  CATCH_REQUIRE(OK == g.set_children("subtask1", std::move(vec2)));
  CATCH_REQUIRE(g.root()->name() == "root_task");
  CATCH_REQUIRE(ta::tdgraph::vertex_parent(g,
                                           g.find_vertex("subtask1"))->name() == "root_task");
  CATCH_REQUIRE(ta::tdgraph::vertex_parent(g,
                                           g.find_vertex("subtask2"))->name() == "root_task");
  CATCH_REQUIRE(ta::tdgraph::vertex_parent(g, g.find_vertex("subtask3"))->name() ==
                "subtask1");
  CATCH_REQUIRE(ta::tdgraph::vertex_parent(g, g.find_vertex("subtask4"))->name() ==
                "subtask1");
}
