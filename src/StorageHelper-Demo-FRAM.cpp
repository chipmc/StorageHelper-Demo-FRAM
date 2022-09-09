/*
 * Project StorageHelper-Demo-FRAM
 * Description: Implementation of the StorageHelper Library using FRAM
 * Author: Chip McClelland - based on examples by Rick
 * Date: July 20th 2022
 */


#include "MyPersistentData.h"

SerialLogHandler logHandler(LOG_LEVEL_INFO);

SYSTEM_THREAD(ENABLED);
SYSTEM_MODE(MANUAL);

void setup() {
  sysStatusData::instance().setup();
}

void loop() {
  static unsigned long lastCheck = 0;
    if (millis() - lastCheck >= 10000) {
        lastCheck = millis();

        sysStatus.load();

        sysStatus.logData("After loading");

        sysStatus.setValue_test1(sysStatus.getValue_test1() + 1);
        sysStatus.setValue_test2(!sysStatus.getValue_test2());
        sysStatus.setValue_test3(sysStatus.getValue_test3() - 0.1);
        sysStatus.setValue_test4("testing sysStaus!"); 

        sysStatus.logData("After update");

        sysStatus.flush(true);
    }  
    sysStatusData::instance().loop();
}



