#include "MyPersistentData.h"

sysStatusData *sysStatusData::_instance;

// [static]
sysStatusData &sysStatusData::instance() {
    if (!_instance) {
        _instance = new sysStatusData();
    }
    return *_instance;
}

sysStatusData::sysStatusData() {
}

sysStatusData::~sysStatusData() {
}

void sysStatusData::setup() {
  fram.begin();
  sysStatus.setup();
}

void sysStatusData::loop() {
    // Put your code to run during the application thread loop here
    sysStatus.flush(true);
}

static const uint32_t SYS_DATA_MAGIC = 0x20a99e73;
static const uint16_t SYS_DATA_VERSION = 1;

SysData sysData;

sysStatusData() : StorageHelperRK::PersistentDataFRAM(::fram, 0, &sysData.sysHeader, sizeof(SysData), SYS_DATA_MAGIC, SYS_DATA_VERSION) {};

int getValue_test1() const {
    return getValue<int>(offsetof(SysData, test1));
}

void setValue_test1(int value) {
    setValue<int>(offsetof(SysData, test1), value);
}

bool getValue_test2() const {
    return getValue<bool>(offsetof(SysData, test2));
}

void setValue_test2(bool value) {
    setValue<bool>(offsetof(SysData, test2), value);
}

double getValue_test3() const {
    return getValue<double>(offsetof(SysData, test3));
}

void setValue_test3(double value) {
    setValue<double>(offsetof(SysData, test3), value);
}

String getValue_test4() const {
    String result;
    getValueString(offsetof(SysData, test4), sizeof(SysData::test4), result);
    return result;
}
bool setValue_test4(const char *str) {
    return setValueString(offsetof(SysData, test4), sizeof(SysData::test4), str);
}

void logData(const char *msg) {
    Log.info("%s: %d, %d, %lf, %s", msg, sysData.test1, (int)sysData.test2, sysData.test3, sysData.test4);
}


