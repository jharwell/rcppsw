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

#ifndef INCLUDE_RCPPSW_TA_DS_TDGRAPH_HPP_
#define INCLUDE_RCPPSW_TA_DS_TDGRAPH_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <boost/graph/adjacency_list.hpp>
#include <functional>
#include <string>
#include <vector>

#include "rcppsw/rcppsw.hpp"
#include "rcppsw/er/client.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ta);

class polled_task;

NS_START(ds);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class tdgraph
 * @ingroup rcppsw ta
 *
 * @brief Representation of an overall task (the root task) as a tree
 * representing the task decomposition of the root task at different
 * granularities (i.e. tasks of different levels of complexity).
 *
 * This is the main input into the task \ref bi_tdgraph_executive, and does not
 * do much on its own. Tasks can have any number of children.
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
  /**
   * @brief We want to convey that the graph owns the vertices in it, which we
   * do by requiring the application to pass unique_ptrs to set up the
   * graph. HOWEVER, boost::add_vertex does not allow for move-construction only
   * types (apparently), and so unique_ptr does not work as the underlying
   * vertice type in the graph, and we have to use shared ptr.
   */
  using vertex_type = std::unique_ptr<polled_task>;
  using walk_cb = std::function<void(polled_task*)>;
  using const_walk_cb = std::function<void(const polled_task*)>;
  using vertex_vector = std::vector<vertex_type>;

  /**
   * @brief Get the parent of a vertex in the graph, given the graph and vertex.
   *
   * @return The parent of the vertex, or NULL if vertex not in graph.
   */
  static polled_task* vertex_parent(const tdgraph& graph, const polled_task* v);

  tdgraph(void);
  ~tdgraph(void) override = default;

  /* Necessary for use in boost::variant */
  tdgraph(const tdgraph&) = default;
  tdgraph& operator=(const tdgraph&) = delete;

  /**
   * @brief Get the parent of a node in the graph, given a node in the graph.
   *
   * @return The parent of the vertex, or NULL if vertex not in graph.
   */
  polled_task* vertex_parent(const polled_task* v) const;

  /**
   * @brief Set the root of the graph/tree.
   *
   * This needs to be the first node added to the graph.
   *
   * @param v The root.
   *
   * @return \ref status_t.
   */
  status_t set_root(std::unique_ptr<polled_task> v);

  const polled_task* root(void) const RCSW_PURE;
  polled_task* root(void) RCSW_PURE;

  /**
   * @brief Set the children for an existing node.
   *
   * @param parent The parent node, which MUST be a partitionable task.
   * @param children The list of children (any #) to associate with the
   * parent.
   *
   * @return \ref status_t.
   */
  status_t set_children(const polled_task* parent, vertex_vector children);
  status_t set_children(const std::string& parent, vertex_vector children);

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

  /**
   * @brief Return the depth of the specified task in the graph, as measured
   * from the root (the root is depth 0).
   *
   * @param v The vertex to obtain the depth of.
   *
   * @return The depth of the vertex from the root, or -1 if no such vertex
   * exists in the graph.
   */
  int vertex_depth(const polled_task* v) const;

  /**
   * @brief Retrieve the numeric ID of the vertex.
   *
   * @return The vertex ID, or -1 if no such vertex in graph.
   */
  int vertex_id(const polled_task* v) const;

  /**
   * @brief Find the task vertex corresponding to the specified task name.
   *
   * @return The task vertex, or NULL if no such task.
   */
  const polled_task* find_vertex(const std::string& task_name) const;
  polled_task* find_vertex(const std::string& task_name);

  size_t n_vertices(void) const { return boost::num_vertices(m_impl); }

  /**
   * @brief Find the task vertex corresponding to the specified vertex id.
   *
   * @return The task vertex, or NULL if no such vertex id
   */
  const polled_task* find_vertex(int id) const RCSW_PURE;
  polled_task* find_vertex(int id) RCSW_PURE;

  /**
   * @brief Run the callback on each node in the graph, in an arbitrary order.
   *
   * @param f The callback.
   */
  void walk(const walk_cb& f);
  void walk(const const_walk_cb& f) const;

 private:
  using vertex_type_impl = std::shared_ptr<polled_task>;
  using graph_impl = boost::adjacency_list<boost::vecS,
                                           boost::vecS,
                                           boost::bidirectionalS,
                                           vertex_type_impl>;
  using vertex_desc = boost::graph_traits<graph_impl>::vertex_descriptor;
  using edge_desc = boost::graph_traits<graph_impl>::edge_descriptor;

  using vertex_iterator = boost::graph_traits<graph_impl>::vertex_iterator;
  using edge_iterator = boost::graph_traits<graph_impl>::edge_iterator;
  using out_edge_iterator = boost::graph_traits<graph_impl>::out_edge_iterator;
  using in_edge_iterator = boost::graph_traits<graph_impl>::in_edge_iterator;

  /**
   * @brief Find the vertex descriptor for the vertex, which is what we need to
   * interact with the graph efficiently.
   */
  vertex_iterator find_vertex_impl(const polled_task* v) const;
  vertex_iterator find_vertex_impl(const std::string& v) const;

  /**
   * @brief Recursively calculate the depth of a vertex from the root in the
   * graph.
   *
   * @param v The current node along trajectory from desired node up to root.
   * @param depth The starting depth (should always be 0).
   */
  uint vertex_depth_impl(const polled_task* v, int depth) const;

  /* clang-format off */
  polled_task*       m_root{nullptr};
  graph_impl         m_impl{};
  /* clang-format on */
};

NS_END(ds, ta, rcppsw);

#endif /* INCLUDE_RCPPSW_TA_DS_TDGRAPH_HPP_ */
