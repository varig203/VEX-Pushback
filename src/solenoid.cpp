#include "Entity/api.hpp"
#include "main.h"
#include "robot/hardware.hpp"
#include "robot/solenoid.hpp"

/*****************************************************
 *                       NOTE:                       *
 * SOLENOIDS CANNOT SEND DATA AND CAN ONLY READ DATA *
 *****************************************************/

// Example piston control function, runs continuously in its own task
void solenoidControl_fn() {
    while (true) {
        // Check if the L1 button was newly pressed (not held)
        int PistonButton = controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1);

        if (PistonButton) {
            example_piston.toggle(); // Toggle piston state ON/OFF
        }

        pros::delay(20); // Small delay to reduce CPU usage
    }
}
