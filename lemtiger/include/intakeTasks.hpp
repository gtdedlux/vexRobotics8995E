#ifndef INTAKE_CONTROL_HPP
#define INTAKE_CONTROL_HPP

#include "pros/rtos.hpp"

// Global intake speed variable
extern int intakeSpeed;
extern bool redSortEnabled; // Flag to disable red sorting when needed
extern bool blueSortEnabled; // Flag to disable blue sorting when needed
extern bool sortingEnabled;



// Function declarations
void intakeTask();

void checkIntakeTask();
void stopIntakeMonitoring();
void startIntakeMonitoring();

void holdRingTask();
void holdRing();
void releaseRing();

    //color sorts
void redSortTask();
void blueSortTask();

// void redSort();
// void stopRed();

// void blueSort();
// void stopBlue();


void startIntakeTasks();

#endif
