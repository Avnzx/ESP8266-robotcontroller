#pragma once

#define USE_LittleFS

// Just in case we want to use SPIFFS
#ifdef USE_LittleFS
  #include <FS.h>
  #define MYFS LittleFS
  #include <LittleFS.h> 
#else
  #define MYFS SPIFFS
#endif

// Set LED_BUILTIN if it is not defined by Arduino framework
#ifndef LED_BUILTIN
    #define LED_BUILTIN 13
#endif
int ledstate = LOW;

#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <FS.h>

class robotcontroller {
    public:
        robotcontroller();
        void RobotInit();
        void RobotPeriodic();
        void DisabledInit();
        void DisabledPeriodic();
        void TeleopInit();
        void TeleopPeriodic();

    private:
        bool m_enabled;
        bool m_safetydisabled;

};