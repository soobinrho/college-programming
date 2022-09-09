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

    // A note on the design of this program:
    // I could've just used cin double, char, and double
    // individually, but I chose to use a getline and then
    // use regex to sanitize the input because I wanted to
    // practice using regex.
    
    // Get user input
    string input_string;
    cout << "Enter an expression: ";
    getline(cin, input_string);

    // Sanitize the input
    //string pattern_valid = R"([\+|-|\*|/]hello)";
    string pattern_valid = R"(\s*([-]{0,1}\d+))"     // e.g. 2
                           R"(\s*([\+|-|\*|/]))"     // e.g. *
                           R"(\s*([-]{0,1}\d+))";    // e.g. 8
    bool is_valid = regex_match(input_string, regex(pattern_valid));

    // Print the results
    cout << "\n"
         << input_string << "\n"
         << "is_valid = " << is_valid << "\n";

    // Return 0 to signal success
    return 0;

}
