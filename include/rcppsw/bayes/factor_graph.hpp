/*******************************************************************************
 * Name            : factor_graph.hpp
 * Project         : rcppsw
 * Module          : bayes
 * Description     : Class representing a factor graph for a Bayesian network
 * Creation Date   : 02/13/17
 * Copyright       : Copyright 2017 John Harwell, All rights reserved
 *
 ******************************************************************************/

#ifndef INCLUDE_RCPPSW_BAYES_FACTOR_GRAPH_HPP_
#define INCLUDE_RCPPSW_BAYES_FACTOR_GRAPH_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <list>
#include "rcppsw/bayes/node.hpp"
#include "rcppsw/er_client.hpp"

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
class factor_graph: public er_client {
 public:
  /* constructors */
  explicit factor_graph(std::list<node*> nodes, er_server* const handle) :
      er_client(handle),
      nodes_(nodes) {
    insmod("Factor graph");
  }

  /* member functions */
  void calculate_marginals(void);

 private:
  /* member functions */
  bool calculate_marginals_step(void);
  std::list<node*>* find_leaf_nodes(void) const;

  /* data members */
  std::list<node*> nodes_;
};

/*******************************************************************************
 * Operater Definitions
 ******************************************************************************/

} /* namespace bayes */
} /* namespace rcppsw */

#endif /* INCLUDE_RCPPSW_BAYES_FACTOR_GRAPH_HPP_ */
