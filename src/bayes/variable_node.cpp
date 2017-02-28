/*******************************************************************************
 * Name            : variable_node.cpp
 * Project         : rcppsw
 * Module          : bayes
 * Description     : Routines that operate on/with variable nodes in a Bayes
 *                   network/factor graph
 * Creation Date   : 02/13/17
 * Copyright       : Copyright 2017 John Harwell, All rights reserved
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/bayes/variable_node.hpp"
#include "rcppsw/bayes/factor_node.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace bayes = rcppsw::bayes;

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
/**
 * variable_node::sum_product_update() - Update node during an iteration
 * of the sum-product algorithm
 *
 * void - N/A
 **/
void bayes::variable_node::sum_product_update(void) {
  ER_DIAG("%s: Updating variable node (%lu links/%lu msgs)",
          name().c_str(), n_links(), incoming_count());

  /*
   * I'm a leaf node, so send a boolean distribution of unity to the
   * corresponding factor to get the algorithm going.
   */
  if (n_links() == 1) {
    if (first_iteration()) {
      ER_VER("%s: First iteration leaf node -> send unity",
              name().c_str());
      boolean_joint_distribution msg({"unity"});
      msg.preposition({{"unity", true}}, 1.0);
      msg.preposition({{"unity", false}}, 0.0);
      send_msg(paired_node(), msg);
      first_iteration(false);
      return;
    } else {
      if (incoming_count() == 1) {
        ER_DIAG("%s: Last iteration leaf node", name().c_str());
        recvd_2nd_msg(true);
        marginal_dist_ = incoming_msgs()[0];
      }
      return;
    }
  } else {
    if (!recvd_all_msgs()) {
      return;
    }
  }
  ER_DIAG("Processing %lu received messages", incoming_count());

  /* compute the product of all incoming messages from factor nodes */
  marginal_dist_ = incoming_msgs()[0];
  boolean_joint_distribution accum = multiply_distributions(&incoming_msgs()[0],
                                                            1);

  /* set outgoing message */
  if (last_msg_src() == paired_node()) {
    std::for_each(links().begin(), links().end(), [&](node* n) {
        if (n != paired_node()) {
          ER_VER("Send msg to factor node %s",((factor_node*)n)->name().c_str());
          send_msg(n, accum);
        }
      });

  } else {
    ER_VER("Send msg to factor node %s",((factor_node*)paired_node())->name().c_str());
    send_msg(paired_node(), accum);
  }
} /* variable_node::sum_product_update() */
