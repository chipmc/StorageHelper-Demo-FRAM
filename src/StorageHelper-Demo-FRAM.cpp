// This must be included before StorageHelperRK.h!MyPersistentData
#include "MB85RC256V-FRAM-RK.h"
#include "StorageHelperRK.h"
#include "MyPersistentData.h"


SYSTEM_THREAD(ENABLED);
SYSTEM_MODE(SEMI_AUTOMATIC);

SerialLogHandler logHandler(LOG_LEVEL_TRACE);

MB85RC256V fram1(Wire, 0);

void setup() {
    // Optional: Enable to make it easier to see debug USB serial messages at startup
    waitFor(Serial.isConnected, 10000);
    delay(2000);

    data.setup();
	Particle.connect();

}

void loop() {

    static unsigned long lastCheck = 0;
    if (millis() - lastCheck >= 10000) {
        lastCheck = millis();

        data.load();

        data.logData("after loading");

        data.setValue_test1(data.getValue_test1() + 1);
        data.setValue_test2(!data.getValue_test2());
        data.setValue_test3(data.getValue_test3() - 0.1);
        data.setValue_test4("testing!"); 

        data.logData("after update");

        data.flush(true);
    }  
}