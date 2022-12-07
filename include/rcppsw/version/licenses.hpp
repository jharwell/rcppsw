/**
 * \file licensing.hpp
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
#include "rcsw/version/licenses.h"

/*******************************************************************************
 * Macros
 ******************************************************************************/
#define RCPPSW_LICENSE_FULL(license, project)  \
  RCSW_LICENSE_FULL(license, project)

#define RCPPSW_LICENSE_SHORT(license, project)  \
  RCSW_LICENSE_SHORT(license, project)

#define RCPPSW_COPYRIGHT(year, author)        \
  RCSW_COPYRIGHT(year, author)
