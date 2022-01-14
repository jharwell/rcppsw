/**
 * \file layout.cpp
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

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/er/layout.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
/* I really hate it when "instantiate class" macros require this... */
using namespace log4cxx;

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/
colored_pattern_layout::colored_pattern_layout() : log4cxx::PatternLayout() {}

colored_pattern_layout::colored_pattern_layout(const LogString &s)
    : log4cxx::PatternLayout(s) {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
IMPLEMENT_LOG4CXX_OBJECT(colored_pattern_layout);

void colored_pattern_layout::format(LogString &output,
                                    const spi::LoggingEventPtr
                                    &event, helpers::Pool &pool) const {
  log4cxx::LogString tmp;
  log4cxx::PatternLayout::format(tmp, event, pool);
  log4cxx::LevelPtr lvl = event->getLevel();
  switch (lvl->toInt()) {
    case log4cxx::Level::FATAL_INT:
      output.append("\u001b[1m\u001b[1m\u001b[0;31m"); /* bold red */
      break;
    case log4cxx::Level::ERROR_INT:
      output.append("\u001b[1m\u001b[0;31m"); /* red FG */
      break;
    case log4cxx::Level::WARN_INT:
      output.append("\u001b[1m\u001b[0;33m"); /* Yellow FG */
      break;
    case log4cxx::Level::INFO_INT:
      output.append("\u001b[1m"); /* Bright */
      break;
    case log4cxx::Level::DEBUG_INT:
      output.append("\u001b[0;32m"); /* Green FG */
      break;
    case log4cxx::Level::TRACE_INT:
      output.append("\u001b[0;34m"); /* Blue FG */
      break;
    default:
      break;
  }
  output.append(tmp);
  output.append("\u001b[m");
}
