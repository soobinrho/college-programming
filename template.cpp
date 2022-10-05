/*
 *    Soobin Rho
 *    October 12, 2022
 *    COSC 226: C++ Programming
 *
 *    Exercise 5
 */ 

#include <iostream>    // Required for cout
#include <utility>     // Required for swap
#include <vector>      // Required for vector<int>

using namespace std;

vector<int> reverseIntVectorA(const vector<int>& vectorInput);
void reverseIntVectorB(vector<int>& vectorInput);
void printVector(const vector<int>& vectorInput);

int main() {
    /*
     *    An exercise for reversing int verctors
     */

    // ---------------------------------------------------
    // 1. Reverse the vector by producing a new vector
    // ---------------------------------------------------
    vector<int> vectorA {1,2,3,4,5,6,7,8,9,10};
    vector<int> vectorANew = reverseIntVectorA(vectorA);
    cout<<"REVERSED VECTOR A:\n";
    printVector(vectorANew);
    cout<<'\n';

    // ---------------------------------------------------
    // 2. Reverse the vector without creating a new vector
    // ---------------------------------------------------
    vector<int> vectorB {1,2,3,4,5,6,7,8,9,10};
    reverseIntVectorB(vectorB);
    cout<<"REVERSED VECTOR B:\n";
    printVector(vectorB);
    cout<<'\n';


    // Return 0 to signal success
    return 0;
}

vector<int> reverseIntVectorA(const vector<int>& vectorInput) {
    /* 
     *    A function for reversing a vertor of ints by
     *    producing a new vector
     */

    vector<int> vectorReversed;
    for (int i=vectorInput.size()-1; i>=0; --i) {
        vectorReversed.push_back(vectorInput[i]);
    }

    return vectorReversed;
}

void reverseIntVectorB(vector<int>& vectorInput) {
    /* 
     *    A function for reversing a vertor of ints by
     *    "passing by reference"
     */

    vector<int> vectorReversed;
}

void printVector(const vector<int>& vectorInput) {
    /*
     *    A function for printing all elements of the vector
     */
    
    for(const int& element : vectorInput) cout<<element<<'\n';
}
