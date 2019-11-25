/**
 * MIT License

 Copyright (c) [2019] [Shantam Bajpai]

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 */

#ifndef INCLUDE_PID_HPP_
#define INCLUDE_PID_HPP_

#include<pid_controller.hpp>

class PID : public PidController {
 public:
  /*
   * @brief: Default constructor
   */
  PID();
  /*
   * @brief: Constructor Initialization
   * @param: Kp is the proportional gain
   * @param: Ki is the Integral gain
   * @param: Kd is the derivative gain
   */
  PID(float Kp, float Ki, float Kd, float threshold);

  /**
   * @brief This function returns the gain values set by the user.
   * @return A float vector that contains the gain values
   * in the order Kp,Ki and Kd in the vector.
   */
  vector<float> getGainValues();

  /*
   * @brief computes the Pid error e(t)
   */
  float computePidError(float setPointVel, float inputVel, float prevError);

  /*
   * @brief: Destructor method for PID Class
   */
  ~PID();
};
#endif /*INCLUDE_PID_HPP_*/
