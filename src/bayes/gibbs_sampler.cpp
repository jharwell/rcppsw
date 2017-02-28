/*******************************************************************************
 * Name            : gibbs_sampler.cpp
 * Project         : rcppsw
 * Module          : bayes
 * Description     : Implementation routines to manipulate Bayesian network
 * Creation Date   : 02/18/17
 * Copyright       : Copyright 2017 John Harwell, All rights reserved
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <list>
#include "rcppsw/bayes/gibbs_sampler.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace rcppsw {
namespace bayes {

/*******************************************************************************
 * Type Definitions
 ******************************************************************************/

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
/**
 * gibbs_sampler::sample_ask() - Perform Gibbs sampling on a Bayesian
 * network, given a set of fixed variables, and a set # of steps
 *
 * std::pair<std::size_t, std::size_t> - The sample count
 *
 **/
std::pair<std::size_t, std::size_t> gibbs_sampler::sample_ask(
    const std::string& query,
    const std::vector<boolean_pair>& fixed_vars,
     std::size_t n_steps) {
  std::vector<std::map<std::string, bool>> samples;
  std::pair<std::size_t, std::size_t> counts;
  boolean_preposition current_state;
  boolean_preposition next_state;
  std::vector<std::string> non_evidence_vars;

  /* create list of active variables */
  for (size_t i = 0; i < vars_.size(); ++i) {
    bool not_found = true;
    for (size_t j = 0; j < fixed_vars.size(); ++j) {
      if (fixed_vars[j].first == vars_[i]) {
        not_found = false;
      }
    } /* for(j..) */
    if (not_found) {
      non_evidence_vars.push_back(vars_[i]);
    }
  } /* for(i..) */

  /* initialize current state with random true/false */
  for (size_t i = 0; i < vars_.size(); ++i) {
    current_state.push_back({vars_[i], rand() % 2});
  } /* for(i..) */

  /* fix evidence variables */
  for (size_t i = 0; i < current_state.size(); ++i) {
    for (size_t j = 0; j < fixed_vars.size(); ++j) {
      if (fixed_vars[j].first == current_state[i].first) {
        current_state[i].second = fixed_vars[j].second;
      }
    } /* for(j..) */
  } /* for(i..) */

  auto query_it = std::find_if(current_state.begin(), current_state.end(),
                               [&](const ::rcppsw::bayes::boolean_pair& p)
                               { return p.first == query;});

/* perform sampling */
  next_state = current_state;
  for (size_t i = 0; i < n_steps; ++i) {
    current_state = next_state;

    for (const std::string& name : non_evidence_vars) {
        double rando = static_cast<double>(rand()) /
                      static_cast<double>(RAND_MAX);

        auto it1 = std::find_if(current_state.begin(), current_state.end(),
                               [&](const ::rcppsw::bayes::boolean_pair& p)
                               { return p.first == name;});
        auto it2 = std::find_if(next_state.begin(), next_state.end(),
                               [&](const ::rcppsw::bayes::boolean_pair& p)
                               { return p.first == name;});
        boolean_preposition tmp = current_state;
        boolean_pair pair = {(*it1).first, (*it1).second};
        tmp.erase(std::remove(tmp.begin(), tmp.end(), pair));
        double current = blankets_[{pair, tmp}];

        /* verify that the needed Markov blanket was found */
        assert(current > 0);
        /* printf("rand: %f current: %s/%f\n",rando, name.c_str(), current); */
        if (rando <= current) {
          (*it2).second = (*it2).second;
        } else {
          (*it2).second = !(*it2).second;
        }
      } /* for(var...) */
    /* for(auto e: current_state) */
    /*   std::cout << e.first << " " << e.second << " "; */
    /* std::cout << std::endl; */
    counts.first += (*query_it).second == true;
    counts.second += (*query_it).second == false;
  } /* for(i..) */
  return counts;
} /* gibbs_sampler::sample_ask() */

} /* namespace bayes */
} /* namespace rcppsw */
