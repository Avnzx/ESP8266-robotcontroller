#include "pwmmotor.h"
#include <math.h>
#include <algorithm>

using namespace motorcontrol;

    void PWMMotorController::Set(double speed){
        if (std::isfinite(speed)) {
            speed = std::clamp(speed, -1.0, 1.0);
        } else {
            speed = 0.0;
        }
    }

    /**
     * Common interface for inverting direction of a speed controller.
     *
     * This call has no effect if the controller is a follower. To invert
     * a follower, see the follow() method.
     *
     * @param isInverted The state of inversion, true is inverted.
     */
    void PWMMotorController::SetInverted(bool isInverted) {

    }