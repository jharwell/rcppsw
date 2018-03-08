/**
 * @file er_msg.hpp
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

#ifndef INCLUDE_RCPPSW_ER_ER_MSG_HPP_
#define INCLUDE_RCPPSW_ER_ER_MSG_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <boost/uuid/uuid_generators.hpp>
#include <string>

#include "rcppsw/common/common.hpp"
#include "rcppsw/er/er_lvl.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, er);

/*******************************************************************************
 * Struct Definitions
 ******************************************************************************/
/**
 * @internal
 * @struct er_msg
 *
 * @brief Internal class wrapping all the information needed to processing a
 * message besides the text of the message itself.
 *
 * @endinternal
 */
struct er_msg {
  er_msg(const boost::uuids::uuid& id_,
         const er_lvl::value& lvl_,
         std::string str_)
      : id(id_), lvl(lvl_), str(std::move(str_)) {}

  boost::uuids::uuid id;
  er_lvl::value lvl;
  std::string str;
};

NS_END(er, rcppsw);

#endif /* INCLUDE_RCPPSW_ER_ER_MSG_HPP_ */
