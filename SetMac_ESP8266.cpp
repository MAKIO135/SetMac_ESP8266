#include "Arduino.h"
#include "SetMac_ESP8266.h"

extern "C" {
    #include "user_interface.h"
}

bool setRandomMac(){
    uint8_t mac[6];
    for (size_t i = 0; i < 6; ++i) {
        mac[i] = random(256);
    }
    mac[0] = mac[0] & ~0x01;
    return setMac(mac);
}

bool setMac(const uint8_t mac[6]){
    return wifi_set_macaddr(STATION_IF, const_cast<uint8*>(mac));
}
