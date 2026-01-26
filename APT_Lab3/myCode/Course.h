/**
 * @file Course.h
 * @brief Declaration of the Course base class.
 *
 * This header defines the Course class, which represents
 * a generic academic course with identifying information,
 * credit points, and a major classification.
 *
 * @date 16-Jan-2026
 * @author agraw
 */

#ifndef COURSE_H_
#define COURSE_H_

#include <map>
#include <iostream>

/**
 * @class Course
 * @brief Abstract representation of an academic course.
 *
 * The Course class serves as a base class for different
 * types of courses. It stores common course attributes
 * and provides virtual methods for outputting course data.
 */
class Course {
private:
	/**
	 * @brief Mapping of major identifiers to major names.
	 */
	static std::map<unsigned char, std::string> majorById;

	/**
	 * @brief Unique key identifying the course.
	 */
	unsigned int m_courseKey;

	/**
	 * @brief Title of the course.
	 */
	std::string m_title;

	/**
	 * @brief Major identifier associated with the course.
	 */
	unsigned char m_major;

	/**
	 * @brief Credit points assigned to the course.
	 */
	float m_creditPoints;

public:
	/**
	 * @brief Constructs a Course object.
	 *
	 * @param courseKey Unique identifier for the course.
	 * @param title Title of the course.
	 * @param major Major name of the course.
	 * @param credits Credit points of the course.
	 */
	Course(const unsigned int courseKey,
			const std::string &title,
			const std::string &major,
			const float credits);

	/**
	 * @brief Gets the major name of the course.
	 *
	 * @return Major name as a string.
	 */
	const std::string getMajor() const;

	/**
	 * @brief Gets the credit points of the course.
	 *
	 * @return Credit points as a float.
	 */
	const float getCredits() const;

	/**
	 * @brief Gets the course key.
	 *
	 * @return Course key as an unsigned int.
	 */
	const unsigned int getCourseKey() const;

	/**
	 * @brief Gets the course title.
	 *
	 * @return Course title as a string.
	 */
	const std::string getTitle() const;

	/**
	 * @brief Writes course information to an output stream.
	 *
	 * This method can be overridden by derived classes
	 * to provide specialized output behavior.
	 *
	 * @param out Output stream to write to.
	 */
	virtual void write(std::ostream& out) const;

	/**
	 * @brief Virtual destructor for safe polymorphic deletion.
	 */
	virtual ~Course() = default;
};

#endif /* COURSE_H_ */
