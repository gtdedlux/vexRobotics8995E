#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "armControl.hpp"


ASSET(test_txt);

//add lemlib configs

void blueRightSide(){
    chassis.setPose(0, 0, 0);
        rush.extend();

    chassis.moveToPoint(0, 20, 1000);
        chassis.moveToPose(0, 5, 0, 1000, {.forwards = false});
pros::delay(2000);
    rush.retract();

}

void blueLeftSide(){
    // set chassis pose
    chassis.setPose(0, 0, 0);
    // lookahead distance: 15 inches
    // timeout: 2000 ms
    // chassis.follow(path_jerryio_txt, 15, 2000, false);

}

void redRightSide(){
}

void redLeftSide(){
}

// void intakeTask() {
//     setIntake(110);  // Run intake motor indefinitely
//      pros::lcd::print(6, "Intake task started");
//     while (true) {
//         pros::lcd::print(7, "Running...");
//         pros::delay(10);  // Keep the task alive
//     }
// }
void checkIntake(){
    if(intake11W.get_actual_velocity() == 0){
         intakeSpeed = -110;
         pros::delay(200);
         intakeSpeed = 115;
    }
}


int intakeSpeed = 0;


void intakeTask() {
    int lastSpeed = 0; // Track last intake speed
    while (true) {
        if (intakeSpeed != lastSpeed) { // Only update if speed changes
            setIntake(intakeSpeed);
            lastSpeed = intakeSpeed;
        }
        pros::delay(10); // Prevent CPU overload
    }
}

bool checkIntakeEnabled = false; // Flag to disable checking when needed
bool holdRingEnabled = false; // Flag to disable checking when needed



void checkIntakeTask() {
    while (true) {
        if (checkIntakeEnabled && intakeSpeed != 0 && intake11W.get_actual_velocity() == 0) {
            intakeSpeed = -110;
            pros::delay(200);
            intakeSpeed = 115;
        }
        pros::delay(100); // Check every 100ms
    }
}
void holdRingTask() {
    while (true) {
        if (holdRingEnabled && optical.get_proximity() <=20) {
            intakeSpeed = 0;
        }
        pros::delay(100); // Check every 100ms
    }
}

// Start the intake control and monitoring tasks
pros::Task intakeController(intakeTask);
pros::Task intakeMonitor(checkIntakeTask);
pros::Task intakeHold(holdRingTask);

void skills(){        
intakeSpeed = 110;
    pros::delay(300);
intakeSpeed = 0;
    pros::delay(200);
        checkIntakeEnabled = true; // Re-enable checking after stopping

    chassis.moveToPoint(0, 14, 4000);  
    chassis.moveToPose(19.5, 14, -90, 2150, {.forwards = false, .maxSpeed = 60}, true);
    pros::delay(1500);
    mogoMech.extend();
    chassis.turnToHeading(0, 500);
    intakeSpeed = 115;
    chassis.moveToPoint(24, 40, 2000);
            // checkIntake();

    chassis.turnToHeading(40, 200); 
            // checkIntake();

        chassis.moveToPose(47, 100, 0, 2000);
        pros::delay(300);
        // checkIntake();
        pros::delay(650);
        setArmTarget(24, 500);
         pros::delay(200);
        // checkIntake();


//64 68
//67
    // // wall stake
            setArmTarget(24, 500);
             chassis.moveToPoint(42, 68, 4000, {.forwards = false}, true);
              checkIntakeEnabled = false; // Disable checking before stopping intake
              chassis.turnToHeading(90, 200);
                     chassis.moveToPose(67, 68.3, 90,  1000,{.maxSpeed = 70});
                     pros::delay(450);
                    intakeSpeed = 0; 
                    pros::delay(600);
                    setArmTarget(145, 300);
                    chassis.moveToPoint(65.5, 68.3, 1000);
                    setArmTarget(145, 100);
                    pros::delay(300);
                                        intakeSpeed = 110;
                    chassis.moveToPoint(50, 68, 1000, {.forwards = false}, true);
                    pros::delay(400);
                    setArmTarget(40, 1500);
                    chassis.turnToHeading(180, 300);
                    // setArmTarget(0, 1500);
                    chassis.moveToPoint(50, 50, 2000);
                    checkIntakeEnabled = true; 
                    setArmTarget(-0.5, 1500);
                    // checkIntake();
                    chassis.moveToPoint(50, 20, 1000, {.maxSpeed = 80});
                    // checkIntake();
                    chassis.moveToPoint(50, 6, 1000, {.maxSpeed = 70});
                    // checkIntake();
                    chassis.moveToPoint(50, 31, 2000, {.forwards = false}, true);
                    chassis.moveToPoint(65, 16, 1000, {.maxSpeed = 90});
                    // checkIntake();
                    checkIntakeEnabled = false;
                    chassis.turnToHeading(-30, 300);
                    pros::delay(30);
                    chassis.moveToPoint(68, 5, 1000, { .forwards = false, .maxSpeed = 70});
                    pros::delay(1200);
                    mogoMech.retract();
                    intakeSpeed = -100;
                    pros::delay(150);
                    intakeSpeed = 0;


            chassis.moveToPoint(45, 16, 1000);
            chassis.turnToHeading(-47, 300);
            

// SECOND MOGO
                    chassis.moveToPoint(-7, 17, 4000, {.forwards = false}, true);
                    chassis.moveToPoint(-22, 17, 2150, {.forwards = false, .maxSpeed = 50}, true);
                    pros::delay(1300);
                    mogoMech.extend();
//reflection



                    chassis.turnToHeading(0, 500);
    intakeSpeed = 115;
    chassis.moveToPoint(-24, 40, 2000);
            // checkIntake();

    chassis.turnToHeading(-40, 200); 
            // checkIntake();

        chassis.moveToPose(-48, 100, 0, 2000);
        pros::delay(300);
        // checkIntake();
        pros::delay(650);
        setArmTarget(24, 500);
         pros::delay(200);
        // checkIntake();


//64 68
//67
    // // wall stake 2
            setArmTarget(24, 500);
             chassis.moveToPoint(-42, 67, 4000, {.forwards = false}, true);
              checkIntakeEnabled = false; // Disable checking before stopping intake
              chassis.turnToHeading(-90, 200);
                     chassis.moveToPose(-68, 67, 90,  1000,{.maxSpeed = 70});
                     pros::delay(450);
                    intakeSpeed = 0; 
                    pros::delay(600);
                    setArmTarget(145, 300);
                    chassis.moveToPoint(-66, 67, 1000);
                    pros::delay(300);
                                        intakeSpeed = 110;
                    chassis.moveToPoint(-49, 67, 1000, {.forwards = false}, true);
                    setArmTarget(145, 100);
                    pros::delay(400);
                    setArmTarget(40, 1500);
                    chassis.turnToHeading(180, 300);
                    // setArmTarget(0, 1500);
                    chassis.moveToPoint(-48, 50, 2000);
                    checkIntakeEnabled = true; 
                    setArmTarget(-0.5, 1500);
                    // checkIntake();
                    chassis.moveToPoint(-48, 20, 1000, {.maxSpeed = 80});
                    // checkIntake();
                    chassis.moveToPoint(-48, 6, 1000, {.maxSpeed = 70});
                    // checkIntake();
                    chassis.moveToPoint(-48, 31, 2000, {.forwards = false}, true);
                    chassis.moveToPoint(-65, 16, 1000, {.maxSpeed = 90});
                    // checkIntake();
                    checkIntakeEnabled = false;
                    chassis.turnToHeading(30, 300);
                    pros::delay(30);
                    chassis.moveToPoint(-68, 5, 1000, { .forwards = false, .maxSpeed = 70});
                    pros::delay(1200);
                    mogoMech.retract();
                    intakeSpeed = -100;
                    pros::delay(150);
                    intakeSpeed = 0;


            chassis.moveToPoint(-50, 70, 1000);
            chassis.moveToPoint(-26, 94, 1000);
   
    
    
    pros::delay(1000); // Let the intake run for 5 seconds
    intakeController.remove(); // Stop the intake task
    setIntake(0); // Stop intake motor 

}

