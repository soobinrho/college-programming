/*
 *    COSC 226: C++ Programming
 *    Soobin Rho
 *    September 30, 2022
 *    Chapter 8: Exercise 5
 *    Technicalities: Functions, etc
 */ 

#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main() {
    /*
     *    A program for
     */

    smatch matches;
    string pattern_valid = R"(\s*([\-]?\d+\.?\d*))"     // e.g. 2
                           R"(\s*([\+|\-|\*|/]))"       // e.g. *
                           R"(\s*([\-]?\d+\.?\d*)\s*)";    // e.g. 8

    // Loop until the user inputs a non-numeric value
    string input;
    double result;
    bool is_valid = true;
    while (is_valid) {

        // Get user input
        cout << "Enter an expression: ";
        getline(cin, input);
        is_valid = regex_match(input, matches, regex(pattern_valid));

        // If the input contains any non-numeric value, exit
        if (!is_valid) break;

        // ----------------------------------------- //
        // Structure of matches:
        // matches[0] -> the whole match
        // matches[1] -> num_1        (e.g. 2)
        // matches[2] -> operation    (e.g. *)
        // matches[3] -> num_2        (e.g. 8)
        // ----------------------------------------- //

        // Convert the input string into num_1, operation, and num_2
        double num_1 = stod(matches[1].str());
        char operation = matches[2].str()[0];
        double num_2 = stod(matches[3].str());

        // ----------------------------------------- //
        // Print the result
        // ----------------------------------------- //

        // Side note:
        // cout << std::scientific is the default, but I could use
        // cout << std::fixed if I didn't want the scientific notation.
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

    }

    // Return 0 to signal success
    return 0;

}

int exampleFunction() {
    /* 
     *    A function for
     */

    int number = 0;
    return number;
}
