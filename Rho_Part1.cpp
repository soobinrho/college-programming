// ---------------------------------------------------- //
// Programmed by: Soobin Rho
// September 14, 2022
// COSC 226: C++
// Hw2: Objects, Types, and Values; Computation; Errors
//
// This program prompts the user for two integers
// and then outputs the smallest, largest, sum,
// difference, product, and the ratio of these two.
// ---------------------------------------------------- //

#include <iostream>
#include <string>

using namespace std;

int main()
{

    // Get user input
    string input_string;
    cout << "Enter any word: ";
    cin >> input_string;

    // Echo the input
    cout << "You've entered \"" << input_string << "\".\n";
    cout << "\n";

    // Get user input
    cout << "Enter any sentence: ";
    std::getline(cin, input_string);
    std::getline(cin, input_string);


    // Echo the input
    cout << "You've entered \"" << input_string << "\".\n";
    cout << "\n";


    // Return 0 to signal success
    return 0;

}
