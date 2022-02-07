/**
 * \file hgrid3D_vertex_property.hpp
 *
 * \copyright 2021 John Harwell, All rights reserved.
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

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/ds/graph/base_vertex_property.hpp"
#include "rcppsw/math/vector3.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ds, graph);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \struct hgrid3D_vertex_property
 * \ingroup ds graph
 *
 * \brief Base class for all vertex properties used with the \ref hgrid3D
 * graph.
 */
struct hgrid3D_vertex_property : public base_vertex_property {
  rmath::vector3z coord{};
};

NS_END(graph, ds, rcppsw);
