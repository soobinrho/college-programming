/*
 *    Soobin Rho
 *    October 12, 2022
 *    COSC 226: C++ Programming
 *    
 *    Hw4
 *    Points, input operations, and output operations.
 */ 

#include <iostream>    // Required for cout
#include <vector>      // Required for vector<int>

using namespace std;

struct Point {
    /*
     *    A struct for Points. This struct will be used for all
     *    input / output / file operations required this homework.
     */

    Point() : x(), y() {};
    Point(int xInput, int yInput) : x(xInput), y(yInput) {};

    int x = 0;
    int y = 0;
};

// ----------------------------------------------
// Opearator overloading for Points
// ----------------------------------------------
bool operator==(const Point& point1, const Point& point2) {
    bool isSame = point1.x==point2.x && point1.y==point2.y;
    return isSame;
}

bool operator!=(const Point& point1, const Point& point2) {
    bool isNotSame = !(point1==point2);
    return isNotSame;
}

// ----------------------------------------------
// Helper functions for Points
// ----------------------------------------------
bool pointsCompare(const Point& point1, const Point& point2) {
    bool isSame = point1==point2;
    return isSame;
}

int main() {
    /*
     *    Driver for Points.
     */


    Point testPoint {1, 1};


    // Return 0 to signal success
    return 0;
}


