#include "vex.h"

void default_constants(){
  // Each constant set is in the form of (maxVoltage, kP, kI, kD, startI).
  chassis.set_drive_constants(12, 1.25, 0, 1, 0); //10, 1.5, 0, 10, 0
  chassis.set_heading_constants(12, 0.33, 0, 0.125, 0); //12, .4, 0, 1, 0
  chassis.set_turn_constants(12, 0.2, 0.0, 1.475, 15); //.4, .03, 3 // 12, .19, 0.01, 1.35, 15 ku .2
  // 180 deg constants chassis.set_turn_constants(12, 0.2, 0.0, 1.9, 15);
  chassis.set_swing_constants(12, .3, .001, 2, 15);


  // Each exit condition set is in the form (settle_error, settle_time, timeout).
  chassis.set_drive_exit_conditions(1.5, 75, 1000);
  chassis.set_turn_exit_conditions(5, 75, 1000);
  chassis.set_swing_exit_conditions(1, 75, 1000);
}

void odom_constants(){
  default_constants();
  chassis.drive_max_voltage = 12;
  chassis.drive_settle_error = 3;
}

void farside_rush(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  blocker_piston1.set(true);
  blocker_piston2.set(true);
  wait(100, msec);
  blocker_piston1.set(false);
  blocker_piston2.set(false);
  cata_intake.spin(reverse, 11, volt);
  chassis.drive_to_point(7.5, 61.3);
  chassis.turn_to_point(17, 60);
  cata_intake.spin(reverse, 0, volt);
  chassis.drive_to_point(27, 38);
  chassis.drive_distance(4);
  chassis.drive_distance(-7);
  chassis.drive_distance(11);
  chassis.drive_distance(-10);
  chassis.turn_to_point(-5, 52);
  intake_pistons.set(false);
  cata_intake.spin(reverse, 11, volt);
  chassis.drive_to_point(-5.5, 52);
  chassis.turn_to_point(0, 17);
  cata_intake.spin(reverse, 0, volt);
  chassis.drive_to_point(0, 17);
  chassis.turn_to_point(30, 0);
  cata_intake.spin(forward, 11, volt);
  wait(500, msec);
  cata_intake.spin(forward, 0, volt);
  chassis.turn_to_point(-18, 0);
  chassis.drive_to_point(-18, 0);
  chassis.turn_to_point(-44, 32);
  chassis.drive_to_point(-44, 32);



  //chassis.drive_to_point(-12, 36);//center triball rush
  //chassis.drive_to_point(-30, 43.5);

  //chassis.drive_to_point(-30, 48);//center triball rush
  //chassis.turn_to_point(-34, 43.5);
  //chassis.turn_to_point(-12, 43.5);//straighten out (intake face the offensive goal)
  //cata_intake.spin(reverse, 0, volt);
  //chassis.drive_to_point(0, 43.5);//push in triball next to goal
  //cata_intake.spin(reverse, 11, volt);
  //chassis.drive_to_point(-34, 24);//third triball
  //chassis.drive_to_point(0, 12);
  //cata_intake.spin(forward, 11, volt);


  //chassis.drive_distance(12);
  //chassis.drive_distance(18);
  //chassis.drive_distance(-36);
}

void driver_skills(){
  default_constants();
  chassis.set_swing_exit_conditions(5, 100, 3000);
  blocker_piston1.set(true);
  blocker_piston2.set(true);
  wait(100, msec);
  blocker_piston1.set(false);
  blocker_piston2.set(false);
  chassis.right_swing_to_angle(-30);




}

void prog_skills(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  blocker_piston1.set(true);
  blocker_piston2.set(true);
  wait(100, msec);
  blocker_piston1.set(false);
  blocker_piston2.set(false);
  chassis.drive_max_voltage = 11;
  chassis.right_swing_to_angle(-30);
  // cata_intake.spin(fwd, 12, volt);
  // wait(25000, msec);
  // cata_intake.spin(fwd, 0, volt);
  chassis.turn_to_point(16, 29);
  chassis.drive_to_point(-8, -10);
  chassis.turn_to_point(-7, 85);
  chassis.drive_to_point(-7, -85);
  chassis.drive_to_point(-4, -92);
  chassis.drive_to_point(-1, -99);
  chassis.drive_to_point(2, -101);
  chassis.turn_to_point(-7, -84);
  chassis.drive_to_point(27, -109);//25
  chassis.drive_distance(11);
  chassis.drive_to_point(25, -109);
  chassis.drive_to_point(9, -109);
  cata_intake.spin(fwd, 11, volt);
  chassis.turn_to_point(0, -120);
  cata_intake.spin(fwd, 0, volt);
  chassis.drive_max_voltage = 8;
  chassis.drive_to_point(16, -84);
  chassis.right_swing_to_angle(225);
  l_wing.set(true);
  chassis.right_swing_to_angle(360);
  l_wing.set(false);
  wait(500, msec);
  chassis.drive_to_point(24, -65);
  chassis.turn_to_point(0, -65);
  chassis.drive_max_voltage = 11;
  chassis.drive_distance(-20);
  chassis.drive_max_voltage = 8;
  chassis.right_swing_to_angle(300);
  l_wing.set(true);
  r_wing.set(true);
  chassis.right_swing_to_angle(360);
  chassis.drive_max_voltage = 11;
  chassis.drive_distance(-24);
  chassis.drive_distance(18);
  chassis.drive_distance(-19);
  cata_intake.spin(fwd, 11, volt);
  chassis.drive_max_voltage = 8;
  l_wing.set(false);
  r_wing.set(false);
  wait(500, msec);
  cata_intake.spin(fwd, 0, volt);
  chassis.drive_max_voltage = 11;
  chassis.drive_distance(27);
  chassis.drive_max_voltage = 8;
  chassis.turn_to_point(0, -56);
  chassis.drive_to_point(90, -56);
  chassis.turn_to_point(80, -48);
  l_wing.set(true);
  wait(300, msec);
  chassis.turn_to_point(80, -48);
  chassis.turn_to_point(80, -30);
  r_wing.set(true);
  wait(300, msec);
  chassis.turn_to_point(120, -30);
  chassis.drive_max_voltage = 11;
  chassis.drive_distance(-40);
  chassis.left_swing_to_angle(0);
  chassis.drive_distance(-7);
  chassis.drive_distance(30);
  l_wing.set(false);
  r_wing.set(false);


  










}

void wp_far(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  blocker_piston1.set(true);
  blocker_piston2.set(true);
  wait(100, msec);
  blocker_piston1.set(false);
  blocker_piston2.set(false);
  cata_intake.spin(fwd, -11, volt);
  wait(200, msec);
  chassis.drive_to_point(0, 8);
  chassis.drive_to_point(4, -27);
  chassis.drive_to_point(10, -35);//33
  chassis.drive_to_point(19, -41);//38
  chassis.drive_to_point(35, -43);
  chassis.drive_to_point(26, -41);
  chassis.set_turn_constants(12, 0.2, 0.0, 1.9, 15);
  chassis.turn_to_angle(90);
  cata_intake.spin(fwd, 0, volt);
  default_constants();
  chassis.drive_distance(15);
  chassis.drive_distance(-15);
  chassis.turn_to_point(35, 2);
  cata_intake.spin(fwd, -11, volt);
  chassis.drive_to_point(43, 2);
  chassis.drive_to_point(55, 2);
  chassis.turn_to_point(55, -30.5);
  cata_intake.spin(fwd, 0, volt);
  chassis.drive_to_point(55, -30.5);
  chassis.drive_to_point(42, -4);
  chassis.turn_to_point(60, 2);
  cata_intake.spin(fwd, -11, volt);
  chassis.drive_to_point(60, 2);
  chassis.turn_to_point(60, -30.5);
  chassis.drive_to_point(60, -31);
  cata_intake.spin(fwd, 0, volt);
  chassis.drive_to_point(19, 2);
  chassis.turn_to_angle(180);
  chassis.drive_distance(-12);






  // chassis.left_swing_to_angle(-180);
  // cata_intake.spin(fwd, 0, volt);
  // chassis.drive_distance(5);
  // chassis.right_swing_to_angle(90);
  // cata_intake.spin(fwd, 11, volt);
  // chassis.drive_distance(-7);
  // cata_intake.spin(fwd, 0, volt);
  // chassis.turn_to_point(-30, -40);
  // chassis.drive_distance(-12);
  // chassis.drive_distance(13);
  // default_constants();
  // chassis.set_swing_exit_conditions(6, 75, 3000);
  // chassis.turn_to_point(35, 2);
  // while (!cata_switch.pressing()) {
  //   cata_intake.spin(forward, 11.0, volt);
  // }
  // cata_intake.spin(forward, 11.0, volt);
  // wait(50, msec);
  // cata_intake.spin(forward, 0.0, volt);
  // cata_intake.spin(fwd, -11, volt);
  // chassis.drive_to_point(35, 2);
  // chassis.drive_to_point(50, 2);
  // cata_intake.spin(fwd, 0, volt);
  // chassis.turn_to_point(50, -30.5);
  // chassis.drive_to_point(50, -30.5);
  // chassis.drive_to_point(19, 2);
  // chassis.turn_to_point(19, -12);
  // chassis.drive_distance(-3);


}


void wp_close(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  blocker_piston1.set(true);
  blocker_piston2.set(true);
  wait(100, msec);
  blocker_piston1.set(false);
  blocker_piston2.set(false);
  wait(300, msec);
  chassis.right_swing_to_angle(-25);
  intake_pistons.set(true);
  wait(300, msec);
  chassis.turn_to_angle(-135);
  intake_pistons.set(false);
  chassis.drive_distance(-16);
  chassis.turn_to_angle(-90);
  chassis.drive_distance(-9);
  chassis.right_swing_to_angle(180);
  chassis.drive_distance(18);
  chassis.right_swing_to_angle(103);
  cata_intake.spin(fwd, -11, volt);
  chassis.drive_distance(27);
  chassis.drive_distance(-6);
  chassis.turn_to_angle(180);
  chassis.drive_distance(14);
  cata_intake.spin(fwd, 11, volt);
  wait(1000, msec);
  cata_intake.spin(fwd, 0, volt);
  chassis.right_swing_to_angle(120);
  while (!cata_switch.pressing()) {
    cata_intake.spin(forward, 11.0, volt);
  }
  cata_intake.spin(forward, 11.0, volt);
  cata_intake.spin(fwd, -11, volt);
  chassis.drive_distance(8);
  chassis.drive_distance(-10.5);
  chassis.turn_to_angle(180);
  chassis.drive_distance(-3.25);
  cata_intake.spin(fwd, 11, volt);
  wait(1000, msec);
  cata_intake.spin(fwd, 0, volt);
  chassis.turn_to_angle(75);
  chassis.drive_distance(-30);
  chassis.turn_to_angle(90);
  chassis.drive_distance(-5);

  


  // chassis.drive_to_point(16, -26);
  // chassis.right_swing_to_angle(0);
  // chassis.drive_distance(-1);
  // wait(600, msec);
  // intake_pistons.set(true);
  // chassis.right_swing_to_angle(-8);
  // chassis.turn_to_angle(-120);
  // chassis.drive_distance(-10);
  // chassis.turn_to_point(-1, -38);
  // chassis.drive_to_point(-1, -38);
  // chassis.drive_distance(-11);
  // chassis.left_swing_to_angle(-60);
  // chassis.drive_distance(-8);
  // chassis.drive_distance(4);


}

void tank_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  //chassis.turn_to_point(24, 24);
  chassis.drive_to_point(24,24);
  chassis.drive_to_point(0,0);
  chassis.turn_to_angle(0);
}

void holonomic_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.holonomic_drive_to_point(0, 18, 90);
  chassis.holonomic_drive_to_point(18, 0, 180);
  chassis.holonomic_drive_to_point(0, 18, 270);
  chassis.holonomic_drive_to_point(0, 0, 0);
}