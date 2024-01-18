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

void function(){
  catapult.stop(coast);
}

int main() {
 // Initializing Robot Configuration. DO NOT REMOVE!
 vexcodeInit();

// 
 while(1){
  //  front_r.spin(reverse,Controller1.Axis3.position(percent),percent);
  //  // front_leftモータの速度ををコントローラーのAxis3の位置(パーセント)によって動かす
  //  back_r.spin(forward,Controller1.Axis3.position(percent),percent);
  //  front_l.spin(reverse,Controller1.Axis2.position(percent),percent);
  //  back_l.spin(forward,Controller1.Axis2.position(percent),percent);


  //  // catapult
  //  if(Controller1.ButtonL1.pressing()){//
  //    catapult.spin(reverse);
  //  }
  //  else if(Controller1.ButtonL2.pressing()){
  //    catapult.stop(hold);
  //  }
  //  else{
  //    // catapult.spin(forward);
  //    // wait(0.5, seconds);
  //    catapult.setStopping(coast);
  //    catapult.stop();}
  int vertical = Controller1.Axis2.position(percent);
  int horizontal = Controller1.Axis1.position(percent);

  // Calculate averages for right and left
  if (vertical > 0)
    {
      int right = (vertical + horizontal)/2;
      int left = (vertical - horizontal)/2;
      front_r.spin(reverse, right, percent);
      back_r.spin(forward, right, percent);
      front_l.spin(reverse, left, percent);
      back_l.spin(forward, left, percent);
    }  
  else 
  {
    int right = (vertical - horizontal) /2;
    int left = (vertical + horizontal) /2;
    front_r.spin(reverse, right, percent);
    back_r.spin(forward, right, percent);
    front_l.spin(reverse, left, percent);
    back_l.spin(forward, left, percent);
  }
  
  if (Controller1.ButtonR1.pressing()){
    function();
  }
  else{}

  if(Controller1.ButtonL1.pressing()){//
    catapult.spin(reverse, 100, rpm);
  }
  else if(Controller1.ButtonL2.pressing()){
    catapult.spin(reverse);
    wait(1.3, seconds);
    catapult.stop(hold);
  }
  else{
     // catapult.spin(forward);
     // wait(0.5, seconds);
    catapult.setStopping(hold);
    catapult.stop();}
 }
 front_l.stop();
 back_l.stop();
 front_r.stop();
 back_r.stop();
 catapult.stop(hold);
}
