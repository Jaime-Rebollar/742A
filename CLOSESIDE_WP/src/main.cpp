#include "vex.h"

using namespace vex;
competition Competition;

/*---------------------------------------------------------------------------*/
/*                             VEXcode Config                                */
/*                                                                           */
/*  Before you do anything else, start by configuring your motors and        */
/*  sensors using the V5 port icon in the top right of the screen. Doing     */
/*  so will update robot-config.cpp and robot-config.h automatically, so     */
/*  you don't have to. Ensure that your motors are reversed properly. For    */
/*  the drive, spinning all motors forward should drive the robot forward.   */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*                             JAR-Template Config                           */
/*                                                                           */
/*  Where all the magic happens. Follow the instructions below to input      */
/*  all the physical constants and values for your robot. You should         */
/*  already have configured your robot manually with the sidebar configurer. */
/*---------------------------------------------------------------------------*/

Drive chassis(

//Specify your drive setup below. There are eight options:
//ZERO_TRACKER_NO_ODOM, ZERO_TRACKER_ODOM, TANK_ONE_ENCODER, TANK_ONE_ROTATION, TANK_TWO_ENCODER, TANK_TWO_ROTATION, HOLONOMIC_TWO_ENCODER, and HOLONOMIC_TWO_ROTATION
//For example, if you are not using odometry, put ZERO_TRACKER_NO_ODOM below:
ZERO_TRACKER_ODOM,

//Add the names of your Drive motors into the motor groups below, separated by commas, i.e. motor_group(Motor1,Motor2,Motor3).
//You will input whatever motor names you chose when you configured your robot using the sidebar configurer, they don't have to be "Motor1" and "Motor2".

//Left Motors:
motor_group(lf, lm, lb),

//Right Motors:
motor_group(rf, rm, rb),

//Specify the PORT NUMBER of your inertial sensor, in PORT format (i.e. "PORT1", not simply "1"):
PORT16,

//Input your wheel diameter. (4" omnis are actually closer to 4.125"):
2.75,

//External ratio, must be in decimal, in the format of input teeth/output teeth.
//If your motor has an 84-tooth gear and your wheel has a 60-tooth gear, this value will be 1.4.
//If the motor drives the wheel directly, this value is 1:
0.75,

//Gyro scale, this is what your gyro reads when you spin the robot 360 degrees.
//For most cases 360 will do fine here, but this scale factor can be very helpful when precision is necessary.
360,

/*---------------------------------------------------------------------------*/
/*                                  PAUSE!                                   */
/*                                                                           */
/*  The rest of the drive constructor is for robots using POSITION TRACKING. */
/*  If you are not using position tracking, leave the rest of the values as  */
/*  they are.                                                                */
/*---------------------------------------------------------------------------*/

//If you are using ZERO_TRACKER_ODOM, you ONLY need to adjust the FORWARD TRACKER CENTER DISTANCE.

//FOR HOLONOMIC DRIVES ONLY: Input your drive motors by position. This is only necessary for holonomic drives, otherwise this section can be left alone.
//LF:      //RF:    
PORT1,     -PORT2,

//LB:      //RB: 
PORT3,     -PORT4,

//If you are using position tracking, this is the Forward Tracker port (the tracker which runs parallel to the direction of the chassis).
//If this is a rotation sensor, enter it in "PORT1" format, inputting the port below.
//If this is an encoder, enter the port as an integer. Triport A will be a "1", Triport B will be a "2", etc.
3,

//Input the Forward Tracker diameter (reverse it to make the direction switch):
2.75,

//Input Forward Tracker center distance (a positive distance corresponds to a tracker on the right side of the robot, negative is left.)
//For a zero tracker tank drive with odom, put the positive distance from the center of the robot to the right side of the drive.
//This distance is in inches:
5.65,

//Input the Sideways Tracker Port, following the same steps as the Forward Tracker Port:
1,

//Sideways tracker diameter (reverse to make the direction switch):
-2.75,

//Sideways tracker center distance (positive distance is behind the center of the robot, negative is in front):
5.5

);

int current_auton_selection = 5;
bool auto_started = false;

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  default_constants();
  imu.calibrate();
  while(imu.isCalibrating()) {
    wait(100, msec);
  }

  while(auto_started == false){            //Changing the names below will only change their names on the
    Brain.Screen.clearScreen();            //brain screen for auton selection.
    switch(current_auton_selection){       //Tap the brain screen to cycle through autons.
      case 0:
        Brain.Screen.printAt(50, 50, "Far Side Rush");
        break;
      case 1:
        Brain.Screen.printAt(50, 50, "Far Side Rush");
        break;
      case 2:
        Brain.Screen.printAt(50, 50, "Driver Skills");
        break;
      case 3:
        Brain.Screen.printAt(50, 50, "Programming Skills");
        break;
      case 4:
        Brain.Screen.printAt(50, 50, "Half Win Point Farside");
        break;
      case 5:
        Brain.Screen.printAt(50, 50, "Half Win Point Closeside");
        break;
      case 6:
        Brain.Screen.printAt(50, 50, "Tank Odom Test");
        break;
      case 7:
        Brain.Screen.printAt(50, 50, "Holonomic Odom Test");
        break;
    }
    if(Brain.Screen.pressing()){
      while(Brain.Screen.pressing()) {}
      current_auton_selection ++;
    } else if (current_auton_selection == 8){
      current_auton_selection = 0;
    }
    task::sleep(10);
  }
}

void autonomous(void) {

  // imu.calibrate();
  // while(imu.isCalibrating()) {
  //   wait(100, msec);
  // }

  auto_started = true;
  switch(current_auton_selection){  
    case 0:
      farside_rush(); //This is the default auton, if you don't select from the brain.
      break;        //Change these to be your own auton functions in order to use the auton selector.
    case 1:         //Tap the screen to cycle through autons.
      farside_rush();
      break;
    case 2:
      driver_skills();
      break;
    case 3:
      prog_skills();
      break;
    case 4:
      wp_far();
      break;
    case 5:
      wp_close();
      break;
    case 6:
      tank_odom_test();
      break;
    case 7:
      holonomic_odom_test();
      break;
 }
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  //driver_skills();
  bool engaged = false;
  
  bool intake = false;
  bool shift_key = false;


  bool wingToggle = false;
  bool lastPressWing = false;
  bool wing = false;

  bool intakeToggle = false;
  bool lastPressIntake = false;
  bool intakepiston = false;

  // bool cataToggle = true;
  // bool cataLatch = true;
  bool cataToggle = false;
  bool lastPressCata = false;
  bool cata = false;

  bool blockerToggle = false;
  bool lastPressBlocker = false;
  bool blocker = false;

  bool ptoToggle = false;
  bool lastPresspto = false;
  bool pto = false;
  


  while (1) {
    intakepiston = controller1.ButtonL1.pressing();
    cata = controller1.ButtonR2.pressing();
    blocker = controller1.ButtonL1.pressing();
    pto = controller1.ButtonR2.pressing();
    intake = controller1.ButtonR1.pressing();
    shift_key = controller1.ButtonL2.pressing();
    wing = controller1.ButtonR1.pressing();

    if (ptoToggle) {
      piston_12t.set(true);
      piston_24t.set(true);
      cata_intake.setStopping(coast);
      engaged = true;
    }
    else {
      piston_12t.set(false);
      piston_24t.set(false);
      cata_intake.setStopping(coast);
      engaged = false;
    }

    if (blockerToggle){
      blocker_piston1.set(true);
      blocker_piston2.set(true);
    }
    else {
      blocker_piston1.set(false);
      blocker_piston2.set(false);
    }

    if (wingToggle) {
      r_wing.set(true);
      l_wing.set(true);
    }
    else {
      r_wing.set(false);
      l_wing.set(false);
    }

    if (intakeToggle){
      intake_pistons.set(true);
    }
    else {
      intake_pistons.set(false);
    }

    if((pto && (!lastPresspto)) && shift_key) {
      ptoToggle = !ptoToggle;
    }
    lastPresspto = pto;

    if((wing && (!lastPressWing)) && shift_key) {
      wingToggle = !wingToggle;
    }
    lastPressWing = wing;

    if((intakepiston && (!lastPressIntake)) && shift_key) {
      intakeToggle = !intakeToggle;
    }
    lastPressIntake = intakepiston;

    if((blocker && (!lastPressBlocker)) && (!shift_key)) {
      blockerToggle = !blockerToggle;
    }
    lastPressBlocker = blocker;

    if((cata && (!lastPressCata)) && (!shift_key)) {
      cataToggle = !cataToggle;
    }
    lastPressCata = cata;





    if (engaged == false) {
      if (intake && (!shift_key)) {
        cata_intake.spin(reverse, 11.0, volt);
      }
      else if(cataToggle) {
        cata_intake.spin(forward, 11.0, volt);
      }
      else if (!cata_switch.pressing()) {
          cata_intake.spin(forward, 11.0, volt);
      }
      else {
        cata_intake.stop(coast);
      }
    }
    //Replace this line with chassis.control_tank(); for tank drive 
    //or chassis.control_holonomic(); for holo drive.
    chassis.control_reverse_arcade(engaged);

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
