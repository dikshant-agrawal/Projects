/**
 * @file SimpleUI.h
 * @brief Declaration of the SimpleUI class.
 *
 * This header defines the SimpleUI class, which provides
 * a simple command-line user interface for interacting
 * with the student database.
 *
 * @date 16-Jan-2026
 * @author agraw
 */

#ifndef SIMPLEUI_H_
#define SIMPLEUI_H_

#include"StudentDb.h"


#include "boost/asio/ip/tcp.hpp"
#include "boost/json.hpp"
#include "boost/asio.hpp"


/**
 * @class SimpleUI
 * @brief Provides a simple user interface for the student database.
 *
 * The SimpleUI class encapsulates menu handling and user interaction
 * logic for managing courses, students, and enrollments stored
 * in the StudentDb.
 */
class SimpleUI {
private:
	/**
	 * @brief Pointer to the student database.
	 */
	StudentDb* m_db;

	/**
	 * @brief Number of menu elements supported by the UI.
	 */
	static const int elements = 11;

	/**
	 * @brief Array of menu print statements.
	 */
	const char* printStatements[elements];

public:
	/**
	 * @brief Constructs a SimpleUI object.
	 *
	 * @param db Reference to the student database.
	 */
	SimpleUI(StudentDb& db);

	/**
	 * @brief Starts the user interface event loop.
	 */
	void run();

	/**
	 * @brief Adds a new course to the database.
	 */
	void addCourse();

	/**
	 * @brief Lists all courses in the database.
	 */
	void listCourses();

	/**
	 * @brief Adds a new student to the database.
	 */
	void addStudent();

	/**
	 * @brief Adds an enrollment for a student.
	 */
	void addEnrollment();

	/**
	 * @brief Prints details of a specific student.
	 */
	void printStudent();

	/**
	 * @brief Searches for a student in the database.
	 */
	void searchStudent();

	/**
	 * @brief Updates student information.
	 */
	void updateStudent();

	/**
	 * @brief Prints enrollment details for a student.
	 *
	 * @param student Student whose enrollments are printed.
	 */
	void printEnrollment(Student &student);

	/**
	 * @brief Saves the database to persistent storage.
	 */
	void saveDb();

	/**
	 * @brief Loads the database from persistent storage.
	 */
	void loadDb();

	/**
	 * @brief Loads the students from server.
	 */
	void loadFromServer();

	/**
	 * @brief JSON Parser and create a student with fetched data
	 */
	void fetchStudent();

};

#endif /* SIMPLEUI_H_ */
