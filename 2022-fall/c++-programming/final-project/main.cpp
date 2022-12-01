/*
 *    Deepak Krishnaa Govindarajan
 *    Marcus Naess
 *    Soobin Rho
 *    Fall, 2022
 *    COSC 226: C++ Programming
 *
 *    Hw: A Container class for handling images.
 */

#include "Image.h"
using namespace std;

int main() {

    // ----------------------------------------------------------------
    // 0. Construct an image.
    // ----------------------------------------------------------------
    Image imageExample {};  // Default constructor creates a gradient

    // ----------------------------------------------------------------
    // 1. Save the image as a P2 type `.pgm` (ASCII) file and
    //    also as a P5 type `.pgm` (binary) file.
    // ----------------------------------------------------------------
    pgmSaveAsFile(imageExample,"imageExample.pgm");
    pgmSaveAsFile(imageExample,"imageExampleBinary.pgm","P5");

    // ----------------------------------------------------------------
    // 2. Read from a P2 type `.pgm` (ASCII) file and
    //    also as a P5 type `.pgm` (binary) file.
    // ----------------------------------------------------------------
    Image imageFromP2 {"imageExample.pgm"};
    Image imageFromP5 {"imageExampleBinary.pgm"};

    // ----------------------------------------------------------------
    // 3. Print a histogram of the image
    // ----------------------------------------------------------------
    pgmPrintHistogram(imageExample);

    // ----------------------------------------------------------------
    // 4. A funciton for adjusting the brightness of an image
    // ----------------------------------------------------------------
    imageExample.setBrightness(1,-5);

    // ----------------------------------------------------------------
    // 7. A function for getting a subset of an image
    // ----------------------------------------------------------------

    // Image imageExampleSubset = imageExample.getSubset(0,0,500,500);

    // ----------------------------------------------------------------
    // 8. A function for downsampling an image
    // ----------------------------------------------------------------
    // Image imageExampleDownsample = imageExample.getDownsample(10);

    // Accepts `int neighborPixels`

    // A member function to downsample an image by 2 in the line direction
    // and by 2 in the sample direction. Include an option to smooth here.
    // It will return a new image. (to smooth an image, average a pixel's
    // neighbors.


    // Return 0 to signal success
    return 0;
}
