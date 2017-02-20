/*******************************************************************************
 * Name            : factor_node.hpp
 * Project         : rcppsw
 * Module          : bayes
 * Description     : Class for factor nodes in a Bayesian network
 * Creation Date   : 02/13/17
 * Copyright       : Copyright 2017 John Harwell, All rights reserved
 *
 ******************************************************************************/

#ifndef INCLUDE_RCPPSW_BAYES_FACTOR_GRAPH_FNODE_HPP_
#define INCLUDE_RCPPSW_BAYES_FACTOR_GRAPH_FNODE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
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
class factor_graph_fnode: public factor_graph_node {
 public:
  /* constructors */
  factor_graph_fnode(const std::string& name,
                     const boolean_distribution& dist,
                     er_server* const handle) :
      factor_graph_node(name, handle) {}

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

#endif  /* INCLUDE_RCPPSW_BAYES_FACTOR_GRAPH_FNODE_HPP_ */
