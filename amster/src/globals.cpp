#include "main.h"

//motors
pros::Motor intake11W(20,pros::v5::MotorGears::blue);
pros::Motor conveyor11W(-8,pros::v5::MotorGears::blue);
//motorgroup since intake and conveyor run at different velocities
pros::Motor fintake(-5,pros::v5::MotorGears::blue); 



//pneumatics
pros::adi::Pneumatics mogoMech('E', false);
pros::adi::Pneumatics doinker('C', false);

pros::Optical eye(6);

// mogoMech.extend();
// mogoMech.retract();
// mogoMech.toggle();
// mogoMech.isExtended();