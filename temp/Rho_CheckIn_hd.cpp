/*
 *    Soobin Rho
 *    October 7, 2022
 *    COSC 226: C++ Programming
 *
 *    Check-in Acitivity
 *
 *    In this acitivity, we try to replicate the hd program (Hex Dump)
 *    with input / output operatoins,
 */ 

#include <iostream>    // Required for cout
#include <fstream>     // Required for ifstream
#include <string>      // Required for FILENAME

using namespace std;

int main() {
    /*
     *    Read a file and print its hex values.
     */

    // ---------------------------------------------------
    // 1. Read the file in binary
    // ---------------------------------------------------

    const string FILENAME = "test.txt";
    ifstream ifstreamMain {FILENAME,ios_base::binary};


    // Return 0 to signal success
    return 0;
}
