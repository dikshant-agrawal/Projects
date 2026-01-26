/*
 * WeeklyCourse.cpp
 *
 *  Created on: 16-Jan-2026
 *      Author: agraw
 */

#include "WeeklyCourse.h"


WeeklyCourse::WeeklyCourse(unsigned int courseKey,
                           const std::string &title,
                           const std::string &major,
                           float credits,
                           boost::date_time::weekdays day,
                           const boost::posix_time::time_duration &start,
                           const boost::posix_time::time_duration &end)
    : Course(courseKey, title, major, credits),
      m_dayOfWeek(day),
      m_startTime(start),
      m_endTime(end) {}

void WeeklyCourse::write(std::ostream& out) const {
    out << 'W' << ';';
    Course::write(out);
    out << ';'
        << static_cast<int>(m_dayOfWeek) << ';'
        << formatTimeHM(m_startTime) << ';'
        << formatTimeHM(m_endTime)
        << '\n';
}

std::string WeeklyCourse::formatTimeHM(
		const boost::posix_time::time_duration& t)const
{
    std::ostringstream oss;

    oss << std::setw(2) << std::setfill('0') << t.hours()
        << ":"
        << std::setw(2) << std::setfill('0') << t.minutes();

    return oss.str();
}

