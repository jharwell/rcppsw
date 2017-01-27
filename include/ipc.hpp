/*******************************************************************************
 * Name            : ipc.hpp
 * Project         : rcppsw
 * Module          : common
 * Description     : Interprocess communication definitions
 * Creation Date   : Sat Jul 25 18:02:48 2015
 * Original Author : jharwell
 *
 ******************************************************************************/

#ifndef INCLUDE_IPC_HPP_
#define INCLUDE_IPC_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <list>
#include <map>
#include <memory>
#include <string>
#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/allocators/allocator.hpp>
#include <boost/interprocess/containers/deque.hpp>
#include <boost/interprocess/containers/map.hpp>
#include <boost/interprocess/containers/string.hpp>
#include <boost/interprocess/containers/list.hpp>
#include <boost/interprocess/ipc/message_queue.hpp>
#include <boost/interprocess/sync/interprocess_condition.hpp>
#include <boost/interprocess/sync/interprocess_mutex.hpp>
#include <boost/interprocess/sync/interprocess_semaphore.hpp>
#include <boost/interprocess/sync/named_mutex.hpp>

/*******************************************************************************
 * Namespace Definitions
 ******************************************************************************/
namespace bip = boost::interprocess;

/*******************************************************************************
 * Template Definitions
 ******************************************************************************/
template <typename T>
using ipc_allocator =  bip::allocator<T,bip::managed_shared_memory::segment_manager>;

template <typename T>
using ipc_vector = std::vector<T, ipc_allocator<T> >;

template <typename T>
using ipc_list = bip::list<T, ipc_allocator<T> >;

template <typename key, typename value>
using ipc_map = bip::map<key, value, std::less<key>,
                         ipc_allocator<std::pair<const key, value>>>;

/*******************************************************************************
 * Type Definitions
 ******************************************************************************/
typedef bip::basic_string<char, std::char_traits<char>, ipc_allocator<char>> ipc_string;

#endif /* INCLUDE_IPC_HPP_ */
