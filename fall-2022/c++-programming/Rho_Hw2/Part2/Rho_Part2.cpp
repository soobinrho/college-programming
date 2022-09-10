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

int main() {

    // ----------------------------------------- //
    // Two possibilities for inputs:
    // A. Valid inputs (e.g. -40 - 40)
    // B. Exit code (Contains non-numeric value)
    // ----------------------------------------- //
    smatch matches;
    string pattern_valid = R"(\s*([\-]?\d+\.?\d*))"        // e.g. 2
                           R"(\s*([\+|\-|\*|/]))"          // e.g. *
                           R"(\s*([\-]?\d+\.?\d*)\s*)";    // e.g. 8

    // Loop until the user inputs a non-numeric value
    string input;
    double result;
    bool is_valid = true;
    while (is_valid) {

        // ----------------------------------------- //
        // 1. Get user input
        // ----------------------------------------- //
        cout << "Enter an expression: ";
        getline(cin, input);
        is_valid = regex_match(input, matches, regex(pattern_valid));

        // If the input contains any non-numeric value, then exit
        if (!is_valid) break;

        // ----------------------------------------- //
        // Structure of matches:
        // matches[0] -> the whole match
        // matches[1] -> num_1        (e.g. 2)
        // matches[2] -> operation    (e.g. *)
        // matches[3] -> num_2        (e.g. 8)
        // ----------------------------------------- //

        // ----------------------------------------- //
        // 2. Convert the input string into 
        //    num_1, operation, and num_2
        // ----------------------------------------- //
        double num_1 = stod(matches[1].str());
        char operation = matches[2].str()[0];
        double num_2 = stod(matches[3].str());

        // ----------------------------------------- //
        // 3. Print the result
        // ----------------------------------------- //
        switch (operation) {

            case '+':
                result = num_1 + num_2;
                cout << "The sum of " << num_1 << " and " << num_2
                     << " is " << result << "\n\n";
                break;

            case '-':
                result = num_1 - num_2;
                cout << "The difference of " << num_1 << " and " << num_2
                     << " is " << result << "\n\n";
                break;

            case '*':
                result = num_1 * num_2;
                cout << "The product of " << num_1 << " and " << num_2
                     << " is " << result << "\n\n";
                break;

            case '/':
                result = num_1 / num_2;
                cout << "The ratio of " << num_1 << " and " << num_2
                     << " is " << result << "\n\n";
                break;

        }

        // Side note:
        // cout << std::scientific is the default, but I could use
        // cout << std::fixed if I didn't want the scientific notation.

    }

    // Return 0 to signal success
    return 0;

}
