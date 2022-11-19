/*
 *    COSC 226: C++ Programming
 *    Soobin Rho
 *    September 30, 2022
 *    Chapter 8 "Technicalities: Functions, etc"
 *    Exercise 7
 */ 

#include <algorithm>    // Required for sort, static_cast<int>, find, and distance
#include <iostream>     // Required for cin and cout
#include <vector>       // Required for vector<string>, etc

using namespace std;

void printVector(const vector<string>&);
void printVector(const vector<double>&);
void printVector(const vector<int>&);
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
        getline(cin,name);
        vectorNames.push_back(name);
    }

    // Prompt the user for the age of each person
    vector<double> vectorAgesUnsorted;
    for (int i=0; i<HOWMANYNAMES; ++i) {
        cout<<"Enter the age of the person "<<i+1<<": ";

        double age;
        cin>>age;
        vectorAgesUnsorted.push_back(age);
    }

    // Create a copy of vectorNames.
    // This saves the right location for each age.
    vector<string> vectorNamesUnsorted {vectorNames};

    // Print the inputs
    cout<<'\n'
        <<"YOUR INPUT\n";
    printVectorPairs(vectorNamesUnsorted,vectorAgesUnsorted);

    // Sort vectorNames as instructed
    sort(vectorNames.begin(),vectorNames.end());

    // Create vectorIndexes.
    // This stores the right index for each age.
    vector<int> vectorIndexes;
    for (int i=0; i<static_cast<int>(vectorNames.size()); ++i) {
        int rightIndex = distance(vectorNames.begin(),
                                  find(vectorNames.begin(),
                                       vectorNames.end(),
                                       vectorNamesUnsorted[i]));
        vectorIndexes.push_back(rightIndex);
    }

    // Put each age into the right place
    vector<double> vectorAges(vectorIndexes.size());
    for (int i=0; i<static_cast<int>(vectorIndexes.size()); ++i) {
        vectorAges[vectorIndexes[i]] = vectorAgesUnsorted[i];
    }

    // Print the results in the form of (Name, Age)
    cout<<'\n'
        <<"SORTED OUTPUT\n";
    printVectorPairs(vectorNames,vectorAges);

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

void printVector(const vector<int>& vectorIndexes) {
    /*
     *    A function for printing all elements of an int vector
     */
    
    for (const int& element : vectorIndexes) cout<<element<<'\n';
}

void printVectorPairs(const vector<string>& vectorNames,
                      const vector<double>& vectorAges) {
    /*
     *    A function for printing the names and ages.
     *    Example:
     *       (Soobin Rho, 24.1) 
     *       (Bean Soup, 0.5)
     */
    
    for(int i=0; i<static_cast<int>(vectorNames.size()); ++i) {
        cout<<'('
            <<vectorNames[i]
            <<", "
            <<vectorAges[i]
            <<")\n";
    }
}
