/**
 * \file rng_parser.hpp
 *
 * \copyright 2018 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include <memory>

#include "rcppsw/rcppsw.hpp"
#include "rcppsw/math/config/rng_config.hpp"
#include "rcppsw/config/xml/xml_config_parser.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace rcppsw::math::config::xml {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class rng_parser
 * \ingroup math config xml
 *
 * \brief Parses XML configuration relating to RNG.
 */
class rng_parser final : public rer::client<rng_parser>,
                         public rconfig::xml::xml_config_parser {
 public:
  using config_type = rng_config;

  rng_parser(void) : ER_CLIENT_INIT() {}

  /**
   * \brief The root tag that all rng configuration values should lie under in
   * the XML tree.
   */
  static inline const std::string kXMLRoot = "rng";

  void parse(const ticpp::Element& node) override RCPPSW_COLD;

  RCPPSW_COLD std::string xml_root(void) const override { return kXMLRoot; }

 private:
  RCPPSW_COLD rcppsw::config::base_config* config_get_impl(void) const override {
    return m_config.get();
  }

  /* clang-format off */
  std::unique_ptr<rng_config> m_config{nullptr};
  /* clang-format on */
};

} /* namespace rcppsw::math::xml, config */

