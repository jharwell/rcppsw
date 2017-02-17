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
  node(const std::string& name):
      first_iteration_(true),
      has_incoming_msg_(false), recvd_2nd_msg_(false),
      outgoing_count_(0), incoming_count_(0), last_msg_src_(NULL),
      next_iter_last_msg_src_(NULL), exclude_(NULL), links_(), name_(name) {}
  virtual ~node(void) {}

  /* member functions */
    const std::string& name(void) const { return name_; }
  void add_link(node* const n) { links_.push_back(n); }
  virtual void sum_product_update(void) = 0;
  std::size_t n_links(void) const { return links_.size(); }
  void exclude(node* const n) { exclude_ = n; }
  node* exclude(void) { return exclude_; }
  std::size_t incoming_count(void) const { return incoming_msgs_.size(); }
  std::vector<boolean_joint_distribution>& incoming_msgs(void) { return incoming_msgs_; }
  node* last_msg_src(void) const { return last_msg_src_; }
  bool recvd_all_msgs(void) {
    return (last_msg_src_ == exclude() && incoming_msgs().size() == 1) ||
        (incoming_msgs().size() > 0 && incoming_msgs().size() == n_links() - 1);
  }
  void recv_msg(node* src, const boolean_joint_distribution& b) {
    next_iter_incoming_msgs_.push_back(b);
    next_iter_last_msg_src_ = src;
  }
  bool first_iteration(void) const { return first_iteration_; }
  void first_iteration(bool b) { first_iteration_ = b; }
  void update_msg_status(void) {
    incoming_msgs_ = next_iter_incoming_msgs_;
    next_iter_incoming_msgs_.clear();
    last_msg_src_ = next_iter_last_msg_src_;
    next_iter_last_msg_src_ = NULL;
  }
  void recvd_2nd_msg(bool b) { recvd_2nd_msg_ = b; }
  bool recvd_2nd_msg(void) const { return recvd_2nd_msg_; }

 protected:
  const std::list<node*>& links(void) { return links_; }
  void send_msg(node* const dest, const boolean_joint_distribution& b) {
    dest->recv_msg(this, b);
    incoming_msgs_.clear();
  }

 private:
  std::size_t n_msgs_recvd(void) {
    std::size_t count = 0;
    for (std::list<node*>::const_iterator it = links_.begin(); it != links_.end() ; ++it) {
      /* count += (*it)->outgoing_count(); */
    } /* for(i..) */
    return count;
  }

  /* member functions */
  node(const node& other) = delete;
  node& operator=(const node& other) = delete;

  /* data members */
  bool first_iteration_;
  bool has_incoming_msg_;
  bool recvd_2nd_msg_;
  std::size_t outgoing_count_;
  std::size_t incoming_count_;
  std::vector<boolean_joint_distribution> incoming_msgs_;
  std::vector<boolean_joint_distribution> next_iter_incoming_msgs_;
  node* last_msg_src_;
  node* next_iter_last_msg_src_;
  node* exclude_;
  std::list<node*> links_;
  std::string name_;
};

/*******************************************************************************
 * Operater Definitions
 ******************************************************************************/

} /* namespace namespace bayes */
} /* namespace rcppsw */

#endif  /* INCLUDE_RCPPSW_BAYES_NODE_HPP_ */
