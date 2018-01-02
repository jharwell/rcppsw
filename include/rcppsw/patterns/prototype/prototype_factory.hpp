/**
 * @file prototype_factory.hpp
 * @ingroup patterns prototype
 *
 * @copyright 2017 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_PATTERNS_PROTOTYPE_PROTOTYPE_FACTORY_HPP_
#define INCLUDE_RCPPSW_PATTERNS_PROTOTYPE_PROTOTYPE_FACTORY_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>

#include "rcppsw/patterns/factory/retaining_factory.hpp"
#include "rcppsw/patterns/prototype/clonable.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, patterns, prototype);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class prototype_factory
 *
 * @brief A \ref sharing_factory of \ref clonable objects.
 */
class prototype_factory : public factory::retaining_factory<clonable> {
 public:
  prototype_factory(void) {}
  virtual ~prototype_factory(void) {}

  std::unique_ptr<clonable> create(const std::string& name) {
    return retaining_factory::create(name)->clone();
  }
};

NS_END(rcppsw, patterns, prototype);

#endif /* INCLUDE_RCPPSW_PATTERNS_PROTOTYPE_PROTOTYPE_FACTORY_HPP_ */
