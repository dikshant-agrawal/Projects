
#include <iostream>
using namespace std;


#include "CCanPort.h"

CCanPort::CCanPort(port_t port, uint32_t baudrate, uint16_t bufferSizeRx, uint16_t bufferSizeTx) : CPort(bufferSizeTx, bufferSizeRx)
{
}


uint8_t CCanPort::getDriverPackageSize()
{
	return 8;
}

RC_t CCanPort::readPackage_hw(CRingBuffer &ringbufferRx)
{
	uint8_t packageSize = getDriverPackageSize();
	uint8_t data;

	for(uint8_t i = 0; i<packageSize; i++){
		if(RC_SUCCESS != readByte_hw(data)){

			return RC_NODATA;

		}
		if(RC_SUCCESS != ringbufferRx.write(data)){
			return RC_BUFFEROVERFLOW;
		}

	}

	return RC_SUCCESS;
}

RC_t CCanPort::writePackage_hw(CRingBuffer &ringbufferTx)
{
	uint8_t packageSize = getDriverPackageSize();
	uint8_t package[packageSize];
	uint8_t count = 0;

    // Build one CAN package
    for (uint8_t i = 0; i < packageSize; i++) {
        if (RC_SUCCESS == ringbufferTx.read(package[count])) {
            count++;
        } else {
            break;  // Ringbuffer empty
        }
    }

    // Nothing to send
    if (count == 0) {
        return RC_SUCCESS;
    }

    // "Send" the package to CAN hardware (stub behavior)
    cout << "Just wrote to CAN hardware: Package: [ ";
    for (uint8_t i = 0; i < count; i++) {
        cout << static_cast<char>(package[i]);
    }
    cout << " ]" << endl;


	return RC_SUCCESS;
}

RC_t CCanPort::readByte_hw(uint8_t &data)
{
	static uint8_t fakeData = 'A';
	static uint16_t counter = 0;

	counter++;

	if (counter >= 20) return RC_NODATA;

	data = fakeData++;

	cout << "Just read from CAN hardware: " << data << endl;

	return RC_SUCCESS;
}

RC_t CCanPort::writeByte_hw(uint8_t data)
{
	cout << "Just wrote to CAN hardware: " << data << endl;
	return RC_SUCCESS;
}
