# SetMac_ESP8266

Uses `wifi_set_macaddr` method from `user_interfaces.h`.  
Exposes 2 simple methods:
- `bool setMac( const uint8_t mac[ 6 ] );` set mac adress
- `bool setRandomMac();` : set a random mac adress

**These methods must be called before `WiFi.begin();`.**

### Usage:
```c++
#include <ESP8266WiFi.h>
#include <SetMac_ESP8266.h>

#define ssid ""
#define password ""

void setup() {
    Serial.begin( 115200 );
    delay( 10 );

    Serial.println();
    Serial.println();

    // set chosen mac adress
    uint8_t mac[ 6 ] = {
        0x5C , 0xCF , 0x7F , 0xEF , 0xBA , 0x77
    };
    setMac( mac );

    // or set a randomly generated adress
    // setRandomMac();

    Serial.print( "MAC address is " );
    Serial.println( WiFi.macAddress() );

    WiFi.hostname( "AwesomeSensor" );

    Serial.print( "Connecting to " );
    Serial.println( ssid );

    WiFi.begin( ssid, password );

    while( WiFi.status() != WL_CONNECTED ) {
        delay( 500 );
        Serial.print( "." );
    }

    Serial.println( "" );
    Serial.println( "WiFi connected" );
    Serial.println( "IP address: " );
    Serial.println( WiFi.localIP() );
}

void loop() {}
```


Based on [How to Change the MAC Address of ESP8266?](https://yoursunny.com/t/2017/change-ESP8266-MAC/)
