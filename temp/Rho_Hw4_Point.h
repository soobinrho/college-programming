/*
 *    Soobin Rho
 *    October 12, 2022
 *    COSC 226: C++ Programming
 *    
 *    Hw4
 *    Points, input operations, and output operations.
 *
 *    This is the header file for Points.
 */ 

#include <iostream>
#include <vector>
#include <fstream>

namespace RhoShapes {

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
bool operator==(const Point& point1, const Point& point2);
bool operator!=(const Point& point1, const Point& point2);
std::ostream& operator<<(std::ostream& ostream1, const Point& point1); 

// ----------------------------------------------
// Helper functions for Points
// ----------------------------------------------

}  // namespace RhoShapes
