
/**
 * @file    MyPersistentData.h
 * @author  (add the author here)
 * @brief   All functions that are used to handle persistent data
 * @details (Add Details Here)
 * @version (Add version here)
 * @date    (Add the date here)
 * 
 * Version History:
 * 0.1 - Initial realease 
 * 
 */

//Include a standard header guard
#ifndef __MyPersistentData_H
#define __MyPersistentData_H

//Include standard header files from libraries:
#include <Particle.h>
#include <MB85RC256V-FRAM-RK.h>
#include <StorageHelperRK.h>

//Include other application specific header files
// #include (no other header files required from other singleton classes)

//Define external class instances. These are typically declared public in the main .CPP. I wonder if we can only declare it here?
extern MB85RC256V fram1;

//Macros(#define) to swap out during pre-processing (use sparingly). This is typically used outside of this .H and .CPP file within the main .CPP file or other .CPP files that reference this header file. 
// This way you can do "data.setup()" instead of "MyPersistentData::instance().setup()" as an example
#define data MyPersistentData::instance()


/**
 * This class is a singleton; you do not create one as a global, on the stack, or with new.
 * 
 * From global application setup you must call:
 * MyPersistentData::instance().setup();
 * 
 * From global application loop you must call:
 * MyPersistentData::instance().loop();
 */
class MyPersistentData : public StorageHelperRK::PersistentDataFRAM  {
public:
    /**
     * @brief Gets the singleton instance of this class, allocating it if necessary
     * 
     * Use MyPersistentData::instance() to instantiate the singleton.
     */
    static MyPersistentData &instance();

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

    class MyData {
	public:
		// This structure must always begin with the header (16 bytes)
		StorageHelperRK::PersistentDataBase::SavedDataHeader header;
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
    MyData myData;

    /**
     * @brief Get the value of....
     * 
     * You typically use MyPersistentData2::instance().getValue_test1();
     */
    int getValue_test1() const;

    /**
     * @brief Set the value of....
     * 
     * You typically use MyPersistentData2::instance().setValue_test1;
     */
	void setValue_test1(int value);

    /**
     * @brief Get the value of....
     * 
     * You typically use MyPersistentData2::instance().getValue_test2();
     */
	bool getValue_test2() const;
	
    
    /**
     * @brief Set the value of....
     * 
     * You typically use MyPersistentData2::instance().setValue_test2;
     */
    void setValue_test2(bool value);
	
     /**
     * @brief Get the value of....
     * 
     * You typically use MyPersistentData2::instance().getValue_test3();
     */
    double getValue_test3() const;
	
    /**
     * @brief Set the value of....
     * 
     * You typically use MyPersistentData2::instance().setValue_test3;
     */
    void setValue_test3(double value);

    /**
     * @brief Get the value of....
     * 
     * You typically use MyPersistentData2::instance().getValue_test4();
     */
	String getValue_test4() const;

    /**
     * @brief Set the value of....
     * 
     * You typically use MyPersistentData2::instance().setValue_test4;
     */
	bool setValue_test4(const char *str);
    
    /**
     * @brief Log the data
     * 
     * You typically use MyPersistentData2::instance().logData;
     */
    void logData(const char *msg); 


//Members here are internal only and therefore protected
protected:
    /**
     * @brief The constructor is protected because the class is a singleton
     * 
     * Use MyPersistentData::instance() to instantiate the singleton.
     */
    MyPersistentData();

    /**
     * @brief The destructor is protected because the class is a singleton and cannot be deleted
     */
    virtual ~MyPersistentData();

    /**
     * This class is a singleton and cannot be copied
     */
    MyPersistentData(const MyPersistentData&) = delete;

    /**
     * This class is a singleton and cannot be copied
     */
    MyPersistentData& operator=(const MyPersistentData&) = delete;

    /**
     * @brief Singleton instance of this class
     * 
     * The object pointer to this class is stored here. It's NULL at system boot.
     */
    static MyPersistentData *_instance;

    //Since these variables are only used internally - They can be private. 
    static const uint32_t DATA_MAGIC = 0x20a99e73;
	static const uint16_t DATA_VERSION = 1;

};

#endif  /* __MyPersistentData_H */