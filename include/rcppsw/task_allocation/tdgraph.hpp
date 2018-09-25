/**
 * @file tdgraph.hpp
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

#ifndef INCLUDE_RCPPSW_TASK_ALLOCATION_TDGRAPH_HPP_
#define INCLUDE_RCPPSW_TASK_ALLOCATION_TDGRAPH_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <boost/graph/adjacency_list.hpp>
#include <vector>
#include <string>

#include "rcppsw/common/common.hpp"
#include "rcppsw/er/client.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

class polled_task;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class tdgraph
 * @ingroup task_allocation
 *
 * @brief Representation of an overall task (the root task) as a tree
 * representing the task decomposition of the root task at different
 * granularities (i.e. tasks of different levels of complexity).
 *
 * This is the main input into the task \ref executive, and does not do much on
 * its own. Tasks can have any number of children.
 *
 * Once you set the root node or the children of a specific node, you cannot
 * change them. Uses boost::graph bidirectional graph, adjacency list flavor.
 *
 * Ideally the graph nodes would be std::unique_ptr<T>, but that does not
 * currently work with the boost libraries, and shared_ptr<T> is not right
 * either, because the graph owns the tasks, so raw pointers are used instead.
 */
class tdgraph : public er::client<tdgraph> {
 public:
  using graph_impl = boost::adjacency_list<boost::vecS,
                                           boost::vecS,
                                           boost::bidirectionalS,
                                           polled_task*>;
  using vertex = boost::graph_traits<graph_impl>::vertex_descriptor;
  using edge = boost::graph_traits<graph_impl>::edge_descriptor;

  using vertex_iterator = boost::graph_traits<graph_impl>::vertex_iterator;
  using edge_iterator = boost::graph_traits<graph_impl>::edge_iterator;
  using out_edge_iterator = boost::graph_traits<graph_impl>::out_edge_iterator;
  using in_edge_iterator = boost::graph_traits<graph_impl>::in_edge_iterator;

  /**
   * @brief Get the parent of a node in the graph, given the graph and node.
   *
   * @return The parent of the vertex, or NULL if vertex not in graph.
   */
  static polled_task* vertex_parent(const tdgraph& graph,
                                    const polled_task* node);

  tdgraph(void);
  virtual ~tdgraph(void);
  tdgraph(const tdgraph& other) = delete;
  tdgraph& operator=(const tdgraph& other) = delete;


  /**
   * @brief Get the parent of a node in the graph, given a node in the graph.
   *
   * @return The parent of the vertex, or NULL if vertex not in graph.
   */
  polled_task* vertex_parent(const polled_task* vertex) const;

  /**
   * @brief Set the root of the graph/tree.
   *
   * This needs to be the first node added to the graph.
   *
   * @param v The root.
   *
   * @return \ref status_t.
   */
  status_t set_root(polled_task* v);

  const polled_task* root(void) const;
  polled_task* root(void);

  /**
   * @brief Set the children for an existing node.
   *
   * @param parent The parent node, which MUST be a \ref partitionable_task.
   * @param children The list of children (any #) to associate with the
   * parent.
   *
   * @return \ref status_t.
   */
  virtual status_t set_children(const polled_task* parent,
                                const std::vector<polled_task*>& children);
  virtual status_t set_children(const std::string& parent,
                                const std::vector<polled_task*>& children);

  /**
   * @brief Return the children of the specified task
   *
   * @param parent The parent task.
   *
   * @return The children. Will ALWAYS be of length 2, unless the root task is
   * passed in, in which case it will have length 3, and the self-reference to
   * the root task will be at index 0.
   */
  std::vector<polled_task*> children(const polled_task* parent) const;

 private:
  /**
   * @brief Find the vertex descriptor for the vertex, which is what we need to
   * interact with the graph efficiently.
   */
  vertex_iterator find_vertex(const polled_task* v) const;
  vertex_iterator find_vertex(const std::string& v) const;

  // clang-format off
  polled_task*       m_root;
  graph_impl         m_graph;
  // clang-format on
};

NS_END(task_allocation, rcppsw);
#endif /* INCLUDE_RCPPSW_TASK_ALLOCATION_TDGRAPH_HPP_ */
