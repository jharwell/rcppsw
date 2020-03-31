/**
 * \file rcppsw.hpp
 *
 * \copyright 2019 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_RCPPSW_HPP_
#define INCLUDE_RCPPSW_RCPPSW_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/common/common.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
/**
 * \defgroup rcppsw rcppsw
 * \brief The root namespace for RCPPSW.
 * @{
 *
 * It is better to define the namespace aliases exported by RCPPSW here, rather
 * than having them be multiply defined in different downstream projects (DRY
 * FTW!).
 *
 * Convention: Namespace aliases from RCPPSW all start with \c 'r', and the
 * first letter of all nested namespaces except the innermost one should be
 * included before the innermost. For example, rcppsw::patterns::visitor should
 * have the \c 'r' from \c 'rcppsw' and the \c 'p' from \c 'patterns' before the
 * target namespace \c 'visitor'.
 *
 * \defgroup metrics metrics
 * \brief Metric interfaces and collector base classes.
 *
 * \defgroup algorithm algorithm
 * \brief Various useful algorithms (duh).
 *
 * @{
 *
 * \defgroup clustering clustering
 * \ingroup algorithm
 *
 * \brief Classes implementing clustering algorithms such as kmeans, nearest
 * neighbor entropy.
 * @}
 *
 *
 * \defgroup patterns patterns
 * \brief Software design patterns.
 *
 * @{
 *
 * \defgroup fsm fsm
 * \brief Finite State Machine (FSM) design pattern.
 *
 * \defgroup visitor visitor
 * \brief Visitor design pattern.
 *
 * \defgroup factory factory
 * \brief Factory design pattern.
 *
 * \defgroup prototype prototype
 * \brief Prototype design pattern.
 *
 * \defgroup decorator decorator
 * \brief Decorator design pattern.
 *
 * @}
 *
 * \defgroup math math
 * \brief Pure mathematical representations of things (duh).
 *
 * \defgroup er er
 * \brief Namespace containing wrapper around log4cxx, providing the logging
 * mechanism used by RCPPSW.
 *
 * \defgroup control control
 * \brief Classes implementing mathematical constructs that can be classified
 * under control theory, such as waveforms and PID loops.
 *
 * \defgroup ta ta
 * \brief Task allocation using task decomposition graphs, with limited
 * supported for other relational task paradigms.
 *
 * \defgroup config config
 * \brief Initialization configuration scaffolding, XML based and otherwise.
 *
 * \defgroup mpl mpl
 * \brief Razor thin wrapper around boost::mpl/specialization of a few things in
 * it I have found useful.
 *
 * \defgroup types types
 * \brief Various STRONG types (i.e. integer types wrapped in classes to carry
 * more meaning through their name).
 *
 * \defgroup utils utils
 * \brief Miscellaneous random things that don't fit anywhere else.
 *
 * \defgroup ds ds
 * \brief Data structures.
 */

/**
 * \namespace rcppsw
 * \brief The root namespace of the RCPPSW library.
 */
namespace rcppsw {

/**
 * \namespace metrics
 * \ingroup metrics
 *
 * \brief Container namespace for metric interfaces and the collectors for them.
 */
namespace metrics {}

/**
 * \namespace patterns
 * \ingroup patterns
 *
 * \brief Container namespace for specific design pattern templates and
 * interfaces.
 */
namespace patterns {

/**
 *
 * \namespace fsm
 * \ingroup fsm
 *
 * \brief Container namespace for classes implementing variants of the Finite
 * State Machine (FSM) design pattern.
 */
namespace fsm {}

/**
 * \namespace visitor
 * \ingroup visitor
 *
 * \brief Container namespace for classes implementating variants of the visitor
 * design pattern (including a polymorphic visitor).
 */
namespace visitor {}

/**
 *
 * \namespace factory
 * \ingroup factory
 *
 * \brief Container namespace for classes implementing variants of the factory
 * design pattern: sharing/factories, multifactory.
 */
namespace factory {}

/**
 * \namespace prototype
 * \ingroup prototype
 *
 * \brief Container namespace for classes implementing variants of the prototype
 * design pattern (or things that are of that flavor...).
 */
namespace prototype {}

/**
 * \namespace decorator
 * \ingroup decorator
 *
 * \brief Container namespace classes implementing variants of the decorator
 * design pattern.
 */
namespace decorator {}

namespace pimpl {}
} /* namespace patterns */

/** @} */

/**
 * \namespace math
 * \ingroup math
 *
 * \brief Container namespace for pure mathematical classes such as vectors,
 * ranges, sigmoids, etc.
*/
namespace math {}

/**
 * \namespace algorithm
 * \ingroup algorithm
 */
namespace algorithm {

/**
 * \namespace clustering
 * \ingroup clustering
 */
namespace clustering {}
} /* namespace algorithm */

/** @} */

/**
 * \namespace er
 * \ingroup er
 */
namespace er {}

/**
 * \namespace control
 * \ingroup control
 */
namespace control {}

/**
 * \namespace config
 * \ingroup config
 */
namespace config {}

/**
 * \namespace ds
 * \ingroup ds
 */
namespace ds {}

/**
 * \namespace mpl
 * \ingroup mpl
 */
namespace mpl {}

/**
 * \namespace types
 * \ingroup types
 */
namespace types {}

/**
 * \namespace utils
 * \ingroup utils
 */
namespace utils {}

} /* namespace rcppsw */
/** @} rcppsw */

namespace rmetrics = rcppsw::metrics;
namespace rtypes = rcppsw::types;
namespace rmath = rcppsw::math;
namespace ralg = rcppsw::algorithm;
namespace rutils = rcppsw::utils;
namespace rer = rcppsw::er;
namespace rct = rcppsw::control;
namespace rconfig = rcppsw::config;
namespace rds = rcppsw::ds;
namespace rmpl = rcppsw::mpl;
namespace rcontrol = rcppsw::control;

namespace ralgorithm = rcppsw::algorithm;
namespace raclustering = ralgorithm::clustering;

namespace rpfsm = rcppsw::patterns::fsm;
namespace rpvisitor = rcppsw::patterns::visitor;
namespace rpfactory = rcppsw::patterns::factory;
namespace rpprototype = rcppsw::patterns::prototype;
namespace rpdecorator = rcppsw::patterns::decorator;
namespace rppimpl = rcppsw::patterns::pimpl;

#endif /* INCLUDE_RCPPSW_RCPPSW_HPP_ */
