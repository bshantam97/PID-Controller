/**@file test.cpp
 * @brief Test source file for PID controller.
 *        Contains the required headers and methods.
 *
 * Detailed description follows here.
 * @author     : Shantam Bajpai
 * @created on : November 24th, 2019
 * @copyright  : This code is written for ENPM808X. Please
 *               cite if code is used.
 */
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/pid_controller.hpp"
#include <PID.hpp>

using ::testing::_;

/*
 * @brief: The mock class for testing the functionality of PidController
 */

class MockPid : public PidController {
 public:
  MOCK_METHOD3(computePidError , float(float,float,float));
};

/*
 * @brief Tests the MOCK_METHOD
 */

TEST(mockPid , computeError) {
  MockPid mockpid;
  PID pid;
  EXPECT_CALL(mockpid , computePidError(_, _, _)).Times(1);
  mockpid.computePidError(9, 4, 2);
  pid.setGainValues(1, 2, 4);
  pid.setThreshold(10);
  EXPECT_EQ(27, pid.computePidError(9, 4, 2));
}

/**
 * @brief Test for setGainValues() function of the PidController class.
 * It checks whether the values set by the user and the values obtained by
 * getGainValues() function are same or not.
 */
TEST(checkValues, shouldPass) {
  PID myPid;
  myPid.setGainValues(2, 3, 4);
  vector<float> inputValues = {2.0, 3.0, 4.0};
  int i = 0;
  /** This range based loop iterated over the values returned by
   * getGainValues() function and the code in it matches the values obtained
   * with the values obtained from inputValues vector.
  */
  for (auto &values : myPid.getGainValues()) {
    ASSERT_EQ(values, inputValues[i]);
    i++;
    }
}
