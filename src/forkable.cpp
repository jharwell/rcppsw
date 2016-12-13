/*******************************************************************************
 * Name            : forkable.cpp
 * Project         : rcppsw
 * Module          : utils
 * Description     : Common fork()/exec() wrappers
 * Creation Date   : Sun Aug 16 10:30:07 2015
 * Original Author : jharwell
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "forkable.hpp"
#include <vector>
#include <string>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "er_frmwk.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
using namespace rcppsw;

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
/**
 * forkable::start() - Start a process
 *
 * RETURN:
 *     pid_t - PID of child process
 *
 **/
pid_t forkable::start(
    int core)
{
    proc_run_ = true;
    pid_ = fork();
    if (pid_ == 0) {
        if (-1 != core) {
            proc_socket_lock(core);
        }
        entry_point(this);
    }
    return pid_;
} /* forkable::start() */

/**
 * forkable::start() - Change cwd and Start a process
 *
 * RETURN:
 *     pid_t - PID of child process
 *
 **/
pid_t forkable::start(
    const std::string& new_wd,
    int core)
{
    proc_run_ = true;
    pid_ = fork();
    if (pid_ == 0) {
        if (0 != chdir(new_wd.c_str())) {

            return -1;
        }
        if (-1 != core) {
            proc_socket_lock(core);
        }
        entry_point(this);
    }
    return pid_;
} /* forkable::start() */

/*******************************************************************************
 * Non-Member Functions
 ******************************************************************************/
/**
 * proc_socket_lock() - Lock a process to a cpu socket.
 *
 * RETURN:
 *     OK if successful, ERROR otherwise
 *
 **/
status_t proc_socket_lock(
                       int socket)
{
    cpu_set_t cpuset;
    char buffer[50];
    char* line;
    int n_sockets,cores_per_socket,n_cpus;

    CPU_ZERO(&cpuset);
    FILE* f = popen("lscpu | grep Socket|awk '{print $2}'","r");
    check_ptr(f);

    line = fgets(buffer,sizeof(buffer),f);
    check_ptr(line);
    pclose(f);
    n_cpus = static_cast<int>(std::thread::hardware_concurrency());
    n_sockets = std::stoi(line);
    cores_per_socket = n_cpus/n_sockets;

    for (int i = socket*cores_per_socket; i < (socket+1)*cores_per_socket; ++i) {
      CPU_SET(i,&cpuset);
    } /* for(i..) */

    check(0 == sched_setaffinity(0,sizeof(cpu_set_t),&cpuset));
    return OK;

error:
    return ERROR;
} /* proc_socket_lock() */

/**
 * fork_exec() - Fork(), exec(), returning pid of child in parent
 *
 * RETURN:
 *     pid_t - pid of child
 *
 **/
pid_t fork_exec(
    const std::vector<std::string>& cmd,
    const std::string& new_wd,
    bool stdout_sup,
    int* pipefd)
{
    pid_t pid = fork();
    if (0 == pid) {
        /* change to the working directory before exec()ing if requested */
        if ("" != new_wd) {
            if (0 != chdir(new_wd.c_str())) {
                return ERROR;
            }
        }

        /* suppress stdout */
        if (stdout_sup) {
            int fd = open("/dev/null",O_WRONLY);
            dup2(fd,1);
        }

        /* the child will read data on stdin from the parent */
        if (NULL != pipefd) {
            dup2(pipefd[0],STDIN_FILENO);
        }
        char *argv[cmd.size() + 1];
        memset(argv,0,sizeof(argv));
        unsigned i;
        for (i = 0; i < cmd.size(); ++i) {
            argv[i] = const_cast<char*>(cmd[i].c_str());
        } /* for() */
        argv[i] = NULL;
        execv(argv[0],argv);
        perror(NULL);
        assert(0); /* execv() should never return */
    } else {
        return pid;
    }
} /* fork_exec() */
