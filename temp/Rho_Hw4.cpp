/*
 *    Soobin Rho
 *    October 12, 2022
 *    COSC 226: C++ Programming
 *    
 *    Hw4
 *    Points, input operations, and output operations.
 *
 *    This file is the main driver for Points.
 */ 

#include "Rho_Hw4_Point.h"
#include <string>

// "using namespace std;" could have been used, but 
// I chose not to because I wanted to be 
// more conscious of which std functions I'm using.
using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::ofstream;
using std::ifstream;
using std::ios_base;
using namespace RhoShapes;

bool isValidChar(const char& char1) {
    bool isValid = char1=='(' || char1==',' || char1==')';
    return isValid;
}

void throwInvalidInput() {
    throw std::invalid_argument("Invalid input.");
}

std::istream& operator>>(std::istream& istream1, Point& point1) {
    /*
     *    This function converts a string of Point into a Point object.
     *    e.g. (98,8) gets converted into a Point {98,8} object.
     */

    int xInput;
    int yInput;
    char auxilaryChar1, auxilaryChar2, auxilaryChar3;

    // e.g. (12,43)
    istream1>>auxilaryChar1
            >>xInput
            >>auxilaryChar2
            >>yInput
            >>auxilaryChar3;

    if (istream1.eof()) return istream1;
    else if (istream1.fail() ||
             istream1. bad() ||
             !isValidChar(auxilaryChar1) || 
             !isValidChar(auxilaryChar2) ||
             !isValidChar(auxilaryChar3)) {

        istream1.clear(ios_base::failbit);
        throwInvalidInput();
    }

    point1.x = xInput;
    point1.y = yInput;

    return istream1;
}

std::istream& operator>>(std::istream& istream1,
                         vector<Point>& pointsVector) {
    /*
     *    This function converts strings of Point into Point objects.
     *    e.g. (1, 2)
     *         (3, 4)
     *         (5, 6)
     *    get converted into vector<Point> with the corresponding values.
     */

    Point pointTemporary;
    while (istream1>>pointTemporary) {
        pointsVector.push_back(pointTemporary);
    }

    return istream1;
}


std::ostream& operator<<(std::ostream& ostream1, 
                         const vector<Point>& pointsVector) {

    for (const Point& element : pointsVector) {
        ostream1<<element<<'\n';
    }

    return ostream1;
}

void printPointsVector(const vector<Point>& points) {
    for (const Point& element : points) cout<<element<<'\n';
}

void savePointsToTXT(const vector<Point>& pointsVector,
                     const string& fileName) {

    ofstream ofstreamMain {fileName};
    if (!ofstreamMain) throwInvalidInput();
    ofstreamMain<<pointsVector;
    ofstreamMain.close();
}


int main() {
    // ----------------------------------------------
    // A. Get user input for the Points vector
    // ----------------------------------------------
    vector<Point> originalPoints;

    cout<<"How many points to input? Enter: ";
    
    int HOWMANYPOINTS;
    cin>>HOWMANYPOINTS;

    for (int i=0; i<HOWMANYPOINTS; i++) {
        cout<<"Enter: ";
        Point pointTemporary;
        cin>>pointTemporary;
        originalPoints.push_back(pointTemporary);
    }

    // ----------------------------------------------
    // B. Print the Points vector from user input
    // ----------------------------------------------
    cout<<'\n'
        <<"POINTS YOU ENTERED\n";
    printPointsVector(originalPoints);
    cout<<'\n';

    // ----------------------------------------------
    // C. Save the vector into a file
    // ----------------------------------------------
    const string FILENAME = "mydata.txt";
    savePointsToTXT(originalPoints, FILENAME);

    // ----------------------------------------------
    // D. Pause for testing purposes
    // ----------------------------------------------
    string stringTemporary;
    while (stringTemporary != "yes") {
        cout<<"Type \"yes\" to cotinue: ";
        cin>>stringTemporary;
    }

    /* // ---------------------------------------------- */
    // E. Read and convert the file into a Points vector
    // ----------------------------------------------
    vector<Point> processedPoints;

    ifstream ifstreamMain {FILENAME};
    if (!ifstreamMain) throwInvalidInput();
    ifstreamMain>>processedPoints;

    // ----------------------------------------------
    // F. Print the Points vector from the file
    // ----------------------------------------------
    cout<<'\n'
        <<"POINTS SAVED IN \"./"<<FILENAME<<"\"\n";
    printPointsVector(processedPoints);
    cout<<'\n';


    // ----------------------------------------------
    // G. Compare originalPoints with processedPoints
    // ----------------------------------------------




    // Return 0 to signal success
    return 0;
}



