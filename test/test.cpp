/**@file test.cpp
 * @brief Test source file for PID controller.
 *        Contains the required headers and methods.
 *
 * Detailed description follows here.
 * @author     : Arjun Gupta
 * @created on : Sep 27, 2019
 * @copyright  : This code is written for ENPM808X. Please
 *               cite if code is used.
 */
#include <gtest/gtest.h>
#include "../include/pid_controller.hpp"

/** 
 * @brief Test for setGainValues() function of the PidController class.
 * It checks whether the values set by the user and the values obtained by 
 * getGainValues() function are same or not.
 */
TEST(checkValues, shouldPass) {
  PidController pid;
  pid.setGainValues(2, 3, 4);
  vector<float> inputValues = {2.0, 3.0, 4.0};
  int i = 0;
  /** This range based loop iterated over the values returned by 
   * getGainValues() function and the code in it matches the values obtained
   * with the values obtained from inputValues vector.
  */
  for (auto &values : pid.getGainValues()) {
    ASSERT_EQ(values, inputValues[i]);
    i++;
    }
}
/** 
 * @brief Test for computePidError() function of the PidController class.
 * It verifies that the computed value is equal to the expected value for 
 * control error less than the threshold value.
 */
TEST(checkFormula, shouldPass) {
  PidController pid;
  pid.setGainValues(1, 2, 4);
  pid.setThreshold(10.0);
  pid.computePidError(5, 3, 2);
  /** Expected value for getControlError() is 6.0 for the given input values
   * and the gain values.
   */
  ASSERT_EQ(6.0, pid.getControlError());
}
/** 
 * @brief Test for computePidError() function of the PidController class.
 * It verifies that the computed value is equal to the expected value for 
 * control error more than the threshold value.
 */
TEST(checkBoundaryCondition, shouldPass) {
  PidController pid;
  pid.setGainValues(1, 2, 4);
  pid.setThreshold(10.0);
  pid.computePidError(9, 4, 2);
  /** Expected value for getControlError() is 10.0 for the given input values
  * and the gain values.
  */
  ASSERT_EQ(10.0, pid.getControlError());
}
