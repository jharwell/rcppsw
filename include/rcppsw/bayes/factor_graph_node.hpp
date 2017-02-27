/*******************************************************************************
 * Name            : factor_graph_node.hpp
 * Project         : rcppsw
 * Module          : bayes
 * Description     : Representation of nodes in a factor graph/Bayesian network
 * Creation Date   : 02/13/17
 * Copyright       : Copyright 2017 John Harwell, All rights reserved
 *
 ******************************************************************************/

#ifndef INCLUDE_RCPPSW_BAYES_FACTOR_GRAPH_NODE_HPP_
#define INCLUDE_RCPPSW_BAYES_FACTOR_GRAPH_NODE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include "rcsw/al/altypes.h"
#include "rcppsw/bayes/boolean_distribution.hpp"
#include "rcppsw/bayes/bayes_node.hpp"
#include "rcppsw/er_client.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace rcppsw {
namespace bayes {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class factor_graph_node: public bayes_node {
 public:
  factor_graph_node(const std::string& name,
                    const boolean_distribution& dist, er_server* handle) :
      bayes_node(name, handle),
      first_iteration_(true), recvd_2nd_msg_(false), last_msg_src_(NULL),
      next_iter_last_msg_src_(NULL), paired_node_(NULL),
      next_iter_incoming_msgs_(), incoming_msgs_(), dist_(dist) {}
  virtual ~factor_graph_node(void) {}

  /* member functions */
  virtual void sum_product_update(void) = 0;
  boolean_distribution dist(void) { return dist_; }
  void dist(const boolean_distribution& d) { dist_ = d; }

  void pair_with(factor_graph_node* const n) { paired_node_ = n; }
  factor_graph_node* paired_node(void) const {
    return paired_node_;
  }

  factor_graph_node* last_msg_src(void) const { return last_msg_src_; }

  std::size_t incoming_count(void) const { return incoming_msgs_.size(); }
  const std::vector<boolean_distribution>& incoming_msgs(void) const {
    return incoming_msgs_;
  }

  bool recvd_all_msgs(void) const {
    return (last_msg_src_ == paired_node() &&
            incoming_msgs().size() == 1) ||
        (incoming_msgs().size() > 0 &&
         incoming_msgs().size() == n_links() - 1);
  }
  void recv_msg(factor_graph_node* src, const boolean_distribution& b) {
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
  void send_msg(factor_graph_node* const dest,
                const boolean_distribution& b) {
    dest->recv_msg(this, b);
    incoming_msgs_.clear();
  }
  boolean_distribution multiply_distributions(
      boolean_distribution* const seed,
      std::size_t start_pos) const {
    boolean_distribution accum = *seed;
    for (size_t i = start_pos; i < incoming_msgs().size(); ++i) {
      accum = accum * incoming_msgs()[i];
    } /* for(i..) */
    return accum;
  }

 private:
  /* member functions */
  factor_graph_node(const factor_graph_node& other) = delete;
  factor_graph_node& operator=(const factor_graph_node& other) = delete;

  /* data members */
  bool first_iteration_;
  bool recvd_2nd_msg_;
  factor_graph_node* last_msg_src_;
  factor_graph_node* next_iter_last_msg_src_;
  factor_graph_node* paired_node_;
  std::vector<boolean_distribution> next_iter_incoming_msgs_;
  std::vector<boolean_distribution> incoming_msgs_;
  boolean_distribution dist_;

};

/*******************************************************************************
 * Operater Definitions
 ******************************************************************************/

} /* namespace namespace bayes */
} /* namespace rcppsw */

#endif  /* INCLUDE_RCPPSW_BAYES_FACTOR_GRAPH_NODE_HPP_ */
