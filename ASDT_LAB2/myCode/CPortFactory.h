/******************************************************************************
 * @file    CPortFactory.h
 * @brief   Factory class for creating communication port instances
 *
 * @copyright
 * Copyright by Darmstadt University of Applied Sciences
 *
 *****************************************************************************/

#ifndef CPORTFACTORY_H
#define CPORTFACTORY_H

#include "CPort.h"
#include "CUartPort.h"
#include "CCanPort.h"

/**
 * @class CPortFactory
 * @brief Factory for creating communication port objects
 *
 * The CPortFactory class provides static factory methods for creating
 * different types of communication ports with default or user-defined
 * configurations.
 */
class CPortFactory
{
public:
    /**
     * @enum port_t
     * @brief Supported port types
     */
    enum port_t
    {
        UART, /**< UART communication port */
        CAN,  /**< CAN communication port */
        NONE  /**< No valid port type */
    };

    /**
     * @brief Create a CAN port instance
     *
     * Creates and initializes a CAN port with the given configuration.
     *
     * @param port         Hardware CAN port to be used
     * @param baudrate     CAN baudrate
     * @param bufferSizeRx Size of the receive buffer
     * @param bufferSizeTx Size of the transmit buffer
     *
     * @return Pointer to the created CPort instance
     *         nullptr if creation failed
     */
    static CPort* createCanPort(
        CCanPort::port_t port = CCanPort::NONE,
        uint32_t baudrate = 1000000,
        uint16_t bufferSizeRx = CAN_DEFAULTBUFFERSIZE,
        uint16_t bufferSizeTx = CAN_DEFAULTBUFFERSIZE);

    /**
     * @brief Create a UART port instance
     *
     * Creates and initializes a UART port with the given configuration.
     *
     * @param port         Hardware UART port to be used
     * @param baudrate     UART baudrate
     * @param bits         Number of data bits
     * @param parity       UART parity configuration
     * @param stopbits     Number of stop bits
     * @param bufferSizeRx Size of the receive buffer
     * @param bufferSizeTx Size of the transmit buffer
     *
     * @return Pointer to the created CPort instance
     *         nullptr if creation failed
     */
    static CPort* createUartPort(
        CUartPort::port_t port = CUartPort::NONE,
        uint32_t baudrate = 115200,
        uint8_t bits = 8,
        CUartPort::parity_t parity = CUartPort::NOPARITY,
        uint8_t stopbits = 1,
        uint16_t bufferSizeRx = UART_DEFAULTBUFFERSIZE,
        uint16_t bufferSizeTx = UART_DEFAULTBUFFERSIZE);

    /**
     * @brief Create a port using default configuration
     *
     * Creates a communication port using the default configuration
     * parameters associated with the given port type.
     *
     * @param port Type of port to be created
     * @return Pointer to the created CPort instance
     *         nullptr if the port type is invalid
     */
    static CPort* createPort(port_t port);
};

#endif /* CPORTFACTORY_H */
