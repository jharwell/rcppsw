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
 * Constructors/Destructors
 ******************************************************************************/

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
      ER_DIAG("%s: First iteration leaf node -> send unity",
              name().c_str());
      boolean_joint_distribution msg({"unity"});
      msg.preposition({{"unity", true}}, 1.0);
      msg.preposition({{"unity", false}}, 0.0);
      std::for_each(links().begin(), links().end(), [&](node* n) {
          send_msg(n, msg);
        });
      first_iteration(false);
      return;
    } else {
      if (incoming_count() == 1) {
        ER_DIAG("%s: Last Iteration leaf node", name().c_str());
        recvd_2nd_msg(true);
      }
      ER_DIAG("%s: Mid iteration msg count: %lu", name().c_str(), incoming_count());
      return;
    }
  } else {
    if (!recvd_all_msgs()) {
      return;
    }
  }
  ER_DIAG("Processing %lu received messages", incoming_count());

  /* compute the product of all incoming messages from factor nodes */
  boolean_joint_distribution accum = incoming_msgs()[0];
  ER_DIAG("Multiplying distributions: base=%s", name().c_str());
  std::for_each(incoming_msgs().begin()+1, incoming_msgs().end(), [&](boolean_joint_distribution& b) {
      accum = accum * b;
    });

  /* set outgoing message */
  if (last_msg_src() == exclude()) {
    std::for_each(links().begin(), links().end(), [&](node* n) {
        if (n != exclude()) {
          ER_DIAG("Send msg to factor node %s",((factor_node*)n)->name().c_str());
          send_msg(n, accum);
        }
      });
  } else {
    ER_DIAG("Send msg to factor node %s",((factor_node*)exclude())->name().c_str());
    send_msg(exclude(), accum);
  }
} /* variable_node::sum_product_update() */
