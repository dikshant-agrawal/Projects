/*
 * Student.cpp
 *
 *  Created on: 16-Jan-2026
 *      Author: agraw
 */

#include "Student.h"

using namespace std;

unsigned int Student::nextMartikelNumber = 100000;


Student::Student(const std::string &firstName,
		const std::string &lastName,
		const boost::gregorian::date& dateOfBirth,
		const Address &address):
		m_firstName(firstName),
		m_lastName(lastName),
		m_dateOfBirth(dateOfBirth),
		m_address(address)
{
	m_martikelNumber = nextMartikelNumber;
	nextMartikelNumber++;

}

const unsigned int Student::getMartikelNumber() const {
	return m_martikelNumber;
}

const boost::gregorian::date Student::getDateOfBirth() const{
	return m_dateOfBirth;
}

const std::string Student::getFirstName()const {
	return m_firstName;
}

const std::string Student::getLastName() const{
	return m_lastName;
}

const std::vector<Enrollment>& Student::getEnrollments()const {
	return m_enrollments;
}

const Address Student::getAddress() const {
	return m_address;
}

void Student::setFirstName(const std::string &firstName) {
	m_firstName = firstName;
}

void Student::setLastName(const std::string &lastName) {
	m_lastName = lastName;
}


void Student::setDateOfBirth(std::string &dateOfBirth) {
	m_dateOfBirth = boost::gregorian::from_simple_string(dateOfBirth);
}

void Student::setAddress(Address &address) {
	m_address = address;
}

void Student::addEnrollment(Enrollment &enrollment) {
	m_enrollments.push_back(enrollment);
}

std::vector<Enrollment>& Student::updateEnrollment() {
	return m_enrollments;
}

void Student::write(std::ostream& out) const {
    out << m_martikelNumber << ';'
        << m_lastName << ';'
        << m_firstName << ';'
        << formatDateDMY(m_dateOfBirth) << ';'
        << m_address.getStreet() << ';'
        << m_address.getPostalCode() << ';'
        << m_address.getCityName() << ';'
        << m_address.getAdditionalInfo()
        << '\n';
}



std::string Student::formatDateDMY(const boost::gregorian::date& d)const
{
    std::ostringstream oss;
    oss.imbue(std::locale(
        std::locale::classic(),
        new boost::gregorian::date_facet("%d.%m.%Y")
    ));
    oss << d;
    return oss.str();
}



