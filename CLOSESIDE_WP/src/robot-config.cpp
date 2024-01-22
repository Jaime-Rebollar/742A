#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors

controller controller1;
//cata side back
motor lf = motor(PORT11, ratio6_1, true);
motor lm = motor(PORT12, ratio6_1, true);
motor lb = motor(PORT13, ratio6_1, true);

motor rf = motor(PORT20, ratio6_1, false);
motor rm = motor(PORT19, ratio6_1, false);
motor rb = motor(PORT18, ratio6_1, false);

motor l_cata = motor(PORT14, ratio6_1, true);
motor r_cata = motor(PORT15, ratio6_1, false);
motor_group cata_intake = motor_group(l_cata, r_cata);

inertial imu = inertial(PORT16);
digital_out piston_12t = digital_out(Brain.ThreeWirePort.A);
digital_out piston_24t = digital_out(Brain.ThreeWirePort.B);
limit cata_switch = limit(Brain.ThreeWirePort.C);
digital_out l_wing = digital_out(Brain.ThreeWirePort.G);
digital_out r_wing = digital_out(Brain.ThreeWirePort.D);
digital_out intake_pistons = digital_out(Brain.ThreeWirePort.E);
digital_out blocker_piston1 = digital_out(Brain.ThreeWirePort.F);
digital_out blocker_piston2 = digital_out(Brain.ThreeWirePort.H);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}