/*
 *    COSC 226: C++ Programming
 *    Soobin Rho
 *    September 30, 2022
 *    Chapter 8 "Technicalities: Functions, etc"
 *    Exercise 5
 */ 

#include <iostream>    // Required for cout
#include <utility>     // Required for swap
#include <vector>      // Required for vector<int>

using namespace std;

vector<int> reverseIntVectorA(const vector<int>&);
void reverseIntVectorB(vector<int>&);

int main() {
    /*
     *    An exercise for reversing a verctor of ints
     */

    vector<int> vectorA {1,2,3,4,5,6,7,8,9,10};
    vector<int> vectorAnew;

    // Return 0 to signal success
    return 0;

}

vector<int> reverseIntVectorA(const vector<int>& vectorOriginal) {
    /* 
     *    A function for reversing a vertor of ints by
     *    producing a new vector
     */

    vector<int> vectorReversed;

    return vectorReversed;
}

void reverseIntVectorB(vector<int>& vectorOriginal) {
    /* 
     *    A function for reversing a vertor of ints by
     *    "passing by reference"
     */

    vector<int> vectorReversed;
}
