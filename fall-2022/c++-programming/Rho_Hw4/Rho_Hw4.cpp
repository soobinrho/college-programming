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

// "using namespace std;" could have been used, but
// I chose to do it the harder way in this homework.
// This way, I can be more conscious of which std functions I'm using.
using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::ofstream;
using std::ifstream;
using std::numeric_limits;
using std::streamsize;
using namespace RhoShapes;

int main() {
    // ----------------------------------------------
    // A. Get user input for the Points vector
    // ----------------------------------------------
    cout<<"Type your points in the form of (a,b).\n"
    <<'\n'
        <<"Example Input:\n"
        <<"  (12,34)\n"
        <<"  (-42,876)\n"
        <<'\n';

    vector<Point> originalPoints;
    Point pointTemporary;
    int count = 0;
    bool isFail {false};
    while (!isFail) {
        cout<<"Enter point "<<count+1<<": ";

        cin>>pointTemporary;
        if (cin.fail()) {
            isFail = true;
            clearerr(stdin);
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cin.clear();
        }
        else {
            originalPoints.push_back(pointTemporary);
        }

        count++;
    }

    // ----------------------------------------------
    // B. Print the Points vector from user input
    // ----------------------------------------------
    cout<<'\n'
        <<"POINTS YOU ENTERED\n"
        <<originalPoints
        <<'\n';

    // ----------------------------------------------
    // C. Save the vector into a file
    // ----------------------------------------------
    const string FILENAME = "mydata.txt";
    savePointsToTXT(originalPoints, FILENAME);

    // ----------------------------------------------
    // D. Pause for testing purposes
    // ----------------------------------------------
    bool isYes {false};
    string stringTemporary;
    while (!isYes) {
        cout<<"Enter \"yes\" to continue: ";
        cin>>stringTemporary;
        if (stringTemporary=="yes") isYes = true;
    }

    // ----------------------------------------------
    // E. Read and convert the file into a Points vector
    // ----------------------------------------------
    vector<Point> processedPoints;
    readPointsFromTXT(processedPoints, FILENAME);

    // ----------------------------------------------
    // F. Print the Points vector from the file
    // ----------------------------------------------
    cout<<'\n'
        <<"POINTS SAVED IN \"./"<<FILENAME<<"\"\n"
        <<processedPoints;

    // ----------------------------------------------
    // G. Compare originalPoints with processedPoints
    // ----------------------------------------------
    cout<<'\n'
        <<"COMPARISON (ORIGINAL vs PROCESSED)\n";
    comparePointsVectors(originalPoints, processedPoints);

    // Return 0 to signal success
    return 0;
}
