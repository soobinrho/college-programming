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
using namespace RhoShapes;

int main() {
    // ----------------------------------------------
    // A. Get user input for the Points vector
    // ----------------------------------------------
 
    // 
    // Why HOWMANYPOINTS as a terminator instead the EOF character?
    //
    // The instruction tells us to use the EOF character
    // as the terminator, so I did so at first.
    // My program, however, kept behaving strangely;
    // it kept ignoring all cin's located after
    // the EOF character was input. 
    //
    // For instane, under "D. Pause for testing purposes" section,
    // there's a "while (!isYes)" loop, which is supposed to
    // stop once the user inputs "yes", but it never worked.
    // All "cin>>..." statements seemed to be dead after the EOF call.
    // The loop never waited for the cin, so it became an infinite loop.
    //
    // Therefore, I switched to the HOWMANYPOINTS approach shown below:
    //
    cout<<"Type your points in the form of (a,b).\n"
        <<'\n'
        <<"Example Input:\n"
        <<"  (12,34)\n"
        <<"  (-42,876)\n"
        <<'\n'
        <<"How many points to input? Enter: ";
    
    int HOWMANYPOINTS;
    cin>>HOWMANYPOINTS;

    vector<Point> originalPoints;
    for (int i=0; i<HOWMANYPOINTS; ++i) {
        cout<<"Enter point "<<i+1<<": ";
        Point pointTemporary;
        cin>>pointTemporary;
        originalPoints.push_back(pointTemporary);
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
    while (!isYes && !cin.eof()) {
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
