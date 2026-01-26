/******************************************************************************
 * @file    CRingBuffer.h
 * @brief   Ring buffer implementation for byte-wise data storage
 *
 * @copyright
 * Copyright by Darmstadt University of Applied Sciences
 *
 *****************************************************************************/

#ifndef CRINGBUFFER_H
#define CRINGBUFFER_H

#include "global.h"

/**
 * @class CRingBuffer
 * @brief Circular buffer for byte-oriented data
 *
 * The CRingBuffer class provides a fixed-size circular buffer
 * implementation for storing and retrieving bytes in FIFO order.
 */
class CRingBuffer
{
private:
    uint8_t*  m_pBuffer;   /**< Pointer to buffer memory */
    uint16_t  m_size;      /**< Total buffer size */
    uint16_t  m_readIdx;   /**< Read index */
    uint16_t  m_writeIdx;  /**< Write index */
    uint16_t  m_fillLevel; /**< Number of stored bytes */

public:
    /**
     * @brief Constructor
     *
     * Allocates a ring buffer of the given size and initializes
     * all internal indices.
     *
     * @param size Size of the ring buffer in bytes
     */
    CRingBuffer(uint16_t size = 10);

    /**
     * @brief Destructor
     *
     * Releases allocated buffer memory.
     */
    ~CRingBuffer();

    /**
     * @brief Read one byte from the buffer
     *
     * Retrieves the next byte from the buffer.
     *
     * @param data Reference to store the read byte
     * @return RC_SUCCESS if a byte was read
     *         RC_BUFFERUNDERFLOW if the buffer is empty
     */
    RC_t read(uint8_t& data);

    /**
     * @brief Write one byte into the buffer
     *
     * Stores a byte in the buffer.
     *
     * @param data Byte to be written
     * @return RC_SUCCESS if the byte was written
     *         RC_BUFFEROVERFLOW if the buffer is full
     */
    RC_t write(uint8_t data);

    /**
     * @brief Get the current fill level of the buffer
     *
     * @return Number of bytes currently stored in the buffer
     */
    uint16_t getFilledLevel() const;

    /**
     * @brief Clear the buffer
     *
     * Resets the buffer indices and fill level.
     *
     * @return RC_SUCCESS on success
     */
    RC_t clear();
};

#endif /* CRINGBUFFER_H */
