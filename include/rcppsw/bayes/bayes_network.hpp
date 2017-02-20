/*******************************************************************************
 * Name            : bayes_network.hpp
 * Project         : rcppsw
 * Module          : bayes
 * Description     : Class representing a Bayesian network
 * Creation Date   : 02/13/17
 * Copyright       : Copyright 2017 John Harwell, All rights reserved
 *
 ******************************************************************************/

#ifndef INCLUDE_RCPPSW_BAYES_BAYES_NETWORK_HPP_
#define INCLUDE_RCPPSW_BAYES_BAYES_NETWORK_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <list>
#include <string>
#include <utility>
#include <map>
#include "rcppsw/er_client.hpp"
#include "rcppsw/bayes/bayes_node.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace rcppsw {
namespace bayes {

/*******************************************************************************
 * Type Definitions
 ******************************************************************************/
typedef std::pair<boolean_pair, boolean_preposition> markov_blanket;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class gibbs_sampler: public er_client {
 public:
  /* constructors */
  gibbs_sampler(er_server* const handle, const std::vector<std::string>& vars,
                const std::map<markov_blanket, double>& blankets) :
      er_client(handle), vars_(vars), blankets_(blankets) {
    insmod("Gibbs Sampler");
  }

  /* member functions */
  std::pair<std::size_t, std::size_t> sample_ask(
      const std::string& query,
      const std::vector<boolean_pair>& fixed_vars,
      std::size_t n_steps);
  void show_gibbs_samples(void);

 private:
  /* data members */
  std::vector<std::string> vars_;
  std::map<markov_blanket, double> blankets_;
};

} /* namespace bayes */
} /* namespace rcppsw */

#endif /* INCLUDE_RCPPSW_BAYES_BAYES_NETWORK_HPP_ */
