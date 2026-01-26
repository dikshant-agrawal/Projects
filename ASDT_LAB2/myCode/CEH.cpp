/*
 * CEH.cpp
 *
 *  Created on: 19-Jan-2026
 *      Author: agraw
 */

#include "CEH.h"
#include <iostream>

using namespace std;

void CEH::CEH_report(CEH_EC errorCodes)
{

	switch(errorCodes){
	case CEH_NULL_POINTER:
		cerr << "Error : NULL Pointer passed" << endl;
		break;
	case CEH_UART_PORT_EXHAUSTED:
		cerr << "Error : UART Port limit exhausted" << endl;
		break;
	case CEH_CAN_PORT_EXHAUSTED:
		cerr << "Error : CAN Port limit exhausted" << endl;
		break;
	}

	std::terminate();


}
