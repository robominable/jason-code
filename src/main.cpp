/*
      READ THE VEXCODE TUTORIAL IF YOU HAVE ANY QUESTIONS
*/

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Todd Rylaarsdam                                           */
/*    Created:      Thu Sep 12 2019                                           */
/*    Description:  Template program                                          */
/*                                                                            */
/*----------------------------------------------------------------------------*/


#include "vex.h"
#include "visionSensor.h"

using namespace vex;

//REMOVE THE //  ON THE LINE WITH YOUR TYPE  OF DRIVE (e.g. if you have an xDrive remove the // on line 24)

// note from todd: you need to uncomment only one type of drive, otherwise bad things happen

#define linearDrive
//#define mechDrive
//#define xDrive



// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain       Brain;
vex::controller Controller = vex::controller(vex::controllerType::primary);
vex::motor Ldrive = vex::motor(PORT2,vex::gearSetting::ratio18_1,false); 
vex::motor Rdrive = vex::motor(PORT1,vex::gearSetting::ratio18_1,false);
vex::motor Larm = vex::motor(PORT3,vex::gearSetting::ratio18_1,false);
vex::motor Rarm = vex::motor(PORT4,vex::gearSetting::ratio18_1,false);
vex::motor Lclaw = vex::motor(PORT7,vex::gearSetting::ratio18_1,false);
vex::motor Rclaw = vex::motor(PORT8,vex::gearSetting::ratio18_1,false);
vex::motor Lbridge = vex::motor(PORT5,vex::gearSetting::ratio18_1,false);
vex::motor Rbridge = vex::motor(PORT6,vex::gearSetting::ratio18_1,false);

int clawSpeed = 100;
int armSpeed = 25;
int bridgeSpeed = 35;
// A global instance of vex::competition
vex::competition Competition;

// define your global instances of motors and other devices here


/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */ 
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton( void ) {
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
  //上抬手臂
  //放下手臂
  
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous( void ) {
  // ..........................................................................
  // Insert autonomous user code here.
  
  //Lclaw.spin(vex::directionType::rev,clawSpeed,vex::velocityUnits::pct);
  //Rclaw.spin(vex::directionType::fwd,clawSpeed,vex::velocityUnits::pct);
  Lbridge.spin(vex::directionType::rev,bridgeSpeed,vex::velocityUnits::pct);
  Rbridge.spin(vex::directionType::fwd,bridgeSpeed,vex::velocityUnits::pct);
  vex::task::sleep(400);
  //Lclaw.stop(vex::brakeType::hold);
  //Rclaw.stop(vex::brakeType::hold);
  Lbridge.stop();
  Rbridge.stop();
  Lbridge.spin(vex::directionType::rev,bridgeSpeed,vex::velocityUnits::pct);
  Rbridge.spin(vex::directionType::fwd,bridgeSpeed,vex::velocityUnits::pct);

  vex::task::sleep(400);
  Lbridge.stop();
  Rbridge.stop();
  Ldrive.spin(vex::directionType::fwd,100,vex::velocityUnits::pct);
  Rdrive.spin(vex::directionType::rev,100,vex::velocityUnits::pct);
  vex::task::sleep(350);
  Ldrive.stop(vex::brakeType::hold);
  Rdrive.stop(vex::brakeType::hold);
  vex::task::sleep(200);

  Lclaw.spin(vex::directionType::fwd,clawSpeed,vex::velocityUnits::pct);
  Rclaw.spin(vex::directionType::rev,clawSpeed,vex::velocityUnits::pct);
  vex::task::sleep(300);
  Ldrive.spin(vex::directionType::fwd,17,vex::velocityUnits::pct);
  Rdrive.spin(vex::directionType::rev,17,vex::velocityUnits::pct);
  vex::task::sleep(300);

  Ldrive.stop(vex::brakeType::hold);
  Rdrive.stop(vex::brakeType::hold);
  vex::task::sleep(400);
  Lclaw.spin(vex::directionType::fwd,clawSpeed,vex::velocityUnits::pct);
  Rclaw.spin(vex::directionType::rev,clawSpeed,vex::velocityUnits::pct);
  Ldrive.spin(vex::directionType::fwd,7,vex::velocityUnits::pct);
  Rdrive.spin(vex::directionType::rev,7,vex::velocityUnits::pct);
  vex::task::sleep(7000);
  Ldrive.stop(vex::brakeType::hold);
  Rdrive.stop(vex::brakeType::hold);

  //vex::task::sleep(600);
  //Lclaw.stop(vex::brakeType::hold);
  //Rclaw.stop(vex::brakeType::hold);

  // ..........................................................................
  
  Ldrive.spin(vex::directionType::rev,100,vex::velocityUnits::pct);
  Rdrive.spin(vex::directionType::rev,100,vex::velocityUnits::pct);
  vex::task::sleep(690);
  Ldrive.stop(vex::brakeType::hold);
  Rdrive.stop(vex::brakeType::hold);

  Ldrive.spin(vex::directionType::fwd,100,vex::velocityUnits::pct);
  Rdrive.spin(vex::directionType::rev,100,vex::velocityUnits::pct);
  vex::task::sleep(600);
  Ldrive.stop(vex::brakeType::hold);
  Rdrive.stop(vex::brakeType::hold);

  Lbridge.spin(vex::directionType::rev,45,vex::velocityUnits::pct);
  Rbridge.spin(vex::directionType::fwd,45,vex::velocityUnits::pct);
  Larm.spin(vex::directionType::fwd,25,vex::velocityUnits::pct);
  Rarm.spin(vex::directionType::rev,25,vex::velocityUnits::pct);
  Lclaw.spin(vex::directionType::fwd,30,vex::velocityUnits::pct);
  Rclaw.spin(vex::directionType::rev,30,vex::velocityUnits::pct);
  Ldrive.spin(vex::directionType::rev,5,vex::velocityUnits::pct);
  Rdrive.spin(vex::directionType::fwd,5,vex::velocityUnits::pct);
  vex::task::sleep(1000);
  Larm.stop(vex::brakeType::hold);
  Rarm.stop(vex::brakeType::hold);
  vex::task::sleep(2500);
  Lbridge.stop(vex::brakeType::hold);
  Rbridge.stop(vex::brakeType::hold);
  
  vex::task::sleep(2000);

  Lclaw.stop();
  Rclaw.stop();
  Ldrive.stop();
  Rdrive.stop();
  
  Ldrive.spin(vex::directionType::rev,30,vex::velocityUnits::pct);
  Rdrive.spin(vex::directionType::fwd,30,vex::velocityUnits::pct);
  vex::task::sleep(1000);
  Ldrive.stop();
  Rdrive.stop();

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

void usercontrol( void ) {
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo 
    // values based on feedback from the joysticks.

    //MECH DRIVES
    #ifdef mechDrive
    int creep;
        creep = float(0.05);
        if (Controller.Axis3.position(vex::percentUnits::pct) > creep || Controller.Axis3.position(vex::percentUnits::pct) < -creep || Controller.Axis1.position(vex::percentUnits::pct) > creep || Controller.Axis1.position(vex::percentUnits::pct) < -creep){
            Ldrive.spin(vex::directionType::fwd,(Controller.Axis3.position(vex::percentUnits::pct) + Controller.Axis1.position(vex::percentUnits::pct)),vex::velocityUnits::pct);
            Rdrive.spin(vex::directionType::rev,(Controller.Axis3.position(vex::percentUnits::pct) - Controller.Axis1.position(vex::percentUnits::pct)),vex::velocityUnits::pct);
        }
          else{
            Ldrive.stop();
            Rdrive.stop();
          }
        /*if (Controller.Axis2.position(vex::percentUnits::pct) > creep || Controller.Axis2.position(vex::percentUnits::pct) < -creep || Controller.Axis1.position(vex::percentUnits::pct) > creep || Controller.Axis1.position(vex::percentUnits::pct) < -creep){
            BLdrive.spin(vex::directionType::fwd,(Controller.Axis2.position(vex::percentUnits::pct) - Controller.Axis1.position(vex::percentUnits::pct)),vex::velocityUnits::pct);
        }
          else{
            BLdrive.stop();
          }
        if (Controller.Axis3.position(vex::percentUnits::pct) > creep || Controller.Axis3.position(vex::percentUnits::pct) < -creep || Controller.Axis4.position(vex::percentUnits::pct) > creep || Controller.Axis4.position(vex::percentUnits::pct) < -creep){
            FRdrive.spin(vex::directionType::fwd,(Controller.Axis3.position(vex::percentUnits::pct) - Controller.Axis4.position(vex::percentUnits::pct)),vex::velocityUnits::pct);
        }
          else{
            FRdrive.stop();
          }
        if (Controller.Axis2.position(vex::percentUnits::pct) > creep || Controller.Axis2.position(vex::percentUnits::pct) < -creep || Controller.Axis1.position(vex::percentUnits::pct) > creep || Controller.Axis1.position(vex::percentUnits::pct) < -creep){
            BRdrive.spin(vex::directionType::fwd,(Controller.Axis2.position(vex::percentUnits::pct) + Controller.Axis1.position(vex::percentUnits::pct)),vex::velocityUnits::pct);
        }
          else{
            BRdrive.stop();
          }*/
      #endif

      //XDRIVE
      #ifdef xDrive
      int creep;
        creep = float(0.05);
        if (Controller.Axis3.position(vex::percentUnits::pct) > creep || Controller.Axis3.position(vex::percentUnits::pct) < -creep || Controller.Axis4.position(vex::percentUnits::pct) > creep || Controller.Axis4.position(vex::percentUnits::pct) < -creep){
            FLdrive.spin(vex::directionType::fwd,(Controller.Axis3.position(vex::percentUnits::pct) + Controller.Axis4.position(vex::percentUnits::pct)),vex::velocityUnits::pct);
        }
          else{
            FLdrive.stop();
          }
        if (Controller.Axis3.position(vex::percentUnits::pct) > creep || Controller.Axis3.position(vex::percentUnits::pct) < -creep || Controller.Axis1.position(vex::percentUnits::pct) > creep || Controller.Axis1.position(vex::percentUnits::pct) < -creep){
            BLdrive.spin(vex::directionType::fwd,(Controller.Axis3.position(vex::percentUnits::pct) - Controller.Axis1.position(vex::percentUnits::pct)),vex::velocityUnits::pct);
        }
          else{
            BLdrive.stop();
          }
        if (Controller.Axis2.position(vex::percentUnits::pct) > creep || Controller.Axis2.position(vex::percentUnits::pct) < -creep || Controller.Axis4.position(vex::percentUnits::pct) > creep || Controller.Axis4.position(vex::percentUnits::pct) < -creep){
            FRdrive.spin(vex::directionType::fwd,(Controller.Axis2.position(vex::percentUnits::pct) - Controller.Axis4.position(vex::percentUnits::pct)),vex::velocityUnits::pct);
        }
          else{
            FRdrive.stop();
          }
        if (Controller.Axis2.position(vex::percentUnits::pct) > creep || Controller.Axis2.position(vex::percentUnits::pct) < -creep || Controller.Axis1.position(vex::percentUnits::pct) > creep || Controller.Axis1.position(vex::percentUnits::pct) < -creep){
            BRdrive.spin(vex::directionType::fwd,(Controller.Axis2.position(vex::percentUnits::pct) + Controller.Axis1.position(vex::percentUnits::pct)),vex::velocityUnits::pct);
        }
          else{
            BRdrive.stop();
          }
        #endif 

    //4 WHEEL LINEAR DRIVE 
    #ifdef linearDrive
    int creep;
        creep = float(0.05);
        if (Controller.Axis3.position(vex::percentUnits::pct) > creep || Controller.Axis3.position(vex::percentUnits::pct) < -creep){
            Ldrive.spin(vex::directionType::fwd,(Controller.Axis3.position(vex::percentUnits::pct)),vex::velocityUnits::pct);
        }
            else{
                Ldrive.stop(vex::brakeType::hold);
            }
        if (Controller.Axis2.position(vex::percentUnits::pct) > creep || Controller.Axis2.position(vex::percentUnits::pct) < -creep){
            Rdrive.spin(vex::directionType::rev,(Controller.Axis2.position(vex::percentUnits::pct)),vex::velocityUnits::pct);
        }
            else{
                Rdrive.stop(vex::brakeType::hold);
              }
      #endif
      
    // ........................................................................
    // Insert user code here. This is where you use the joystick values to 
    // update your motors, etc.
    // ........................................................................
    
    if(Controller.ButtonL2.pressing()){
      Larm.spin(vex::directionType::fwd,armSpeed,vex::velocityUnits::pct);
      Rarm.spin(vex::directionType::rev,armSpeed,vex::velocityUnits::pct);
    }
    
    else if(Controller.ButtonY.pressing()){
      Larm.spin(vex::directionType::rev,armSpeed,vex::velocityUnits::pct);
      Rarm.spin(vex::directionType::fwd,armSpeed,vex::velocityUnits::pct);
    }
    else if(Controller.ButtonX.pressing()){
      Larm.stop();
      Rarm.stop();
    }
    else{
      Larm.stop(vex::brakeType::hold);
      Rarm.stop(vex::brakeType::hold);
    }

    if(Controller.ButtonL1.pressing()){
      Lbridge.spin(vex::directionType::rev,bridgeSpeed,vex::velocityUnits::pct);
      Rbridge.spin(vex::directionType::fwd,bridgeSpeed,vex::velocityUnits::pct);
    }
    else if(Controller.ButtonB.pressing()){
      Lbridge.spin(vex::directionType::fwd,bridgeSpeed,vex::velocityUnits::pct);
      Rbridge.spin(vex::directionType::rev,bridgeSpeed,vex::velocityUnits::pct);
    }
    else{
      Lbridge.stop(vex::brakeType::hold);
      Rbridge.stop(vex::brakeType::hold);
    }

    if(Controller.ButtonR1.pressing() || Controller.ButtonR2.pressing()){
      if(Controller.ButtonR1.pressing()){
        Lclaw.spin(vex::directionType::fwd,clawSpeed,vex::velocityUnits::pct);
        Rclaw.spin(vex::directionType::rev,clawSpeed,vex::velocityUnits::pct);
      }
      if(Controller.ButtonR2.pressing()){
        Lclaw.spin(vex::directionType::rev,clawSpeed,vex::velocityUnits::pct);
        Rclaw.spin(vex::directionType::fwd,clawSpeed,vex::velocityUnits::pct);
      }
    }

    else{
      Lclaw.stop(vex::brakeType::hold);
      Rclaw.stop(vex::brakeType::hold);
    }
    
 
    vex::task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources. 
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
    //Set up callbacks for autonomous and driver control periods.
    Competition.autonomous( autonomous );
    Competition.drivercontrol( usercontrol );
    
    //Run the pre-autonomous function. 
    pre_auton();
       
    //Prevent main from exiting with an infinite loop.                        
    while(1) {
      vex::task::sleep(100);//Sleep the task for a short amount of time to prevent wasted resources.
    }    
       
}
