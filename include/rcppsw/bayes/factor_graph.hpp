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
#include <vector>
#include "rcppsw/bayes/node.hpp"
#include "rcppsw/er_client.hpp"
#include "rcppsw/bayes/factor_node.hpp"
#include "rcppsw/bayes/variable_node.hpp"

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
  explicit factor_graph(std::vector<node*> nodes, er_server* const handle) :
      er_client(handle),
      nodes_(nodes) {
    insmod("Factor graph");
  }

  /* member functions */
  void calculate_marginals(void);
  void show_marginals(void) {
    std::for_each(nodes_.begin(), nodes_.end(), [&](bayes::node* n) {
        variable_node * f = dynamic_cast<variable_node*>(n);
        if (NULL != f) {
          std::cout << f->marginal_dist();
        }
      });
  }
  std::vector<node*>* find_leaf_nodes(void) const;

 private:
  /* member functions */


  /* data members */
  std::vector<node*> nodes_;
};

/*******************************************************************************
 * Operater Definitions
 ******************************************************************************/

} /* namespace bayes */
} /* namespace rcppsw */

#endif /* INCLUDE_RCPPSW_BAYES_FACTOR_GRAPH_HPP_ */
