/**
 * @file tdgraph.cpp
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
#include "rcppsw/task_allocation/tdgraph.hpp"
#include "rcppsw/task_allocation/polled_task.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/
tdgraph::tdgraph(void)
    : ER_CLIENT_INIT("rcppsw.ta.tdgraph") {}

tdgraph::~tdgraph(void) {
  vertex_iterator v_i, v_end;
  boost::tie(v_i, v_end) = boost::vertices(m_graph);
  while (v_i != v_end) {
    delete m_graph[*v_i];
    v_i++;
  } /* while() */
}

/*******************************************************************************
 * Static Member Functions
 ******************************************************************************/
polled_task* tdgraph::vertex_parent(const tdgraph& graph,
                                    const polled_task* const vertex) {
  return graph.vertex_parent(vertex);
} /* vertex_parent() */

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
__rcsw_pure const polled_task* tdgraph::root(void) const { return m_root; }
__rcsw_pure polled_task* tdgraph::root(void) { return m_root; }

const polled_task* tdgraph::find_vertex(const std::string& task_name) const {
  return m_graph[*find_vertex_impl(task_name)];
} /* find_vertex() */

int tdgraph::vertex_id(const polled_task* const v) const {
  auto it = find_vertex_impl(v);
  if (it == boost::vertices(m_graph).second) {
    ER_WARN("No such vertex %s found in graph", v->name().c_str());
    return -1;
  }
  return *it;
} /* vertex_id() */

int tdgraph::vertex_depth(const polled_task* const v) const {
  auto it = find_vertex_impl(v);
  if (it == boost::vertices(m_graph).second) {
    ER_WARN("No such vertex %s found in graph", v->name().c_str());
    return -1;
  }
  return vertex_depth_impl(v, 0);
} /* vertex_depth() */

void tdgraph::walk(const walk_cb& f) const {
  vertex_iterator v_i, v_end;
  boost::tie(v_i, v_end) = boost::vertices(m_graph);
  while (v_i != v_end) {
    f(m_graph[*v_i]);
    ++v_i;
  } /* while() */
} /* walk() */

uint tdgraph::vertex_depth_impl(const polled_task* const v, int depth) const {
  /*
   * Only the root's parent is equal to itself.
   */
  if (vertex_parent(v) == v) {
    return depth;
  } else {
    return vertex_depth_impl(vertex_parent(v), depth + 1);
  }
} /* vertex_depth_impl() */

tdgraph::vertex_iterator tdgraph::find_vertex_impl(
    const polled_task* const v) const {
  vertex_iterator v_i, v_end;
  boost::tie(v_i, v_end) = boost::vertices(m_graph);
  auto it = std::find_if(v_i, v_end, [&](const tdgraph::vertex& tmp) {
    return v == m_graph[tmp];
  });
  return it;
} /* find_vertex_impl() */

tdgraph::vertex_iterator tdgraph::find_vertex_impl(const std::string& v) const {
  vertex_iterator v_i, v_end;
  boost::tie(v_i, v_end) = boost::vertices(m_graph);
  auto it = std::find_if(v_i, v_end, [&](const tdgraph::vertex& tmp) {
    return v == m_graph[tmp]->name();
  });
  return it;
} /* find_vertex_impl() */

polled_task* tdgraph::vertex_parent(const polled_task* const vertex) const {
  auto found = find_vertex_impl(vertex);
  if (found == boost::vertices(m_graph).second) {
    ER_WARN("No such vertex %s found in graph", vertex->name().c_str());
    return nullptr;
  }
  /*
   * Now, we can just look in the incident edges for the vertex and return the
   * one we find (if there is more than 1, that's an error).
   */
  in_edge_iterator ie, ie_end;
  boost::tie(ie, ie_end) = boost::in_edges(*found, m_graph);
  ER_ASSERT(1 == ie_end - ie,
            "Vertex %s has more than 1 parent",
            vertex->name().c_str());
  return m_graph[boost::source(*ie, m_graph)];
} /* vertex_parent() */

status_t tdgraph::set_root(polled_task* const v) {
  vertex new_v;
  ER_CHECK(0 == boost::num_edges(m_graph), "Root already set for graph!");
  new_v = boost::add_vertex(v, m_graph);
  m_root = v;
  boost::add_edge(new_v, new_v, m_graph); /* parent of root is root */
  return OK;

error:
  return ERROR;
} /* set_root() */

std::vector<polled_task*> tdgraph::children(
    const polled_task* const parent) const {
  auto it = find_vertex_impl(parent);
  ER_ASSERT(it != boost::vertices(m_graph).second,
            "No such vertex %s found in graph",
            parent->name().c_str());
  std::vector<polled_task*> kids;
  out_edge_iterator oe, oe_end;

  boost::tie(oe, oe_end) = boost::out_edges(*it, m_graph);
  while (oe != oe_end) {
    kids.push_back(m_graph[boost::target(*oe, m_graph)]);
    ++oe;
  } /* while() */

  return kids;
} /* children() */

status_t tdgraph::set_children(const std::string& parent,
                               const std::vector<polled_task*>& children) {
  return set_children(m_graph[*find_vertex_impl(parent)], children);
} /* set_children() */

status_t tdgraph::set_children(const polled_task* parent,
                               const std::vector<polled_task*>& children) {
  out_edge_iterator oe_start, oe_end;
  auto vertex_d = find_vertex_impl(parent);
  ER_CHECK(vertex_d != boost::vertices(m_graph).second,
           "No such vertex %s in graph",
           parent->name().c_str());

  /* The root always has "children", in the sense it points to itself */
  if (m_graph[*vertex_d] != m_root) {
    ER_CHECK(0 == boost::out_degree(*vertex_d, m_graph),
             "Graph vertex %s already has children",
             m_graph[*vertex_d]->name().c_str());
  }

  for (auto& c : children) {
    vertex new_v = boost::add_vertex(c, m_graph);
    ER_TRACE("Add edge %s -> %s",
             m_graph[*vertex_d]->name().c_str(),
             m_graph[new_v]->name().c_str());
    boost::add_edge(*vertex_d, new_v, m_graph);
  } /* for(c..) */
  return OK;

error:
  return ERROR;
} /* set_children() */

NS_END(rcppsw, task_allocation);
