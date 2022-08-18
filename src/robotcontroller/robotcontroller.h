#pragma once

#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <FS.h>

#include "constants.h"

class robotcontroller {
    public:
        robotcontroller();
        void RobotInit();
        void RobotPeriodic();
        void DisabledInit();
        void DisabledPeriodic();
        void TeleopInit();
        void TeleopPeriodic();

        void Disable();
        void SafetyDisable();
        void Enable();

    private:
        bool m_enabled;
        bool m_safetydisabled;

};