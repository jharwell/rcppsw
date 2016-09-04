/*******************************************************************************
 * Name            : er_frmwk.hpp
 * Project         : rcppsw
 * Module          : erf
 * Description     : Header file for Event Reporting Framework (ERF) base class
 * Creation Date   : Wed Jun 24 14:42:12 2015
 * Original Author : jharwell
 *
 ******************************************************************************/

#ifndef _ER_FRMWK_HPP
#define _ER_FRMWK_HPP

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "altypes.h"
#include "dbg.h"
#include "er_frmwk_mod.hpp"
#include "shared_queue.hpp"
#include "threadable.hpp"

#include <vector>
#include <fstream>
#include <thread>
#include <mutex>

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
namespace rcppsw {

    class er_frmwk : public threadable
    {
    public:
        struct erf_msg {
            boost::uuids::uuid id;
            erf_lvl::value lvl;
            std::string str;
            explicit erf_msg(
                const boost::uuids::uuid& id_,
                const erf_lvl::value& lvl_,
                const std::string& str_) :
                id(id_),
                lvl(lvl_),
                str(str_) {}
        };

        enum {
            queue_size = 100,
            max_modules = 10
        };
        /* data members */
        char hostname[32];

        /* constructors */
        er_frmwk(
            const std::string& logfile_fname_="logfile",
            const erf_lvl::value& dbglvl_= erf_lvl::nom,
            const erf_lvl::value& loglvl_= erf_lvl::nom);

        /* destructor */
        ~er_frmwk(void);

        /* member functions */
        void self_dbg_en(void) {
            insmod(erf_id,"ERF");
            mod_dbglvl(erf_id,erf_lvl::nom);
        }
        status_t insmod(
            const boost::uuids::uuid& mod_id,
            const erf_lvl::value& loglvl_,
            const erf_lvl::value& dbglvl_,
            const std::string& mod_name);
        status_t insmod(
            const boost::uuids::uuid& id,
            const std::string& name);
        status_t rmmod(
            const boost::uuids::uuid& id);
        status_t mod_dbglvl(
            const boost::uuids::uuid& id,
            const erf_lvl::value& lvl);
        status_t mod_loglvl(
            const boost::uuids::uuid& id,
            const erf_lvl::value& lvl);
        int flush(void);
        status_t recv(
            const boost::uuids::uuid& id,
            const erf_lvl::value& lvl,
            const std::string& str);
        boost::uuids::uuid idgen(void) { return gen(); }
        void thread_main(void);
        erf_lvl::value loglvl(void) { return loglvl_dflt; }
        erf_lvl::value dbglvl(void) { return dbglvl_dflt; }
        void loglvl(
            const erf_lvl::value& lvl) { loglvl_dflt = lvl; }
        void dbglvl(
            const erf_lvl::value& lvl) { dbglvl_dflt = lvl; }
        void report_msg(
            const erf_msg& msg);

    private:

        /* member functions */

        /* data members */
        std::vector<er_frmwk_mod> modules;
        shared_queue<erf_msg> queue;
        std::string logfile_fname;
        std::ofstream _logfile;
        erf_lvl::value loglvl_dflt;
        erf_lvl::value dbglvl_dflt;
        boost::uuids::random_generator gen;
        boost::uuids::uuid erf_id;
    };
} /* namespace rcppsw */

/*******************************************************************************
 * Macros
 ******************************************************************************/
/*
 * Reporting events. This needs to be a macro, instead of a function call so
 * I can get the line # and function from the preprocessor/compiler.
 */
#define er_report(lvl,msg, ...) {                                          \
    char _str[1000];                                                    \
    sprintf(_str,"%s:%d:%s: " msg "\n",__FILE__,__LINE__,__FUNCTION__, ##__VA_ARGS__); \
    rcppsw::er_frmwk::erf_msg _msg(erf_id,lvl,std::string(_str));       \
    erf_handle.report_msg(_msg);                                        \
    }

/*
 * Like report, but only reports errors and goes to the error/bailout section
 * of a function only if a condition is false.
 */
#define er_check(cond,msg,...) {            \
        if(!(cond)) {                                                   \
            report(erf_lvl::err,msg,##__VA_ARGS__); \
            goto error;                                                 \
        }                                                               \
    }
#define er_sentinel(msg,...) {                     \
        report(erf_lvl::err,msg,##__VA_ARGS__);     \
        goto error;                             \
    }

#define er_assert(cond,msg,...)  if(!(cond)) {                           \
        report(erf_lvl::err, msg, ##__VA_ARGS__);                       \
        assert(0);                                                      \
    }

/*
 * OK to undefine, because if this file is included I want the C++ version, not
 * the C version defined in rcsw.
 */
#if defined(check_ptr)
#undef check_ptr
#endif
#define check_ptr(ptr) if (nullptr == (ptr)) {  \
        report(erf_lvl::err, "ERROR: " #ptr " is NULL"); goto error;}   \

#endif /*  _ER_FRMWK_HPP  */
