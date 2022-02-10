/**
 * \file ipc.hpp
 *
 * \copyright 2017 John Harwell, All rights reserved.
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
/// \file
/// here is my file
#pragma once

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

#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, multiprocess);
namespace bip = boost::interprocess;

/*******************************************************************************
 * Template Definitions
 ******************************************************************************/
/**
 * \typedef ipc_allocator
 * \ingroup multiprocess
 *
 * \brief An allocator for shared memory for stuff allocated to be shared across
 * processes.
 */
template <typename T>
using ipc_allocator =
    bip::allocator<T, bip::managed_shared_memory::segment_manager>;

/**
 * \typedef ipc_vector
 * \ingroup multiprocess
 *
 * \brief A std::vector capable of being shared across processes.
 */
template <typename T>
using ipc_vector = std::vector<T, ipc_allocator<T>>;

/**
 * \typedef ipc_list
 * \ingroup multiprocess
 *
 * \brief A std::list capable of being shared across processes.
 */
template <typename T>
using ipc_list = bip::list<T, ipc_allocator<T>>;

/**
 * \typedef ipc_map
 * \ingroup multiprocess
 *
 * \brief A std::map capable of being shared across processes.
 */
template <typename key, typename value>
using ipc_map = bip::
    map<key, value, std::less<key>, ipc_allocator<std::pair<const key, value>>>;

/*******************************************************************************
 * Type Definitions
 ******************************************************************************/
/**
 * \typedef ipc_string
 * \ingroup multiprocess
 *
 * \brief A string capable of being shared across processes.
 */
using ipc_string =
    bip::basic_string<char, std::char_traits<char>, ipc_allocator<char>>;

NS_END(multiprocess, rcppsw);

