/**
 * @file er_lvl.hpp
 *
 * Interface for classes that want to be able to use the ER Server.
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

#ifndef INCLUDE_RCPPSW_ER_ER_LVL_HPP_
#define INCLUDE_RCPPSW_ER_ER_LVL_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/common/common.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, er);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class er_lvl
 * @ingroup er
 *
 * @brief The different levels of reportable events.
 *
 * OFF: Used when you want to turn debugging OFF for all modules.
 *
 * ERR: Used to print things regarding errors, as in something bad happened
 *      in your program.
 *
 * WARN: Used to print warning things, as in something happened athat is
 *       somewhat alarming/sub-optimal, but not in of itself
 *       catastrophic/fatal.
 *
 * NOM: Normal/nominative printing. Use this for things that you want your
 *      program to print when everything is going smoothly. According to UNIX
 *      philosophy, if your program has nothing interesting to say, it should
 *      say nothing if this is the debugging level.
 *
 * DIAG: Used to print diagnostic information, as in additional info that
 *       a developer can use to help debug a problem.
 *
 * VER: Used to print verbose information, for use on tough problems when you
 *      want the use to get as much information from your program as
 *      possible.
 */

class er_lvl {
 public:
  enum value { OFF, ERR, WARN, NOM, DIAG, VER };
};

NS_END(er, rcppsw);

#endif /* INCLUDE_RCPPSW_ER_ER_LVL_HPP_ */
