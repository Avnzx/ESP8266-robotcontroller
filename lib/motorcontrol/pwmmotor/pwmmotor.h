#pragma once 
#include <Servo.h>

namespace motorcontrol {
class PWMMotorController : Servo {

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
     * @brief Get the value in microseconds of the controller
     * 
     *
     */
    double GetUs();

    /**
     * @brief Set the speed in microseconds of the controller
     * 
     * @param speed 
     */
    void SetUs(double speed);


    /**
     * @brief Has to be updated, call this when you call Run() for the master
     * 
     * @param controller to follow 
     */
    void FollowOnce(PWMMotorController* controller);

    /**
     * Common interface for inverting direction of a speed controller.
     *
     * This call has no effect if the controller is a follower. To invert
     * a follower, see the follow() method.
     *
     * @param isInverted The state of inversion, true is inverted.
     */
    void SetInverted(bool isInverted);


    /**
     * @brief DO NOT RUN OUTSIDE OF LOOP
     * 
     */
    void Run();

private:
    Servo m_servo;

    int m_reverseUs = 1000;
    int m_neutralUs = 1500;
    int m_forwardUs = 2000;
    int m_deadbandUs = 40;

    bool m_inverted = false;

    int m_port;
    int m_valueUs = m_neutralUs;


};
} // namespace motorcontrol