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
  ER_DIAG("%s: Updating factor node (%lu links/%lu msgs)",
          name_.c_str(), n_links(), incoming_count());

  if (n_links() == 1) {
    /*
     * If it is the first iteration, and we are a leaf node, send the initial
     * distribution as is. If it is not the first iteration, and we are a leaf
     * node and we get a message, we are done.
     */
    if (first_iteration()) {
      ER_DIAG("%s: First iteration leaf node -> send initial distribution",
              name_.c_str());
      send_msg(exclude(), dist_);
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
  /* std::cout <<"Before multiplying\n"; */
  /* std::cout << dist_; */
  /*
   * Compute the product of all incoming messages from variable nodes, and
   * multiply by the factor (i.e. distribution) at the current factor node.
   */
  boolean_joint_distribution accum = dist_;
  ER_DIAG("Multiplying distributions: base=%s", name().c_str());
  std::for_each(incoming_msgs().begin(), incoming_msgs().end(), [&](boolean_joint_distribution& b) {
      accum = accum * b;
    });
  /* std::cout <<"Before summing out\n"; */
  /* std::cout << accum; */

  /* Sum out all variables the factor node is operating over/on */
  std::vector<std::string> names = accum.names();
  std::for_each(
      names.begin(),
      names.end(),
      [&](const std::string& var_name) {
        if (var_name != name()) {
          ER_DIAG("Sum out %s", var_name.c_str());
          accum.sum_out(var_name);
          std::cout << accum;
        }
      });

  /* set outgoing message */
  printf("last msg src: %p exclude: %p\n",last_msg_src(), exclude());
  if (last_msg_src() == exclude()) {
    std::for_each(links().begin(), links().end(), [&](node* n) {
        if (n != exclude()) {
          ER_DIAG("Send msg to variable node %s",((variable_node*)n)->name().c_str());
          send_msg(n, accum);
        }
      });
  } else {
    send_msg(exclude(), accum);
    ER_DIAG("Send msg to variable node %s",((variable_node*)exclude())->name().c_str());
  }
} /* factor_node::sum_product_update() */
