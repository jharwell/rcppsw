/*******************************************************************************
 * Name            : bayes_node.hpp
 * Project         : rcppsw
 * Module          : bayes
 * Description     : base class for nodes in a Bayesian network
 * Creation Date   : 02/13/17
 * Copyright       : Copyright 2017 John Harwell, All rights reserved
 *
 ******************************************************************************/

#ifndef INCLUDE_RCPPSW_BAYES_BAYES_NODE_HPP_
#define INCLUDE_RCPPSW_BAYES_BAYES_NODE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include "rcsw/al/altypes.h"
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
struct gibbs_sample_msg {
  boolean_pair pair;
  boolean_preposition prep;
};

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class bayes_node: public er_client {
 public:
  bayes_node(const std::string& name, er_server* handle):
      er_client(handle), marginal_prob_(0.0), links_(),
      name_(name) { insmod("bayes_node"); }
  virtual ~bayes_node(void) {}

  /* member functions */
  const std::string& name(void) const { return name_; }
  void add_link(bayes_node* const n) { links_.push_back(n); }
  std::size_t n_links(void) const { return links_.size(); }
  const std::list<bayes_node*>& links(void) { return links_; }
  boolean_distribution dist(void) { return dist_; }
  void dist(const boolean_distribution& d) { dist_ = d; }
  double marginal_prob(void) const { return marginal_prob_; }
  void marginal_prob(double d) { marginal_prob_ = d; }
  double mb_prob(void) const { return mb_prob_; }
  void mb_prob(double d) { mb_prob_ = d; }

 private:
  /* member functions */
  bayes_node(const bayes_node& other) = delete;
  bayes_node& operator=(const bayes_node& other) = delete;

  /* data members */
  double marginal_prob_;
  double mb_prob_;
  std::list<bayes_node*> links_;
  std::string name_;
  boolean_distribution dist_;
};

} /* namespace namespace bayes */
} /* namespace rcppsw */

#endif  /* INCLUDE_RCPPSW_BAYES_BAYES_NODE_HPP_ */
