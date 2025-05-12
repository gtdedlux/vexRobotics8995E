#include "main.h"

//motors
pros::Motor intake11W(-8,pros::v5::MotorGears::blue);
pros::Motor ladyB(-21,pros::v5::MotorGears::red);



pros::Optical optical(10);
pros::Distance distance(20);
pros::Rotation armSensor(13);



//pros::Motor conveyor11W(-8,pros::v5::MotorGears::blue);
//pros::MotorGroup fintake({-8,20},pros::v5::MotorGears::blue); 

pros::ADIAnalogIn aSelector ('F');

//pneumatics
pros::adi::Pneumatics mogoMech('E', false);
pros::adi::Pneumatics doinker('C', false);
pros::adi::Pneumatics rush('F', false);

// mogoMech.extend();
// mogoMech.retract();
// mogoMech.toggle();
// mogoMech.isExtended();