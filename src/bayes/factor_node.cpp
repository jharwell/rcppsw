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
#include "rcppsw/bayes/factor_node.hpp"
#include "rcppsw/bayes/variable_node.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace bayes = rcppsw::bayes;

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
/**
 * factor_node::sum_product_update() - Update node during an iteration
 * of the sum-product algorithm
 *
 * void - N/A
 **/
void bayes::factor_node::sum_product_update(void) {
  ER_DIAG("%s: Updating factor node (%lu links/%lu msgs)",
          name_.c_str(), n_links(), incoming_count());

  if (n_links() == 1) {
    /*
     * If it is the first iteration, and we are a leaf node, send the initial
     * distribution as is. If it is not the first iteration, and we are a leaf
     * node and we get a message, we are done.
     */
    if (first_iteration()) {
      ER_VER("%s: First iteration leaf node -> send initial distribution",
              name_.c_str());
      send_msg(paired_node(), dist_);
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
  boolean_joint_distribution dist_new = multiply_distributions(&dist_, 0);

  /*
   * If the message was received from the paired variable node, send to all
   * connections except that node. Otherwise, you must have received messages
   * from all other connected nodes, and should only send to the paired node
   */
  if (last_msg_src() == paired_node()) {
    std::for_each(links().begin(), links().end(), [&](node* n) {
        if (n != paired_node()) {
          ER_VER("Send msg to variable node %s",((variable_node*)n)->name().c_str());
          boolean_joint_distribution tmp = dist_new;
          tmp.not_sum(n->name());
          send_msg(n, tmp);
        }
      });
  } else {
    dist_new.not_sum(paired_node()->name());
    send_msg(paired_node(), dist_new);
    ER_VER("Send msg to variable node %s",((variable_node*)paired_node())->name().c_str());
  }
} /* factor_node::sum_product_update() */
