#ifndef __MYPERSISTENTDATA_H
#define __MYPERSISTENTDATA_H

#include "Particle.h"
#include "MB85RC256V-FRAM-RK.h"
#include "StorageHelperRK.h"

/**
 * This class is a singleton; you do not create one as a global, on the stack, or with new.
 * 
 * From global application setup you must call:
 * sysStatusData::instance().setup();
 * 
 * From global application loop you must call:
 * sysStatusData::instance().loop();
 */
class sysStatusData : public StorageHelperRK::PersistentDataFRAM {
public:
    /**
     * @brief Gets the singleton instance of this class, allocating it if necessary
     * 
     * Use sysStatusData::instance() to instantiate the singleton.
     */
    static sysStatusData &instance();

    /**
     * @brief Perform setup operations; call this from global application setup()
     * 
     * You typically use MyPersistentData::instance().setup();
     */
    void setup();

    /**
     * @brief Perform application loop operations; call this from global application loop()
     * 
     * You typically use MyPersistentData::instance().loop();
     */
    void loop();

    class SysData {
		// This structure must always begin with the header (16 bytes)
		StorageHelperRK::PersistentDataBase::SavedDataHeader sysHeader;
		// Your fields go here. Once you've added a field you cannot add fields
		// (except at the end), insert fields, remove fields, change size of a field.
		// Doing so will cause the data to be corrupted!
		// You may want to keep a version number in your data.
		int test1;
		bool test2;
		double test3;
		char test4[10];
		// OK to add more fields here 
	};

    static const uint32_t SYS_DATA_MAGIC;
	static const uint16_t SYS_DATA_VERSION;

	//sysStatusData() : StorageHelperRK::PersistentDataFRAM(MB85RC &fram, int framOffset, SavedDataHeader *savedDataHeader, size_t savedDataSize, uint32_t savedDataMagic, uint16_t savedDataVersion) {};

	int getValue_test1(); 
	void setValue_test1(int value); 

	bool getValue_test2(); 
	void setValue_test2(bool value); 

	double getValue_test3(); 
	void setValue_test3(double value); 

	String getValue_test4(); 
	bool setValue_test4(const char *str); 

    void logData(const char *msg); 


protected:
    /**
     * @brief The constructor is protected because the class is a singleton
     * 
     * Use MyPersistentData::instance() to instantiate the singleton.
     */
    sysStatusData();

    /**
     * @brief The destructor is protected because the class is a singleton and cannot be deleted
     */
    virtual ~sysStatusData();

    /**
     * This class is a singleton and cannot be copied
     */
    sysStatusData(const sysStatusData&) = delete;

    /**
     * This class is a singleton and cannot be copied
     */
    sysStatusData& operator=(const sysStatusData&) = delete;

    /**
     * @brief Singleton instance of this class
     * 
     * The object pointer to this class is stored here. It's NULL at system boot.
     */
    static sysStatusData *_instance;

};

extern sysStatusData sysStatus;
#endif  /* __MYPERSISTENTDATA_H */
