/**
 * @file Enrollment.h
 * @brief Declaration of the Enrollment class.
 *
 * This header defines the Enrollment class, which represents
 * the association between a course and a semester, including
 * the grade obtained.
 *
 * @date 16-Jan-2026
 * @author agraw
 */

#ifndef ENROLLMENT_H_
#define ENROLLMENT_H_

#include<iostream>
#include "Course.h"

/**
 * @class Enrollment
 * @brief Represents a student's enrollment in a course.
 *
 * The Enrollment class links a Course with a specific
 * academic semester and stores the corresponding grade.
 */
class Enrollment {
private:
	/**
	 * @brief Semester in which the course is taken.
	 */
	std::string m_semester;

	/**
	 * @brief Pointer to the enrolled course.
	 */
	const Course* m_course;

	/**
	 * @brief Grade achieved in the course.
	 */
	float m_grade;

public:
	/**
	 * @brief Constructs an Enrollment object.
	 *
	 * @param semester Academic semester.
	 * @param course Course in which the enrollment is made.
	 * @param grade Grade obtained in the course.
	 */
	Enrollment(const std::string &semester, const Course &course,
			const float grade);

	/**
	 * @brief Sets the grade for the enrollment.
	 *
	 * @param grade New grade value.
	 */
	void setGrade(float const &grade);

	/**
	 * @brief Gets the grade of the enrollment.
	 *
	 * @return Grade as a float.
	 */
	float getGrade() const ;

	/**
	 * @brief Gets the enrolled course.
	 *
	 * @return Pointer to the associated Course.
	 */
	const  Course* getCourse() const ;

	/**
	 * @brief Gets the semester of the enrollment.
	 *
	 * @return Semester as a string.
	 */
	const  std::string getSemester() const ;

	/**
	 * @brief Writes enrollment information to an output stream.
	 *
	 * @param out Output stream to write to.
	 */
	void write(std::ostream& out) const;
};

#endif /* ENROLLMENT_H_ */
