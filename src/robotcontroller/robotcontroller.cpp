#include "robotcontroller.h"
#include <TaskManagerIO.h>
#include "constants.h"

#include <stdexcept>

robotcontroller::robotcontroller(){}

void robotcontroller::RobotInit() {
    // initialize LED digital pin as an output.
    Serial.begin(115200);
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN,0);
    // setup AP open
    WiFi.mode(WIFI_AP);
    WiFi.softAP(ssid, NULL, 11, 0, 4);
    Serial.printf("\n We are: %s \n", ssid);

    m_safetydisabled = false;


    if (MDNS.begin("esp8266")){
        Serial.println("MDNS responder started");
    }
    

    if (MYFS.begin()) {
        Serial.print(F("FS mounted\n"));
    } else {
        throw std::runtime_error("FS mount failed\n");
    }

    // create a task for the load LED indicator
    taskManager.scheduleFixedRate(500, [] {
    digitalWrite(LED_BUILTIN,LOW); // this is the idle LED, HIGH = off
    delay(50);
    digitalWrite(LED_BUILTIN,HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN,LOW);
    delay(50);    
    digitalWrite(LED_BUILTIN,HIGH);
    }, TIME_MILLIS);
}
void robotcontroller::RobotPeriodic() {}
void robotcontroller::DisabledInit() {}
void robotcontroller::DisabledPeriodic() {}
void robotcontroller::TeleopInit() {}
void robotcontroller::TeleopPeriodic() {}