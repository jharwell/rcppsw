/*******************************************************************************
 * Name            : variable_node.hpp
 * Project         : rcppsw
 * Module          : bayes
 * Description     : Class for variable nodes in a Bayesian network
 * Creation Date   : 02/13/17
 * Copyright       : Copyright 2017 John Harwell, All rights reserved
 *
 ******************************************************************************/

#ifndef INCLUDE_RCPPSW_BAYES_VARIABLE_NODE_HPP_
#define INCLUDE_RCPPSW_BAYES_VARIABLE_NODE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/bayes/node.hpp"
#include "rcppsw/bayes/boolean_joint_distribution.hpp"

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
class variable_node: public node {
 public:
  /* constructors */
  variable_node(void) {}

  /* member functions */
  void sum_product_update(void);

 private:
  /* member functions */

  /* data members */
};

/*******************************************************************************
 * Operater Definitions
 ******************************************************************************/


} /* namespace namespace bayes */
} /* namespace rcppsw */

#endif  /* INCLUDE_RCPPSW_BAYES_VARIABLE_NODE_HPP_ */
