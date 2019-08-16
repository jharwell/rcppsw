/**
 * @file rcppsw.hpp
 *
 * @copyright 2019 John Harwell, All rights reserved.
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
namespace rcppsw {

namespace metrics {}

namespace patterns {
namespace fsm {}
namespace visitor {}
namespace factory {}
namespace prototype {}
namespace decorator {}
} /* namespace patterns */

namespace math {}
namespace ta {}
namespace algorithm {
namespace clustering {}
} /* namespace algorithm */

namespace utils {}
namespace er {}
namespace control {}
namespace config {}
namespace ds {}
namespace mpl {}

namespace types {}
} /* namespace rcppsw */

/*
 * It is better to define the namespace aliases exported by RCPPSW here, rather
 * than having them be multiply defined in different downstream projects (DRY
 * FTW!).
 *
 * Convention: Namespace aliases from RCPPSW all start with 'r', and the first
 * letter of all nested namespaces except the innermost one should be included
 * before the innermost. For example, rcppsw::patterns::visitor should have the
 * 'r' from 'rcppsw' and the 'p' from 'patterns' before the target namespace
 * 'visitor'.
 */
namespace rmetrics = rcppsw::metrics;
namespace rtypes = rcppsw::types;
namespace rmath = rcppsw::math;
namespace rta = rcppsw::ta;
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

#endif /* INCLUDE_RCPPSW_RCPPSW_HPP_ */
