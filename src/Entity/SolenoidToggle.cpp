#include "Entity/SolenoidToggle.hpp"
#include "main.h"

/*****************************************************
 *                 entity::Piston Class               *
 *                                                    *
 * This class extends pros::adi::DigitalOut to        *
 * represent a solenoid piston, adding a toggle()     *
 * method to switch between ON/OFF states easily.     *
 *                                                    *
 * Note: Solenoids can only output signals and cannot *
 *            send data back (read input).            *
 *****************************************************/

// Reusable function as this is used everytime to switch the state of a piston.
namespace entity {

Piston::Piston(uint8_t port) : pros::adi::DigitalOut(port) {
    set_value(state ? 1 : 0);
}

void Piston::toggle() {
    state = !state;
    set_value(state ? 1 : 0);
}

} // namespace entity