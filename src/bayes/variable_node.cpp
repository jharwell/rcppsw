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
  /*
   * I'm a leaf node, so send a boolean distribution of unity to the
   * corresponding factor to get the algorithm going.
   */
  if (n_links() == 1) {
    boolean_joint_distribution msg({"unity"});
    msg.preposition({{"unity", true}}, 1.0);
    msg.preposition({{"unity", false}}, 0.0);
    outgoing_msg(msg);
    return;
  } else if (n_msgs_recvd() == 1 && exclude()->has_outgoing_msg()) {
    outgoing_msg(exclude()->outgoing_msg());
    return;
  }
  /* have an incoming message from all non-excluded nodes */
  auto it = links().begin();
  node* start;
  if (links().front() == exclude()) {
    it++;
  }
  start = *it;
  it++;

  /* compute the product of all incoming messages from factor nodes */
  boolean_joint_distribution accum = start->dist();
  std::for_each(links().begin(), links().end(), [&](node * n) {
      if (n != exclude()) {
        accum = accum * n->outgoing_msg();

        /* notify all connected nodes that we have processed their messages */
        n->ack_msg();
      }
    });
  /* set outgoing message */
  outgoing_msg(accum);
} /* variable_node::sum_product_update() */
