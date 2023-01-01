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

int main() {

  // ----------------------------------------------------------------
  // 0. Construct an image.
  // ----------------------------------------------------------------
  RhoPGM::Image imageEg{};

  // ----------------------------------------------------------------
  // 1. Save the image as a P2 type `.pgm` (ASCII) file and
  //    also as a P5 type `.pgm` (binary) file.
  // ----------------------------------------------------------------
  RhoPGM::pgmSaveAsFile(imageEg,"imageExample.pgm");
  RhoPGM::pgmSaveAsFile(imageEg,"imageExampleBinary.pgm","P5");

  // ----------------------------------------------------------------
  // 2. Read from a P2 type `.pgm` (ASCII) file and
  //    also as a P5 type `.pgm` (binary) file.
  // ----------------------------------------------------------------
  RhoPGM::Image imageFromP2{"imageExample.pgm"};
  RhoPGM::Image imageFromP5{"imageExampleBinary.pgm"};

  // ----------------------------------------------------------------
  // 3. Print a histogram of the image.
  // ----------------------------------------------------------------
  RhoPGM::pgmPrintHistogram(imageEg);

  // ----------------------------------------------------------------
  // 4. A funciton for adjusting the brightness of an image.
  // ----------------------------------------------------------------
  imageFromP2.setBrightness(0.99,-4);
  RhoPGM::pgmSaveAsFile(imageFromP2,"imageExampleBrightness.pgm");

  // ----------------------------------------------------------------
  // 5. A function for getting a subset of an image.
  // ----------------------------------------------------------------
  RhoPGM::Image imageEgSubset = imageEg.getSubset(0,0,1000,1000);
  RhoPGM::pgmSaveAsFile(imageEgSubset,"imageExampleSubset.pgm");

  // ----------------------------------------------------------------
  // 6. A function for downsampling an image
  // ----------------------------------------------------------------
  RhoPGM::Image imageEgDownsample = imageEg.getDownsample();
  RhoPGM::pgmSaveAsFile(imageEgDownsample,"imageExampleDownsample.pgm");

  // Return 0 to signal success
  return 0;
}
