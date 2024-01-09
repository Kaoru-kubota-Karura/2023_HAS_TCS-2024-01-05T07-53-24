/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\cosmo                                            */
/*    Created:      Wed Oct 11 2023                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/


// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// back_l               motor         11              
// back_r               motor         20              
// front_l              motor         1               
// front_r              motor         10              
// catapult             motor         3               
// ---- END VEXCODE CONFIGURED DEVICES ----


#include "vex.h"


using namespace vex;


int main() {
 // Initializing Robot Configuration. DO NOT REMOVE!
 vexcodeInit();
 while(1){
   front_l.spin(forward,Controller1.Axis3.position(percent),percent);
   // front_leftモータの速度ををコントローラーのAxis3の位置(パーセント)によって動かす
   back_l.spin(reverse,Controller1.Axis3.position(percent),percent);
   front_r.spin(forward,Controller1.Axis2.position(percent),percent);
   back_r.spin(reverse,Controller1.Axis2.position(percent),percent);


   // catapult
   if(Controller1.ButtonL1.pressing()){//
     catapult.spin(reverse);
   }
   else if(Controller1.ButtonL2.pressing()){
     catapult.stop(hold);
   }
   else{
     // catapult.spin(forward);
     // wait(0.5, seconds);
     catapult.setStopping(coast);
     catapult.stop();}
 }
 front_l.stop();
 back_l.stop();
 front_r.stop();
 back_r.stop();
}
