#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"

extern Drive chassis;

// Your motors, sensors, etc. should go here.  Below are examples

// inline pros::Motor intake(1);
// inline pros::adi::DigitalIn limit_switch('A');

inline pros::Motor ladyB(21);

inline void set_lift(int input) {
  ladyB.move(input);
}

inline ez::PID liftPID{0.6, 0, 1.5, 0, "Lift"};