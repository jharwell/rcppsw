/*******************************************************************************
 * Name            : er_frmwk_base.cpp
 * Project         : rcppsw
 * Module          : erf
 * Description     : Event Reporting Framework (ERF)
 * Creation Date   : Wed Jun 24 15:21:29 2015
 * Original Author : jharwell
 *
 ******************************************************************************/

#define _ER_FRMWK_BASE_CPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#define BOOST_NO_CXX11_SCOPED_ENUMS
#include <boost/filesystem.hpp>
#include <algorithm>
#include "utils.h"
#include "er_frmwk.hpp"

/*******************************************************************************
 * Namespace Definitions
 ******************************************************************************/
using namespace rcppsw;

/*******************************************************************************
 * Macros
 ******************************************************************************/
/*
 * Reporting events. This needs to be a macro, instead of a function call so
 * I can get the line # and function from the preprocessor/compiler. For
 * internal use inside ERF only.
 */
#define report_internal(lvl,msg, ...) {                                 \
        char _str[6000];                                                \
        struct timespec _curr_time;                                     \
        clock_gettime(CLOCK_REALTIME,&_curr_time);                      \
        sprintf(_str,"[%s:%lu.%lu]:%s:%d:%s: " msg "\n",                \
                hostname, _curr_time.tv_sec,_curr_time.tv_nsec,         \
                __FILE__,__LINE__,__FUNCTION__, ##__VA_ARGS__);         \
        er_frmwk::erf_msg _msg(erf_id,lvl,std::string(_str));           \
        report_msg(_msg);                                               \
    }

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/
er_frmwk::er_frmwk(
    const std::string& logfile_fname_,
    const erf_lvl::value& dbglvl_,
    const erf_lvl::value& loglvl_) :
    modules(),
    queue(),
    logfile_fname(logfile_fname_),
    _logfile(),
    loglvl_dflt(loglvl_),
    dbglvl_dflt(dbglvl_),
    gen(),
    erf_id(idgen())
{
    /* get hostname */
    gethostname(hostname,32);

    if (boost::filesystem::exists(logfile_fname)) {
        boost::filesystem::remove(logfile_fname);
    }
    _logfile.open(logfile_fname.c_str());
} /* er_frmwk::er_frmwk() */

er_frmwk::~er_frmwk(void) {
    _logfile.close();
} /* er_frmwk::~er_frmwk() */

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
/**
 * insmod() - Install a new reporting module
 *
 * RETURN:
 *     status_t - OK if successful, ERROR otherwise
 *
 **/
status_t er_frmwk::insmod(
    const boost::uuids::uuid& mod_id,
    const erf_lvl::value& loglvl_,
    const erf_lvl::value& dbglvl_,
    const std::string& mod_name)
{
    er_frmwk_mod mod(mod_id,loglvl_,dbglvl_,mod_name);

    /* make sure module not already present */
    check(modules.end() == std::find(modules.begin(), modules.end(),mod));
    modules.push_back(mod);
    return OK;

error:
    report_internal(erf_lvl::err,"Failed to install module %s: module exists",
                    mod_name.c_str());
    return ERROR;
} /* insmod() */

/**
 * insmod() - Install a new reporting module, with inherited initial levels
 *
 * RETURN:
 *     status_t - OK if successful, ERROR otherwise
 *
 **/
status_t er_frmwk::insmod(
    const boost::uuids::uuid& id,
    const std::string& name)
{
    return insmod(id,loglvl_dflt,dbglvl_dflt,name);
} /* insmod() */

/**
 * er_frmwk::recv() - Add a msg to the queue
 *
 * RETURN:
 *     status_t - OK if successful, ERROR otherwise
 *
 **/
status_t er_frmwk::recv(
    const boost::uuids::uuid& mod_id,
    const erf_lvl::value& lvl,
    const std::string& str)
{
    queue.enq(erf_msg(mod_id,lvl,str));
    return OK;
} /* er_frmwk::recv() */

/**
 * er_frmwk::report_msg() - Report a msg
 *
 * RETURN:
 *     N/A
 *
 **/

void er_frmwk::report_msg(
    const erf_msg& msg)
{
    er_frmwk_mod tmp(msg.id,"tmp");
    std::vector<er_frmwk_mod>::const_iterator iter = std::find(modules.begin(), modules.end(),tmp);

    if (iter != modules.end()) {
        iter->logmsg(msg.str,msg.lvl,_logfile);
        iter->dbgmsg(msg.str,msg.lvl);
    }
} /* er_frmwk::report_msg() */

/**
 * er_frmwk::flush() - Flush all msgs in the queue to stdout/logfile
 *
 * RETURN:
 *     int - How many msgs were flushed
 *
 **/
int er_frmwk::flush(void)
{
    int count = 0;
    while (queue.size() > 0) {
        erf_msg next = queue.dq();
        er_frmwk::report_msg(next);
        count ++;
    } /* while() */
    return count;
} /* er_frmwk::flush() */

/**
 * er_frmwk::mod_dbglvl() - Set debugging lvl for a module
 *
 * RETURN:
 *     status_t - OK if successful, ERROR otherwise
 *
 **/
status_t er_frmwk::mod_dbglvl(
    const boost::uuids::uuid& id,
    const erf_lvl::value& lvl)
{
    er_frmwk_mod mod(id,erf_lvl::nom,erf_lvl::nom,"tmp");

    /* make sure module is already present */
    std::vector<er_frmwk_mod>::iterator iter = std::find(modules.begin(),
                                                             modules.end(),
                                                             mod);
    check(iter != modules.end());
    iter->set_dbglvl(lvl);

    report_internal(erf_lvl::ver,"Successfully updated dbglvl for module %s",
           iter->name.c_str());
    return OK;

error:
    report_internal(erf_lvl::err,"Failed to update dbglvl for module %s: no such module",
           iter->name.c_str());
    return ERROR;
} /* er_frmwk::mod_dbglvl() */

/**
 * er_frmwk::mod_loglvl() - Set logging lvl for a module
 *
 * RETURN:
 *     status_t - OK if successful, ERROR otherwise
 *
 **/
status_t er_frmwk::mod_loglvl(
    const boost::uuids::uuid& id,
    const erf_lvl::value& lvl)
{
    er_frmwk_mod mod(id,erf_lvl::nom,erf_lvl::nom,"tmp");

    /* make sure module is already present */
    std::vector<er_frmwk_mod>::iterator iter = std::find(modules.begin(), modules.end(),mod);
    check(iter != modules.end());
    iter->set_loglvl(lvl);

    report_internal(erf_lvl::ver,"Successfully updated loglvl for module %s",
           iter->name.c_str());
    return OK;

error:
    report_internal(erf_lvl::err,"Failed to update loglvl for module %s: no such module",
           iter->name.c_str());
    return ERROR;
} /* er_frmwk::mod_loglvl() */

/**
 * er_frmwk::thread_main() - Main ERF thread for the master
 *
 * RETURN:
 *     N/A
 *
 **/
void er_frmwk::thread_main(void)
{
    report_internal(erf_lvl::nom,"Start");
    while (!terminated()) {
        while (0 == queue.size()) sleep(1);
        erf_msg msg = queue.dq();
        report_msg(msg);
    } /* while() */
    report_internal(erf_lvl::nom,"Exit");

    /* make sure all events remaining in queue are reported */
    while (queue.size()) {
        erf_msg msg = queue.dq();
        report_msg(msg);
    }
} /* er_frmwk::thread_main() */

#undef _ER_FRMWK_CPP
