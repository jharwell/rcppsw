/**
 * \file version.hpp
 *
 * \copyright 2022 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>

#include "rcppsw/rcppsw.hpp"
#include "rcppsw/version/meta_info.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace rcppsw::version {

/*******************************************************************************
 * Free Functions
 ******************************************************************************/
std::string meta_info_to_str(meta_info* info);

/*******************************************************************************
 * Global Variables
 ******************************************************************************/
/**
 * \brief The version of the library, to aid with debugging sanity checks.
 */
extern meta_info kVersion;

} /* namespace rcppsw::version */
