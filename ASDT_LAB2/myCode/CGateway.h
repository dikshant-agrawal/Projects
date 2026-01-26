/******************************************************************************
 * @file    CParser.h
 * @brief   Gateway class for data transmission between two ports
 *
 * @author  Fromm
 * @date    01.12.2019
 *
 *****************************************************************************/

#ifndef CPARSER_H_
#define CPARSER_H_

#include "global.h"
#include "CPort.h"
#include "CPortFactory.h"
#include "CEH.h"

/**
 * @class CGateway
 * @brief Gateway for forwarding data between two communication ports
 *
 * The CGateway class connects two CPort instances and allows data
 * transmission from port A to port B.
 */
class CGateway
{
private:
    CPort* m_portA; /**< Pointer to source port */
    CPort* m_portB; /**< Pointer to destination port */

public:
    /**
     * @brief Constructor using explicit port objects
     *
     * Creates a gateway using already instantiated port objects.
     *
     * @param portA Reference to the source port
     * @param portB Reference to the destination port
     */
    CGateway(CPort& portA, CPort& portB);

    /**
     * @brief Constructor using port factory types
     *
     * Creates ports using the default port factory configuration.
     *
     * @param portA Type of source port to be created
     * @param portB Type of destination port to be created
     */
    CGateway(CPortFactory::port_t portA, CPortFactory::port_t portB);

    /**
     * @brief Transmit data from port A to port B
     *
     * Reads data from port A and forwards it to port B.
     *
     * @return RC_SUCCESS on successful transmission
     *         Error code otherwise
     */
    RC_t transmitFromAToB();

    /**
     * @brief Destructor
     *
     * Releases allocated resources.
     */
    virtual ~CGateway();
};

#endif /* CPARSER_H_ */
