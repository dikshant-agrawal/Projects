/*
 * Address.cpp
 *
 *  Created on: 16-Jan-2026
 *      Author: agraw
 */

#include "Address.h"

Address::Address(const std::string &street,
		const std::string &cityName,
		const std::string &additionalInfo,
		const unsigned short postalCode) :
		m_street(street),
		m_cityName(cityName),
		m_additionalInfo(additionalInfo),
		m_postalCode(postalCode) {
}

const std::string Address::getStreet() const{
	return m_street;
}

const std::string Address::getCityName() const{
	return m_cityName;
}

const std::string Address::getAdditionalInfo() const{
	return m_additionalInfo;
}

const unsigned short Address::getPostalCode() const{
	return m_postalCode;
}
