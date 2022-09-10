#include "MyPersistentData.h"

MyPersistentData *MyPersistentData::_instance;

// [static]
MyPersistentData &MyPersistentData::instance() {
    if (!_instance) {
        _instance = new MyPersistentData();
    }
    return *_instance;
}

MyPersistentData::MyPersistentData() : StorageHelperRK::PersistentDataFRAM(fram1, 0, &myData.header, sizeof(MyData), DATA_MAGIC, DATA_VERSION) {
};

MyPersistentData::~MyPersistentData() {
}

void MyPersistentData::setup() {
    fram1.begin();
}

void MyPersistentData::loop() {
    // Put your code to run during the application thread loop here
}

int MyPersistentData::getValue_test1() const 
{
    return getValue<int>(offsetof(MyData, test1));
}


void MyPersistentData::setValue_test1(int value) {
    setValue<int>(offsetof(MyData, test1), value);
}

bool MyPersistentData::getValue_test2() const {
    return getValue<bool>(offsetof(MyData, test2));
}

void MyPersistentData::setValue_test2(bool value) {
    setValue<bool>(offsetof(MyData, test2), value);
}

double MyPersistentData::getValue_test3() const {
    return getValue<double>(offsetof(MyData, test3));
}

void MyPersistentData::setValue_test3(double value) {
    setValue<double>(offsetof(MyData, test3), value);
}

String MyPersistentData::getValue_test4() const {
    String result;
    getValueString(offsetof(MyData, test4), sizeof(MyData::test4), result);
    return result;
}
bool MyPersistentData::setValue_test4(const char *str) {
    return setValueString(offsetof(MyData, test4), sizeof(MyData::test4), str);
}

void MyPersistentData::logData(const char *msg) {
    Log.info("%s: %d, %d, %lf, %s", msg, myData.test1, (int)myData.test2, myData.test3, myData.test4);
}