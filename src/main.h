#include <pwmmotor/pwmmotor.h>



#include <ArduinoOTA.h>
#include <ESPAsyncWebServer.h>
#include <Arduino.h>
#include <ESPAsyncTCP.h>
#include <TaskManagerIO.h>
#include "constants.h"
#include <string.h>
#include <Servo.h>
#include <ArduinoJson.h>
#include <heartbeat.h>

heartbeat::Heart m_heart; // default constructor, 100ms heartdeath


motorcontrol::PWMMotorController m_leftFMotor{motors::frontleft};
motorcontrol::PWMMotorController m_leftRMotor{motors::rearleft};

motorcontrol::PWMMotorController m_rightFMotor{motors::frontright};
motorcontrol::PWMMotorController m_rightRMotor{motors::rearright};


AsyncWebServer server(httpport);
AsyncWebSocket ws("/ws");
AsyncEventSource events("/events");