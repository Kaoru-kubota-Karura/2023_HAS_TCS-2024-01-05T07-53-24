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
// front_right          motor         11              
// front_left           motor         20              
// back_right           motor         1               
// back_left            motor         10              
// catapult             motor         3               
// ---- END VEXCODE CONFIGURED DEVICES ----


#include "vex.h"


using namespace vex;


int main() {
 // Initializing Robot Configuration. DO NOT REMOVE!
 vexcodeInit();
 while(1){
   front_left.spin(forward,Controller1.Axis3.position(percent),percent);
   // front_leftモータの速度ををコントローラーのAxis3の位置(パーセント)によって動かす
   back_left.spin(reverse,Controller1.Axis3.position(percent),percent);
   front_right.spin(forward,Controller1.Axis2.position(percent),percent);
   back_right.spin(reverse,Controller1.Axis2.position(percent),percent);


   // catapult
   if(Controller1.ButtonL1.pressing()){//
     catapult.spin(reverse);
   }else{
     // catapult.spin(forward);
     // wait(0.5, seconds);
     catapult.stop();}
 }
 front_left.stop();
 back_left.stop();
 front_right.stop();
 back_right.stop();
}
