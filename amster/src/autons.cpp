#include "main.h"

/////
// For installation, upgrading, documentations, and tutorials, check out our website!
// https://ez-robotics.github.io/EZ-Template/
/////

// These are out of 127
const int DRIVE_SPEED = 110;
const int TURN_SPEED = 80;
const int SWING_SPEED = 100;

///
// Constants
///


void default_constants() {
  chassis.pid_drive_constants_forward_set(10, 0.026, 100);
  chassis.pid_drive_constants_backward_set(8, 0.011, 99.5);

  chassis.pid_heading_constants_set(11, 0, 20);
  //chassis.pid_drive_constants_set(5, 0.026, 100); //23
  chassis.pid_turn_constants_set(4, 0.05, 22.25, 15);
  chassis.pid_swing_constants_set(9.2, 0.01, 73.75);

  chassis.pid_turn_exit_condition_set(80_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_swing_exit_condition_set(80_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_drive_exit_condition_set(80_ms, 1_in, 250_ms, 3_in, 400_ms, 400_ms);

  chassis.pid_turn_chain_constant_set(3_deg);
  chassis.pid_swing_chain_constant_set(5_deg);
  chassis.pid_drive_chain_constant_set(3_in);

  chassis.slew_drive_constants_set(7_in, 80);
  liftPID.exit_condition_set(80, 50, 300, 150, 500, 500);

}

void lift_auto(double target) {
 liftPID.target_set(target);
  ez::exit_output exit = ez::RUNNING;
  while (liftPID.exit_condition(ladyB, true) == ez::RUNNING) {
    set_lift(liftPID.compute(ladyB.get_position()));
    pros::delay(ez::util::DELAY_TIME);
  }
  set_lift(0);
}

void BlueRightSide(){
  chassis.pid_drive_set(-16.5_in,90);
  chassis.pid_wait_quick_chain();
  chassis.pid_swing_set(ez::RIGHT_SWING, 10_deg, SWING_SPEED, 5);
  chassis.pid_wait_quick_chain();
  chassis.pid_swing_set(ez::LEFT_SWING, -3_deg, SWING_SPEED, 5);
  chassis.pid_wait();
  mogoMech.extend();
  pros::delay(800); //tweak based on mogo time
  setIntake(100);
  chassis.pid_turn_set(-105_deg, 80);
  chassis.pid_wait();
  chassis.pid_drive_set(23_in, DRIVE_SPEED);
  chassis.pid_wait();
   setIntake(-110);
  pros::delay(100);
  setIntake(110);
  pros::delay(100);
  chassis.pid_drive_set(5_in, 10); //so ring has time to reach mogo
  chassis.pid_wait();
 //top 2 rings
  chassis.pid_swing_set(ez::RIGHT_SWING, -200_deg, SWING_SPEED, 10);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(2_in, DRIVE_SPEED);
  chassis.pid_wait();
  pros::delay(500);
    setIntake(-110);
  pros::delay(150);
  setIntake(110);
  pros::delay(200);
   chassis.pid_swing_set(ez::RIGHT_SWING, -160_deg, SWING_SPEED, 53);
  chassis.pid_wait();
    chassis.pid_turn_set(-205_deg, 80);
  chassis.pid_wait();
    chassis.pid_drive_set(24_in, DRIVE_SPEED);
  chassis.pid_wait();
  pros::delay(500);
  chassis.pid_swing_set(ez::RIGHT_SWING, -40_deg, SWING_SPEED, 15);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(25_in, DRIVE_SPEED);
  chassis.pid_wait();

}

void BlueLeftSide(){
  // while(true){
  //   ez::screen_print(util::to_string_with_precision(eye.get_proximity()), 3);
  // }

  chassis.pid_drive_set(-16.5_in,90);
  chassis.pid_wait_quick_chain();
  chassis.pid_swing_set(ez::RIGHT_SWING, 10_deg, SWING_SPEED, 5);
  chassis.pid_wait_quick_chain();
  chassis.pid_swing_set(ez::LEFT_SWING, -3_deg, SWING_SPEED, 9);
  chassis.pid_wait();
  mogoMech.extend();
  pros::delay(800); //tweak based on mogo time
  setIntake(110);
  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();
  mogoMech.retract();
  runIntake(-100, 550);
  pros::delay(200);
  setIntake(110);
  chassis.pid_swing_set(ez::LEFT_SWING, 117_deg, SWING_SPEED, 68);
  chassis.pid_wait();
  pros::delay(85);
  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();
  setIntake(0);
   chassis.pid_drive_set(-19_in,100);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(-3_in,50);
  chassis.pid_wait();
  mogoMech.extend();
      pros::delay(500);
    setIntake(110);
  chassis.pid_drive_set(20.5_in, DRIVE_SPEED);
  chassis.pid_wait();
  pros::delay(500);



}
void RedRightSide(){
  chassis.pid_drive_set(-16.5_in,90);
  chassis.pid_wait_quick_chain();
  chassis.pid_swing_set(ez::RIGHT_SWING, 10_deg, SWING_SPEED, 5);
  chassis.pid_wait_quick_chain();
  chassis.pid_swing_set(ez::LEFT_SWING, -3_deg, SWING_SPEED, 9);
  chassis.pid_wait();
  mogoMech.extend();
  pros::delay(800); //tweak based on mogo time
  setIntake(110);
  chassis.pid_turn_set(-90_deg, TURN_SPEED);
  chassis.pid_wait();
  mogoMech.retract();
  runIntake(-100, 550);
  pros::delay(200);
  setIntake(110);
  chassis.pid_swing_set(ez::RIGHT_SWING, -117_deg, SWING_SPEED, 68);
  chassis.pid_wait();
  pros::delay(85);
  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();
  setIntake(0);
   chassis.pid_drive_set(-19_in,100);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(-3_in,50);
  chassis.pid_wait();
  mogoMech.extend();
  pros::delay(500);
    setIntake(110);
  chassis.pid_drive_set(20.5_in, DRIVE_SPEED);
  chassis.pid_wait();
    pros::delay(500);

  

}

void RedLeftSide(){
  chassis.pid_drive_set(-16.5_in,90);
  chassis.pid_wait_quick_chain();
  chassis.pid_swing_set(ez::RIGHT_SWING, 10_deg, SWING_SPEED, 5);
  chassis.pid_wait_quick_chain();
  chassis.pid_swing_set(ez::LEFT_SWING, -3_deg, SWING_SPEED, 5);
  chassis.pid_wait();
  mogoMech.extend();
  pros::delay(800); //tweak based on mogo time
  setIntake(100);
  chassis.pid_turn_set(105_deg, 80);
  chassis.pid_wait();
  chassis.pid_drive_set(23_in, DRIVE_SPEED);
  chassis.pid_wait();
   setIntake(-110);
  pros::delay(100);
  setIntake(110);
  pros::delay(100);
  chassis.pid_drive_set(6_in, 10); //so ring has time to reach mogo
  chassis.pid_wait();
 //top 2 rings
  chassis.pid_swing_set(ez::LEFT_SWING, 200_deg, SWING_SPEED, 10);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(2_in, DRIVE_SPEED);
  chassis.pid_wait();
    pros::delay(500);
      setIntake(-110);
  pros::delay(100);
  setIntake(110);
  pros::delay(100);
   chassis.pid_swing_set(ez::LEFT_SWING, 160_deg, SWING_SPEED, 53);
  chassis.pid_wait();
    chassis.pid_turn_set(205_deg, 80);
  chassis.pid_wait();
    chassis.pid_drive_set(23.5_in, DRIVE_SPEED);
  chassis.pid_wait();
  pros::delay(500);
  chassis.pid_drive_set(-5_in, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
   setIntake(-110);
  pros::delay(100);
  setIntake(110);
  pros::delay(500);


}

void skills(){  
  setIntake(110);
  pros::delay(300);
  setIntake(0);
  pros::delay(200);
  
  chassis.pid_drive_set(16_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-90_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-18_in, DRIVE_SPEED);
  chassis.pid_wait();
  
  chassis.pid_drive_set(-1_in, 50);
  chassis.pid_wait_quick();
  
  mogoMech.extend();
  pros::delay(200);

  chassis.pid_drive_set(-9_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  setIntake(115);
  
  chassis.pid_drive_set(22_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(86_deg, TURN_SPEED);
  chassis.pid_wait();

  setIntake(-110);
  pros::delay(150);
  setIntake(110);
  pros::delay(200);


  chassis.pid_drive_set(22_in, DRIVE_SPEED);
  chassis.pid_wait();

  pros::delay(700);

  chassis.pid_turn_set(180_deg, TURN_SPEED);
  chassis.pid_wait();

  setIntake(-110);
  pros::delay(150);
  setIntake(115);

  chassis.pid_drive_set(20_in, 70);
  chassis.pid_wait();

  chassis.pid_drive_set(15.5_in, 40);
  chassis.pid_wait();

  setIntake(-110);
  pros::delay(200);
  setIntake(110);

  chassis.pid_swing_set(ez::LEFT_SWING, 77_deg, SWING_SPEED, 0);
  chassis.pid_wait();

  chassis.pid_drive_set(20_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-20_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-15_in, DRIVE_SPEED);
  chassis.pid_wait();

  mogoMech.retract();
  pros::delay(300);

  setIntake(-110);
  pros::delay(100);
  setIntake(0);
  pros::delay(200);
  chassis.pid_drive_set(11_in, DRIVE_SPEED);
  chassis.pid_wait();

  //_________________________
  //second mogo

  chassis.pid_turn_set(90.3_deg, TURN_SPEED);
  chassis.pid_wait();
  
  chassis.pid_drive_set(-76_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-8_in, 40);
  chassis.pid_wait();
  
  mogoMech.extend();
  pros::delay(400);

  chassis.pid_drive_set(-3_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  setIntake(115);
  
  chassis.pid_drive_set(22_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-86_deg, TURN_SPEED);
  chassis.pid_wait();

  setIntake(-115);
  pros::delay(150);
  setIntake(110);
  pros::delay(200);


  chassis.pid_drive_set(23_in, DRIVE_SPEED);
  chassis.pid_wait();

  pros::delay(500);


  chassis.pid_turn_relative_set(-90_deg, TURN_SPEED);
  chassis.pid_wait();

  setIntake(-110);
  pros::delay(150);
  setIntake(110);

  chassis.pid_drive_set(20_in, 70);
  chassis.pid_wait();

  chassis.pid_drive_set(15.5_in, 40);
  chassis.pid_wait();

  setIntake(-110);
  pros::delay(200);
  setIntake(110);

  chassis.pid_swing_set(ez::RIGHT_SWING, -77_deg, SWING_SPEED, 0);
  chassis.pid_wait();

  chassis.pid_drive_set(20_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(20_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-15_in, DRIVE_SPEED);
  chassis.pid_wait();

  mogoMech.retract();
  pros::delay(200);

  setIntake(-110);
  pros::delay(150);
  setIntake(0);
    chassis.pid_drive_set(10_in, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  //wall stake and other 


  chassis.pid_turn_set(0, TURN_SPEED); 
  chassis.pid_wait_quick_chain();
  setIntake(110);
  chassis.pid_drive_set(49_in, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  lift_auto(-350);
  pros::delay(130);
  chassis.pid_drive_set(-4_in, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_turn_relative_set(-93, TURN_SPEED);
  chassis.pid_wait();
  pros::delay(25);
  setIntake(0);
  chassis.pid_drive_set(7_in, 50);
  chassis.pid_wait();
  lift_auto(-1750);
  pros::delay(50);
  lift_auto(-0);

  //corners
  chassis.pid_drive_set(-7_in, 50);
  chassis.pid_wait_quick_chain();
  chassis.pid_turn_relative_set(-32, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(-103_in, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_turn_relative_set(30, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(-35_in, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(85_in, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_turn_relative_set(25, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(22_in, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(-5_in, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  pros::delay(100);
   chassis.pid_turn_relative_set(10, TURN_SPEED);
  chassis.pid_wait_quick_chain();
    chassis.pid_drive_set(6_in, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();







}


///
// Drive Example
///
void drive_example() {
  // The first parameter is target inches
  // The second parameter is max speed the robot will drive at
  // The third parameter is a boolean (true or false) for enabling/disabling a slew at the start of drive motions
  // for slew, only enable it when the drive distance is greater than the slew distance + a few inches

  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_drive_set(-12_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-12_in, DRIVE_SPEED);
  chassis.pid_wait();
}

///
// Turn Example
///
void turn_example() {
  // The first parameter is the target in degrees
  // The second parameter is max speed the robot will drive at

  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();
}

///
// Combining Turn + Drive
///
void drive_and_turn() {
  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-24_in, DRIVE_SPEED, true);
  chassis.pid_wait();
}

///
// Wait Until and Changing Max Speed
///
void wait_until_change_speed() {
  // pid_wait_until will wait until the robot gets to a desired position

  // When the robot gets to 6 inches slowly, the robot will travel the remaining distance at full speed
  chassis.pid_drive_set(24_in, 30, true);
  chassis.pid_wait_until(6_in);
  chassis.pid_speed_max_set(DRIVE_SPEED);  // After driving 6 inches at 30 speed, the robot will go the remaining distance at DRIVE_SPEED
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  // When the robot gets to -6 inches slowly, the robot will travel the remaining distance at full speed
  chassis.pid_drive_set(-24_in, 30, true);
  chassis.pid_wait_until(-6_in);
  chassis.pid_speed_max_set(DRIVE_SPEED);  // After driving 6 inches at 30 speed, the robot will go the remaining distance at DRIVE_SPEED
  chassis.pid_wait();
}

///
// Swing Example
///
void swing_example() {
  // The first parameter is ez::LEFT_SWING or ez::RIGHT_SWING
  // The second parameter is the target in degrees
  // The third parameter is the speed of the moving side of the drive
  // The fourth parameter is the speed of the still side of the drive, this allows for wider arcs

  chassis.pid_swing_set(ez::LEFT_SWING, 45_deg, SWING_SPEED, 45);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::RIGHT_SWING, 0_deg, SWING_SPEED, 45);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::RIGHT_SWING, 45_deg, SWING_SPEED, 45);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::LEFT_SWING, 0_deg, SWING_SPEED, 45);
  chassis.pid_wait();
}

///
// Motion Chaining
///
void motion_chaining() {
  // Motion chaining is where motions all try to blend together instead of individual movements.
  // This works by exiting while the robot is still moving a little bit.
  // To use this, replace pid_wait with pid_wait_quick_chain.
  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait_quick_chain();

  chassis.pid_turn_set(-45_deg, TURN_SPEED);
  chassis.pid_wait_quick_chain();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  // Your final motion should still be a normal pid_wait
  chassis.pid_drive_set(-24_in, DRIVE_SPEED, true);
  chassis.pid_wait();
}

///
// Auto that tests everything
///
void combining_movements() {
  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::RIGHT_SWING, -45_deg, SWING_SPEED, 45);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-24_in, DRIVE_SPEED, true);
  chassis.pid_wait();
}

///
// Interference example
///
void tug(int attempts) {
  for (int i = 0; i < attempts - 1; i++) {
    // Attempt to drive backward
    printf("i - %i", i);
    chassis.pid_drive_set(-12_in, 127);
    chassis.pid_wait();

    // If failsafed...
    if (chassis.interfered) {
      chassis.drive_sensor_reset();
      chassis.pid_drive_set(-2_in, 20);
      pros::delay(1000);
    }
    // If the robot successfully drove back, return
    else {
      return;
    }
  }
}

// If there is no interference, the robot will drive forward and turn 90 degrees.
// If interfered, the robot will drive forward and then attempt to drive backward.
void interfered_example() {
  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  if (chassis.interfered) {
    tug(3);
    return;
  }

  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();
}

// . . .
// Make your own autonomous functions here!
// . . .