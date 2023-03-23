/**
 * \file rng_impl.hpp
 *
 * RESTRICTED RIGHTS
 *
 * Contract No. 9700-1100-001-009
 *
 * Smart Information Flow Technologies
 *
 * 319 1st Ave N, Suite 400
 * Minneapolis, MN 55401-1689
 *
 * The Government's rights to use, modify, reproduce, release, perform, display,
 * or disclose this software are restricted by paragraph (b)(3) of the Rights in
 * Noncommercial Computer Software and Noncommercial Computer Software
 * Documentation clause contained in the above identified contract. Any
 * reproduction of computer software or portions thereof marked with this legend
 * must also reproduce the markings. Any person, other than the Government, who
 * has been provided access to such software must promptly notify the above
 * named Contractor.
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <random>

#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace rcppsw::math::detail {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
struct rng_impl {
  explicit rng_impl(uint seed) : engine(seed) {}
  std::default_random_engine engine;
};

} /* namespace rcppsw::math::detail */
