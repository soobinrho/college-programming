/*
 *    COSC 226: C++ Programming
 *    Marcus Naess, Shannon McCormick, Soobin Rho
 *    October 3, 2022
 *    In-class acitivity
 */ 

#include <iostream>    // Required for cout
#include <vector>      // Required for vector<int>

using namespace std;

namespace shapes {
/*
 *    All our point definitions and helper functions
 *    will be written in this namespace.
 */
    
struct Point {
public:
    Point(int x, int y);
    Point();
    int x = 0;
    int y = 0;
};

// -------------------------------
// Opearator overloading
// -------------------------------
bool operator==(const Point& point1, const Point& point2) {
    // Initialize the final return value
    bool isSame {false};

    // Check individual x and y values
    if (point1.x == point2.x && point1.y == point2.y) isSame = true;
    
    return isSame;
}

// -------------------------------
// Helper Functions for points
// -------------------------------
int pointsCompare(Point point1, Point point2) {

    // If these points are the same, return 0
    if (point1 == point2) return 0;

    // If these points are not the smae, return -1
    return -1;

}

}    // namespace shapes {
