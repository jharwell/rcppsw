/**
 * \file output_mode.hpp
 *
 * \copyright 2020 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, metrics);

/*******************************************************************************
 * Type Definitions
 ******************************************************************************/
/**
 * \brief Defines the behavior when metrics are written out to the filesystem.
 */
enum class output_mode {
  /**
   * \brief Metrics are not written out ever. Like seriously ever.
   */
  ekNONE = 0,

  /**
   * \brief Each time metrics are written out, they are appended to the same
   * file. This is suitable for metric collectors that output data for a set of
   * one dimensional signals. Only valid for \ref fil_sink based sinks.
   */
  ekAPPEND = 1 << 0,

  /**
   * \brief Each time metrics are written out, the output file is truncated and
   * the header re-written with the current data. Suitable for metric collectors
   * that output a single two dimensional signal as a cumulative average (that
   * is, each time the signal is written out, it is a cumulative average of that
   * signal up to that point in time). Only valid for \ref file_sink based
   * sinks.
   */
  ekTRUNCATE = 1 << 1,

  /**
   * \brief Each time metrics are written out, a new output file is created with
   * the header and the current data, with the current timestep being added to
   * the name stem for the output file in order to guarantee uniqueness of
   * output files. Suitable for metric collectors for signals of any
   * dimensionality where post-processing to create a set of images/movie
   * illustrating how the signal changes over time is desired. Only valid for
   * \ref file_sink based sinks.
   */
  ekCREATE = 1 << 2,

  /**
   * \brief Each time metrics are written out, they are sent directly to the
   * network socket/stream/whatever. Only valid for \ref network_sink based
   * sinks.
   */

  ekSTREAM = 1 << 3
};

NS_END(metrics, rcppsw);
