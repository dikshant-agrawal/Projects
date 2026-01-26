/*
 * BlockCourse.cpp
 *
 *  Created on: 16-Jan-2026
 *      Author: agraw
 */

#include "BlockCourse.h"


BlockCourse::BlockCourse(unsigned int courseKey,
                         const std::string &title,
                         const std::string &major,
                         float credits,
                         const boost::gregorian::date &startDate,
                         const boost::gregorian::date &endDate,
                         const boost::posix_time::time_duration &startTime,
                         const boost::posix_time::time_duration &endTime)
    : Course(courseKey, title, major, credits),
      m_startDate(startDate),
      m_endDate(endDate),
      m_startTime(startTime),
      m_endTime(endTime) {}

void BlockCourse::write(std::ostream& out) const {
    out << 'B' << ';';
    Course::write(out);
    out << ';'
        << formatDateDMY(m_startDate) << ';'
        << formatDateDMY(m_endDate) << ';'
        << formatTimeHM(m_startTime) << ';'
        << formatTimeHM(m_endTime)
        << '\n';
}


std::string BlockCourse::formatDateDMY(const boost::gregorian::date& d)const
{
    std::ostringstream oss;
    oss.imbue(std::locale(
        std::locale::classic(),
        new boost::gregorian::date_facet("%d.%m.%Y")
    ));
    oss << d;
    return oss.str();
}


std::string BlockCourse::formatTimeHM(
		const boost::posix_time::time_duration& t)const
{
    std::ostringstream oss;

    oss << std::setw(2) << std::setfill('0') << t.hours()
        << ":"
        << std::setw(2) << std::setfill('0') << t.minutes();

    return oss.str();
}

