// Jordan Bailey
// CIS 1202 101
// 7-21-24

#include <iostream>
#include <stdexcept>        // Header files
using namespace std;

// The -try- statement allows you to define a block of code to be tested for errors while it is being executed.
// The -catch- statement allows you to define a block of code to be executed, if an error occurs in the try block.
// The -throw- keyword throws an exception when a problem is detected, which lets us create a custom error.

// runtime_error - This class defines the type of objects thrown as exceptions to report errors that can only be detected during runtime.





class invalidCharacterException : public runtime_error {
public:
    invalidCharacterException() : runtime_error("invalidCharacterExcpeption") {}
};

class invalidRangeException : public runtime_error {
public:
    invalidRangeException() : runtime_error("invalidRangeExpection") {}
};

char character(char start, int offset) {
    // Check if start is a letter
    if (!(start >= 'A' && start <= 'Z') && !(start >= 'a' && start <= 'z')) {
        throw invalidCharacterException();
    }

    // Calculate the target character
    char target = start + offset;

    // Check if the target is a letter
    if (!(target >= 'A' && target <= 'Z') && !(target >= 'a' && target <= 'z')) {
        throw invalidRangeException();
    }

    return target;
}


// ====================================================================================================================

int main() {
    try {
        cout << "character('a', 1) => " << character('a', 1) << endl << endl;  // character('a', 1) should return 'b'
        cout << character('a', -1) << endl << endl;  // character('a', -1) should throw an invalidRangeExpection
    }
    catch (const invalidRangeException& e) {
        cerr << e.what() << endl << endl;
    }

    try {
        cout << "character('Z', -1) => " << character('Z', -1) << endl << endl;  // character('Z', -1) should return 'Y'
    }
    catch (const std::exception& e) {
        cerr << e.what() << endl << endl;
    }

    try {
        cout << "character('?', 5) => " << character('?', 5) << endl << endl;  // character('?', 5) should throw an invalidCharacterExcpeption
    }
    catch (const invalidCharacterException& e) {
        cerr << e.what() << endl << endl;
    }

    try {
        cout << "character('A', 32) => " << character('A', 32) << endl << endl;  // Do not allow upper- and lower-case transitions.  character('A', 32) should throw an exception, not return 'a'
    }
    catch (const invalidRangeException& e) {
        cerr << e.what() << endl << endl;
    }

    return 0;
}