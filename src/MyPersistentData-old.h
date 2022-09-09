#ifndef __MYPERSISTENTDATA_H
#define __MYPERSISTENTDATA_H

#include "Particle.h"
#include "MB85RC256V-FRAM-RK.h"
#include "StorageHelperRK.h"


MB85RC256V fram(Wire, 0);


class sysStatusData : public StorageHelperRK::PersistentDataFRAM {
public:
	class SysData {
	public:
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

	static const uint32_t SYS_DATA_MAGIC = 0x20a99e73;
	static const uint16_t SYS_DATA_VERSION = 1;

	sysStatusData() : StorageHelperRK::PersistentDataFRAM(::fram, 0, &sysData.sysHeader, sizeof(SysData), SYS_DATA_MAGIC, SYS_DATA_VERSION) {
    };

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


	SysData sysData;
};

#endif  /* __MYPERSISTENTDATA_H */
