/*
 * Enrollment.cpp
 *
 *  Created on: 16-Jan-2026
 *      Author: agraw
 */

#include "Enrollment.h"


Enrollment::Enrollment(const std::string &semester, const Course &course,
		const float grade) :
m_semester(semester), m_course(&course), m_grade(grade){}

void Enrollment::setGrade(float const &grade)  {
	m_grade = grade;
}

const  Course* Enrollment::getCourse() const  {
	return m_course;
}

float Enrollment::getGrade() const  {
	return m_grade;
}

const  std::string Enrollment::getSemester()const  {
	return m_semester;
}


void Enrollment::write(std::ostream& out) const {
    out << m_course->getCourseKey() << ';'
        << m_semester << ';'
        << m_grade;
}

