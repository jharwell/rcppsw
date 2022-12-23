/**
 * \file discretize_ratio.hpp
 *
 * \copyright 2019 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/types/named_type.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace rcppsw::types {

/*******************************************************************************
 * Type Definitions
 ******************************************************************************/
/**
 * \typedef discretize_ratio
 * \ingroup types
 *
 * \brief Specifies the ratio of discretized space to real space, and therefore
 * should always be <= 1.0.
 */
using discretize_ratio = named_type<double, struct discretize_ratio_tag>;

} /* namespace rcppsw::types */

