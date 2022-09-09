// --------------------------------------------------------------- //
// Soobin Rho
// September 14, 2022
// COSC 226: C++
// Hw2: Objects, Types, and Values; Computation; Errors
//
// This is a simple calculator that accepts +, -, *, and /.
// To exit, type any non-numeric character.
//
// Example: 
//     Enter an expression: 2 * 8
//     16
//     Enter an expression: -40 - 40
//     0
// --------------------------------------------------------------- //

#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{

    // ----------------------------------------- //
    // Two possibilities for inputs:
    // 1. Valid inputs (e.g. -40 - 40)
    // 2. Exit code (Contains non-numeric value)
    // ----------------------------------------- //
    smatch matches;
    const string pattern_valid = R"(\s*([-]{0,1}\d+))"     // e.g. 2
                                 R"(\s*([\+|-|\*|/]))"     // e.g. *
                                 R"(\s*([-]{0,1}\d+))";    // e.g. 8
                                                           //
    // Loop until the user inputs a non-numeric value
    string input;
    bool is_valid = true;
    while (is_valid) {

        // Get user input
        cout << "Enter an expression: ";
        getline(cin, input);
        is_valid = regex_match(input, matches, regex(pattern_valid));

        // Debugging
        cout << matches[0];

    }

    // Print the results
    cout << "\n"
         << input << "\n"
         << "is_valid = " << is_valid << "\n";

    // Return 0 to signal success
    return 0;

}
