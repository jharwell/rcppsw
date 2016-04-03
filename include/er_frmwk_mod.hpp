/*******************************************************************************
 * Name            : er_frmwk_mod.hpp
 * Project         : paradyn
 * Module          : erf
 * Description     : Header file for Event Reporting Framework Module class
 * Creation Date   : Wed Jun 24 14:15:34 2015
 * Original Author : jharwell
 *
 ******************************************************************************/

#ifndef _ER_FRMWK_MOD_HPP_
#define _ER_FRMWK_MOD_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <string>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

#include "altypes.h"

/*******************************************************************************
 * SVN Version
 ******************************************************************************/
static char __unused svnid_er_frmwk_mod_hpp_[] =
  "$Id:$ SwRI";

/*******************************************************************************
 * Namespace Definitions
 ******************************************************************************/

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class erf_lvl
    {
    public:
        enum value {
            off,
            err,
            warn,
            nom,
            diag,
            ver
        };
    };

    class er_frmwk_mod
    {
    public:

        /* data members */
        boost::uuids::uuid id;
        std::string name;

        /* member functions */
        er_frmwk_mod(
            const boost::uuids::uuid& id_,
            const erf_lvl::value& loglvl_,
            const erf_lvl::value& dbglvl_,
            const std::string& name_);
        er_frmwk_mod(
            const boost::uuids::uuid& id_,
            const std::string& name);
        void set_loglvl(
            const erf_lvl::value& lvl);
        void set_dbglvl(
            const erf_lvl::value& lvl);
        void logmsg(
            const std::string& msg,
            const erf_lvl::value& lvl,
            std::ofstream& file) const;
        void dbgmsg(
            const std::string& msg,
            const erf_lvl::value& lvl) const;
        bool operator==(
            const er_frmwk_mod& rhs);
    private:
        erf_lvl::value loglvl;
        erf_lvl::value dbglvl;
    };

/*******************************************************************************
 * Operator Definitions
 ******************************************************************************/
std::ostream& operator<<(
    std::ostream& os,
    const er_frmwk_mod& mod);

#endif /*  _ER_FRMWK_MOD_HPP_  */
