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

std::ostream& operator<<(std::ostream& ostream1, 
                         const std::vector<Point>& pointsVector) {

    for (const Point& element : pointsVector) {
        ostream1<<element<<'\n';
    }

    return ostream1;
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
             istream1.bad() ||
             !isValidChar(auxilaryChar1) || 
             !isValidChar(auxilaryChar2) ||
             !isValidChar(auxilaryChar3)) {

        istream1.clear(std::ios_base::failbit);
        throwInvalidInput();
    }

    point1.x = xInput;
    point1.y = yInput;

    return istream1;
}

std::istream& operator>>(std::istream& istream1,
                         std::vector<Point>& pointsVector) {
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

// ----------------------------------------------
// Helper functions for Points
// ----------------------------------------------
bool isValidChar(const char& char1) {
    bool isValid = char1=='(' || char1==',' || char1==')';
    return isValid;
}

void throwInvalidInput() {
    throw std::invalid_argument("Invalid input.");
}

void savePointsToTXT(const std::vector<Point>& pointsVector,
                     const std::string& fileName) {

    std::ofstream ofstreamMain {fileName};
    if (!ofstreamMain) throwInvalidInput();
    ofstreamMain<<pointsVector;
    ofstreamMain.close();
}

void readPointsFromTXT(std::vector<Point>& pointsVector,
                       const std::string& fileName) {

    std::ifstream ifstreamMain {fileName};
    if (!ifstreamMain) throwInvalidInput();
    ifstreamMain>>pointsVector;
    ifstreamMain.close();
}

void comparePointsVectors(const std::vector<Point>& pointsVector1,
                          const std::vector<Point>& pointsVector2) {

    for (int i=0; i<static_cast<int>(pointsVector1.size()); i++) {
        bool isSame = pointsVector1[i]==pointsVector2[i];
        std::string isSameString = isSame ? "Same Point" : "Different";
        std::cout<<pointsVector1[i]<<' '<<pointsVector2[i]
            <<" | "<<isSameString<<'\n';
    }
}

}  // namespace RhoShapes
