/*******************************************************************************
 * Name            : boolean_variable.hpp
 * Project         : rcppsw
 * Module          : bayes
 * Description     : Representation of a boolean variable associated with a
 *                   node in a Bayes Network
 * Creation Date   : 02/13/17
 * Copyright       : Copyright 2017 John Harwell, All rights reserved
 *
 ******************************************************************************/

#ifndef INCLUDE_RCPPSW_BAYES_BOOLEAN_VARIABLE_HPP_
#define INCLUDE_RCPPSW_BAYES_BOOLEAN_VARIABLE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <string>

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
class boolean_variable {
 public:
  /* constructors */
  explicit boolean_variable(const std::string& name) : name_(name), dist_(2) {}

  /* member functions */
  void pfalse(float p) { dist_[0] = p; }
  void ptrue(float p) { dist_[1] = p; }
  float pfalse(void) const { return dist_[0]; }
  float ptrue(void) const { return dist_[1]; }
  std::string name(void) const { return name_; }

 private:
  /* member functions */

  /* data members */
  std::string name_;
  std::vector<float> dist_;
};

/*******************************************************************************
 * Operater Definitions
 ******************************************************************************/


} /* namespace bayes */
} /* namespace rcppsw */

#endif /* INCLUDE_RCPPSW_BAYES_BOOLEAN_VARIABLE_HPP_ */
