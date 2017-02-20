/*******************************************************************************
 * Name            : factor_node.cpp
 * Project         : rcppsw
 * Module          : bayes
 * Description     : Representation of a factor node in a graph/Bayesian network
 * Creation Date   : 02/15/17
 * Copyright       : Copyright 2017 John Harwell, All rights reserved
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/bayes/factor_graph_fnode.hpp"
#include "rcppsw/bayes/factor_graph_vnode.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace bayes = rcppsw::bayes;

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
/**
 * factor_graph_fnode::sum_product_update() - Update node during an iteration
 * of the sum-product algorithm
 *
 * void - N/A
 **/
void bayes::factor_graph_fnode::sum_product_update(void) {
  ER_DIAG("%s: Updating factor node (%lu links/%lu msgs)",
          name().c_str(), n_links(), incoming_count());

  if (n_links() == 1) {
    /*
     * If it is the first iteration, and we are a leaf node, send the initial
     * distribution as is. If it is not the first iteration, and we are a leaf
     * node and we get a message, we are done.
     */
    if (first_iteration()) {
      ER_VER("%s: First iteration leaf node -> send initial distribution",
              name().c_str());
      send_msg(paired_node(), dist());
      first_iteration(false);
      return;
    } else {
      if (incoming_count() == 1) {
        ER_DIAG("%s: Last iteration leaf node", name().c_str());
        recvd_2nd_msg(true);
      }
      return;
    }
  } else {
    if (!recvd_all_msgs()) {
      return;
    }
  }

  ER_DIAG("Processing %lu received messages", incoming_count());
  /*
   * Compute the product of all incoming messages from variable nodes, and
   * multiply by the factor (i.e. distribution) at the current factor node, and
   * then perform a not sum over all the variables except the one for the
   * current node.
   */
  boolean_distribution tmp = dist();
  dist(multiply_distributions(&tmp, 0));
  dist().not_sum(name());

  /*
   * If the message was received from the paired variable node, send to all
   * connections except that node. Otherwise, you must have received messages
   * from all other connected nodes, and should only send to the paired node
   */
  if (last_msg_src() == paired_node()) {
    std::for_each(links().begin(), links().end(), [&](bayes_node* n) {
        if (n != paired_node()) {
          ER_VER("Send msg to variable node %s",
                 (dynamic_cast<factor_graph_vnode*>(n))->name().c_str());
          send_msg(dynamic_cast<factor_graph_node*>(n), dist());
        }
      });
  } else {
    send_msg(paired_node(), dist());
    ER_VER("Send msg to variable node %s",
           (dynamic_cast<factor_graph_vnode*>(paired_node()))->name().c_str());
  }
} /* factor_graph_fnode::sum_product_update() */
