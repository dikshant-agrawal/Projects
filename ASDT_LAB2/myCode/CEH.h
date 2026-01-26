/******************************************************************************
 * @file    CEH.h
 * @brief   Central Error Handler (CEH) interface
 *
 * @author  agraw
 * @date    19-Jan-2026
 *
 *****************************************************************************/

#ifndef CEH_H_
#define CEH_H_

#include "global.h"

/**
 * @enum CEH_EC
 * @brief Error codes handled by the Central Error Handler
 *
 * Defines all error conditions that can be reported to the
 * Central Error Handler.
 */
enum CEH_EC
{
    CEH_NULL_POINTER,        /**< Null pointer detected */
    CEH_UART_PORT_EXHAUSTED, /**< No UART ports available */
    CEH_CAN_PORT_EXHAUSTED   /**< No CAN ports available */
};

/**
 * @class CEH
 * @brief Central Error Handler
 *
 * Provides a centralized interface for reporting system-wide
 * errors and exceptional conditions.
 */
class CEH
{
public:
    /**
     * @brief Report an error to the Central Error Handler
     *
     * Reports the specified error code for further processing,
     * logging, or system reaction.
     *
     * @param errorCodes Error code to be reported
     */
    static void CEH_report(CEH_EC errorCodes);
};

#endif /* CEH_H_ */
