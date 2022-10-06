/*
 *    Soobin Rho
 *    October 12, 2022
 *    COSC 226: C++ Programming
 *    
 *    Hw4
 *    Points, input operations, and output operations.
 *    
 *    This file includes the definitions for Points.
 */ 

#include "Rho_Hw4_Point.h"

namespace RhoShapes {

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

std::ostream& operator<<(std::ostream& ostream1, const Point& point1) {
    return ostream1<<'('<<point1.x<<','<<point1.y<<')';
}

// ----------------------------------------------
// Helper functions for Points
// ----------------------------------------------
/* bool pointsCompare(const Point& point1, const Point& point2) { */
/*     bool isSame = point1==point2; */
/*     return isSame; */
/* } */

}  // namespace RhoShapes
