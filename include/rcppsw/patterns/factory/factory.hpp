/**
 * \file factory.hpp
 *
 * \copyright 2017 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/patterns/factory/base_factory.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace rcppsw::patterns::factory {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class releasing_factory
 * \ingroup patterns factory
 *
 * \brief Specialization of the \ref detail::base_factory class for releasing
 * ownership of created objects via std::unique_ptr.
 */
template<typename TBase, typename TKeyType, typename...Args>
class releasing_factory : public detail::base_factory<detail::factory_releasing_type,
                                                      std::unique_ptr,
                                                      TBase,
                                                      TKeyType,
                                                      Args...> {
 public:
  ~releasing_factory(void) override = default;
};


/**
 * \class sharing_factory
 * \ingroup patterns factory
 *
 * \brief Specialization of the \ref detail::base_factory class for
 * sharing ownership of created objects via std::shared_ptr.
 */
template<typename TBase, typename TKeyType, typename...Args>
class sharing_factory : public detail::base_factory<detail::factory_sharing_type,
                                                    std::shared_ptr,
                                                    TBase,
                                                    TKeyType,
                                                    Args...> {
 public:
  ~sharing_factory(void) override = default;
};

} /* namespace rcppsw::patterns::factory */

