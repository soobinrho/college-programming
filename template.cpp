// --------------------------------------------------------------- //
// Soobin Rho
// September 14, 2022
// COSC 226: C++
// Hw2: Objects, Types, and Values; Computation; Errors
//
// This program prompts the user for two integers and then outputs 
// the smallest, largest, sum, difference, product, and the ratio 
// of these two.
// --------------------------------------------------------------- //

#include <iostream>
#include <string>

using namespace std;

int main()
{

    // Prompt the user for two integers
    int val1;
    int val2;
    cout << "Enter two integers: ";
    cin >> val1 >> val2;

    // Print the smallest and the largest
    int smallest;
    int largest;
    if (val1 < val2) {
        val1 = smallest;
        val2 = largest;
    }
    else if (val1 > val2) {
        val1 = largest;
        val2 = smallest;
    }
    else if (val1 == val2) {
        val1 = smallest;
        val1 = largest;
    }

    // Note: I could've used else instead of else if, 
    // but I chose to be verbose to make it easier to understand.

    cout << val1 << val2;

    /* // Echo the input */
    /* cout << "You've entered \"" << input_string << "\".\n"; */
    /* cout << "\n"; */

    /* // Get user input */
    /* cout << "Enter any sentence: "; */
    /* std::getline(cin, input_string); */
    /* std::getline(cin, input_string); */


    /* // Echo the input */
    /* cout << "You've entered \"" << input_string << "\".\n"; */
    /* cout << "\n"; */


    // Return 0 to signal success
    return 0;

}
