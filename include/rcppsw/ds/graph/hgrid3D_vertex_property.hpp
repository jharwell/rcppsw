/**
 * \file hgrid3D_vertex_property.hpp
 *
 * \copyright 2021 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
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
namespace rcppsw::ds::graph {

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

} /* namespace rcppsw::ds::graph */
