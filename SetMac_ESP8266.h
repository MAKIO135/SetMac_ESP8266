#ifndef SetMac_ESP8266_H
    #define SetMac_ESP8266_H

    #include <cstdint>

    bool setRandomMac();

    bool setMac(const uint8_t mac[6]);
#endif
