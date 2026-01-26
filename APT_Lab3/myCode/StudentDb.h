/**
 * @file StudentDb.h
 * @brief Declaration of the StudentDb class.
 *
 * This header defines the StudentDb class, which manages
 * collections of students, courses, and enrollments.
 * It provides functionality to add, search, update,
 * persist, and list academic data.
 *
 * @date 16-Jan-2026
 * @author agraw
 */

#ifndef STUDENTDB_H_
#define STUDENTDB_H_

#include"Student.h"
#include"Course.h"
#include "BlockCourse.h"
#include "WeeklyCourse.h"

#include<map>
#include "boost/date_time/gregorian/gregorian.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"

/**
 * @class StudentDb
 * @brief Manages students, courses, and enrollments.
 *
 * The StudentDb class acts as a central repository for
 * student records and course definitions. It supports
 * adding different course types, enrolling students,
 * searching records, and serialization.
 */
class StudentDb {
private:
	/**
	 * @brief Map of martikel numbers to students.
	 */
	std::map<int, Student> m_students;

	/**
	 * @brief Map of course keys to course objects.
	 *
	 * Courses are stored as unique pointers to allow
	 * polymorphic behavior.
	 */
	std::map<int, std::unique_ptr<const Course>> m_courses;

public:
	/**
	 * @brief Constructs an empty StudentDb.
	 */
	StudentDb();

	/**
	 * @brief Adds a new student to the database.
	 *
	 * @param firstName First name of the student.
	 * @param lastName Last name of the student.
	 * @param dateOfBirth Date of birth as a string.
	 * @param street Street name of the address.
	 * @param city City name of the address.
	 * @param postalCode Postal code.
	 * @param additionalInfo Additional address information.
	 *
	 * @return Generated martikel number of the student.
	 */
	unsigned int addStudent(const std::string &firstName,
			const std::string &lastName,
			const std::string &dateOfBirth,
			const std::string &street,
			const std::string &city,
			const unsigned short &postalCode,
			const std::string &additionalInfo);

	/**
	 * @brief Adds a block course to the database.
	 *
	 * @param courseKey Unique identifier for the course.
	 * @param title Title of the course.
	 * @param major Major of the course.
	 * @param credits Credit points.
	 * @param startDate Start date of the block course.
	 * @param endDate End date of the block course.
	 * @param startTime Daily start time.
	 * @param endTime Daily end time.
	 */
	void addBlockCourse(
	    const unsigned int& courseKey,
	    const std::string& title,
	    const std::string& major,
	    const float& credits,
	    const boost::gregorian::date& startDate,
	    const boost::gregorian::date& endDate,
	    const boost::posix_time::time_duration& startTime,
	    const boost::posix_time::time_duration& endTime);

	/**
	 * @brief Adds a weekly course to the database.
	 *
	 * @param courseKey Unique identifier for the course.
	 * @param title Title of the course.
	 * @param major Major of the course.
	 * @param credits Credit points.
	 * @param dayOfWeek Day of the week the course is held.
	 * @param startTime Start time of the course.
	 * @param endTime End time of the course.
	 */
	void addWeeklyCourse(
	    const unsigned int& courseKey,
	    const std::string& title,
	    const std::string& major,
	    const float& credits,
	    const boost::date_time::weekdays& dayOfWeek,
	    const boost::posix_time::time_duration& startTime,
	    const boost::posix_time::time_duration& endTime);

	/**
	 * @brief Enrolls a student in a course.
	 *
	 * @param martikelNumber Martikel number of the student.
	 * @param courseKey Key of the course.
	 * @param semester Semester of enrollment.
	 * @param grade Initial grade.
	 *
	 * @return True if enrollment was successful, false otherwise.
	 */
	bool addEnrollment(const unsigned int &martikelNumber,
			const unsigned int &courseKey,
			const std::string &semester,
			const float &grade);

	/**
	 * @brief Searches for a student by martikel number.
	 *
	 * @param martikelNumber Martikel number to search for.
	 * @return Pointer to the student if found, otherwise nullptr.
	 */
	Student* searchMartikel(const unsigned int &martikelNumber);

	/**
	 * @brief Searches for a course by course key.
	 *
	 * @param courseKey Course key to search for.
	 * @return Pointer to the course if found, otherwise nullptr.
	 */
	const Course* searchCourse(const unsigned int &courseKey) const;

	std::vector<const Student*> searchStudent(const std::string& input)
			const;

	/**
	 * @brief Updates the address of a student.
	 *
	 * @param martikelNumber Martikel number of the student.
	 * @param street New street name.
	 * @param city New city name.
	 * @param postalCode New postal code.
	 * @param additionalInfo New additional address information.
	 */
	void updateAddress(const unsigned int &martikelNumber,
			const std::string &street,
			const std::string &city,
			const unsigned short &postalCode,
			const std::string &additionalInfo);

	/**
	 * @brief Return all courses in the database.
	 */
	const std::map<int, std::unique_ptr<const Course>>& getCourses() const;

	/**
	 * @brief Writes the database contents to an output stream.
	 *
	 * @param out Output stream to write to.
	 */
	void write(std::ostream& out) const;

	/**
	 * @brief Reads the database contents from an input stream.
	 *
	 * @param in Input stream to read from.
	 */
	void read(std::istream& in);
};

#endif /* STUDENTDB_H_ */
