/*
 *    COSC 226: C++ Programming
 *    Soobin Rho
 *    September 30, 2022
 *    Chapter 8 "Technicalities: Functions, etc"
 *    Exercise 7
 */ 

#include <algorithm>    // Required for sort
#include <iostream>     // Required for cin, cout
#include <vector>       // Required for vector<string>, etc

using namespace std;

void printVector(const vector<string>&);
void printVector(const vector<double>&);
void printVectorPairs(const vector<string>&, const vector<double>&);

int main() {
    /*
     *    An exercise for getting used to vectors.
     *    How did I design this program?
     *
     *    As the textbook says, the tricky part of this exercise
     *    is "to get the age vector in the correct order to
     *    match the sorted name vector." (pg. 301)
     *    I approahced this exercise by creating a vector<int>
     *    storing the right index number of the age for each person.
     */

    // Prompt the user for five names
    const int HOWMANYNAMES = 5;
    vector<string> vectorNames;
    for (int i=0; i<HOWMANYNAMES; ++i) {
        cout<<"Enter the name of the person "<<i+1<<": ";

        string name;
        cin>>name;
        vectorNames.push_back(name);
    }

    // Prompt the user for the age of each person
    vector<double> vectorAges;
    for (int i=0; i<HOWMANYNAMES; ++i) {
        cout<<"Enter the age of the person "<<i+1<<": ";

        double age;
        cin>>age;
        vectorAges.push_back(age);
    }

    // Create a copy of vectorNames.
    // This saves the right location for each age.


    // Create vectorIndexes.
    // This stores the right index for each age.


    // Put each age into the right place



    // Return 0 to signal success
    return 0;
}

void printVector(const vector<string>& vectorNames) {
    /*
     *    A function for printing all elements of a string vector
     */
    
    for (const string& element : vectorNames) cout<<element<<'\n';
}

void printVector(const vector<double>& vectorAges) {
    /*
     *    A function for printing all elements of a double vector
     */
    
    for (const double& element : vectorAges) cout<<element<<'\n';
}


void printVectorPairs(const vector<string>& vectorNames,
                      const vector<double>& vectorAges) {
    /*
     *    A function for printing the names and ages.
     *    Example:
     *       (Soobin Rho, 24.1) 
     *       (Bean Soup, 0.5)
     */
    
    for(
    

}
