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

    // Get the smallest and the largest
    int smallest;
    int largest;
    if (val1 < val2) {
        smallest = val1;
        largest = val2;
    }
    else if (val1 > val2) {
        smallest = val2;
        largest = val1;
    }
    else if (val1 == val2) {
        smallest = val1;
        largest = val1;
    }

    // Note: Above, I could've used else instead of else if, 
    // but I did this to make it easier to understand.

    // Get the sum
    int sum = val1 + val2;

    // Get the difference
    int difference = val1 - val2;

    // Get the product
    int product = val1 * val2;

    // Get the ratio
    int quotient = val1 / val2;

    // Print the results
    cout << "\n"
         << "smallest = " << smallest << "\n"
         << "largest = " << largest << "\n"
         << "sum = " << sum << "\n"
         << "difference = " << difference << "\n"
         << "product = " << product << "\n"
         << "ratio = " << quotient << "\n";

    // Return 0 to signal success
    return 0;

}
