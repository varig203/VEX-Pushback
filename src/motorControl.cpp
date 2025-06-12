#include "main.h"
#include "robot/hardware.hpp"

void motorControl_fn() {
    // Insert potential variable initalizing here

    while (true) {
        // Insert your motor control code here
        // Including buttons
        // Example motor control
        bool exampleMotor = controller.get_digital(DIGITAL_B);

        if (exampleMotor) {
            example_motor.move_velocity(600); // Assuming blue motor
        } else {
            example_motor.move_velocity(0); // Stops
        }
        pros::delay(20);
    }
}

// Basic dual stick arcade style chassis control
// Docs: https://lemlib.readthedocs.io/en/stable/tutorials/3_driver_control.html
void chassis_fn() {
    while (true) {
        int leftY  = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);  // Up and down on the left stick
        int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X); // Left and right on the right stick

        // Drivetrain control
        chassis.arcade(leftY, -rightX); // Change arcade to curve if you want curve drive and vice versa.

        // detects if L2 is pressed
        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
            left_motors.set_voltage_limit(12000);  // changes to 12 volts once pressed
            right_motors.set_voltage_limit(12000); // AKA 600 rpm for blue carts
            controller.rumble("-");                // rumbles the controller
        } else {
            left_motors.set_voltage_limit(6000); // changes to 300 rpm aka 50% power.
            right_motors.set_voltage_limit(6000);
        }
        pros::delay(20);
    }
}
