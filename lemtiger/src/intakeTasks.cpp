#include "pros/motors.hpp"
#include "main.h"

// Global variables
int intakeSpeed = 0;
bool checkIntakeEnabled = false; // Flag to disable checking when needed
bool holdRingEnabled = false; // Flag to disable checking when needed
bool redSortEnabled = false; // Flag to disable red sorting when needed
bool blueSortEnabled = false; // Flag to disable blue sorting when needed
bool sortingEnabled = false; // Toggle for sorting system



// Intake control task
void intakeTask() {
    int lastSpeed = 0; // Track last intake speed
    while (true) {
        // Only update if speed changes
        if (intakeSpeed != lastSpeed) { 
            setIntake(intakeSpeed);
            lastSpeed = intakeSpeed;
        }
        pros::delay(10); // Prevent CPU overload
    }
}

// Intake stall detection task
void checkIntakeTask() {
    while (true) {
        if (checkIntakeEnabled && intakeSpeed != 0
            && intake11W.get_actual_velocity() == 0) {
            intakeSpeed = -110;
            pros::delay(200);
            intakeSpeed = 115;
        }
        pros::delay(75); // Check every 75ms
    }
}

void holdRingTask() {
    while (true) {
        //prints for debugging
        pros::lcd::print(5, "HoldRing Task Running");
        pros::lcd::print(6, "Optical Value: %d", optical.get_proximity());
        // Check if the ring hold is enabled and the optical sensor detects a ring
        if (holdRingEnabled && optical.get_proximity() >= 200) {
            intakeSpeed = 0;
            pros::lcd::print(7, "Ring Detected: Intake Stopped");
        }

        pros::delay(10); // Check every 10ms
    }
}
// **Sorting Task for Red Rings**
void redSortTask() {
    while (true) {
        if (redSortEnabled && optical.get_proximity() >= 200) {
            int hue = optical.get_hue();
            if (hue >= 208 && hue <= 220) {
                intakeSpeed = 0; 
                intake11W.move_relative(250, 600); // Move intake to remove blue ring
                pros::delay(100);  
            } else {
                // int tempSpeed = intakeSpeed;  // Save current intake speed
                intakeSpeed = 0;  // Stop intake
                pros::delay(70);
            }
        }
        pros::delay(10);
    }
}

// **Sorting Task for Blue Rings**
void blueSortTask() {
    while (true) {
        if (blueSortEnabled && optical.get_proximity() >= 200) {
            int hue = optical.get_hue();
            if (hue >= 5 && hue <= 15) {
                intakeSpeed = 0;  
                intake11W.move_relative(250, 600); // Move intake to sort blue ring
                pros::delay(100);  
            } else {
                intakeSpeed = 0;  // Stop intake briefly if incorrect color
                pros::delay(70);
            }
        }
        pros::delay(10);
    }
}

// Function to start the intake tasks
void startIntakeTasks() {
    static pros::Task intakeController(intakeTask);
    static pros::Task intakeMonitor(checkIntakeTask);
    static pros::Task intakeHold(holdRingTask);
    static pros::Task redSort(redSortTask);
    static pros::Task blueSort(blueSortTask);

}


// Functions to control intake monitoring
void stopIntakeMonitoring() { checkIntakeEnabled = false; }
void startIntakeMonitoring() { checkIntakeEnabled = true; }

//Functions to control ring holds
void holdRing() { holdRingEnabled = true;            
 }
void releaseRing() { holdRingEnabled = false; }




//Color sort functions
// void redSort() { redSortEnabled= true; }
// void stopRed() {redSortEnabled = false;}

// void blueSort(){ blueSortEnabled = true;}
// void stopBlue(){blueSortEnabled = false;}