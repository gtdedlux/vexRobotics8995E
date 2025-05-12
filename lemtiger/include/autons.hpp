#pragma once

#include "lemlib/api.hpp"

// Declare a chassis 
extern lemlib::Chassis chassis;
extern lemlib::PID armPID;


// Declare functions for autonomous routines
void blueRingRush();
void blueLeftSide();
void blueLeftSideRush();

void redRightSide();
void redRingRush();
void redRightSideRush();
void redLeftSide();

void skills();


