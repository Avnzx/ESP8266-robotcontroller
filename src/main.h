#include <pwmmotor/pwmmotor.h>
#include <ArduinoOTA.h>
#include <ESPAsyncWebServer.h>
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <FS.h>
#include <ESPAsyncTCP.h>
#include <TaskManagerIO.h>
#include "constants.h"
#include <string.h>
#include <Servo.h>
#include <ArduinoJson.h>


motorcontrol::PWMMotorController m_leftFMotor{5};
motorcontrol::PWMMotorController m_leftRMotor{4};

motorcontrol::PWMMotorController m_rightFMotor{14};
motorcontrol::PWMMotorController m_rightRMotor{12};

// Set LED_BUILTIN if it is not defined by Arduino framework
#ifndef LED_BUILTIN
    #define LED_BUILTIN 13
#endif
int ledstate = LOW;


AsyncWebServer server(httpport);
AsyncWebSocket ws("/ws");
AsyncEventSource events("/events");