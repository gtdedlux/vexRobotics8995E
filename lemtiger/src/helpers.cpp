#include "main.h"
#include "cmath" // For std::abs()




// void monitorIntake(int intakePower) {
//     intake11W.move(intakePower); // Set the intake motor to the desired power
//     int stuckTime = 0;

//     while (true) {
//         if (intake11W.get_actual_velocity() == 0) {
//             stuckTime += 100; // Increment the stuck time if velocity is 0
//         } else {
//             stuckTime = 0; // Reset the counter if velocity is non-zero
//         }

//         if (stuckTime >= 2000) { // If stuck for 2 seconds
//             intake11W.move_relative(-500, intakePower); // Reverse briefly to clear jam
//             pros::delay(500); // Allow the reverse action to complete
//             intake11W.move(intakePower); // Resume normal operation
//             stuckTime = 0; // Reset the timer
//         }

//         pros::delay(100); // Check velocity every 100 ms
//     }
// }



void moveIntake(int intakePower, bool reverse, int degrees){
    intake11W.move_relative(degrees, intakePower);

}
void setArm(int armSpeed){
    ladyB.move(armSpeed);
    ladyB.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    
}
void setIntake(int speed) {
    if (sortingEnabled && optical.get_proximity() >= 200) {
        return; // Prevent manual control when sorting is active
    }
    intake11W.move(speed);
    pros::delay(10);
}

void setArmTargetIME(float target, int timeout) {
   
    float diff = target - ladyB.get_position();

    while (std::abs(diff) > 5) { // Exit when diff is small (tolerance)
        diff = target - ladyB.get_position();
        
        // Get PID output
        float output = armPID.update(diff);
        
        // Apply power to motor (limit between -127 and 127)
        ladyB.move_voltage(output * 12000 / 127);

        pros::delay(20); // Small delay to avoid CPU overload
    }

    // Stop the motor when the target is reached
    ladyB.move_voltage(0);
    
}
// void moveArmToTarget(float target) {
//     float error = target - ladyB.get_position();

//     while (std::abs(error) > 5) { // Exit when error is small (tolerance)
//         error = target - ladyB.get_position();
        
//         // Get PID output
//         float output = armPID.update(error);
        
//         // Apply power to motor (limit between -127 and 127)
//         ladyB.move_voltage(output * 12000 / 127);

//         pros::delay(20); // Small delay to avoid CPU overload
//     }

//     // Stop the motor when the target is reached
//     ladyB.move_voltage(0);
// }

void setArmTarget(float target, int timeout) {
    int elapsedTime = 0;
    
    //loop makes sure that the arm is moving to the target position
    //while the arm is not within 5 degrees of the target position
    //and the timeout has not been reached
    while (elapsedTime < timeout) { 
        int currentPos = armSensor.get_position()/100;
        int diff = target - currentPos;

        if (std::abs(diff) <= 5) break; // Exit when within tolerance
     
        float output = armPID.update(diff); //pid calculations
        if (diff < 0 && output >0){
            output = std::abs(output);
        }
        int voltage = (output*12000) / 127;
        
        //print current values to screen for debugging
        pros::lcd::print(1, "Current: %d", currentPos); 
        pros::lcd::print(2, "Diff: %d", diff);
        pros::lcd::print(3, "Output: %f", output);
        pros::lcd::print(4, "Targets: %f", target);
        pros::lcd::print(5, "Voltage: %d", voltage);
        
        // Finally move arm motor according to calulated voltage
        ladyB.move_voltage(voltage);

        pros::delay(30);
        elapsedTime += 10;
    }

    ladyB.move_voltage(0);
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


void redSort(int intakePower) {
    optical.set_led_pwm(50);
    // If incorrect color is detected, override and sort
    if (distance.get_distance() < 5 && optical.get_hue() >= 200 && optical.get_hue() <= 210) {
        intake11W.move_relative(-600, 200);  // Spin intake backward for 600 degrees
        while (!intake11W.get_actual_velocity()!=0) pros::delay(10);  // Wait until sorting is done
        setIntake(intakePower);  // Resume normal intake
    }
        setIntake(intakePower);

    
}

void blueSort(int intakePower) {
    optical.set_led_pwm(50);

    // If incorrect color is detected, override and sort
    if (distance.get_distance() < 5 && optical.get_hue() >= 5 && optical.get_hue() <= 25) {
        intake11W.move_relative(-600, 200);  // Spin intake backward for 600 degrees
        while (!intake11W.get_actual_velocity()!=0) pros::delay(10);  // Wait until sorting is done
        setIntake(intakePower);  // Resume normal intake
    }
        setIntake(intakePower);
}