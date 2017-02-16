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
  ER_DIAG("%s: Updating variable node", name_.c_str());

  /*
   * I'm a leaf node, so send a boolean distribution of unity to the
   * corresponding factor to get the algorithm going.
   */
  if (n_links() == 1) {
    if (first_iteration()) {
      ER_DIAG("%s: First iteration leaf variable node", name_.c_str());
      boolean_joint_distribution msg({"unity"});
      msg.preposition({{"unity", true}}, 1.0);
      msg.preposition({{"unity", false}}, 0.0);
      outgoing_msg(msg);
      return;
    } else if (n_msgs_recvd() == 1) {
      ER_DIAG("%s: Last Iteration leaf variable node", name_.c_str());
      return;
    }
  } else if (n_msgs_recvd() == 1 && exclude()->has_outgoing_msg()) {
    outgoing_msg(exclude()->outgoing_msg());
    return;
  } else if (n_msgs_recvd() != n_links() - 1) {
    ER_DIAG("%s: Have not received messages from all non-excluded nodes yet", name_.c_str());
    return;
  }
  ER_DIAG("Messages received from all non-excluded nodes");
  /* have an incoming message from all non-excluded nodes */
  auto it = links().begin();
  node* start;
  if (links().front() == exclude()) {
    it++;
  }
  start = *it;
  it++;

  /* compute the product of all incoming messages from factor nodes */
  boolean_joint_distribution accum = dynamic_cast<factor_node*>(start)->dist();
  while (it != links().end()) {
    if (*it != exclude()) {
      accum = accum * (*it)->outgoing_msg();

      /* notify all connected nodes that we have processed their messages */
      (*it)->ack_msg();
    }
  } /* while() */
  /* set outgoing message */
  outgoing_msg(accum);
} /* variable_node::sum_product_update() */
