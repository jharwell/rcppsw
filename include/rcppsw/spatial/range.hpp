/**
 * \file range.hpp
 *
 * \copyright 2020 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/math/range.hpp"
#include "rcppsw/spatial/euclidean_dist.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace rcppsw::spatial {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \typedef range
 * \ingroup spatial
 *
 * \brief A \ref rmath::range<T> of \ref rspatial::euclidean_dist.
 */
using erange = math::range<spatial::euclidean_dist>;

} /* namespace rcppsw::spatial */
