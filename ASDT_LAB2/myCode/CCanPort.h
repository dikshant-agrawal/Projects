/******************************************************************************
 * @file    CCANPORT.h
 * @brief   CAN port abstraction class
 *
 * @copyright
 * Copyright by Darmstadt University of Applied Sciences
 *
 *****************************************************************************/

#ifndef CCANPORT_H
#define CCANPORT_H

#include "global.h"
#include "CPort.h"
#include "CRingbuffer.h"
#include "CUartPort.h"

class CRingBuffer;

/** Default CAN buffer size */
#define CAN_DEFAULTBUFFERSIZE 64

/**
 * @class CCanPort
 * @brief CAN communication port implementation
 *
 * This class implements a CAN port based on the generic CPort interface.
 * It handles initialization of the CAN peripheral as well as RX/TX buffering.
 */
class CCanPort : public CPort
{
public:

    /**
     * @enum port_t
     * @brief Available CAN ports
     */
    enum port_t
    {
        CAN1,   /**< CAN Port 1 */
        CAN2,   /**< CAN Port 2 */
        NONE    /**< No valid port selected */
    };

    /**
     * @brief Constructor
     *
     * Initializes the CAN peripheral and sets up the receive and transmit
     * ring buffers.
     *
     * @note Please verify hardware limitations and supported baud rates
     *       before using this constructor.
     *
     * @param port         Hardware CAN port to be used
     * @param baudrate     CAN baudrate (e.g. 1 Mbps)
     * @param bufferSizeRx Size of the receive buffer
     * @param bufferSizeTx Size of the transmit buffer
     */
    CCanPort(port_t port = NONE,
             uint32_t baudrate = 1000000,
             uint16_t bufferSizeRx = CAN_DEFAULTBUFFERSIZE,
             uint16_t bufferSizeTx = CAN_DEFAULTBUFFERSIZE);

private:

    /**
     * @brief Send one byte to the CAN hardware
     *
     * This function is non-blocking. If the hardware is busy, no data
     * will be transmitted and an error code is returned.
     *
     * @note This function is intended to be called from an ISR.
     *
     * @param data Byte to be transmitted
     * @return RC_SUCCESS if the byte was transmitted successfully
     *         RC_PERIPHERALOCCUPIED if the hardware was busy
     */
    RC_t writeByte_hw(uint8_t data);

    /**
     * @brief Receive one byte from the CAN hardware
     *
     * This function is non-blocking. If no data is available,
     * an error code is returned.
     *
     * @note This function is intended to be called from an ISR.
     *
     * @param data Reference to store the received byte
     * @return RC_SUCCESS if a byte was received
     *         RC_NODATA if no data was available
     */
    RC_t readByte_hw(uint8_t& data);

    /**
     * @brief Get the CAN driver package size
     *
     * @return Size of one CAN driver package in bytes
     */
    uint8_t getDriverPackageSize();

    /**
     * @brief Read a CAN package into the RX ring buffer
     *
     * @param ringbufferRx Reference to the receive ring buffer
     * @return Result code indicating success or failure
     */
    RC_t readPackage_hw(CRingBuffer& ringbufferRx);

    /**
     * @brief Write a CAN package from the TX ring buffer
     *
     * @param ringbufferTx Reference to the transmit ring buffer
     * @return Result code indicating success or failure
     */
    RC_t writePackage_hw(CRingBuffer& ringbufferTx);
};

#endif /* CCANPORT_H */
