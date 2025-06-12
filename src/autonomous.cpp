#include "Entity/api.hpp"
#include "main.h"
#include "robot/autonomous.hpp"
#include "robot/hardware.hpp"

// To add an auton file use the example below for reference
// Check out the LemLib Wiki for advanced pure pursuit techniques:
// https://lemlib.readthedocs.io/en/stable/tutorials/7_pure_pursuit.html

ASSET(example_txt); // Path to the trajectory file for the example auton

void example_auton() {
    // Set starting position of the robot (x, y, heading in radians)
    chassis.setPose(0, 0, 0);

    // Follow the trajectory with a lookahead distance of 15 inches
    // Timeout after 2000 milliseconds if not completed
    chassis.follow(example_txt, 15, 2000);
}

/**
 * Runs the user autonomous code.
 * This task is started automatically during competition autonomous mode.
 * It will be stopped if the robot is disabled or communication is lost.
 * On re-enable, it restarts from the beginning.
 */

// Basic autonomous routines
// Note: function names prefixed with 'r' or 'b' indicate red or blue side of the field

void rNear_side_awp() {
    // TODO: Implement autonomous routine for red near side
}

void rFar_side_awp() {
    // TODO: Implement autonomous routine for red far side
}

void bNear_side_awp() {
    // TODO: Implement autonomous routine for blue near side
}

void bFar_side_awp() {
    // TODO: Implement autonomous routine for blue far side
}

void skills() {
    // TODO: Implement skills autonomous routine
}
