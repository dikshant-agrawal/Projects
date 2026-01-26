/******************************************************************************
 * @file    CPort.h
 * @brief   Abstract base class for communication ports
 *
 * @copyright
 * Copyright by Darmstadt University of Applied Sciences
 *
 *****************************************************************************/

#ifndef CPORT_H
#define CPORT_H

#include "global.h"
#include "CRingBuffer.h"
#include <string>

/**
 * @class CPort
 * @brief Abstract communication port interface
 *
 * The CPort class provides a generic interface for byte- and
 * package-based communication ports. It manages transmit and
 * receive ring buffers and defines hardware-specific interfaces
 * to be implemented by derived classes.
 */
class CPort
{
protected:
    /** Transmit ring buffer */
    CRingBuffer m_ringBufferTx;

    /** Receive ring buffer */
    CRingBuffer m_ringBufferRx;

public:
    /**
     * @brief Constructor
     *
     * Initializes the transmit and receive ring buffers.
     *
     * @param txSize Size of the transmit buffer in bytes
     * @param rxSize Size of the receive buffer in bytes
     */
    CPort(uint16_t txSize = 10, uint16_t rxSize = 10);

    /**
     * @brief Write a byte stream to the transmit buffer
     *
     * Copies the given data into the transmit ring buffer.
     *
     * @param data Byte stream to be transmitted
     * @return RC_SUCCESS if data was written successfully
     *         RC_BUFFEROVERFLOW if the buffer is full
     */
    RC_t writeByteStream(const std::string& data);

    /**
     * @brief Read a byte stream from the receive buffer
     *
     * Extracts data from the receive ring buffer.
     *
     * @param data Reference to store the received data
     * @return RC_SUCCESS if data was read successfully
     *         RC_BUFFERUNDERFLOW if the buffer is empty
     */
    RC_t readByteStream(std::string& data);

    /**
     * @brief Transmit buffered data to the hardware (ISR context)
     *
     * Sends all available data from the transmit buffer to
     * the hardware interface.
     *
     * @note Intended to be called from an interrupt service routine.
     *
     * @return RC_SUCCESS on success
     *         Device-specific error code on failure
     */
    RC_t portTx_isr();

    /**
     * @brief Receive data from hardware into the buffer (ISR context)
     *
     * Reads available data from the hardware interface and stores
     * it into the receive buffer.
     *
     * @note Intended to be called from an interrupt service routine.
     *
     * @return RC_SUCCESS on success
     *         Device-specific error code on failure
     */
    RC_t portRx_isr();

    /**
     * @brief Send one byte directly to the hardware
     *
     * @param data Byte to be transmitted
     * @return RC_SUCCESS if the byte was transmitted
     *         Device-specific error code on failure
     */
    virtual RC_t writeByte_hw(uint8_t data) = 0;

    /**
     * @brief Receive one byte directly from the hardware
     *
     * @param data Reference to store the received byte
     * @return RC_SUCCESS if a byte was received
     *         Device-specific error code on failure
     */
    virtual RC_t readByte_hw(uint8_t& data) = 0;

    /**
     * @brief Write a data package from the transmit buffer to hardware
     *
     * @param m_ringBufferTx Transmit ring buffer
     * @return Result code indicating success or failure
     */
    virtual RC_t writePackage_hw(CRingBuffer& m_ringBufferTx) = 0;

    /**
     * @brief Read a data package from hardware into the receive buffer
     *
     * @param m_ringBufferRx Receive ring buffer
     * @return Result code indicating success or failure
     */
    virtual RC_t readPackage_hw(CRingBuffer& m_ringBufferRx) = 0;
};

#endif /* CPORT_H */
