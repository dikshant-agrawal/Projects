/******************************************************************************
 * @file    CUartPort.h
 * @brief   UART communication port implementation
 *
 * @copyright
 * Copyright by Darmstadt University of Applied Sciences
 *
 *****************************************************************************/

#ifndef CUARTPORT_H
#define CUARTPORT_H

#include "global.h"
#include "CPort.h"
#include "CRingBuffer.h"

/** Default UART buffer size */
#define UART_DEFAULTBUFFERSIZE 20

/**
 * @class CUartPort
 * @brief UART communication port
 *
 * Implements a UART-based communication port derived from CPort.
 * Handles hardware initialization and RX/TX buffering.
 */
class CUartPort : public CPort
{
public:
    /**
     * @enum port_t
     * @brief Available UART (ASCLIN) ports
     */
    enum port_t
    {
        ASCLIN1, /**< ASCLIN Port 1, default mapped to USB bridge */
        ASCLIN2, /**< ASCLIN Port 2, mapped to P12(0), P12(2) */
        ASCLIN3, /**< ASCLIN Port 3, mapped to P12(3), P12(4) */
        ASCLIN4, /**< ASCLIN Port 4, mapped to P12(1), P12(5) */
        ASCLIN5, /**< ASCLIN Port 5, mapped to P12(6) */
        NONE     /**< No valid port selected */
    };

    /**
     * @enum parity_t
     * @brief UART parity configuration
     */
    enum parity_t
    {
        ODD,      /**< Odd parity */
        EVEN,     /**< Even parity */
        NOPARITY  /**< No parity check */
    };

    /**
     * @brief Constructor
     *
     * Initializes the UART peripheral and configures the receive and
     * transmit buffers.
     *
     * @note Ensure that the selected configuration parameters are
     *       supported by the hardware.
     *
     * @param port         Hardware UART port to be used
     * @param baudrate     UART baudrate
     * @param bits         Number of data bits
     * @param parity       Parity configuration
     * @param stopbits     Number of stop bits
     * @param bufferSizeRx Size of the receive buffer
     * @param bufferSizeTx Size of the transmit buffer
     */
    CUartPort(port_t port = NONE,
              uint32_t baudrate = 115200,
              uint8_t bits = 8,
              parity_t parity = NOPARITY,
              uint8_t stopbits = 1,
              uint16_t bufferSizeRx = UART_DEFAULTBUFFERSIZE,
              uint16_t bufferSizeTx = UART_DEFAULTBUFFERSIZE);

private:
    /**
     * @brief Send one byte to the UART hardware
     *
     * This function is non-blocking. If the hardware is busy,
     * no data is transmitted.
     *
     * @note Intended to be called from an interrupt service routine.
     *
     * @param data Byte to be transmitted
     * @return RC_SUCCESS if the byte was transmitted
     *         RC_PERIPHERALOCCUPIED if the hardware was busy
     */
    RC_t writeByte_hw(uint8_t data);

    /**
     * @brief Receive one byte from the UART hardware
     *
     * This function is non-blocking. If no data is available,
     * an error code is returned.
     *
     * @note Intended to be called from an interrupt service routine.
     *
     * @param data Reference to store the received byte
     * @return RC_SUCCESS if a byte was received
     *         RC_NODATA if no data was available
     */
    RC_t readByte_hw(uint8_t& data);

    /**
     * @brief Get the UART driver package size
     *
     * @return Size of one UART driver package in bytes
     */
    uint8_t getDriverPackageSize();

    /**
     * @brief Read a data package from UART hardware
     *
     * @param ringbufferRx Receive ring buffer
     * @return Result code indicating success or failure
     */
    RC_t readPackage_hw(CRingBuffer& ringbufferRx);

    /**
     * @brief Write a data package to UART hardware
     *
     * @param ringbufferTx Transmit ring buffer
     * @return Result code indicating success or failure
     */
    RC_t writePackage_hw(CRingBuffer& ringbufferTx);
};

#endif /* CUARTPORT_H */
