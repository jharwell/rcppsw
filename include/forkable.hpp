/*******************************************************************************
 * Name            : forkable.hpp
 * Project         : rcppsw
 * Module          : utils
 * Description     : Common threading functionality
 * Creation Date   : Sat Jul 18 14:33:49 2015
 * Original Author : jharwell
 *
 ******************************************************************************/

#ifndef FORKABLE_HPP_
#define FORKABLE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <thread>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>

/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
namespace rcppsw {
    class forkable
    {
    public:
        /* data members */

        /* member functions */
        forkable(void) : proc_run(false),
                         _pid(0) {}
        virtual ~forkable(void) {}
        pid_t pid(void) { return _pid; };
        virtual pid_t start(
            int core = -1);

        virtual pid_t start(
            const std::string& new_wd,
            int core = -1);

        virtual void term(void) { proc_run = false; }
        bool terminated(void) { return (false == proc_run); }
        virtual void proc_main(void) = 0;

    private:
        /* data members */
        bool proc_run;
        pid_t _pid;

        /* non-member functions */
        static void entry_point(
            void* this_p) { forkable *pt = static_cast<forkable*>(this_p); pt->proc_main(); }
        /* operators */
    };
}

/*******************************************************************************
 * Non-member Functions
 ******************************************************************************/
pid_t fork_exec(
    const std::vector<std::string>& cmd,
    const std::string& new_wd,
    bool stdout_sup,
    int * pipefd);
status_t proc_core_lock(
    int core);

#endif /* FORKABLE_HPP_ */
