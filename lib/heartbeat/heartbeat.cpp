#include "heartbeat.h"
#include <type_traits>
#include <Arduino.h>

using namespace heartbeat;

Heart::Heart(unsigned long timeout){
    m_timeout = timeout;    
}

void Heart::ResetHeart(){
    m_lastBeat = millis();
}

bool Heart::HeartDead(){
    return (millis() - m_lastBeat) > m_timeout ? true : false;
}
