#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "armControl.hpp"


ASSET(test_txt);

//add lemlib configs

void blueRingRush(){

    chassis.setPose(23,13, 24);
    chassis.moveToPoint(39.6, 50, 1500);
    pros::delay(500);
    rush.extend();
    chassis.moveToPoint(30.5, 30, 1500, {.forwards = false});
    //chassis.turnToHeading(0, 300);
    pros::delay(1000);
    rush.retract();
    chassis.turnToHeading(160,300 , { .maxSpeed = 60});
    chassis.moveToPoint(20, 41, 4000, {.forwards = false, .maxSpeed = 50});
    pros::delay(1600);
    mogoMech.extend();
        pros::delay(50);
    intakeSpeed = 115;
    chassis.moveToPoint(11, 46, 4000, {.forwards = false, .maxSpeed = 40});
    pros::delay(50);
        chassis.turnToHeading(87,300);
    chassis.moveToPoint(50, 46, 2000, {.maxSpeed = 80});
    // holdRing();
    // redSortEnabled = true;
    chassis.moveToPoint(59, 46, 2000, {.maxSpeed = 50});
    pros::delay(200);
    startIntakeMonitoring(); // Re-enable checking after stopping
     chassis.moveToPoint(20, 42, 2000, {.forwards = false, .maxSpeed = 100});
     chassis.turnToHeading(0,300);
     chassis.moveToPoint(24,53, 1000);

}

void blueLeftSide(){
  chassis.setPose(-5,0,141);
    setArmTarget(140,300);
    pros::delay(300);
    setArmTarget(-0.5,300);
    // pros::delay(200);
    // chassis.moveToPose(21, 30, -190, 2000,{.forwards = false} );
    chassis.moveToPoint(-25, 20, 1000, {.forwards = false} );
    chassis.turnToHeading(220, 300);
    chassis.moveToPoint(-16, 39, 1000, {.forwards = false} );
    pros::delay(900);
    mogoMech.extend();
    pros::delay(200);

    intakeSpeed = 115;
    chassis.turnToHeading(262, 300);
    chassis.moveToPoint(-43, 34, 1000 );
    intakeSpeed = 0; 
    chassis.turnToHeading(183, 300);
    // chassis.moveToPose(-57, -4.5, 220, 2000);
    // pros::delay(1500);
    // chassis.moveToPoint(-21.5, 48, 3000 );

}
void blueLeftSideRush(){
  chassis.setPose(-58, 10, 0);
    chassis.moveToPoint(-55,47,1000);
    pros::delay(700);
    doinker.extend();
    chassis.moveToPoint(-57, 27, 1000, {.forwards = false});
    pros::delay(700);
    doinker.retract();
    chassis.turnToHeading(-173, 300);
    chassis.moveToPose(-54,36, -173, 500,{.forwards = false});
    chassis.moveToPoint(-47,47, 500,{.forwards = false, .maxSpeed = 60});
    pros::delay(1250);
        intakeSpeed = 115;
    mogoMech.extend();
    pros::delay(100);
    chassis.moveToPose(-37, 7, -44, 2000, {.forwards = false,  .maxSpeed = 90} );
    pros::delay(1500);
            intakeSpeed = 0;
        mogoMech.retract();

        chassis.turnToHeading(-140, 300);
    chassis.moveToPoint(-15,45 , 2500,{.forwards = false, .maxSpeed = 60});
    pros::delay(1500);
    mogoMech.extend();
    chassis.turnToHeading(-45, 500);
    intakeSpeed = 115;
    chassis.moveToPoint(-23, 47, 1000);
    chassis.swingToHeading(-135, lemlib::DriveSide::RIGHT, 500);
    chassis.moveToPoint(-33, 40, 1200);

    chassis.moveToPose(-61, 0, -135, 1200);
    pros::delay(100);
    chassis.moveToPoint(-62, -1, 1200);
    pros::delay(500);
    chassis.moveToPoint(-56, 10, 1000, {.forwards = false});
    pros::delay(500);
    chassis.moveToPose(-22.4, 52, 12.7, 3000);

}
void redRightSide(){
    chassis.setPose(5,0,-141);
    setArmTarget(150,300);
    pros::delay(300);
    setArmTarget(-0.5,300);
    // pros::delay(200);
    // chassis.moveToPose(21, 30, -190, 2000,{.forwards = false} );
    startIntakeMonitoring();
    chassis.moveToPoint(25, 20, 1000, {.forwards = false} );
    chassis.turnToHeading(-220, 300);
    chassis.moveToPoint(16, 39, 1000, {.forwards = false} );
    pros::delay(900);
    mogoMech.extend();
    pros::delay(200);

    intakeSpeed = 115;
    chassis.turnToHeading(-262, 300);
    chassis.moveToPoint(44, 34, 1000 );
    chassis.turnToHeading(-170, 300);
    // chassis.moveToPose(57, -4.5, -222, 2000, {.maxSpeed = 90});
    // pros::delay(1500);
    // stopIntakeMonitoring();


    chassis.moveToPoint(21.5, 48, 3000, {.maxSpeed = 70} );


    pros::delay(2000); // Let the intake run for 5 seconds
    // // intakeController.remove(); // Stop the intake task
    // setIntake(0); // Stop intake motor 





}

void redRightSideRush(){
    chassis.setPose(58, 10, 0);
    chassis.moveToPoint(55,47,1000);
    pros::delay(700);
    doinker.extend();
    chassis.moveToPoint(57, 27, 1000, {.forwards = false});
    pros::delay(700);
    doinker.retract();
    chassis.turnToHeading(173, 300);
    chassis.moveToPose(54,36, 173, 500,{.forwards = false});
    chassis.moveToPoint(47,47, 500,{.forwards = false, .maxSpeed = 60});
    pros::delay(1250);
        intakeSpeed = 115;
    mogoMech.extend();
    pros::delay(100);
    chassis.moveToPose(37, 7, 44, 2000, {.forwards = false,  .maxSpeed = 90} );
    pros::delay(1500);
            intakeSpeed = 0;
        mogoMech.retract();

        chassis.turnToHeading(140, 300);
    chassis.moveToPoint(15,45 , 2500,{.forwards = false, .maxSpeed = 60});
    pros::delay(1500);
    mogoMech.extend();
    chassis.turnToHeading(45, 500);
    intakeSpeed = 115;
    chassis.moveToPoint(23, 47, 1000);
    chassis.swingToHeading(135, lemlib::DriveSide::RIGHT, 500);
    chassis.moveToPoint(33, 40, 1200);

    chassis.moveToPose(61, 0, 135, 1200);
    pros::delay(100);
    chassis.moveToPoint(62, -1, 1200);
    pros::delay(500);
    chassis.moveToPoint(56, 10, 1000, {.forwards = false});
    pros::delay(500);
    chassis.moveToPose(22.4, 52, -12.7, 3000);






    pros::delay(2000); // Let the intake run for 5 seconds
    // intakeController.remove(); // Stop the intake task
    setIntake(0); // Stop intake motor 

}
void redRingRush(){
    
    chassis.setPose(-23,13, -24);
    chassis.moveToPoint(-39.6, 50, 1500);
    pros::delay(500);
    rush.extend();
    chassis.moveToPoint(-30.5, 30, 1500, {.forwards = false});
    //chassis.turnToHeading(0, 300);
    pros::delay(1000);
    rush.retract();
    chassis.turnToHeading(-160,300 , { .maxSpeed = 60});
    chassis.moveToPoint(-20, 41, 4000, {.forwards = false, .maxSpeed = 50});
    pros::delay(1600);
    mogoMech.extend();
        pros::delay(50);
    intakeSpeed = 115;
    chassis.moveToPoint(-11, 46, 4000, {.forwards = false, .maxSpeed = 40});
    pros::delay(50);
        chassis.turnToHeading(-87,300);
    chassis.moveToPoint(-50, 46, 2000, {.maxSpeed = 80});
    // holdRing();
    // redSortEnabled = true;
    chassis.moveToPoint(-59, 46, 2000, {.maxSpeed = 50});
    pros::delay(200);
    startIntakeMonitoring(); // Re-enable checking after stopping
         chassis.moveToPoint(-20, 42, 2000, {.forwards = false, .maxSpeed = 100});
     chassis.turnToHeading(0,300);
     chassis.moveToPoint(-24,53, 1000);


    pros::delay(2000); // Let the intake run for 5 seconds

}
void redLeftSide(){
}


void skills(){    
 // Set initial pose of the robot
chassis.setPose(0, -0.4, 0);

// Start intake to drop first ring into alliance stake
intakeSpeed = 110;
pros::delay(300);
intakeSpeed = 0;
pros::delay(200);

// Enable intake monitoring so that intake doens't get stuck on rings
startIntakeMonitoring(); 

// Move to ring near center line
chassis.moveToPoint(0, 14, 4000);  

// Approach first mobile goal
chassis.moveToPose(19.5, 14, -90, 2150, {.forwards = false, .maxSpeed = 60}, true);
pros::delay(1500);

// Extend clamp to grab first mobile goal
mogoMech.extend();

// Turn back toward field center
chassis.turnToHeading(0, 500);

// Intake next ring
intakeSpeed = 115;
chassis.moveToPoint(24, 40, 2000);

// Turn toward far side ring
chassis.turnToHeading(40, 200); 

// Move to far side ring
chassis.moveToPose(47, 100, 0, 2000);
pros::delay(300);
pros::delay(650);

// Raise arm to hold ring and prepare for wall stake
setArmTarget(24, 500);
pros::delay(200);
setArmTarget(24.5, 500);

// Back into wall to stake
chassis.moveToPoint(42, 68, 4000, {.forwards = false}, true);
stopIntakeMonitoring(); // Disable monitoring while pushing against wall

// Turn to face parallel to wall
chassis.turnToHeading(90, 200);

// Move alongside wall to align for goal
chassis.moveToPose(66, 68.3, 90, 1000, {.maxSpeed = 70});
pros::delay(450);

// Drop first mobile goal
intakeSpeed = 0; 
pros::delay(600);
setArmTarget(150, 300);
chassis.moveToPoint(65.5, 68.3, 1000);
pros::delay(300);

// Reactivate intake to collect another ring
intakeSpeed = 115;

// Back away from wall
chassis.moveToPoint(50, 68, 1000, {.forwards = false}, true);
pros::delay(500);

// Lower arm to intake position
setArmTarget(40, 1500);

// Turn and move to center
chassis.turnToHeading(180, 300);
chassis.moveToPoint(50, 50, 2000);

// Resume intake monitoring
startIntakeMonitoring();

// Bring arm back to intake position
setArmTarget(-0.5, 1500);

// Move to bottom of field to collect more rings
chassis.moveToPoint(50, 20, 1000, {.maxSpeed = 80});
chassis.moveToPoint(50, 6, 1000, {.maxSpeed = 70});
chassis.moveToPoint(50, 31, 2000, {.forwards = false}, true);
chassis.moveToPoint(65, 16, 1000, {.maxSpeed = 90});

// Disable intake monitoring before robot touches wall
stopIntakeMonitoring();
chassis.turnToHeading(-30, 300);
pros::delay(30);

// Back into corner and drop stake
chassis.moveToPoint(68, 5, 1000, { .forwards = false, .maxSpeed = 70});
pros::delay(1200);
mogoMech.retract();

// Reverse intake to settle rings
intakeSpeed = -100;
pros::delay(150);
intakeSpeed = 0;

// Move away and turn toward next mobile goal
startIntakeMonitoring();
chassis.moveToPoint(45, 16, 1000);
chassis.turnToHeading(-47, 300);

// SECOND MOBILE GOAL

// Backtrack to second goal position and clamp
chassis.moveToPoint(-7, 17, 4000, {.forwards = false}, true);
chassis.moveToPoint(-22, 17, 2150, {.forwards = false, .maxSpeed = 50}, true);
pros::delay(1300);
mogoMech.extend();

// Turn and collect more rings
chassis.turnToHeading(0, 500);
intakeSpeed = 115;
chassis.moveToPoint(-24, 40, 2000);
chassis.turnToHeading(-38, 200); 
chassis.moveToPose(-46.5, 100, 0, 2000);
pros::delay(300);
pros::delay(650);

// Raise arm again to hold ring and prepare for second wall stake 
setArmTarget(24, 500);
pros::delay(200);
setArmTarget(24.5, 500);
chassis.moveToPoint(-42, 67.5, 4000, {.forwards = false}, true);
stopIntakeMonitoring();
chassis.turnToHeading(-90, 200);
chassis.moveToPose(-68, 67.5, 90, 1000, {.maxSpeed = 70});
pros::delay(450);

//stop intake so that rings don't get stuck
intakeSpeed = 0; 
pros::delay(600);
setArmTarget(150, 300);
chassis.moveToPoint(-66, 67.5, 1000);
pros::delay(300);

// Reactivate intake
intakeSpeed = 115;

// Back off from wall
chassis.moveToPoint(-49, 67.5, 1000, {.forwards = false}, true);
setArmTarget(150, 100);
pros::delay(400);
setArmTarget(40, 1500);
chassis.turnToHeading(180, 300);
chassis.moveToPoint(-47, 50, 2000);
startIntakeMonitoring();
setArmTarget(-0.5, 1500);

// Collect more rings
chassis.moveToPoint(-46.7, 20, 1000, {.maxSpeed = 80});
chassis.moveToPoint(-46.7, 6, 1000, {.maxSpeed = 70});
chassis.moveToPoint(-46.7, 31, 2000, {.forwards = false}, true);
chassis.moveToPoint(-65, 16, 1000, {.maxSpeed = 90});

// Disable monitoring before interaction
stopIntakeMonitoring();
chassis.turnToHeading(30, 300);
pros::delay(30);

// Drop second mobile goal in corner
chassis.moveToPoint(-68, 5, 1000, { .forwards = false, .maxSpeed = 70});
pros::delay(1200);
mogoMech.retract();
intakeSpeed = -100;
pros::delay(150);

// Move to next ring and collect
chassis.moveToPoint(-50, 70, 1000);
intakeSpeed = 115;
chassis.moveToPose(-27, 90, 38.7, 1200);

//hold intake when ring is collected because mogo is not clamped on yet
holdRing();
chassis.turnToHeading(-120, 300);
chassis.moveToPoint(-2, 125, 1200, { .forwards = false , .maxSpeed = 80});
pros::delay(1600);

// Grab third mobile goal
mogoMech.extend();
pros::delay(300);
//releases ring now that mogo is clamped
releaseRing();
startIntakeMonitoring();

// Collect more rings from top corner
intakeSpeed = 115;
chassis.turnToHeading(-232, 300);
chassis.moveToPoint(25, 101, 1500);
chassis.moveToPoint(38, 117, 1500);
chassis.moveToPoint(55, 122, 1500);
pros::delay(100);

// Backtrack and reposition
chassis.moveToPoint(30, 117, 1500, { .forwards = false});
chassis.moveToPoint(40, 130, 1500);

// Swing turn for corner placement
chassis.swingToHeading(-160,  lemlib::DriveSide::RIGHT, 1500);
pros::delay(50);

// Stop intake and place goal
intakeSpeed = 0;
chassis.moveToPose(55 , 133, -160, 1500, { .forwards = false});
pros::delay(500);
mogoMech.retract();

// Finally push 4th mobile goal into corner
chassis.moveToPoint(38, 115, 1500);
chassis.moveToPoint(-23, 130, 1500);
chassis.moveToPoint(-65, 133, 1500);

// Hang
chassis.turnToHeading(-51.3, 300);
chassis.moveToPoint(-13, 78.5, 3000, {.forwards = false,.maxSpeed = 80});
pros::delay(500);
setArmTarget(150, 300);
pros::delay(1000);
setArmTarget(-0.5, 700);

// Final delay and stop intake
pros::delay(1000);
setIntake(0);


}

