/*******************************************************************************
 * Name            : shared_queue.hpp
 * Project         : paradyn
 * Module          : utils
 * Description     : A simple multiple-producer, single-consumer queue with locking
 * Creation Date   : Thu Jun 25 17:18:36 2015
 * Original Author : jharwell
 *
 ******************************************************************************/

#ifndef _SHARED_QUEUE_HPP_
#define _SHARED_QUEUE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <queue>
#include <boost/thread/locks.hpp>
#include <boost/thread.hpp>

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
template <typename T>
class shared_queue
{
private:
    std::deque<T> queue;  // Use STL queue to store data
    boost::mutex mtx;   // The mutex to synchronise on
    boost::condition_variable cv;// The condition to wait for

public:
    shared_queue(void) :
        queue(),
        mtx(),
        cv() {}
    bool empty(void) { return 0 == size(); }

    // Add data to the queue and notify others
    void enq(const T& data)
        {
            // Acquire lock on the queue
            boost::unique_lock<boost::mutex> lock(mtx);

            // Add the data to the queue
            queue.push_back(data);

            // Notify others that data is ready
            cv.notify_one();

        } // Lock is automatically released here

    // Get data from the queue. Wait for data if not available
    T dq()
        {
            // Acquire lock on the queue
            boost::unique_lock<boost::mutex> lock(mtx);

            // When there is no data, wait till someone fills it.
            // Lock is automatically released in the wait and obtained
            // again after the wait
            while (queue.size()==0) cv.wait(lock);

            // Retrieve the data from the queue
            T result=static_cast<T>(queue.front()); queue.pop_front();
            return result;

        } // Lock is automatically released here

    // get the size of the queue
    size_t size() {
        // Acquire lock on the queue
        boost::unique_lock<boost::mutex> lock(mtx);

        return queue.size();
    } // Lock is automatically released here
};

#endif /*  _SHARED_QUEUE_HPP_  */
