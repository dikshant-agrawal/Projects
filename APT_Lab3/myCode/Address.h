/**
 * @file Address.h
 * @brief Declaration of the Address class.
 *
 * This header defines the Address class, which encapsulates
 * basic address-related information such as street, city,
 * postal code, and optional additional details.
 *
 * @date 16-Jan-2026
 * @author agraw
 */

#ifndef ADDRESS_H_
#define ADDRESS_H_

#include<iostream>

/**
 * @class Address
 * @brief Represents a physical or mailing address.
 *
 * The Address class stores address details including street name,
 * city name, postal code, and optional additional information.
 * It provides read-only access to its members through getter methods.
 */
class Address {
private:
	/**
	 * @brief Street name of the address.
	 */
	std::string m_street;

	/**
	 * @brief City name of the address.
	 */
	std::string m_cityName;

	/**
	 * @brief Additional address information (e.g., apartment, landmark).
	 */
	std::string m_additionalInfo;

	/**
	 * @brief Postal code of the address.
	 */
	unsigned short m_postalCode;

public:
	/**
	 * @brief Constructs an Address object.
	 *
	 * @param street Street name of the address.
	 * @param cityName City name of the address.
	 * @param additionalInfo Additional address information.
	 * @param postalCode Postal code of the address.
	 */
	Address(const std::string &street,
			const std::string &cityName,
			const std::string &additionalInfo,
			const unsigned short postalCode);

	/**
	 * @brief Gets the street name.
	 *
	 * @return Street name as a string.
	 */
	const std::string getStreet() const;

	/**
	 * @brief Gets the city name.
	 *
	 * @return City name as a string.
	 */
	const std::string getCityName() const;

	/**
	 * @brief Gets the additional address information.
	 *
	 * @return Additional information as a string.
	 */
	const std::string getAdditionalInfo() const;

	/**
	 * @brief Gets the postal code.
	 *
	 * @return Postal code as an unsigned short.
	 */
	const unsigned short getPostalCode() const;
};

#endif /* ADDRESS_H_ */
