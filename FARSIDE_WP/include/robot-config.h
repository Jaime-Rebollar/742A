using namespace vex;

extern brain Brain;

// VEXcode devices

extern controller controller1;

extern motor lf;
extern motor lm;
extern motor lb;

extern motor rf;
extern motor rm;
extern motor rb;

extern motor l_cata;
extern motor r_cata;
extern motor_group cata_intake;

extern inertial imu;
extern limit cata_switch;
extern distance triball_sensor;
extern digital_out piston_12t;
extern digital_out piston_24t;
extern digital_out l_wing;
extern digital_out r_wing;
extern digital_out intake_pistons;
extern digital_out blocker_piston1;
extern digital_out blocker_piston2;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );