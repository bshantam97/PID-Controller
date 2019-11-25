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
#include <gmock/gmock.h>
#include "../include/pid_controller.hpp"
#include <PID.hpp>

class MockPid : public PidController {
 public:
  MOCK_METHOD3(computePidError , float(float,float,float));
};

TEST(mockPid , computeError) {
  MockPid mockpid;
  PID pid;
  EXPECT_CALL(mockpid , computePidError(2,3,4)).Times(1);
  EXPECT_EQ(pid.computePidError(2, 3, 4), -25);
}

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
