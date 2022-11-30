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
    // 1. Create a constant image and print a histogram of the image
    // ----------------------------------------------------------------
    const int CONSTANT_COLOR {13};
    Image imageGrey {CONSTANT_COLOR};
    pgmPrintHistogram(imageGrey);

    // Print a whitespace for better readability
    cout<<'\n';

    // ----------------------------------------------------------------
    // 2. Create a wedge image and print a histogram of the image
    // ----------------------------------------------------------------
    Image imageGradient {};
    pgmPrintHistogram(imageGradient);

    // ----------------------------------------------------------------
    // 3. Save the example image files
    // ----------------------------------------------------------------
    pgmSaveAsFile(imageGrey,"imageGrey.pgm");
    pgmSaveAsFile(imageGradient,"imageGradient.pgm");

    // ----------------------------------------------------------------
    // 4. Initiate an Image instance using an existing pgm file
    // ----------------------------------------------------------------
    Image imageFromFile {"imageGradient.pgm"};

    // ----------------------------------------------------------------
    // 5. Adjust brightness and then save as a file.
    //    "imageAdjusted.pgm" is saved in P2 form (ASCII).
    //    "imageAdjustedBinary.pgm" is saved in P5 form (binary).
    // ----------------------------------------------------------------
    imageFromFile.setBrightness(1,-5);
    pgmSaveAsFile(imageFromFile,"imageAdjusted.pgm");
    pgmSaveAsFile(imageFromFile,"imageAdjustedBinary.pgm","P5");

    // Return 0 to signal success
    return 0;
}
