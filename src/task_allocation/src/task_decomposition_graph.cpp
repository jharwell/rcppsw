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
task_decomposition_graph::vertex_iterator task_decomposition_graph::find_vertex(
    const task_graph_vertex& v) const {
    vertex_iterator v_i, v_end;
  boost::tie(v_i, v_end) = boost::vertices(m_graph);
  auto it =  std::find_if(v_i,
                          v_end,
                          [&](const task_decomposition_graph::vertex& tmp) {
                            return v == m_graph[tmp]; });
  return it;
} /* find_vertex() */

task_decomposition_graph::vertex_iterator task_decomposition_graph::find_vertex(
    const std::string& v) const {
  vertex_iterator v_i, v_end;
  boost::tie(v_i, v_end) = boost::vertices(m_graph);
  auto it =  std::find_if(v_i,
                          v_end,
                          [&](const task_decomposition_graph::vertex& tmp) {
                            return v == m_graph[tmp]->name(); });
  return it;
} /* find_vertex() */

const task_graph_vertex& task_decomposition_graph::vertex_parent(
    const task_graph_vertex& vertex) const {

  auto found = find_vertex(vertex);
  ER_ASSERT(found != boost::vertices(m_graph).second,
            "FATAL: No such vertex %s found in graph",
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

std::vector<task_graph_vertex> task_decomposition_graph::children(
    const task_graph_vertex& parent) const {
  auto it = find_vertex(parent);
  ER_ASSERT(it != boost::vertices(m_graph).second,
            "FATAL: No such vertex %s found in graph",
            parent->name().c_str());
  std::vector<task_graph_vertex> kids;
  out_edge_iterator oe, oe_end;

  boost::tie(oe, oe_end) = boost::out_edges(*it, m_graph);
  while (oe != oe_end) {
    kids.push_back(m_graph[boost::target(*oe, m_graph)]);
    ++oe;
  } /* while() */

  return kids;
} /* children() */

status_t task_decomposition_graph::set_children(const std::string& parent,
                                                std::list<task_graph_vertex> children) {
  return set_children(m_graph[*find_vertex(parent)], children);
} /* set_children() */

status_t task_decomposition_graph::set_children(const task_graph_vertex& parent,
                                                std::list<task_graph_vertex> children) {
  out_edge_iterator oe_start, oe_end;
  auto vertex_d = find_vertex(parent);
  ER_CHECK(vertex_d != boost::vertices(m_graph).second,
           "ERROR: No such vertex %s in graph", parent->name().c_str());

  /* The root always has "children", in the sense it points to itself */
  if (m_graph[*vertex_d] != m_root) {
    ER_CHECK(0 == boost::out_degree(*vertex_d, m_graph),
             "ERROR: Graph vertex %s already has children",
             m_graph[*vertex_d]->name().c_str());
  }

  for (auto& c : children) {
    vertex new_v = boost::add_vertex(c, m_graph);
    ER_VER("Add edge %s -> %s", m_graph[*vertex_d]->name().c_str(),
           m_graph[new_v]->name().c_str());
    boost::add_edge(*vertex_d, new_v, m_graph);
  } /* for(c..) */
  return OK;

error:
  return ERROR;
} /* set_children() */

NS_END(rcppsw, task_allocation);
