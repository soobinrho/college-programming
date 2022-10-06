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
std::ostream& operator<<(std::ostream& ostream1, 
                         const std::vector<Point>& pointsVector);
std::istream& operator>>(std::istream& istream1, Point& point1);
std::istream& operator>>(std::istream& istream1,
                         std::vector<Point>& pointsVector);

// ----------------------------------------------
// Helper functions for Points
// ----------------------------------------------
bool isValidChar(const char& char1);
void throwInvalidInput();
void printPointsVector(const std::vector<Point>& points);
void savePointsToTXT(const std::vector<Point>& pointsVector,
                     const std::string& fileName);
void readPointsFromTXT(std::vector<Point>& pointsVector,
                       const std::string& fileName);
void comparePointsVectors(const std::vector<Point>& pointsVector1,
                          const std::vector<Point>& pointsVector2);

}  // namespace RhoShapes
