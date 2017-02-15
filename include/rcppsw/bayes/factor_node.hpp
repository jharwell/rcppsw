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
  explicit factor_node(const boolean_joint_distribution& dist): dist_(dist) {}

  /* member functions */
  void sum_product_update(void);
  boolean_joint_distribution dist(void) const { return dist_; }

 private:
  /* member functions */

  /* data members */
  boolean_joint_distribution dist_;
};

/*******************************************************************************
 * Operater Definitions
 ******************************************************************************/


} /* namespace namespace bayes */
} /* namespace rcppsw */

#endif  /* INCLUDE_RCPPSW_BAYES_FACTOR_NODE_HPP_ */
