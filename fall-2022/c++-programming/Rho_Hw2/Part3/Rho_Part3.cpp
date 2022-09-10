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

int main() {

    cout << "Enter the N value: ";
    int N;
    cin >> N;

    // This regex pattern is used for checking if the input is valid.
    // How do we know if it's valid? It should only contain digits.
    string pattern_valid = R"(\d+)";

    // Loop until the user inputs | to quit
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

    // Throw error if the user put less integers than N.
    // As instructed, I did this by writing a function.
    if (integers.size() < N) !!!!

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
