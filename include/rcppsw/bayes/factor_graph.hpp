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
#include "rcppsw/er_client.hpp"
#include "rcppsw/bayes/factor_graph_fnode.hpp"
#include "rcppsw/bayes/factor_graph_vnode.hpp"

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
  factor_graph(std::vector<factor_graph_node*> nodes, er_server* const handle) :
      er_client(handle),
      nodes_(nodes) {
    insmod(er_lvl::VER, er_lvl::VER, "Factor graph");

  }

  /* member functions */
  void calculate_marginals(void);
  void show_marginals(void) {
    std::for_each(nodes_.begin(), nodes_.end(), [&](bayes::factor_graph_node* n) {
        factor_graph_fnode *f = dynamic_cast<factor_graph_fnode*>(n);
        if (NULL != f) {
          std::cout << f->dist();
        }
      });
  }
  std::vector<factor_graph_node*>* find_leaf_nodes(void) const;

 private:
  /* member functions */


  /* data members */
  std::vector<factor_graph_node*> nodes_;
};

/*******************************************************************************
 * Operater Definitions
 ******************************************************************************/

} /* namespace bayes */
} /* namespace rcppsw */

#endif /* INCLUDE_RCPPSW_BAYES_FACTOR_GRAPH_HPP_ */
