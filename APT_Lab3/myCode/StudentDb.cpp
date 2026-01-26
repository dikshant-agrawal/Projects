/*
 * StudentDb.cpp
 *
 *  Created on: 16-Jan-2026
 *      Author: agraw
 */

#include "StudentDb.h"
#include <memory>

using namespace std;

StudentDb::StudentDb() {

}


unsigned int StudentDb::addStudent(const std::string &firstName,
		const std::string &lastName,
		const std::string &dateOfBirth,
		const std::string &street,
		const std::string &city,
		const unsigned short &postalCode,
		const std::string &additionalInfo) {

    Address address(street, city, additionalInfo, postalCode);

    boost::gregorian::date l_dateOfBirth  =
    		boost::gregorian::from_simple_string(dateOfBirth);


    Student student(firstName, lastName, l_dateOfBirth, address);

    unsigned int martikelNummer = student.getMartikelNumber();

    m_students.emplace(martikelNummer, student);

    return martikelNummer;


}

void StudentDb::addBlockCourse(
    const unsigned int& courseKey,
    const std::string& title,
    const std::string& major,
    const float& credits,
    const boost::gregorian::date& startDate,
    const boost::gregorian::date& endDate,
    const boost::posix_time::time_duration& startTime,
    const boost::posix_time::time_duration& endTime)
{
    try {
        m_courses.emplace(
            courseKey,
            std::unique_ptr<const Course>(
                new BlockCourse(
                    courseKey,
                    title,
                    major,
                    credits,
                    startDate,
                    endDate,
                    startTime,
                    endTime
                )
            )
        );
    }
    catch (const std::invalid_argument& err) {
        std::cerr << "[FAILED] Invalid Major, Try Again\n";
    }
}


void StudentDb::addWeeklyCourse(
    const unsigned int& courseKey,
    const std::string& title,
    const std::string& major,
    const float& credits,
    const boost::date_time::weekdays& dayOfWeek,
    const boost::posix_time::time_duration& startTime,
    const boost::posix_time::time_duration& endTime)
{
    try {
        m_courses.emplace(
            courseKey,
            std::unique_ptr<const Course>(
                new WeeklyCourse(
                    courseKey,
                    title,
                    major,
                    credits,
                    dayOfWeek,
                    startTime,
                    endTime
                )
            )
        );
    }
    catch (const std::invalid_argument& err) {
        std::cerr << "[FAILED] Invalid Major, Try Again\n";
    }
}


bool StudentDb::addEnrollment(const unsigned int &martikelNumber,
		const unsigned int &courseKey,
		const std::string &semester, const float &grade) {

	const Course* course = searchCourse(courseKey);
	Student* student = searchMartikel(martikelNumber);

	/*

	if(!course || !student){
		return false;
	}

	*/

    for (const auto& e : student->getEnrollments()) {
        if (e.getCourse()->getCourseKey() == courseKey &&
            e.getSemester() == semester) {
            return false;
        }
    }

    Enrollment enrollment(semester, *course, grade);
	student->addEnrollment(enrollment);

	return true;
}

const Course* StudentDb::searchCourse(const unsigned int &courseKey)const {

	auto me = m_courses.find(courseKey);

	    if (me != m_courses.end()) {
	        return me->second.get();
	    }

	    return nullptr;
}


Student* StudentDb::searchMartikel(const unsigned int &martikelNumber){

	auto me = m_students.find(martikelNumber);

	    if (me != m_students.end()) {
	        return &me->second;
	    }

	    return nullptr;
}

void StudentDb::updateAddress(const unsigned int &martikelNumber,
		const std::string &street, const std::string &city,
		const unsigned short &postalCode, const std::string &additionalInfo)
 {


    Student* student = searchMartikel(martikelNumber);
    if (!student) {
        return;
    }

    Address newAddress(street, city, additionalInfo, postalCode);

    student->setAddress(newAddress);

}

void StudentDb::write(std::ostream& out) const {

    // Courses
    out << m_courses.size() << '\n';
    for (const auto& courseMap : m_courses) {
    	courseMap.second->write(out);
    }

    // Students
    out << m_students.size() << '\n';
    for (const auto& studentMap : m_students) {
    	studentMap.second.write(out);
    }

    // Enrollments
    size_t count = 0;
    for (const auto& studentMap : m_students) {
        count += studentMap.second.getEnrollments().size();
    }

    out << count << '\n';
    for (const auto& studentMap : m_students) {
        for (const auto& enrollment : studentMap.second.getEnrollments()) {
            out << studentMap.second.getMartikelNumber() << ';';
            enrollment.write(out);
            out << '\n';
        }
    }
}

std::vector<const Student*> StudentDb::searchStudent(
		const std::string &input) const {

	std::vector<const Student*> result;

    for (const auto& pair : m_students) {
        const Student& student = pair.second;

        if (student.getFirstName().find(input) != std::string::npos ||
            student.getLastName().find(input)  != std::string::npos) {
            result.push_back(&student);
        }
    }

    return result;
}

const std::map<int, std::unique_ptr<const Course> >&
StudentDb::getCourses() const {
	return m_courses;
}

void StudentDb::read(std::istream& in) {

    m_students.clear();
    m_courses.clear();

    size_t courseCount;
    in >> courseCount;
    in.ignore();

    for (size_t i = 0; i < courseCount; ++i) {
        std::string line;
        std::getline(in, line);
    }

    size_t studentCount;
    in >> studentCount;
    in.ignore();

    for (size_t i = 0; i < studentCount; ++i) {
        std::string line;
        std::getline(in, line);

    }

    size_t enrollmentCount;
    in >> enrollmentCount;
    in.ignore();

    for (size_t i = 0; i < enrollmentCount; ++i) {
        std::string line;
        std::getline(in, line);
    }

}

