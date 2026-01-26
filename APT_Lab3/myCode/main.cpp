// Standard (system) header files
#include <iostream>
#include <cstdlib>
// Add more standard header files as required
// #include <string>

#include "StudentDb.h"
#include "SimpleUI.h"

using namespace std;


// Main program
int main ()
{
	StudentDb students;

	SimpleUI ui(students);

	while(1){
		ui.run();
	}

	return 0;
}
