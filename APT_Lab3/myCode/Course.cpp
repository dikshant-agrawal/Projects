/*
 * Course.cpp
 *
 *  Created on: 16-Jan-2026
 *      Author: agraw
 */

#include "Course.h"

std::map<unsigned char, std::string> Course::majorById = {
    {'E', "Embedded"},
    {'A', "Automation"},
    {'C', "Communication"},
    {'P', "Power"}
};

Course::Course(const unsigned int courseKey,
		const std::string &title,
		const std::string &major,
		const float credits) :
				m_courseKey(courseKey),
				m_title(title),
				m_creditPoints(credits) {

    for (const auto& me : majorById) {
        if (me.second == major) {
            m_major = me.first;
            return;
        }
    }

    throw std::invalid_argument("Invalid major");

}

const std::string Course::getMajor() const{
	return majorById.at(m_major);
}

const float Course::getCredits() const{
	return m_creditPoints;
}

const unsigned int Course::getCourseKey() const {
	return m_courseKey;
}

const std::string Course::getTitle() const {
	return m_title;
}

void Course::write(std::ostream& out) const {
    out << m_courseKey << ';'
        << m_title << ';'
        << getMajor() << ';'
        << m_creditPoints;
}

