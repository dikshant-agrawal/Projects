/*
 * SimpleUI.cpp
 *
 *  Created on: 16-Jan-2026
 *      Author: agraw
 */

#include "SimpleUI.h"
#include<iostream>
#include <fstream>


using namespace std;

SimpleUI::SimpleUI(StudentDb &db) : m_db(&db) {
    printStatements[0] = "Exit";
    printStatements[1] = "Add new Course";
    printStatements[2] = "List courses";
    printStatements[3] = "Add new student";
    printStatements[4] = "Add enrollment";
    printStatements[5] = "Print student";
    printStatements[6] = "Search student";
    printStatements[7] = "Update student";
    printStatements[8] = "Save DB to file";
    printStatements[9] = "Load DB from file";
    printStatements[10] = "Student from Server";
}

void SimpleUI::run() {

	for(int i = 0; i < elements; i++){
		cout << "[" << i << "] " << printStatements[i] << endl;
	}

	int x;

	cout << "Enter your response: ";
	cin >> x;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


	if (x >= 0 && x < elements) {

		switch(x){

			case 0:
				return;

			case 1:
				addCourse();
				break;

			case 2:
				listCourses();
				break;

			case 3:
				addStudent();
				break;

			case 4:
				addEnrollment();
				break;

			case 5:
				printStudent();
				break;

			case 6:
				searchStudent();
				break;

			case 7:
				updateStudent();
				break;
			case 8:
				saveDb();
				break;
			case 9:
				loadDb();
				break;
			case 10:
				loadFromServer();
				break;
		}
	}

	else{
		cout << "Incorrect Input : Try again" << endl;
		return;
	}

}

void SimpleUI::addCourse() {

	string input;
	unsigned int courseKey;
	string title;
	string major;
	float credits;
	int courseType;
	string startDate;
	string startTime;
	string endDate;
	string endTime;
	int weekdayInput;

	cout<< "[Course] Choose Course Type: " << endl;
	cout << "[0] Block Course: " << endl;
	cout << "[1] Weekly Course: " << endl;

	while(true){
		getline(cin, input);

		try {
			courseType = std::stoi(input);
			break;
		}
		catch (const std::invalid_argument&) {
			cerr << "Invalid input. Please enter a number.\n";
		}
	}


	cout<< "[Course] Enter the Course Key: ";

	while(true){
		getline(cin, input);

		try {
			courseKey = std::stoi(input);
			break;
		}
		catch (const std::invalid_argument&) {
			cerr << "Invalid input. Please enter a number.\n";
		}
	}

	cout<< "[Course] Enter the Title: ";
	getline(cin,title);

	cout<< "[Course] Enter the Major: ";
	getline(cin,major);

	cout<< "[Course] Enter the Credit Points: ";

	while(true){
		getline(cin, input);

		try {
			credits = stof(input);
			break;
		}
		catch (const std::invalid_argument&) {
			cerr << "Invalid input. Please enter a number.\n";
		}
	}

	if(courseType == 0){

		cout << "[Course] Enter the Start Date [YYYY-MM-DD]: ";
		getline(cin, startDate);

		cout << "[Course] Enter the End Date [YYYY-MM-DD]: ";
		getline(cin, endDate);

		cout << "[Course] Enter the Start Time (HH:MM):: ";
		getline(cin, startTime);

		cout << "[Course] Enter the End Time [HH:MM]: ";
		getline(cin, endTime);

	    boost::gregorian::date l_startDate  =
	    		boost::gregorian::from_simple_string(startDate);

	    boost::gregorian::date l_endDate  =
	    		boost::gregorian::from_simple_string(endDate);

		boost::posix_time::time_duration l_startTime =
		    boost::posix_time::duration_from_string(startTime);

		boost::posix_time::time_duration l_endTime =
		    boost::posix_time::duration_from_string(endTime);

		m_db->addBlockCourse(courseKey, title, major, credits,
				l_startDate, l_endDate, l_startTime, l_endTime);


	}

	else if(courseType == 1){


		cout << "[0] Sunday" << endl;
		cout << "[1] Monday" << endl;
		cout << "[2] Tuesday" << endl;
		cout << "[3] Wednesday" << endl;
		cout << "[4] Thursday" << endl;
		cout << "[5] Friday" << endl;
		cout << "[6] Saturday" << endl;

		 cout << "[Course] Enter the Day of Week by Idx: ";
		 while(true){
		 		getline(cin, input);

		 		try {
		 			weekdayInput = stoi(input);
		 			break;
		 		}
		 		catch (const std::invalid_argument&) {
		 			cerr << "Invalid input. Please enter a number.\n";
		 		}
		 	}


		 if (weekdayInput < 0 || weekdayInput > 6) {
		     std::cout << "Invalid weekday\n";
		     return;
		 }

		 boost::date_time::weekdays weekday =
		     static_cast<boost::date_time::weekdays>(weekdayInput);

		cout << "[Course] Enter the Start Time [HH:MM]: ";
		getline(cin, startTime);

		cout << "[Course] Enter the End Time [HH:MM]: ";
		getline(cin, endTime);

		boost::posix_time::time_duration l_startTime =
		    boost::posix_time::duration_from_string(startTime);

		boost::posix_time::time_duration l_endTime =
		    boost::posix_time::duration_from_string(endTime);


		m_db->addWeeklyCourse(courseKey, title, major, credits,
				weekday, l_startTime , l_endTime);

	}

	else{
		cerr << "Invalid input. Please enter correct input.\n";
	}


}




void SimpleUI::addStudent() {

	string firstName;
	string lastName;
	string dateOfBirth;
	string street;
	string postalCode;
	string city;
	string additionalInfo;
	unsigned int martikelNummer;
	unsigned short l_postalCode;

	cout<< "[Student] Enter the First Name: ";
	getline(cin, firstName);

	cout << "[Student] Enter the Last Name: ";
	getline(cin, lastName);

	cout << "[Student] Enter the Date of Birth [YYYY-MM-DD]: ";
	getline(cin, dateOfBirth);

	cout << "[Address] Enter the Name of Street: ";
	getline(cin, street);

	cout << "[Address] Enter the Postal Code: ";

	while(true){
		getline(cin, postalCode);

		try {
			l_postalCode =
					static_cast<unsigned short>(std::stoul(postalCode));
			break;
		}
		catch (const std::invalid_argument&) {
			cerr << "Invalid input. Please enter a number.\n";
		}
	}

	cout << "[Address] Enter the Name of City: ";
	getline(cin, city);

	cout << "[Address] Enter the any Additional Info: ";
	getline(cin, additionalInfo);

	martikelNummer = m_db->addStudent(firstName, lastName, dateOfBirth,
			street, city, l_postalCode, additionalInfo);

	cout << "Martikel Number: " << martikelNummer <<endl;

}

void SimpleUI::addEnrollment() {

	string input;
	unsigned int martikelNumber;
	unsigned int courseKey;
	string semester;
	float grade;

	cout<< "[Enrollment] Enter the Martikel Number: ";

	while(true){
		getline(cin, input);

		try {
			martikelNumber = stoi(input);
			break;
		}
		catch (const std::invalid_argument&) {
			cerr << "Invalid input. Please enter a number.\n";
		}
	}


	cout<< "[Enrollment] Enter the Course Key: ";

	while(true){
		getline(cin, input);

		try {
			courseKey = stoi(input);
			break;
		}
		catch (const std::invalid_argument&) {
			cerr << "Invalid input. Please enter a number.\n";
		}
	}

	cout<< "[Enrollment] Enter the Semester: ";
	getline(cin,semester);

	cout<< "[Enrollment] Enter the Grade: ";
	while(true){
		getline(cin, input);

		try {
			grade = stof(input);
			break;
		}
		catch (const std::invalid_argument&) {
			cerr << "Invalid input. Please enter a number.\n";
		}
	}


	bool result = m_db->addEnrollment(martikelNumber, courseKey,
			semester, grade);
	if(result != true){
		cerr << "[WARNING] Enrollment already exists" << endl;
	}
}

void SimpleUI::printEnrollment(Student &student) {

    const auto& enrollments = student.getEnrollments();

    if (enrollments.empty()) {
        std::cout << "Enrollment : None\n";
        return;
    }

    for (size_t i = 0; i < enrollments.size(); ++i) {
        const Enrollment& e = enrollments[i];

        std::cout << "Enrollment [" << i << "] :"
                  << e.getCourse()->getTitle()
                  << " (" << e.getSemester() << ")";

        if (e.getGrade() > 0) {
            std::cout << " Grade: " << e.getGrade();
        } else {
            std::cout << " Grade: not graded";
        }

        cout << endl;
    }

}


void SimpleUI::printStudent() {
	unsigned int martikelNumber;
	string input;

	cout<< "[Print Student] Enter the Martikel Number: ";
	getline(cin, input);
	try {
		martikelNumber = stoi(input);
	}
	catch (const std::invalid_argument&) {
		cerr << "Invalid input. Please enter a number.\n";
	}

	Student* student = m_db->searchMartikel(martikelNumber);

	if(student == nullptr){
		cerr << "[ERROR] Student Not Found" << endl;
		return;
	}

	cout << "First Name: " <<
			student->getFirstName() << endl;

	cout << "Last Name: " <<
			student->getLastName() << endl;

	cout << "Date of Birth: " <<
			student->getDateOfBirth()<< endl;

	cout << "Name of Street: "<<
			student->getAddress().getStreet() << endl;

	cout << "Postal Code: "<<
			student->getAddress().getPostalCode() << endl;

	cout << "Name of City: "<<
			student->getAddress().getCityName() << endl;

	cout << "Additional Info: "<<
			student->getAddress().getAdditionalInfo() << endl;

	printEnrollment(*student);

}

void SimpleUI::searchStudent() {
	string input;
	cout<< "[Search Student] Enter the Search String: ";
		getline(cin, input);

	for (const auto* s : m_db->searchStudent(input)) {
	    cout <<"Martikel Number: " <<s->getMartikelNumber() << endl;
	    cout <<"Last Name: " <<s->getLastName() << endl;
		cout <<"First Name: " <<s->getFirstName() << endl;
		cout<< endl;
	}
}

void SimpleUI::updateStudent() {
	string input;
	string street;
	string city;
	string additionalInfo;
	int elements = 8;

	unsigned int operation;
	float grade;
	int idx;
	unsigned short postalCode;
	unsigned int martikelNumber;
	int x;

	cout<< "[Update Student] Enter the Martikel Number: ";
	getline(cin, input);
	try {
		martikelNumber = stoi(input);
	}
	catch (const std::invalid_argument&) {
		cerr << "Invalid input. Please enter a number.\n";
	}

	Student* student = m_db->searchMartikel(martikelNumber);

	if(student == nullptr){
		cerr << "[ERROR] Student Not Found" << endl;
		return;
	}

	while(true){

		cout << "[0] Exit: " << endl;

		cout << "[1] First Name: " <<
				student->getFirstName() << endl;

		cout << "[2] Last Name: " <<
				student->getLastName() << endl;

		cout << "[3] Date of Birth [YYYY-MM-DD]: " <<
				student->getDateOfBirth()<< endl;

		street = student->getAddress().getStreet();
		cout << "[4] Name of Street: "<< street << endl;

		postalCode = student->getAddress().getPostalCode();
		cout << "[5] Postal Code: "<< postalCode << endl;

		city = student->getAddress().getCityName();
		cout << "[6] Name of City: "<< city << endl;

		additionalInfo = student->getAddress().getAdditionalInfo();
		cout << "[7] Additional Info: "<< additionalInfo << endl;

		cout << "[8] Enrollments: " << endl;
		printEnrollment(*student);

		cout << "Enter your response: ";
		cin >> x;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (x < 0 || x > elements) {
            cout << "Incorrect Input : Try again\n";
            continue;
        }

		switch(x){

			case 0:
				return;

			case 1:
				cout << "[Update Student] Enter the First Name: "<<endl;
				getline(cin, input);
				student->setFirstName(input);
				cout << "[SUCCESS] First Name: "<<
						student->getFirstName() << endl;
				break;

			case 2:
				cout << "[Update Student] Enter the Last Name: "<<endl;
				getline(cin, input);
				student->setLastName(input);
				cout << "[SUCCESS] Last Name: "<<
						student->getLastName() << endl;
				break;

			case 3:
				cout <<
				"[Update Student] Enter the Date of Birth [YYYY-MM-DD]:"
				<<endl;
				getline(cin, input);
				student->setDateOfBirth(input);
				cout << "[SUCCESS] Date of Birth: "<<
						student->getDateOfBirth() << endl;
				break;

			case 4:
				cout << "[Update Student] Enter the Name of Street: "<<endl;
				getline(cin, street);
			    m_db->updateAddress(martikelNumber, street, city,
			    		postalCode, additionalInfo);
				cout << "[SUCCESS] Address Updated: "<<
						student->getAddress().getStreet() << endl;
				break;

			case 5:
				cout << "[Update Student] Enter the Postal Code: "<<endl;
				getline(cin, input);
				postalCode = static_cast<unsigned short>(std::stoul(input));
			    m_db->updateAddress(martikelNumber, street, city,
			    		postalCode, additionalInfo);
				cout << "[SUCCESS] Address Updated: "<<
						student->getAddress().getPostalCode() << endl;
				break;

			case 6:
				cout << "[Update Student] Enter the Name of City: "<<endl;
				getline(cin, city);
			    m_db->updateAddress(martikelNumber, street, city,
			    		postalCode, additionalInfo);
				cout << "[SUCCESS] Address Updated: "<<
						student->getAddress().getCityName() << endl;
				break;

			case 7:
				cout << "[Update Student] Enter the Additional Info:"<<endl;
				getline(cin, additionalInfo);
			    m_db->updateAddress(martikelNumber, street, city,
			    		postalCode, additionalInfo);
				cout << "[SUCCESS] Address Updated: "<<
						student->getAddress().getAdditionalInfo() << endl;
				break;

			case 8:
				cout <<"[Update Student] Enter the Enrollment Index:"<<endl;
				getline(cin, input);
				try {
					idx = stoi(input);
				}
				catch (const std::invalid_argument&) {
					cerr << "Invalid input. Please enter a number.\n";
					break;
				}

				auto& enrollments = student->updateEnrollment();

			    if (idx < 0 || idx >= static_cast<int>(enrollments.size())){
			        cerr << "[ERROR] Invalid enrollment index" << endl;
			        break;
			    }

				cout <<"[0] Remove Enrollment:"<<endl;
				cout <<"[1] Enter Mark:"<<endl;
				cout <<"[Update Student] Enter the Operation Index:"<<endl;
				getline(cin, input);
				try {
					operation = stoi(input);
				}
				catch (const std::invalid_argument&) {
					cerr << "Invalid input. Please enter a number.\n";
					break;
				}

				// REMOVE
				if(operation == 0){
					enrollments.erase(enrollments.begin() + idx);

				}

				// GRADE
				else if(operation == 1){
					cout<< "Enter the Mark: " <<endl;
					getline(cin, input);
					try {
						grade = stof(input);
					}
					catch (const std::invalid_argument&) {
						cerr << "Invalid input. Please enter a number.\n";
						break;
					}
					enrollments.at(idx).setGrade(grade);

				}


				else{
					cout << "Invalid Input selected" << endl;
					break;
				}


				cout << "[SUCCESS] Enrollment Updated: "<< endl;
				printEnrollment(*student);
				break;
		}
	}
}


void SimpleUI::saveDb() {
    string filename;
    cout << "Filename: ";
    cin >> filename;

    std::ofstream file(filename);
    m_db->write(file);
}

void SimpleUI::loadDb() {
    string filename;
    cout << "Filename: ";
    cin >> filename;

    std::ifstream file(filename);
    m_db->read(file);
}

void SimpleUI::listCourses() {

    const auto& courses = m_db->getCourses();

    if (courses.empty()) {
        cerr << "No Courses are available" << std::endl;
        return;
    }

    for (const auto& entry : courses) {
        const Course* course = entry.second.get();

            cout << "[Course] Key: "     << course->getCourseKey() << endl;
            cout << "[Course] Title: "   << course->getTitle()     << endl;
            cout << "[Course] Major: "   << course->getMajor()     << endl;
            cout << "[Course] Credits: " << course->getCredits()   << endl;
            cout << endl;
        }

}

void SimpleUI::loadFromServer() {
	string input;
	int number;
	cout << "Number of students to add: " << endl;
	while(true){
		getline(cin, input);
		try {
			number = stoi(input);
			break;
		}
		catch (const std::invalid_argument&) {
			cerr << "Invalid input. Please enter a number.\n";
		}
	}
	for(int i = 0; i < number; i++){
		fetchStudent();
	}
}

void SimpleUI::fetchStudent() {
	try {
		boost::asio::io_context io;
		boost::asio::ip::tcp::resolver resolver(io);

		auto endpoints = resolver.resolve(
			"www.hhs.users.h-da.cloud", "4242");

		boost::asio::ip::tcp::socket socket(io);
		boost::asio::connect(socket, endpoints);

		string generateCmd = "generate\n";
		boost::asio::write(socket, boost::asio::buffer(generateCmd));


		boost::asio::streambuf buffer;
		boost::system::error_code ec;

		while (boost::asio::read(
				   socket,
				   buffer,
				   boost::asio::transfer_at_least(1),
				   ec)) {
		}

		if (ec != boost::asio::error::eof) {
			throw boost::system::system_error(ec);
		}

		istream is(&buffer);
		string line;
		string jsonText;

		while (std::getline(is, line)) {
			if (!line.empty() && line.front() == '{') {
				jsonText = line;
				break;
			}
		}

		if (jsonText.empty()) {
			throw std::runtime_error("JSON data not received");
		}

		boost::json::value jv = boost::json::parse(jsonText.c_str());
		boost::json::object obj = jv.as_object();

		auto name     = obj["name"].as_object();
		auto location = obj["location"].as_object();
		auto dob      = obj["dateOfBirth"].as_object();


		string firstName = name["firstName"].as_string().c_str();
		string lastName  = name["lastName"].as_string().c_str();

		string street   = location["street"].as_string().c_str();
		string city     = location["city"].as_string().c_str();
		string postCode = location["postCode"].as_string().c_str();
		unsigned short l_postCode =
				static_cast<unsigned short>(stoi(postCode));


		int year  = static_cast<int>(dob["year"].as_int64()) + 1900;
		int month = static_cast<int>(dob["month"].as_int64()) + 1;
		int date   = static_cast<int>(dob["date"].as_int64());

		std::ostringstream oss;
		oss << year << "-"
		    << setw(2) << setfill('0') << month << "-"
		    << setw(2) << setfill('0') << date;

		string dobString = oss.str();
		string additionalInfo = "None";

		unsigned int martikelNumber =
				m_db->addStudent(firstName, lastName,dobString,street, city,
				l_postCode, additionalInfo);
		cout << "Martikel Number :" << martikelNumber <<endl;

	    }
	    catch (std::exception& e) {
	        std::cerr << "Fetch failed: " << e.what() << "\n";
	    }

	    cout << "Sucess" << endl;
}

