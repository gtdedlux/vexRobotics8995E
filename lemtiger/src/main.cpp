#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "pros/llemu.hpp"
#include "armControl.hpp"



pros::Controller master(pros::E_CONTROLLER_MASTER);

pros::MotorGroup left_mg({-16, -11, -6},pros::MotorGearset::blue);   
pros::MotorGroup right_mg({1, 2, 19}, pros::MotorGearset::blue);  


// drivetrain settings
lemlib::Drivetrain drivetrain(&left_mg, // left motor group
                              &right_mg, // right motor group
                              13, //track width
                              lemlib::Omniwheel::NEW_325, // using new 3.25" omnis
                              450, // drivetrain rpm 
                              2 // horizontal drift is 2 (for now)
);



pros::Imu imu(9);
// horizontal tracking wheel encoder

        // pros::Rotation horizontal_encoder(4);

// vertical tracking wheel encoder
pros::Rotation vertical_encoder(-4);
// horizontal tracking wheel

        // lemlib::TrackingWheel horizontal_tracking_wheel(&horizontal_encoder, lemlib::Omniwheel::NEW_2, 2.625); 

// vertical tracking wheel
lemlib::TrackingWheel vertical_tracking_wheel(&vertical_encoder, lemlib::Omniwheel::NEW_2, -.5); 
// odometry settings
lemlib::OdomSensors sensors(&vertical_tracking_wheel, // vertical tracking wheel 1, set to null
                            nullptr, // vertical tracking wheel 2, set to nullptr as we are using IMEs
                            nullptr, // horizontal tracking wheel 1
                            nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                            &imu // inertial sensor
);

// lateral PID controller
lemlib::ControllerSettings lateral_controller(18, // proportional gain (kP)
                                              0.02, // integral gain (kI)
                                              95, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in inches
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in inches
                                              500, // large error range timeout, in milliseconds
                                              20 // maximum acceleration (slew)
);

// angular PID controller
lemlib::ControllerSettings angular_controller(8, // proportional gain (kP)
                                            0, // integral gain (kI)
                                              70, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in inches
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in inches
                                              500, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
);

// input curve for throttle input during driver control
lemlib::ExpoDriveCurve throttle_curve(3, // joystick deadband out of 127
                                     10, // minimum output where drivetrain will move out of 127
                                     1.019 // expo curve gain
);

// // input curve for steer input during driver control
// lemlib::ExpoDriveCurve steer_curve(3, // joystick deadband out of 127
//                                   10, // minimum output where drivetrain will move out of 127
//                                   1.019 // expo curve gain
// );

// create the chassis
lemlib::Chassis chassis(drivetrain,
                        lateral_controller,
                        angular_controller,
                        sensors,
                        &throttle_curve

);

lemlib::PID armPID(4.5, 0.02, 8, 5, false);




/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */

void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
	
}


/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */


void initialize() {
    pros::lcd::initialize(); // initialize brain screen

    chassis.calibrate(); // calibrate chassis sensors + imu
    aSelector.calibrate();
    ladyB.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    optical.set_led_pwm(50);
    armSensor.reset();
    startIntakeTasks();






// print position to brain screen for debugging
                    pros::Task screen_task([&]() {
                        while (true) {
                            // print robot location to the brain screen
                            pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
                            pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
                            pros::lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading
                            pros::lcd::print(4, "IMU Heading: %f", imu.get_heading());
                           // pros::lcd::print(7, "ARM: %d", armSensor.get_position());


                            // delay to save resources
                            pros::delay(20);
                        }
                    });
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */

int auton_selection = 0; // Global variable to store selected autonomous routine

// List of autonomous routines
const char* auton_names[] = {
    "Blue Right Side",
    "Blue Left Side",
    "Red Right Side",
    "Red Left Side",
    "Skills",
    "None"
};



void competition_initialize() {
    pros::lcd::initialize();

    if(aSelector.get_value() < 800){
        auton_selection = 0;
    } else if(aSelector.get_value() < 1600){
        auton_selection = 1;
    } else if(aSelector.get_value() < 2400){
        auton_selection = 2;
    } else if(aSelector.get_value() < 3200){
        auton_selection = 3;
    } else if(aSelector.get_value() < 4095){
        auton_selection = 4;
    } else {
        auton_selection = 5;
    }
    pros::lcd::print(2, "Selected: %s", auton_names[auton_selection]);
    pros::lcd::print(3, "Potentiometer: %d", aSelector.get_value());
    
    //for debugging
    // while (true){
    //     pros::lcd::print(3, "Potentiometer: %d", aSelector.get_value());
    //     pros::delay(20);
    // }

}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
    skills();
 


    // switch (auton_selection) {
    //     case 0:
    //         blueRightSide();
    //         break;
    //     case 1:
    //         blueLeftSide();
    //         break;
    //     case 2:
    //         redRightSide();
    //         break;
    //     case 3:
    //         redLeftSide();
    //         break;
    //     case 4:
    //         skills();
    //         break;
    //     default:
    //         // No autonomous selected
    //         break;
    // }
}




/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */


// bool redSortEnabled = false;
// bool blueSortEnabled = false;
// bool sorting = false;  // Prevents multiple sort actions from interfering

// void sortObject() {
//     while (true) {
//         if (distance.get_distance() == 1) {  // Object detected
//             pros::delay(50);  // Give the sensor a little time to stabilize

//             int hueSum = 0;
//             int numReadings = 5;  // Number of times to read the sensor
//             for (int i = 0; i < numReadings; i++) {
//                 hueSum += optical.get_hue();
//                 pros::delay(5);  // Small delay between readings
//             }
//             int avgHue = hueSum / numReadings;  // Calculate average hue

//             if ((blueSortEnabled && avgHue >= 5 && avgHue <= 25) || 
//                 (redSortEnabled && avgHue >= 200 && avgHue <= 210)) {
                
//                 sorting = true;
//                 intake11W.move_relative(245, 1200);

//                 int timeout = 1000;
//                 int elapsed_time = 0;
//                 while (intake11W.get_actual_velocity() != 0 && elapsed_time < timeout) {
//                     pros::delay(10);
//                     elapsed_time += 10;
//                 }

//                 pros::delay(500);  // Ensure sorting completes before allowing new input
//                 sorting = false;
//             }
//         }
//         pros::delay(10);  // Prevent CPU overuse
//     }
// }

void toggleSorting() {
    sortingEnabled = !sortingEnabled;
    master.print(2, 0, sortingEnabled ? "Sorting Enabled" : "Sorting Disabled");
}

void opcontrol() {
    competition_initialize();
    //autonomous();

    while (true) {
        pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
                         (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
                         (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);

        
    // if (master.get_digital_new_press(DIGITAL_RIGHT)) {
    //     redSortEnabled = !redSortEnabled;
    //     master.print(0, 0, redSortEnabled ? "RedSort ON " : "RedSort OFF");
    // }

    // if (master.get_digital_new_press(DIGITAL_LEFT)) {
    //     blueSortEnabled = !blueSortEnabled;
    //     master.print(1, 0, blueSortEnabled ? "BlueSort ON " : "BlueSort OFF");
    // }

    if (master.get_digital(DIGITAL_X)&&master.get_digital(DIGITAL_RIGHT)) {
            autonomous(); // auto tests

    }
    
    setIntake((master.get_digital(DIGITAL_L1) - master.get_digital(DIGITAL_L2)) * 115);

        // **Clamp function (B button)**
        if (master.get_digital_new_press(DIGITAL_B)) {
            mogoMech.toggle();
        }

        // **Doinker function (A button)**
        if (master.get_digital_new_press(DIGITAL_A)) {
            doinker.toggle();
        }
               // **rush function (Y button)**
        if (master.get_digital_new_press(DIGITAL_Y)) {
            rush.toggle();
        }

        // **Arm control using R1 and R2**
        if (master.get_digital(DIGITAL_R2) ) {
                setArm(-127);
                
        }
         else if (master.get_digital(DIGITAL_R1)&&armSensor.get_position()<12000) {
            setArm(120);

        } else {
            setArm(0);
        }
       
        // **Set arm target positions**
        if (master.get_digital(DIGITAL_UP)) {
            setArmTarget(24, 500);
 
        } else if (master.get_digital(DIGITAL_DOWN)) {
            setArmTarget(0, 500);
        }

        // **Tank drive control**
        int leftY = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightY = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
        chassis.tank(leftY, rightY);

        pros::delay(25);  // Prevents CPU overuse
    }
}
