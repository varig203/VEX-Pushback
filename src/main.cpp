#include "main.h"
#include "robot/autonomous.hpp"
#include "robot/hardware.hpp"
#include "robot/motorControl.hpp"
#include "robot/solenoid.hpp"
#include "teamlogo.h"

/**********************************************************************
 * WELCOME TO ENTITY TEMPLATE! CHECK OUT THE GITHUB FOR DOCUMENTATION.*
 *          HTTPS://GITHUB.COM/VARIG203/ENTITY-TEMPLATE              *
 **********************************************************************/

// Initialize the autonomous selector with named routines
rd::Selector autonSelector({{"Red Ring AWP", rFar_side_awp},
                            {"Red Goal AWP", rNear_side_awp},
                            {"Blue Ring AWP", bFar_side_awp},
                            {"Blue Goal AWP", bNear_side_awp},
                            {"Skills", skills}});

rd::Console console;                           // Initialize RoboDash console for debug output
rd::Image   team_logo(&teamlogo, "Team_Logo"); // Load and label team logo image

// Called once when the program starts; keep this quick!
void initialize() {
    chassis.calibrate(); // Calibrate sensors (IMU, encoders, etc.)

    team_logo.focus(); // Display the team logo on the screen
}

// Called repeatedly while the robot is disabled
void disabled() {
    controller.print(0, 0, "Robot Crippled"); // Display message to driver
    controller.rumble(".-.-.-.-");            // Rumble pattern to alert driver
}

// Called once when connected to field control but before autonomous starts
void competition_initialize() {
    // Optional: Add any pre-autonomous initialization here
}

// Autonomous mode: runs selected autonomous routine
void autonomous() {
    autonSelector.run_auton();
}

// Operator control mode: runs driver control tasks concurrently
void opcontrol() {
    // Run chassis control in its own task/thread
    pros::Task chassisControl(chassis_fn);
    // Run solenoid control in its own task/thread
    pros::Task solenoidControl(solenoidControl_fn);
    // Run motor control in its own task/thread
    pros::Task motorControl(motorControl_fn);
}
