/**
 * \file ipc.hpp
 *
 * \copyright 2017 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
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
namespace rcppsw::multiprocess {
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

} /* namespace rcppsw::multiprocess */

