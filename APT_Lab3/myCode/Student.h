/**
 * @file Student.h
 * @brief Declaration of the Student class.
 *
 * This header defines the Student class, which represents
 * a student with personal information, address details,
 * and a list of course enrollments.
 *
 * @date 16-Jan-2026
 * @author agraw
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include"Address.h"
#include"Enrollment.h"
#include <vector>
#include <iostream>
#include "boost/date_time/gregorian/gregorian.hpp"

/**
 * @class Student
 * @brief Represents a student entity.
 *
 * The Student class stores identifying information,
 * personal details, address data, and enrollment records.
 * Each student is assigned a unique martikel number.
 */
class Student {
private:
	/**
	 * @brief Next available martikel number.
	 */
	static unsigned int nextMartikelNumber;

	/**
	 * @brief Unique martikel number of the student.
	 */
	unsigned int m_martikelNumber;

	/**
	 * @brief First name of the student.
	 */
	std::string m_firstName;

	/**
	 * @brief Last name of the student.
	 */
	std::string m_lastName;

	/**
	 * @brief Date of birth of the student.
	 */
	boost::gregorian::date m_dateOfBirth;

	/**
	 * @brief List of enrollments associated with the student.
	 */
	std::vector<Enrollment> m_enrollments;

	/**
	 * @brief Address of the student.
	 */
	Address m_address;

    /**
     * @brief Formats a date in day-month-year format.
     *
     * @param d Date to be formatted.
     * @return Formatted date string.
     */
    std::string formatDateDMY(const boost::gregorian::date& d) const;

public:
	/**
	 * @brief Constructs a Student object.
	 *
	 * @param firstName First name of the student.
	 * @param LastName Last name of the student.
	 * @param dateOfBirth Date of birth of the student.
	 * @param address Address of the student.
	 */
	Student(const std::string &firstName,
			const std::string &LastName,
			const boost::gregorian::date& dateOfBirth,
			const Address &address);

	/**
	 * @brief Gets the martikel number.
	 *
	 * @return Martikel number as an unsigned int.
	 */
	const unsigned int getMartikelNumber() const;

	/**
	 * @brief Gets the date of birth.
	 *
	 * @return Date of birth.
	 */
	const boost::gregorian::date getDateOfBirth() const;

	/**
	 * @brief Gets the first name.
	 *
	 * @return First name as a string.
	 */
	const std::string getFirstName() const;

	/**
	 * @brief Gets the last name.
	 *
	 * @return Last name as a string.
	 */
	const std::string getLastName() const;

	/**
	 * @brief Gets the list of enrollments.
	 *
	 * @return Vector of Enrollment objects.
	 */
	const std::vector<Enrollment>& getEnrollments() const;

	/**
	 * @brief Gets the address of the student.
	 *
	 * @return Address object.
	 */
	const Address getAddress() const;

	/**
	 * @brief Sets the first name.
	 *
	 * @param firstName New first name.
	 */
	void setFirstName(std::string const &firstName);

	/**
	 * @brief Sets the last name.
	 *
	 * @param lastName New last name.
	 */
	void setLastName(std::string const &lastName);

	/**
	 * @brief Sets the date of birth.
	 *
	 * @param dateOfBirth Date of birth as a string.
	 */
	void setDateOfBirth(std::string &dateOfBirth);

	/**
	 * @brief Sets the address.
	 *
	 * @param address New address.
	 */
	void setAddress(Address &address);

	/**
	 * @brief Adds an enrollment to the student.
	 *
	 * @param enrollment Enrollment to be added.
	 */
	void addEnrollment(Enrollment &enrollment);

	/**
	 * @brief Provides access to enrollments for update.
	 *
	 * @return Reference to the enrollment vector.
	 */
	std::vector<Enrollment>& updateEnrollment();

	/**
	 * @brief Writes student information to an output stream.
	 *
	 * @param out Output stream to write to.
	 */
	void write(std::ostream& out) const;
};

#endif /* STUDENT_H_ */
