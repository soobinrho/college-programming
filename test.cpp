// Programmed by: Soobin Rho
// Hw1: Environment
// September 2, 2022
// COSC 226: C++

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
