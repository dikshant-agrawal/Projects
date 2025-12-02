// Standard (system) header files
#include <iostream>
#include <cstdlib>
// Add more standard header files as required
// #include <string>

using namespace std;

// Add your project's header files here
// #include "CFraction.h"
#include "ModuloNDigit.h"
//#include "ModuloNCounter.h"

// Main program
int main ()
{
    // Create a modulo-5 counter
    ModuloNDigit digit(5);

    std::cout << "Initial value: " << digit.getValue() << std::endl;

    // Increment several times
    for (int i = 0; i < 7; ++i) {
        digit++;
        std::cout << "After increment: " << digit.getValue() << std::endl;
    }

    // Reset
    digit.resetCounter();
    std::cout << "After reset: " << digit.getValue() << std::endl;

    return 0;
}
