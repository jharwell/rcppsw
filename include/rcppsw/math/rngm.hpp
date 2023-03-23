/**
 * \file rngm.hpp
 *
 * \copyright 2019 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <map>
#include <memory>
#include <string>

#include "rcppsw/patterns/prototype/caching_factory.hpp"
#include "rcppsw/patterns/singleton/singleton.hpp"
#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace rcppsw::math {
class rng;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class rngm
 * \ingroup math
 *
 * \brief Random Number Generator (RNG) Manager. A caching factory that
 * returns references to previously created objects rather than creating new
 * objects each time like a regular factory.
 */
class rngm : public patterns::prototype::caching_factory<rng, uint>,
             public patterns::singleton::singleton<rngm> {};

} /* namespace rcppsw::math */

