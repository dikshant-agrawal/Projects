/**
 * @file WeeklyCourse.h
 * @brief Declaration of the WeeklyCourse class.
 *
 * This header defines the WeeklyCourse class, which represents
 * a course held weekly on a specific day with defined start
 * and end times.
 *
 * @date 16-Jan-2026
 * @author agraw
 */

#ifndef WEEKLYCOURSE_H_
#define WEEKLYCOURSE_H_

#include "Course.h"

#include "boost/date_time/posix_time/posix_time.hpp"
#include "boost/date_time/gregorian/gregorian.hpp"

/**
 * @class WeeklyCourse
 * @brief Represents a course scheduled on a weekly basis.
 *
 * WeeklyCourse is a specialization of Course that occurs
 * once per week on a fixed weekday with specified start
 * and end times.
 */
class WeeklyCourse : public Course {

private:
	/**
	 * @brief Day of the week on which the course is held.
	 */
	boost::date_time::weekdays m_dayOfWeek;

	/**
	 * @brief Start time of the weekly course.
	 */
	boost::posix_time::time_duration m_startTime;

	/**
	 * @brief End time of the weekly course.
	 */
	boost::posix_time::time_duration m_endTime;

	/**
	 * @brief Formats a time in hour-minute format.
	 *
	 * @param t Time duration to be formatted.
	 * @return Formatted time string.
	 */
	std::string formatTimeHM(
			const boost::posix_time::time_duration& t) const;

public:
	/**
	 * @brief Constructs a WeeklyCourse object.
	 *
	 * @param courseKey Unique identifier for the course.
	 * @param title Title of the course.
	 * @param major Major of the course.
	 * @param credits Credit points.
	 * @param day Day of the week the course is held.
	 * @param start Start time of the course.
	 * @param end End time of the course.
	 */
    WeeklyCourse(const unsigned int courseKey,
                 const std::string &title,
                 const std::string &major,
                 const float credits,
                 boost::date_time::weekdays day,
                 const boost::posix_time::time_duration &start,
                 const boost::posix_time::time_duration &end);

    /**
     * @brief Writes course information to an output stream.
     *
     * Overrides the base class implementation to include
     * weekly scheduling details.
     *
     * @param out Output stream to write to.
     */
    void write(std::ostream& out) const override;
};

#endif /* WEEKLYCOURSE_H_ */
