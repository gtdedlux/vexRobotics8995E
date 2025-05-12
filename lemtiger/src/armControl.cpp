#include "armControl.hpp"
#include "pros/rtos.hpp"
#include "main.h"

pros::Task* armTask = nullptr; // Pointer to track the task

void armControlTask(void* param) {
    float target = *(float*)param;
    int timeout = 3000; // Adjust as needed
    int elapsedTime = 0;
    
    while (elapsedTime < timeout) { 
        int currentPos = armSensor.get_position() / 100;
        int diff = target - currentPos;

        if (std::abs(diff) <= 5) break;

        float output = armPID.update(diff);
        int voltage = (output * 12000) / 127;

        ladyB.move_voltage(voltage);

        pros::delay(30);
        elapsedTime += 30;
    }

    ladyB.move_voltage(0);

    delete armTask; // Delete the task when done
    armTask = nullptr; // Reset the pointer
}

void setArmTargetAsync(float target) {
    static float targetValue = 0; // Make sure it persists
    targetValue = target;

    if (armTask != nullptr) { 
        armTask->remove(); // Stop the previous task
        delete armTask;    // Free memory
        armTask = nullptr;
    }

    armTask = new pros::Task(armControlTask, &targetValue, "Arm Control Task");
}
