#pragma once

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

