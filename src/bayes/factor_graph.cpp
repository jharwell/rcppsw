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
 * Member Functions
 ******************************************************************************/
/**
 * factor_graph::find_leaf_nodes() - Find all the leaf nodes in a factor graph
 *
 * std::list<node*>* - The list of nodes, or NULL if an error occurred
 **/
std::vector<bayes::factor_graph_node*>* bayes::factor_graph::find_leaf_nodes(void) const {
  std::vector<bayes::factor_graph_node*>* leaves = new std::vector<bayes::factor_graph_node*>();
  for (bayes::factor_graph_node* n : nodes_) {
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
  ER_NOM("Begin calculating marginals");

  std::vector<bayes::factor_graph_node*>* leaves = find_leaf_nodes();
  std::for_each(leaves->begin(), leaves->end(), [&](bayes::factor_graph_node* const n) {
      n->first_iteration(true);
    });

  std::size_t step = 1;

  while (true) {
    std::for_each(nodes_.begin(), nodes_.end(), [&](bayes::factor_graph_node* n) {
        n->update_msg_status();
      });
    ER_NOM("step%lu", step++);
    for (size_t i = 0; i < nodes_.size(); ++i) {
      factor_graph_fnode * f = dynamic_cast<factor_graph_fnode*>(nodes_[i]);

      if (f) {
        ER_DIAG("Factor node %s: %lu links, %lu incoming messages",
                nodes_[i]->name().c_str(), nodes_[i]->n_links(),
                nodes_[i]->incoming_count());
        std::cout << ((bayes::factor_graph_node*)nodes_[i])->dist();
      } else {
        ER_DIAG("Variable node %s: %lu links, %lu incoming messages",
                nodes_[i]->name().c_str(), nodes_[i]->n_links(),
                nodes_[i]->incoming_count());
      }
    } /* for(i..) */

    /* one step of the algorithm */
    std::for_each(nodes_.begin(), nodes_.end(), [&](bayes::factor_graph_node* n) {
        n->sum_product_update();
      });
    bool term = true;
    std::for_each(leaves->begin(), leaves->end(), [&](bayes::factor_graph_node* n) {
        if (!n->recvd_2nd_msg()) {
          ER_VER("Leaf node has not received 2nd message yet");
          term = false;
        } else {
          ER_VER("Leaf node has received 2nd message\n");
        }
      });
    if (term) {
      ER_NOM("Finished calculating marginals");
      break;
    }
  } /* while() */
  delete leaves;
} /* factor_graph::calculate_marginals() */
