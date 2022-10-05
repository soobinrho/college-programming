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
     *    A struct for Points. All input / output / file
     *    operations will be done using this struct.
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
    bool isSame {false};
    if (point1.x==point2.x && point1.y==point2.y) isSame = true;
    return isSame;
}

bool operator!=(const Point& point1, const Point& point2) {
    return !(point1==point2);
}

// ----------------------------------------------
// Helper functions for Points
// ----------------------------------------------
int pointsCompare(const Point& point1, const Point& point2) {
    bool isSame = point1==point2;
    return isSame ? 0 : -1;

    // If these points are not the smae, return -1
    return -1;

}
