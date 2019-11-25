/**@file pid_controller.cpp
 * @brief This file containts definitions for functions
 * declared in header file.
 * @author     : Arjun Gupta
 * @created on : Sep 27, 2019
 * @copyright  : This code is written for ENPM808X. Please
 *               cite if code is used.
 */

#include "../include/pid_controller.hpp"

PidController::PidController() {
    this->Kp = 0;
    this->Ki = 0;
    this->Kd = 0;
    this->controlError = 0;
    this->cumulativeError = 0;
    this->threshold = 0;
}

void PidController::setGainValues(float _kp, float _ki, float _kd) {
    this->Kp = _kp;
    this->Ki = _ki;
    this->Kd = _kd;
}

void PidController::setThreshold(float _threshold) {
    this->threshold = _threshold;
}

PidController::~PidController() {
}
