/**
 * \file base_parser.hpp
 *
 * \copyright 2017 John Harwell, All rights reserved.
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

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, config);
struct base_config;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class base_parser
 * \ingroup config xml
 *
 * \brief Interface specifying functionality for parsing parameters into a \ref
 * base_config derived parameter structure.
 */
class base_parser {
 public:
  base_parser(void) = default;
  virtual ~base_parser(void) = default;

  /**
   * \brief Validate the range, value, etc. of all parsed parameters. As such,
   * don't call this unless the parameters have already been parsed.
   *
   * \return \c TRUE if all parameters are valid, \c FALSE otherwise.
   */
  virtual bool validate(void) const { return true; }

  /**
   * \brief Get the results of parameter parse. This is the front end of the
   * non-virtual interface to getting the results of a parameter parse, so that
   * covariance with smart pointer return types will work.
   */
  template <typename T>
  RCPPSW_COLD const T* config_get(void) const {
    static_assert(std::is_base_of<base_config, T>::value,
                  "Config type to get must be derived from base_config!");
    return static_cast<const T*>(config_get_impl());
  }

  RCPPSW_COLD bool is_parsed(void) const {
    return (nullptr != config_get_impl()) ? true : false;
  }

 protected:
  /**
   * \brief Implementation (back end) of how to get the results of a parameter
   * parse using covariance. This is to make parameter parsing easy when you
   * only have a handle on THIS class, even if the object is actually a derived
   * class parameter parser.
   */
  virtual const base_config* config_get_impl(void) const = 0;
};

NS_END(config, rcppsw);
