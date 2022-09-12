#include "Particle.h"
#include "MyPersistentData.h"
#include "Another_Module.h"

SYSTEM_THREAD(ENABLED);
SYSTEM_MODE(MANUAL);

SerialLogHandler logHandler(LOG_LEVEL_TRACE);

void setup() {
    // Optional: Enable to make it easier to see debug USB serial messages at startup
    waitFor(Serial.isConnected, 10000);
    data.setup();
}

void loop() {

    static unsigned long lastCheck = 0;
    if (millis() - lastCheck >= 10000) {
        lastCheck = millis();


        data.logData("after loading");

        data.setValue_test1(data.getValue_test1() + 1);
        data.setValue_test2(!data.getValue_test2());
        data.setValue_test3(data.getValue_test3() - 0.1);
        data.setValue_test4("testing!"); 

        data.logData("after update");

        testStorageAccess();

    }  

    data.loop();
}