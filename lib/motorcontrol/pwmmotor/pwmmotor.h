#pragma once 

namespace motorcontrol {
class PWMMotorController {

public:
    /**
     * Create a new object to control a SPARK motor Controller
     *
     * @param port the pin the controller is connected to.
     */
    explicit PWMMotorController(int port);

    /**
    * Free the PWM channel.
    *
    * Free the resource associated with the PWM channel and set the value to 0.
    */
    ~PWMMotorController();


    /**** Speed Controller Interface ****/
    /**
     * Common interface for setting the speed of a speed controller.
     *
     * @param speed The speed to set.  Value should be between -1.0 and 1.0.
     */
    void Set(double speed);

    /**
     * Common interface for inverting direction of a speed controller.
     *
     * This call has no effect if the controller is a follower. To invert
     * a follower, see the follow() method.
     *
     * @param isInverted The state of inversion, true is inverted.
     */
    void SetInverted(bool isInverted);

private:
    int m_port;


};
} // namespace motorcontrol