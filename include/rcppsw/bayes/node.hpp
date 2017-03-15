/*******************************************************************************
 * Name            : node.hpp
 * Project         : rcppsw
 * Module          : bayes
n * Description     : base class for nodes in a Bayesian network
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
#include <string>
#include "rcsw/common/common.h"
#include "rcppsw/bayes/boolean_distribution.hpp"
#include "rcppsw/er_client.hpp"

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
class node: public er_client {
 public:
  node(const std::string& name, er_server* handle):
      er_client(handle),
      first_iteration_(true), recvd_2nd_msg_(false), last_msg_src_(NULL),
      next_iter_last_msg_src_(NULL), paired_node_(NULL), incoming_msgs_(),
      next_iter_incoming_msgs_(), links_(),
      name_(name) {
    insmod("Bayes node");
  }
  virtual ~node(void) {}

  /* member functions */
  virtual void sum_product_update(void) = 0;

  const std::string& name(void) const { return name_; }
  void add_link(node* const n) { links_.push_back(n); }
  std::size_t n_links(void) const { return links_.size(); }

  void pair_with(node* const n) { paired_node_ = n; }
  node* paired_node(void) { return paired_node_; }

  std::size_t incoming_count(void) const { return incoming_msgs_.size(); }
  std::vector<boolean_distribution>& incoming_msgs(void) {
    return incoming_msgs_;
  }
  node* last_msg_src(void) const { return last_msg_src_; }
  bool recvd_all_msgs(void) {
    return (last_msg_src_ == paired_node() && incoming_msgs().size() == 1) ||
        (incoming_msgs().size() > 0 && incoming_msgs().size() == n_links() - 1);
  }
  void recv_msg(node* src, const boolean_distribution& b) {
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
  void send_msg(node* const dest, const boolean_distribution& b) {
    dest->recv_msg(this, b);
    incoming_msgs_.clear();
  }
  boolean_distribution multiply_distributions(
      boolean_distribution* const seed,
      std::size_t start_pos) {
    ER_DIAG("Multiplying distributions: base=%s", name().c_str());
    boolean_distribution accum = *seed;
    for (size_t i = start_pos; i < incoming_msgs().size(); ++i) {
      accum = accum * incoming_msgs()[i];
    } /* for(i..) */
    return accum;
  }

 private:
  /* member functions */
  node(const node& other) = delete;
  node& operator=(const node& other) = delete;

  /* data members */
  bool first_iteration_;
 bool recvd_2nd_msg_;
  node* last_msg_src_;
  node* next_iter_last_msg_src_;
  node* paired_node_;
  std::vector<boolean_distribution> incoming_msgs_;
  std::vector<boolean_distribution> next_iter_incoming_msgs_;
  std::list<node*> links_;
  std::string name_;
};

/*******************************************************************************
 * Operater Definitions
 ******************************************************************************/

} /* namespace namespace bayes */
} /* namespace rcppsw */

#endif  /* INCLUDE_RCPPSW_BAYES_NODE_HPP_ */
