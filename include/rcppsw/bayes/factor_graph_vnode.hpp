/*******************************************************************************
 * Name            : variable_node.hpp
 * Project         : rcppsw
 * Module          : bayes
 * Description     : Class for variable nodes in a Bayesian network
 * Creation Date   : 02/13/17
 * Copyright       : Copyright 2017 John Harwell, All rights reserved
 *
 ******************************************************************************/

#ifndef INCLUDE_RCPPSW_BAYES_FACTOR_GRAPH_VNODE_HPP_
#define INCLUDE_RCPPSW_BAYES_FACTOR_GRAPH_VNODE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/bayes/factor_graph_node.hpp"

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
class factor_graph_vnode: public factor_graph_node {
 public:
  /* constructors */
  factor_graph_vnode(const std::string& name,
                     er_server* const handle) :
      factor_graph_node(name, boolean_distribution(), handle) {}

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

#endif  /* INCLUDE_RCPPSW_BAYES_FACTOR_GRAPH_VNODE_HPP_ */
