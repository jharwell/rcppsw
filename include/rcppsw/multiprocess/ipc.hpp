/**
 * @file ipc.hpp
 * @ingroup interprocess
 *
 * @copyright 2017 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_MULTIPROCESS_IPC_HPP_
#define INCLUDE_RCPPSW_MULTIPROCESS_IPC_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <boost/interprocess/allocators/allocator.hpp>
#include <boost/interprocess/containers/deque.hpp>
#include <boost/interprocess/containers/list.hpp>
#include <boost/interprocess/containers/map.hpp>
#include <boost/interprocess/containers/string.hpp>
#include <boost/interprocess/ipc/message_queue.hpp>
#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/sync/interprocess_condition.hpp>
#include <boost/interprocess/sync/interprocess_mutex.hpp>
#include <boost/interprocess/sync/interprocess_semaphore.hpp>
#include <boost/interprocess/sync/named_mutex.hpp>
#include <functional>
#include <list>
#include <map>
#include <memory>
#include <string>
#include <utility>
#include <vector>
#include "rcppsw/common/common.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, multiprocess);
namespace bip = boost::interprocess;

/*******************************************************************************
 * Template Definitions
 ******************************************************************************/
template <typename T>
using ipc_allocator =
    bip::allocator<T, bip::managed_shared_memory::segment_manager>;

template <typename T>
using ipc_vector = std::vector<T, ipc_allocator<T>>;

template <typename T>
using ipc_list = bip::list<T, ipc_allocator<T>>;

template <typename key, typename value>
using ipc_map =
    bip::map<key, value, std::less<key>, ipc_allocator<std::pair<const key, value>>>;

/*******************************************************************************
 * Type Definitions
 ******************************************************************************/
typedef bip::basic_string<char, std::char_traits<char>, ipc_allocator<char>>
    ipc_string;

NS_END(multiprocess, rcppsw);

#endif /* INCLUDE_RCPPSW_MULTIPROCESS_IPC_HPP_ */
