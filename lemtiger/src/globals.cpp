#include "main.h"

//motors
pros::Motor intake11W(20,pros::v5::MotorGears::blue);

//pros::Motor conveyor11W(-8,pros::v5::MotorGears::blue);
//pros::MotorGroup fintake({-8,20},pros::v5::MotorGears::blue); 

//pneumatics
pros::adi::Pneumatics mogoMech('A', false);
pros::adi::Pneumatics doinker('B', false);

// mogoMech.extend();
// mogoMech.retract();
// mogoMech.toggle();
// mogoMech.isExtended();