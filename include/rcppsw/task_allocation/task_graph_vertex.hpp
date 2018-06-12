/**
 * @file task_graph_vertex.hpp
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

#ifndef INCLUDE_RCPPSW_TASK_ALLOCATION_TASK_GRAPH_VERTEX_HPP_
#define INCLUDE_RCPPSW_TASK_ALLOCATION_TASK_GRAPH_VERTEX_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/common/common.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class executable_task;
using task_graph_vertex = std::shared_ptr<executable_task>;

template <typename T, typename ...Args>
task_graph_vertex make_task_graph_vertex(Args&&... args) {
  return std::make_shared<T>(args...);
}

NS_END(task_allocation, rcppsw);

#endif /* INCLUDE_RCPPSW_TASK_ALLOCATION_TASK_GRAPH_VERTEX_HPP_ */
