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

constexpr auto ssid = "4739-esp";
const int httpport = 80;

namespace specialmessage{
    const char* heartbeat = "HB";
} // namespace specialmessage

namespace motors{
    int frontleft = 5;
    int frontright = 14;
    int rearleft = 4;
    int rearright = 12;
} // namespace motors


const char delimiter = ',';

