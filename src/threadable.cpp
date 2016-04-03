/*******************************************************************************
 * Name            : threadable.cpp
 * Project         : paradyn
 * Module          : common
 * Description     : Threadable base class
 * Creation Date   : Mon Nov 16 16:04:20 2015
 * Original Author : jharwell
 *
 ******************************************************************************/

#ifndef _THREADABLE_CPP_
#define _THREADABLE_CPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "threadable.hpp"
#include "utils.h"
#include "dbg.h"

/*******************************************************************************
 * SVN Version
 ******************************************************************************/
static char __unused svnid_threadable_cpp_[] =
  "$Id:$ SwRI";

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
/*******************************************************************************
 * Constant Definitions
 ******************************************************************************/

/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/

/*******************************************************************************
 * Global Variables
 ******************************************************************************/

/*******************************************************************************
 * Forward Declarations
 ******************************************************************************/

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/

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
        thread_lock_to_core(internal_thread.native_handle(),core);
    }
} /* threadable::start() */

/**
 * threadable::thread_lock_to_core() - Lock a thread to a core
 *
 * RETURN:
 *     status_t - OK if successful, ERROR otherwise
 *
 **/
status_t threadable::thread_lock_to_core(
    pthread_t thread,
    int core)
{
    cpu_set_t cpuset;

    CPU_ZERO(&cpuset);
    CPU_SET(core,&cpuset);
    check(0 == pthread_setaffinity_np(thread,sizeof(cpu_set_t),&cpuset));
    return OK;

error:
    return ERROR;
} /* threadable::thread_lock_to_core() */


#endif /*  _THREADABLE_CPP_  */
