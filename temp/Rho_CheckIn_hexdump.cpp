/*
 *    Soobin Rho
 *    October 7, 2022
 *    COSC 226: C++ Programming
 *
 *    Check-in Acitivity
 *
 *    In this acitivity, we try to make a hexdump program
 *    by using input / output operatoins.
 */ 

#include <iostream>    // Required for cout
#include <fstream>     // Required for ifstream
#include <string>      // Required for string variables
#include <iomanip>     // Required for cout<<setw(...)

using namespace std;

void hexdump(istream& ist);
void hexdumpAnotherWay(istream& ist);
void throwInvalidInput();

int main() {
    /*
     *    Read a file and print its hex values.
     */

    // ---------------------------------------------------
    // 1. Read the file in binary
    // ---------------------------------------------------
    const string FILENAME = "test.txt";  // NOTE: Change to user input
    ifstream ifs {FILENAME,ios_base::binary};
    if (!ifs) throwInvalidInput();


    /* ifs.seekg(0, ifs.end); */
    /* int length = ifs.ge; */



    hexdumpAnotherWay(ifs);

    ifs.close();

    // ---------------------------------------------------
    //  . Convert to hex and print
    // ---------------------------------------------------



    // Return 0 to signal success
    return 0;
}

void hexdump(istream& ist){
    /*
     *    A
     */


}

void hexdumpAnotherWay(istream& ist) {
    /*
     *    Actually, before writing the previous hexdump function,
     *    I wrote this function for better understanding of the problem.
     *
     *    Rather than directly reading the file as bytes directly,
     *    this function reads the file as char values, converts these
     *    into int, and then prints the int values in hexadecimal.
     *    Obviously, this is less efficient than directly reading as bytes.
     *    Nevertheless, I like this version too
     *    because it doesn't use any pointer unlike the previous function.
     */

    cout<<setfill('0')
        <<hex;

    int count = 0;
    int countTotalBytes = 0;

    for (char charIn; ist.get(charIn);) {
        // Print the number of total bytes
        // e.g. 00000010
        if (count%16==0 || count==0) {
            cout<<setw(8)<<countTotalBytes<<' ';
        }

        // Print the hexadeximals
        // e.g. 49 6c 6f 76 65 70 61 73 74 61 77 69 74 68 74 6f
        // This, by the way, means "Ilovepastawithto[matosauce]"
        cout<<setw(2)<<static_cast<int>(charIn)<<' ';

        ++count;
        if (count%16==0) {
            cout<<'\n';
            countTotalBytes+=16;
        }
    }
}

void throwInvalidInput() {
    throw std::invalid_argument("Invalid input.");
}

