/**
 * @file BlockCourse.h
 * @brief Declaration of the BlockCourse class.
 *
 * This header defines the BlockCourse class, which represents
 * a course conducted over a continuous block of dates with
 * specific start and end times.
 *
 * @date 16-Jan-2026
 * @author agraw
 */

#ifndef BLOCKCOURSE_H_
#define BLOCKCOURSE_H_

#include "Course.h"

#include "boost/date_time/gregorian/gregorian.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"

/**
 * @class BlockCourse
 * @brief Represents a course scheduled over a fixed date range.
 *
 * BlockCourse is a specialization of Course that is defined by
 * a start date, end date, and daily start and end times.
 * It overrides the write method to output block-course-specific
 * information.
 */
class BlockCourse : public Course {
private:
    /**
     * @brief Start date of the block course.
     */
    boost::gregorian::date m_startDate;

    /**
     * @brief End date of the block course.
     */
    boost::gregorian::date m_endDate;

    /**
     * @brief Daily start time of the block course.
     */
    boost::posix_time::time_duration m_startTime;

    /**
     * @brief Daily end time of the block course.
     */
    boost::posix_time::time_duration m_endTime;

    /**
     * @brief Formats a date in day-month-year format.
     *
     * @param d Date to be formatted.
     * @return Formatted date string.
     */
    std::string formatDateDMY(const boost::gregorian::date& d) const;

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
     * @brief Constructs a BlockCourse object.
     *
     * @param courseKey Unique identifier for the course.
     * @param title Title of the course.
     * @param major Major or field of study.
     * @param credits Credit value of the course.
     * @param startDate Start date of the block course.
     * @param endDate End date of the block course.
     * @param startTime Daily start time.
     * @param endTime Daily end time.
     */
    BlockCourse(const unsigned int courseKey,
                const std::string &title,
                const std::string &major,
                const float credits,
                const boost::gregorian::date &startDate,
                const boost::gregorian::date &endDate,
                const boost::posix_time::time_duration &startTime,
                const boost::posix_time::time_duration &endTime);

    /**
     * @brief Writes course information to an output stream.
     *
     * Overrides the base class implementation to include
     * block-course-specific scheduling details.
     *
     * @param out Output stream to write to.
     */
    void write(std::ostream& out) const override;
};

#endif /* BLOCKCOURSE_H_ */
