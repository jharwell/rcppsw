/**
 * \file layout.hpp
 *
 * \copyright 2021 John Harwell, All rights reserved.
 *
 * This file is part of RCPPSW.
 *
 * RCPPSW is free software: you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 *
 * RCPPSW is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 * A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * RCPPSW.  If not, see <http://www.gnu.org/licenses/
 */

#ifndef INCLUDE_RCPPSW_ER_LAYOUT_HPP_
#define INCLUDE_RCPPSW_ER_LAYOUT_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <log4cxx/helpers/pool.h>
#include <log4cxx/patternlayout.h>

#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace log4cxx {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class LOG4CXX_EXPORT colored_pattern_layout : public ::log4cxx::PatternLayout {
public:
    DECLARE_LOG4CXX_OBJECT(colored_pattern_layout)
    BEGIN_LOG4CXX_CAST_MAP()
        LOG4CXX_CAST_ENTRY(colored_pattern_layout)
        LOG4CXX_CAST_ENTRY_CHAIN(Layout)
    END_LOG4CXX_CAST_MAP()

    colored_pattern_layout();
    colored_pattern_layout(const log4cxx::LogString &s);
    void format(log4cxx::LogString &output,
                const log4cxx::spi::LoggingEventPtr &event,
                log4cxx::helpers::Pool &pool) const override;
};
LOG4CXX_PTR_DEF(colored_pattern_layout);
} /* namespace log4cxx */

#endif /* INCLUDE_RCPPSW_ER_LAYOUT_HPP_ */
