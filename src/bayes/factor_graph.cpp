/*******************************************************************************
 * Name            : factor_graph.cpp
 * Project         : rcppsw
 * Module          : bayes
 * Description     : Implementation of factor graph for usage in Bayes net
 *                   calculations
 * Creation Date   : 02/13/17
 * Copyright       : Copyright 2017 John Harwell, All rights reserved
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/bayes/factor_graph.hpp"
#include <algorithm>

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace bayes = rcppsw::bayes;

/*******************************************************************************
 * Constant Definitions
 ******************************************************************************/

/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/

/*******************************************************************************
 * Global Variables
 ******************************************************************************/

/*******************************************************************************
 * Forward Declarations
 ******************************************************************************/

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
/**
 * factor_graph::find_leaf_nodes() - Find all the leaf nodes in a factor graph
 *
 * std::list<node*>* - The list of nodes, or NULL if an error occurred
 **/
std::list<bayes::node*>* bayes::factor_graph::find_leaf_nodes(void) const {
  std::list<bayes::node*>* leaves = new std::list<bayes::node*>();
  for (bayes::node* n : nodes_) {
    if (n->n_links() == 1) {
      leaves->push_back(n);
    }
  } /* for(n..) */
  return leaves;
} /* factor_graph::find_leaf_nodes() */

/**
 * factor_graph::calculate_marginals() - Calculate the marginal distribution of
 * all variables in the graph simultaneously
 *
 * void - N/A
 **/
void bayes::factor_graph::calculate_marginals(void) {

  for (size_t i = 0; i < nodes_.size(); ++i) {
    calculate_marginals_step();
  } /* for(i..) */
} /* factor_graph::calculate_marginals() */

/**
 * factor_graph::calculate_marginals_step() - One iteration of the marginal
 * calculation algorithm
 *
 * bool - TRUE if the algorithm should terminate, FALSE otherwise
 **/
bool bayes::factor_graph::calculate_marginals_step(void) {
  std::for_each(nodes_.begin(), nodes_.end(), [&](bayes::node* n) {
      n->sum_product_update();
    });
} /* factor_graph::calculate_marginals_step() */
