/*******************************************************************************
 * Name            : factor_node.hpp
 * Project         : rcppsw
 * Module          : bayes
 * Description     : Class for factor nodes in a Bayesian network
 * Creation Date   : 02/13/17
 * Copyright       : Copyright 2017 John Harwell, All rights reserved
 *
 ******************************************************************************/

#ifndef INCLUDE_RCPPSW_BAYES_FACTOR_NODE_HPP_
#define INCLUDE_RCPPSW_BAYES_FACTOR_NODE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/bayes/node.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace rcppsw {
namespace bayes {

/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class factor_node: public node {
 public:
  /* constructors */
  factor_node(const std::string& name, const boolean_distribution& dist,
              er_server* const handle): node(name, handle), name_(name),
                                        dist_(dist) {}
  const std::string& name(void) { return name_; }
  /* member functions */
  void sum_product_update(void);
  boolean_distribution dist(void) const { return dist_; }
  void  dist(const boolean_distribution& b) { dist_ = b; }
 private:
  /* member functions */

  /* data members */
  std::string name_;
  boolean_distribution dist_;
};

/*******************************************************************************
 * Operater Definitions
 ******************************************************************************/


} /* namespace namespace bayes */
} /* namespace rcppsw */

#endif  /* INCLUDE_RCPPSW_BAYES_FACTOR_NODE_HPP_ */
