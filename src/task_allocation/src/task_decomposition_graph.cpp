/**
 * @file task_decomposition_graph.cpp
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
#include "rcppsw/task_allocation/task_decomposition_graph.hpp"
#include "rcppsw/task_allocation/executable_task.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/
task_decomposition_graph::task_decomposition_graph(
    const std::shared_ptr<er::server>& server) :
    client(server), m_root(), m_graph() {
  insmod("tdg", er::er_lvl::DIAG, er::er_lvl::VER);
}

/*******************************************************************************
 * Static Member Functions
 ******************************************************************************/
const task_graph_vertex& task_decomposition_graph::vertex_parent(
    const task_decomposition_graph& graph,
    const task_graph_vertex& vertex) {
  return graph.vertex_parent(vertex);
} /* vertex_parent() */

const task_graph_vertex& task_decomposition_graph::vertex_parent(
    const std::shared_ptr<task_decomposition_graph>& graph,
    const task_graph_vertex& vertex) {
  return vertex_parent(*graph, vertex);
} /* vertex_parent */

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
const task_graph_vertex& task_decomposition_graph::vertex_parent(
    const task_graph_vertex& vertex) const {

  /*
   * First, find the vertex descriptor for the vertex, which is what we need to
   * interact with the graph.
   */
  vertex_iterator v_i, v_end;
  boost::tie(v_i, v_end) = boost::vertices(m_graph);
  auto found = std::find_if(v_i,
                            v_end,
                            [&](const task_decomposition_graph::vertex& v) {
                              return vertex == m_graph[v]; });
  ER_ASSERT(found != v_end, "FATAL: No such vertex %s found in graph",
            vertex->name().c_str());

  /*
   * Now, we can just look in the incident edges for the vertex and return the
   * one we find (if there is more than 1, that's an error).
   */
  in_edge_iterator ie, ie_end;
  boost::tie(ie, ie_end) = boost::in_edges(*found, m_graph);
  ER_ASSERT(1 == ie_end - ie, "FATAL: Vertex %s has more than 1 parent",
            vertex->name().c_str());
  return m_graph[boost::source(*ie, m_graph)];
} /* vertex_parent() */

status_t task_decomposition_graph::set_root(const task_graph_vertex& v) {
  vertex added;
  ER_CHECK(0 == boost::num_edges(m_graph), "ERROR: Root already set for graph!");
  added = boost::add_vertex(v, m_graph);
  m_root = v;
  boost::add_edge(added, added, m_graph);
  return OK;

error:
  return ERROR;
} /* set_root() */

status_t task_decomposition_graph::set_children(const std::string& parent,
                                                  std::list<task_graph_vertex> children) {
  vertex_iterator v_i, v_end;
  out_edge_iterator oe_start, oe_end;

  boost::tie(v_i, v_end) = boost::vertices(m_graph);
  auto it = std::find_if(v_i,
                         v_end,
                         [&](const vertex& v) {
                           return parent == m_graph[v]->name();
                         });
  ER_CHECK(it != v_end, "ERROR: No such vertex %s in graph", parent.c_str());

  /* The root always has "children", in the sense it points to itself */
  if (m_graph[*it] != m_root) {
    ER_CHECK(0 == boost::out_degree(*it, m_graph),
             "ERROR: Graph vertex %s already has children",
             m_graph[*it]->name().c_str());
  }

  for (auto& c : children) {
    vertex new_v = boost::add_vertex(c, m_graph);
    ER_VER("Add edge %s -> %s", m_graph[*it]->name().c_str(),
           m_graph[new_v]->name().c_str());
    boost::add_edge(*it, new_v, m_graph);
  } /* for(c..) */
  return OK;

error:
  return ERROR;
} /* set_children() */

NS_END(rcppsw, task_allocation);
