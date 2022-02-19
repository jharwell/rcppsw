/**
 * \file md5.hpp
 *
 * \copyright 2022 John Harwell, All rights reserved.
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
#include <iosfwd>
#include <array>

#include <openssl/md5.h>

#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, utils);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class md5
 * \ingroup utils
 *
 * \brief Calculates the MD5 sum of various things.
 */
class md5 {
 public:
  md5(void) = default;

  /* Not move/copy constructable/assignable by default */
  md5(const md5&) = delete;
  md5& operator=(const md5&) = delete;
  md5(md5&&) = delete;
  md5& operator=(md5&&) = delete;

  std::array<unsigned char, MD5_DIGEST_LENGTH>
  operator()(std::ifstream& file) const;

 private:
  /* clang-format off */
  /* clang-format on */
};

NS_END(utils, rcppsw);
