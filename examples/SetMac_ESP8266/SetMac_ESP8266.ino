#include <ESP8266WiFi.h>
#include <SetMac_ESP8266.h>

#define ssid ""
#define password ""

void setup() {
    Serial.begin( 115200 );
    delay( 10 );

    Serial.println();
    Serial.println();

    uint8_t mac[ 6 ] = {
        0x5C , 0xCF , 0x7F , 0xEF , 0xBA , 0x77
    };
    setMac( mac );

    // or
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
