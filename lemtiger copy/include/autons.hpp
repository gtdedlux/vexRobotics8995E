#pragma once

#include "lemlib/api.hpp"

// Declare a chassis 
extern lemlib::Chassis chassis;
extern lemlib::PID armPID;


// Declare functions for autonomous routines
void blueRightSide();
void blueLeftSide();
void redRightSide();
void redLeftSide();
void skills();


