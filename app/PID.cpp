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

#include<PID.hpp>
#include<../include/pid_controller.hpp>

PID::PID() {
  Kp = 2;
  Ki = 3;
  Kd = 4;
  threshold = 5;
}

PID::PID(float kp, float ki, float kd, float thresHold) {
  Kp = kp;
  Ki = ki;
  Kd = kd;
  threshold = thresHold;
  cumulativeError = 0;
  controlError = 0;
}

float PID::computePidError(float setPointVel, float inputVel, float prevError) {
  auto currentError = setPointVel - inputVel;
  cumulativeError += currentError;
  controlError = Kp * currentError + Kd * (currentError - prevError)
      + Ki * (cumulativeError);
  /*if (controlError > threshold)
    controlError = threshold;
  else
    std::cout << "Control error is:" << controlError;
   cout << "New velocity is: " << controlError + inputVel << endl;*/
  return controlError;
}

PID::~PID() {
  std::cout << "Destructor called";
}
/*float PID::getControlError() {
  return this->controlError;
 }*/
