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

using namespace std;

int main() {

    cout << "Enter the N value: ";
    int N;
    cin >> N;

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
        if (input == "|") {
            isComplete = true;
            break;
        }

        // Add the input to the integers vector
        integers.push_back(stoi(input));

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
