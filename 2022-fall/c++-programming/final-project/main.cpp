/*
 *    Soobin Rho
 *    Fall, 2022
 *    COSC 226: C++ Programming
 *
 *    Final Project: STL-like Image Container
 *
 *    Main driver. This file is in charge of demonstrating
 *    examples of all functions.
 */

#include "Image.h"
using namespace std;

int main() {

  // ----------------------------------------------------------------
  // 0. Construct an image.
  // ----------------------------------------------------------------
  Image imageExample{};

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
  Image imageFromP2{"imageExample.pgm"};
  Image imageFromP5{"imageExampleBinary.pgm"};

  // ----------------------------------------------------------------
  // 3. Print a histogram of the image.
  // ----------------------------------------------------------------
  pgmPrintHistogram(imageExample);

  // ----------------------------------------------------------------
  // 4. A funciton for adjusting the brightness of an image.
  // ----------------------------------------------------------------
  imageExample.setBrightness(0.99,-4);
  pgmSaveAsFile(imageExample,"imageExampleBrightness.pgm");

  // ----------------------------------------------------------------
  // 5. A function for getting a subset of an image.
  // ----------------------------------------------------------------
  Image imageExampleSubset = imageExample.getSubset(0,0,1280,800);
  pgmSaveAsFile(imageExampleSubset,"imageExampleSubset.pgm");

  // ----------------------------------------------------------------
  // 6. A function for downsampling an image
  // ----------------------------------------------------------------
  Image imageExampleDownsample = imageExample.getDownsample(10);
  pgmSaveAsFile(imageExampleDownsample,"imageExampleDownsample.pgm");

  // Return 0 to signal success
  return 0;
}
