#include "pwmmotor.h"
#include <math.h>
#include <algorithm>
#include <TaskManagerIO.h>

#ifdef DEBUG
#include <Arduino.h>
#endif

using namespace motorcontrol;

    PWMMotorController::PWMMotorController(int port){
        m_port = port;
        m_servo.attach(m_port);
    }

    PWMMotorController::~PWMMotorController(){
        m_servo.detach();
    }

    void PWMMotorController::Set(double speed){
        if (!std::isfinite(speed)) { speed = 0.0; }
        speed = m_inverted ? -speed : speed;

        if (speed > 0){
            m_valueUs = ((m_forwardUs - (m_neutralUs + m_deadbandUs)) * speed) + (m_neutralUs + m_deadbandUs);
        } else if (speed < 0) {
            m_valueUs = ((((m_neutralUs - m_deadbandUs) - m_reverseUs) * speed) + m_neutralUs);
        } else {
            m_valueUs = m_neutralUs;
        }
        Run();
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

    double PWMMotorController::GetUs(){
        return m_valueUs;
    }

    void PWMMotorController::SetUs(double speed){
        m_valueUs = speed;
    }

    void PWMMotorController::FollowOnce(PWMMotorController* controller){
        m_valueUs = controller->GetUs();
    }

    void PWMMotorController::Disable(){
        m_enabled = false;

    }

    void PWMMotorController::Enable(){
        m_enabled = true;
    }

    void PWMMotorController::Run(){
        if(m_enabled){
            m_servo.writeMicroseconds(m_valueUs);
        } else {
            m_servo.writeMicroseconds(m_neutralUs);

        }
    }

    