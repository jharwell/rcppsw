/*******************************************************************************
 * Name            : ipc_queue.hpp
 * Project         : rcppsw
 * Module          : ds
 * Description     : Interprocess synchronized queue
 * Creation Date   : Sun Jul 26 14:20:04 2015
 * Original Author : jharwell
 *
 ******************************************************************************/

#ifndef INCLUDE_IPC_QUEUE_HPP_
#define INCLUDE_IPC_QUEUE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <boost/thread/thread_time.hpp>
#include "include/ipc.hpp"

/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
template <class T> class ipc_queue {

public:
    typedef bip::allocator<T, bip::managed_shared_memory::segment_manager> allocator_type;

 private:
    bip::deque<T, allocator_type> sQueue;
    mutable bip::interprocess_mutex io_mutex_;
    mutable bip::interprocess_condition waitCondition;

 public:
    ipc_queue(allocator_type alloc) :
        sQueue(alloc),
        io_mutex_(),
        waitCondition()
        {}

    void push(T element) {
        bip::scoped_lock<bip::interprocess_mutex> lock(io_mutex_);
        sQueue.push_back(element);
        waitCondition.notify_one();
    }
    bool empty() const {
        bip::scoped_lock<bip::interprocess_mutex> lock(io_mutex_);
        return sQueue.empty();
    }
    T pop(void) {
        bip::scoped_lock<bip::interprocess_mutex> lock(io_mutex_);

        T element = sQueue.front();
        sQueue.pop_front();

        return element;
    }
    bool pop(T &element) {
        bip::scoped_lock<bip::interprocess_mutex> lock(io_mutex_);

        if (sQueue.empty()) {
            return false;
        }

        element = sQueue.front();
        sQueue.pop_front();

        return true;
    }
    unsigned int size() const {
        // try to lock the mutex
        bip::scoped_lock<bip::interprocess_mutex> lock(io_mutex_);
        return sQueue.size();
    }
    void pop_wait(T &element) {
        bip::scoped_lock<bip::interprocess_mutex> lock(io_mutex_);

        while (sQueue.empty()) {
            waitCondition.wait(lock);
        }

        element = sQueue.front();
        sQueue.pop_front();
    }
    bool pop_timed_wait(
        T &element,
        int to_sec)
        {
            bip::scoped_lock<bip::interprocess_mutex> lock(io_mutex_);
            boost::system_time to = boost::get_system_time() + boost::posix_time::seconds(to_sec);
            waitCondition.timed_wait(lock,to);
            if (sQueue.empty()) {
                return false;
            }
            element = sQueue.front();
            sQueue.pop_front();
            return true;
        } /* pop_timed_wait() */
    void clear(void) { sQueue.clear(); }
};

#endif /* INCLUDE_IPC_QUEUE_HPP_ */
