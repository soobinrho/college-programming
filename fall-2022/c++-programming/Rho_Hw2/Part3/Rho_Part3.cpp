// --------------------------------------------------------------- //
// Soobin Rho
// September 14, 2022
// COSC 226: C++
// Hw2: Objects, Types, and Values; Computation; Errors
//
// This program first prompts the user to input integers.
// Then, it calculates the sum of the first N integers.
// --------------------------------------------------------------- //

#include <iostream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

// A function for checking if the user entered less integers than N
void throw_invalid_argument(string message);

int main() {

    cout << "Enter the N value: ";
    int N;
    cin >> N;

    // This regex pattern is used for checking if the input is valid.
    // How do we know if it's valid? It should only contain digits.
    string pattern_valid = R"(\d+)";

    // Loop until the user inputs "|" to quit
    vector<int> integers;
    bool isComplete = false;
    while (!isComplete) {

        // ----------------------------------------------- //
        // 1. Get user input
        // ----------------------------------------------- //
        cout << "Enter integers (| to quit): ";
        string input;
        cin >> input;

        // If the input is |, then complete the input
        if (input == "|") isComplete = true;

        // Check if the input contains any non-numeric value
        else if (regex_match(input, regex(pattern_valid)) == false) {
            cout << "Invalid input :)\n";
        }

        // Add the input to the integers vector
        else integers.push_back(stoi(input));

    }

    try {

        // Throw error if the user entered less integers than N.
        // I did this by writing a function. It wasn't necessary to do so,
        // but I wanted to practice writing functions.
        if (integers.size() < (long unsigned) N) {
            string message = "\nInvalid input :) "
                             "You entered less integers than N.\n";
            throw_invalid_argument(message);
        }

    }

    catch (std::invalid_argument& error) {

        // Print the error message
        cerr << error.what();

        // Return 1 to signal error
        return 1;

    }

    // ----------------------------------------------- //
    // 2. Calculate the sum of the first N integers
    // ----------------------------------------------- //
    int sum;
    for (int i = 0; i < N; ++i) sum += integers[i];

    // ----------------------------------------------- //
    // 3. Print the sum
    // ----------------------------------------------- //
    cout << "\n"
         << "The sum of the first " << N << " integers = " << sum
         << "\n";

    // Return 0 to signal success
    return 0;

}

void throw_invalid_argument(string message) {
    throw std::invalid_argument(message);
}
