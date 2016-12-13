/*******************************************************************************
 * Name            : erf_client.hpp
 * Project         : rcppsw
 * Module          : rcppsw
 * Description     : Interface for classes that want to be able to use the ERF
 * Creation Date   : Sat Apr  9 19:13:05 2016
 * Original Author : jharwell
 *
 ******************************************************************************/

#ifndef ERF_CLIENT_HPP_
#define ERF_CLIENT_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "er_frmwk.hpp"

/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
namespace rcppsw {
    class erf_client
    {
    public:
        /* constructors */
        erf_client(
            er_frmwk& erf_handle_) :
            erf_handle(erf_handle_),
            erf_id(erf_handle.idgen()) {}

        /* destructor */
        virtual ~erf_client(void) {}

        /* member functions */

        /* operators */

    protected:
        er_frmwk& erf_handle;
        boost::uuids::uuid erf_id;

    private:
        /* data members */

        /* member functions */

        /* operators */
    };

} /* namespace rcppsw */
/*******************************************************************************
 * Operater Definitions
 ******************************************************************************/

#endif /* ERF_CLIENT_HPP_ */
