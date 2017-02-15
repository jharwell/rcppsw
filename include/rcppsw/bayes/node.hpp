/*******************************************************************************
 * Name            : node.hpp
 * Project         : rcppsw
 * Module          : bayes
 * Description     : base class for nodes in a Bayesian network
 * Creation Date   : 02/13/17
 * Copyright       : Copyright 2017 John Harwell, All rights reserved
 *
 ******************************************************************************/

#ifndef INCLUDE_RCPPSW_BAYES_NODE_HPP_
#define INCLUDE_RCPPSW_BAYES_NODE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <algorithm>
#include <list>
#include "rcsw/al/altypes.h"
#include "rcppsw/bayes/boolean_joint_distribution.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace rcppsw {
namespace bayes {

/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class node {
 public:
  node(void): first_iteration_(true), outgoing_msg_(false), msg_(),
              exclude_(NULL), links_() {}
  virtual ~node(void) {}

  /* member functions */
  void add_link(node* const node) { links_.push_back(node); }
  virtual void sum_product_update(void) = 0;
  std::size_t n_links(void) const { return links_.size(); }
  void exclude(const node* const n) { exclude_ = n; }
  const node* exclude(void) { return exclude_; }
  const boolean_joint_distribution& outgoing_msg(void) const { return msg_; }
  bool has_outgoing_msg(void) const { return true == outgoing_msg_; }
  void ack_msg(void) { outgoing_msg_ = false; }
  bool first_iteration(void) const { return first_iteration_; }

 protected:
  std::size_t n_msgs_recvd(void) {
    std::size_t count = 0;
    for (std::list<node*>::const_iterator it = links_.begin(); it != links_.end() ; ++it) {
      if ((*it)->has_outgoing_msg()) {
        ++count;
      }
    } /* for(i..) */
    return count;
  }
  const std::list<node*>& links(void) { return links_; }
  void outgoing_msg(const boolean_joint_distribution& b) {
    msg_ = b; outgoing_msg_ = true;
  }

 private:
  /* member functions */
  node(const node& other) = delete;
  node& operator=(const node& other) = delete;

  /* data members */
  bool first_iteration_;
  bool outgoing_msg_;
  boolean_joint_distribution msg_;
  const node* exclude_;
  std::list<node*> links_;
};

/*******************************************************************************
 * Operater Definitions
 ******************************************************************************/

} /* namespace namespace bayes */
} /* namespace rcppsw */

#endif  /* INCLUDE_RCPPSW_BAYES_NODE_HPP_ */
