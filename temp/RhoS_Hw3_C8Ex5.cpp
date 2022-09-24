/*
 *    COSC 226: C++ Programming
 *    Soobin Rho
 *    September 30, 2022
 *    Chapter 8 "Technicalities: Functions, etc"
 *    Exercise 5
 */ 

#include <iostream>    // Required for cout and static_cast
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

    // Print the reversed vector
    cout<<"REVERSED VECTOR A:\n";
    printVector(vectorANew);
    cout<<'\n';

    // ---------------------------------------------------
    // 2. Reverse the vector without creating a new vector
    // ---------------------------------------------------
    vector<int> vectorB {11,12,13,14,15,16,17,18,19,20};
    reverseIntVectorB(vectorB);

    // Print the reversed vector
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

    // The loop's terminating condition has two possibilities:
    //
    // Possibility A: The vector's SIZE is an even number.
    //                In this case, int terminatingNum = SIZE/2;
    //
    // Possibility B: The vector's SIZE is an odd number.
    //                In this case, int terminatingNum = SIZE/2;
    //
    // Yes, that is right. In both possibilities, it's the same.
    int terminatingNum = static_cast<int>(vectorInput.size()/2);
    int iReverse = vectorInput.size()-1;
    for (int i=0; i<terminatingNum; i++) {
        swap(vectorInput[i],vectorInput[iReverse]);
        --iReverse;
    }
}

void printVector(const vector<int>& vectorInput) {
    /*
     *    A function for printing all elements of the vector
     */
    
    for(const int& element : vectorInput) cout<<element<<'\n';
}
