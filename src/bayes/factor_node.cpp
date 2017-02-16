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
 * factor_node::sum_product_update() - Update node during an iteration
 * of the sum-product algorithm
 *
 * void - N/A
 **/
void bayes::factor_node::sum_product_update(void) {
  ER_DIAG("Updating distribution for factor node %s", name_.c_str());
  if (n_links() == 1) {
    /*
     * If it is the first iteration, and we are a leaf node, send the initial
     * distribution as is. If it is not the first iteration, and we are a leaf
     * node and we get a message, we are done.
     */
    if (first_iteration()) {
      ER_DIAG("%s: First iteration leaf factor node -> send initial distribution",
              name_.c_str());
      outgoing_msg(dist_);
      return;
    } else if (n_msgs_recvd() == 1) {
      ER_DIAG("%s: Last iteration leaf factor node", name_.c_str());
      return;
    }
  } else if (n_msgs_recvd() == 1 && exclude()->has_outgoing_msg()) {
    ER_DIAG("%s: Received message from excluded node", name_.c_str());
    outgoing_msg(dist_);
    return;
  } else if (n_msgs_recvd() != n_links() - 1) {
    ER_DIAG("%s: Have not received messages from all non-excluded nodes yet", name_.c_str());
    return;
  }

  ER_DIAG("Messages received from all non-excluded nodes");
  /* have an incoming message */
  auto it = links().begin();
  if (links().front() == exclude()) {
    it++;
  }

  /*
   * Compute the product of all incoming messages from variable nodes, and
   * multiply by the factor (i.e. distribution) at the current factor node.
   */
  boolean_joint_distribution accum = dist_;
  while (it != links().end()) {
    node* n = *it;
    if (n != exclude()) {
      accum = accum * n->outgoing_msg();

      /* notify all connected nodes that we have processed their messages */
      n->ack_msg();
    }
    it++;
  } /* while() */

  /* Sum out all variables the factor node is operating over/on */
  std::for_each(
      accum.names().begin(),
      accum.names().end(),
      [&](const std::string& name) {
        accum.sum_out(name);
      });

  /* set outgoing message */
  outgoing_msg(accum);
} /* factor_node::sum_product_update() */
