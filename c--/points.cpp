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
    
struct point {
public:
    point(int x, int y);
    point();
    int getX() {
        return x;
    }
    int getY() {
        return y;
    }

    bool operator==(const point& point2) {
        // Initialize the final return value
        bool isSame {false};

        // Check individual x and y values
        if (x == point2.x && y == point2.y) isSame = true;
        
        return isSame;
    }

private:
    int x = 0;
    int y = 0;
};

// -------------------------------
// Helper Functions for points
// -------------------------------
int pointsCompare(point point1, point point2) {

    // If these points are the same, return 0
    if (point1 == point2) return 0;

    // If these points are not the smae, return -1
    return -1;

}

}    // namespace shapes {
