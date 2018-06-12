/**
 * @file task_decomposition_graph.hpp
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

#ifndef INCLUDE_RCPPSW_TASK_ALLOCATION_TASK_DECOMPOSITION_GRAPH_HPP_
#define INCLUDE_RCPPSW_TASK_ALLOCATION_TASK_DECOMPOSITION_GRAPH_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <boost/graph/adjacency_list.hpp>
#include <list>

#include "rcppsw/common/common.hpp"
#include "rcppsw/er/client.hpp"
#include "rcppsw/task_allocation/task_graph_vertex.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

class executable_task;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class task_decomposition_graph
 * @ingroup task_allocation
 *
 * @brief Representation of an overall task (the root task) as a tree
 * representing the task decomposition of the root task at different
 * granularities (i.e. tasks of different levels of complexity).
 *
 * This is the main input into the task \ref executive, and does not do much on
 * its own.
 *
 * Once you set the root node or the children of a specific node, you cannot
 * change them. Uses boost::graph bidirectional graph, adjacency list flavor.
 */
class task_decomposition_graph : public er::client {
 public:
  using graph_impl = boost::adjacency_list<boost::vecS,
                                           boost::vecS,
                                           boost::bidirectionalS,
                                           task_graph_vertex>;
  using vertex = boost::graph_traits<graph_impl>::vertex_descriptor;
  using edge = boost::graph_traits<graph_impl>::edge_descriptor;

  using vertex_iterator = boost::graph_traits<graph_impl>::vertex_iterator;
  using edge_iterator = boost::graph_traits<graph_impl>::edge_iterator;
  using out_edge_iterator = boost::graph_traits<graph_impl>::out_edge_iterator;
  using in_edge_iterator = boost::graph_traits<graph_impl>::in_edge_iterator;

  static const task_graph_vertex& vertex_parent(const task_decomposition_graph& graph,
                                                const task_graph_vertex& node);
  static const task_graph_vertex& vertex_parent(
      const std::shared_ptr<task_decomposition_graph>& graph,
      const task_graph_vertex& nodee);

  explicit task_decomposition_graph(const std::shared_ptr<er::server>& server);

  /**
   * @brief Set the root of the graph/tree.
   *
   * This needs to be the first node added to the graph.
   *
   * @param v The root.
   *
   * @return \ref status_t.
   */
  status_t set_root(const task_graph_vertex& v);

  const task_graph_vertex&  root(void) const { return m_root; }

  /**
   * @brief Set the children for an existing node.
   *
   * @param parent The parent node, which MUST be a \ref partitionable_task.
   * @param children The list of children (any #) to associate with the parent.
   *
   * @return \ref status_t.
   */
  status_t set_children(const std::string& parent,
                        std::list<task_graph_vertex> children);

 private:
  // clang-format off
  task_graph_vertex m_root;
  graph_impl        m_graph;
  // clang-format on
};

NS_END(task_allocation, rcppsw);
#endif /* INCLUDE_RCPPSW_TASK_ALLOCATION_TASK_DECOMPOSITION_GRAPH_HPP_ */
