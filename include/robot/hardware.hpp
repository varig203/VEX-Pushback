#pragma once

#include "Entity/api.hpp"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "pros/misc.hpp"

// Motor groups
extern pros::MotorGroup left_motors;
extern pros::MotorGroup right_motors;
extern pros::Motor      example_motor;

// Controllers and Pistons
extern pros::Controller controller;
extern entity::Piston   example_piston;

// Sensors
extern pros::Imu             imu;
extern pros::Rotation        vertical_encoder;
extern pros::Rotation        horizontal_encoder;
extern lemlib::TrackingWheel vertical_tracking_wheel;
extern lemlib::TrackingWheel horizontal_tracking_wheel;

// Drivetrain settings
extern lemlib::Drivetrain  drivetrain;
extern lemlib::OdomSensors sensors;

// PID controllers
extern lemlib::ControllerSettings lateral_controller;
extern lemlib::ControllerSettings angular_controller;

// Input curves
extern lemlib::ExpoDriveCurve throttle_curve;
extern lemlib::ExpoDriveCurve steer_curve;

// Chassis
extern lemlib::Chassis chassis;
