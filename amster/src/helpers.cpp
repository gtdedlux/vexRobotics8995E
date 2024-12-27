#include "main.h"

void setIntake(int intakePower){
    fintake.move(intakePower);
    
}

void monitorIntake(int intakePower) {
    intake11W.move(intakePower); // Set the intake motor to the desired power
    int stuckTime = 0;

    while (true) {
        if (intake11W.get_actual_velocity() == 0) {
            stuckTime += 100; // Increment the stuck time if velocity is 0
        } else {
            stuckTime = 0; // Reset the counter if velocity is non-zero
        }

        if (stuckTime >= 2000) { // If stuck for 2 seconds
            intake11W.move_relative(-500, intakePower); // Reverse briefly to clear jam
            pros::delay(500); // Allow the reverse action to complete
            intake11W.move(intakePower); // Resume normal operation
            stuckTime = 0; // Reset the timer
        }

        pros::delay(100); // Check velocity every 100 ms
    }
}


void moveIntake(int intakePower, bool reverse, int degrees){
    intake11W.move_relative(degrees, intakePower);

}

void mogoSwitch(){
    if(mogoMech.is_extended()){
        mogoMech.retract();
    }
    if(!(mogoMech.is_extended())){
        mogoMech.extend();
    }

}

void doinkerSwitch(){
    if(doinker.is_extended()){
        doinker.retract();
    }
    if(!(doinker.is_extended())){
        doinker.extend();
    }
}