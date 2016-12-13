/*******************************************************************************
 * Name            : threadable.cpp
 * Project         : rcppsw
 * Module          : utils
 * Description     : Threadable base class
 * Creation Date   : Mon Nov 16 16:04:20 2015
 * Original Author : jharwell
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "threadable.hpp"
#include "er_frmwk.hpp"

/*******************************************************************************
 * Namespace Definitions
 ******************************************************************************/
using namespace rcppsw;

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
/**
 * threadable::start() - Start a thread
 *
 * RETURN:
 *     N/A
 *
 **/
void threadable::start(
    int core)
{
    /* start main thread */
    thread_run = true;

    internal_thread = std::thread(&threadable::entry_point,this);
    if (-1 != core) {
        thread_core_lock(internal_thread.native_handle(),core);
    }
} /* threadable::start() */

/**
 * threadable::thread_core_lock() - Lock a thread to a core
 *
 * RETURN:
 *     status_t - OK if successful, ERROR otherwise
 *
 **/
status_t threadable::thread_core_lock(
    pthread_t thread,
    int core)
{
    cpu_set_t cpuset;

    CPU_ZERO(&cpuset);
    CPU_SET(core,&cpuset);
    CHECK(0 == pthread_setaffinity_np(thread,sizeof(cpu_set_t),&cpuset));
    return OK;

error:
    return ERROR;
} /* threadable::thread_core_lock() */
