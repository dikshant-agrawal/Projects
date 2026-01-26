
/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CPORTFACTORY.CPP
* Author          :
* Description     :
*
*
****************************************************************************/


//System Include Files


//Own Include Files
#include "CPortFactory.h"
#include "CEH.h"
#include "config.h"


//Method Implementations
uint16_t m_UARTPort = 0;
uint16_t m_CANPort = 0;


CPort* CPortFactory::createCanPort(CCanPort::port_t port,
		uint32_t baudrate, uint16_t bufferSizeRx, uint16_t bufferSizeTx)
{
	if(m_CANPort >= PORT_CANNMAX){
		CEH::CEH_report(CEH_CAN_PORT_EXHAUSTED);
	}

	m_CANPort++;
	return new CCanPort(port, baudrate,bufferSizeRx, bufferSizeTx);
}

CPort* CPortFactory::createUartPort(CUartPort::port_t port,
		uint32_t baudrate, uint8_t bits, CUartPort::parity_t parity,
		uint8_t stopbits, uint16_t bufferSizeRx, uint16_t bufferSizeTx)
{
	if(m_CANPort >= PORT_ASCLINMAX){
		CEH::CEH_report(CEH_UART_PORT_EXHAUSTED);
	}

	m_UARTPort++;

	return new CUartPort(port, baudrate, bits, parity,stopbits, bufferSizeRx, bufferSizeTx);
}

CPort* CPortFactory::createPort(port_t port)
{
	switch (port)
	{
	case UART: return createUartPort();
	case CAN: return createCanPort();
	default: /* Some error handling */ break;
	}

	return 0;
}
