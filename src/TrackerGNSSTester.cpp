#include "Particle.h"

#include "location_service.h"

SYSTEM_THREAD(ENABLED);
SYSTEM_MODE(SEMI_AUTOMATIC);

void setup() {
    LocationService::instance().begin();

    LocationService::instance().start();
}

void loop() {
    if (Serial.available()) {
        uint8_t buf[128];
        size_t len = 0;

        while(len < sizeof(buf) && Serial.available()) {
            buf[len++] = (uint8_t) Serial.read();
        }
        
        LocationService::instance().writeBytes(buf, len);
    }
}

