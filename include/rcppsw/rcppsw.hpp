/**
 * \file rcppsw.hpp
 *
 * \copyright 2019 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/common/common.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
/**
 * It is better to define the namespace aliases exported by RCPPSW here, rather
 * than having them be multiply defined in different downstream projects (DRY
 * FTW!).
 *
 * Convention: Namespace aliases from RCPPSW all start with \c 'r', and the
 * first letter of all nested namespaces except the innermost one should be
 * included before the innermost. For example, rcppsw::patterns::visitor should
 * have the \c 'r' from \c 'rcppsw' and the \c 'p' from \c 'patterns' before the
 * target namespace \c 'visitor'.
 */

/**
 * \namespace rcppsw
 * \brief The root namespace of the RCPPSW library.
 */
namespace rcppsw {

/**
 * \brief Base metric interfaces and the collectors for them.
 */
namespace metrics {
namespace config {
namespace xml {}
}
}

/**
 * \brief Design pattern templates and interfaces.
 */
namespace patterns {

/**
 * \brief The Finite State Machine (FSM) design pattern: simple and
 * hierarchical variants.
 */
namespace fsm {}

/**
 * \brief Visitor design pattern variants: polymorphic, filtered, etc.
 */
namespace visitor {}

/**
 * \brief Factory design pattern: sharing/releasing, multifactory.
 */
namespace factory {}

/**
 * \brief Prototype design pattern interfaces and classes: clonable, caching
 * factory.
 */
namespace prototype {}

/**
 * \brief Decorator design pattern: pointer and member variants.
 */
namespace decorator {}

/**
 * \brief Interfaces for the singleton design pattern.
 */
namespace singleton {}

/**
 * \brief The PIMPL design pattern (the boost candidate did not work).
 */
namespace pimpl {}
} /* namespace patterns */

/**
 * \brief Pure mathematical classes such as vectors, ranges, sigmoids, etc.
*/
namespace math {}

/**
 * \brief Various algorithms: closest pair, max subarray, clustering.
 */
namespace algorithm {

/**
 * \brief Different clustering algorithms: kmeans, entropy.
 */
namespace clustering {}
} /* namespace algorithm */

/**
 * \brief The Event Reporting framework used in RCPPSW and its derived projects.
 */
namespace er {}

/**
 * \brief Control theory classes: periodic/aperiodic waveform generators, PID
 * loops, etc. and their configuration.
 */
namespace control {}

/**
 * \brief Base namespace for run-time configuration parsing and data
 * containers. Currently includes base class implementations for:
 *
 * - XML
 */
namespace config {}

/**
 * \brief Data structures: 2D/3D lattice grids, 2D/3D discretizing grids to
 * overlay onto continuous space, Poisson queue, rtree for 2D space,
 * heterogeneous stacked 2D grid, type map for using in C++ quasi-reflection.
 */
namespace ds {
/**
 * \brief Graph data structures: Heterogeneous 3D grid graph.
 */
namespace graph {}
namespace metrics {}
}

/**
 * \brief Meta programming namespace. Mainly a few aliases around things which
 * boost provides.
 */
namespace mpl {}

/**
 * \brief Common non-primitive types: timestep, UUID for types, etc. Mainly for
 * eliminating bugs caused by implicit conversions between primitive types which
 * do not elicit a compiler warning.
 */
namespace types {}

/**
 * \brief Various utility things which don't fit anywhere else: Base CLI parsing
 * class, file/line parsers, colors, enum utilities, string utilities.
 */
namespace utils {}

/**
 * \brief Multi-threaded variants of other classes: FSM, queue, vector,
 * threadable interface for daemon-esque classes, lockable interface.
 */
namespace multithread {}

/**
 * \brief Multi-process variants of other classes: queue. Forkable interface.
 */
namespace multiprocess {}

/**
 * \brief Abstraction Layer (AL) for types which can be compiled differently for
 * different targets.
 */
namespace al {}

/**
 * \brief Named types for spatial distance/range measurements and related
 * calculations.
 */
namespace spatial {}
} /* namespace rcppsw */

namespace rmetrics = rcppsw::metrics;
namespace rmconfig = rmetrics::config;
namespace rmcxml = rmconfig::xml;

namespace rtypes = rcppsw::types;
namespace rmath = rcppsw::math;
namespace ralg = rcppsw::algorithm;
namespace rutils = rcppsw::utils;
namespace rer = rcppsw::er;
namespace rct = rcppsw::control;
namespace rconfig = rcppsw::config;
namespace rmpl = rcppsw::mpl;
namespace rcontrol = rcppsw::control;
namespace rmultithread = rcppsw::multithread;

namespace ralgorithm = rcppsw::algorithm;
namespace raclustering = ralgorithm::clustering;

namespace rspatial = rcppsw::spatial;

namespace rds = rcppsw::ds;
namespace rdmetrics = rds::metrics;
namespace rdgraph = rds::graph;

namespace ral = rcppsw::al;

namespace rpfsm = rcppsw::patterns::fsm;
namespace rpvisitor = rcppsw::patterns::visitor;
namespace rpfactory = rcppsw::patterns::factory;
namespace rpprototype = rcppsw::patterns::prototype;
namespace rpdecorator = rcppsw::patterns::decorator;
namespace rppimpl = rcppsw::patterns::pimpl;
