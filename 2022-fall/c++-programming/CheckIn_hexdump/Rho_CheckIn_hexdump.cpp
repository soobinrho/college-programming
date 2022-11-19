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

void hexdump(string fileName);
void hexdumpAnotherWay(string fileName);
void throwInvalidArgument();

int main() {
    // ---------------------------------------------------
    // 1. Hexdump the testfile
    // ---------------------------------------------------
    const string TESTFILENAME = "Rho_CheckIn_hexdump.txt";
    try {
        hexdump(TESTFILENAME);
    }
    catch (invalid_argument& error) {
        cout<<"Skipping the test file, since it doesn't exist.\n";
    }

    // ---------------------------------------------------
    // 2. (Optional) Hexdump more files given by the user
    // ---------------------------------------------------
    cout<<'\n'
        <<"OPTIONAL: ENTER YOUR OWN FILE NAME\n"
        <<"e.g. \"test.txt\"\n"
        <<"(Type q to quit)\n";

    string stringIn;
    bool isTerminating {false};
    while (!isTerminating && !cin.eof()) {
        cout<<'\n'
            <<"Enter: ";
        cin>>stringIn;

        if (stringIn=="q") isTerminating = true;
        else {
            cout<<'\n';
            string fileName = stringIn;
            try {
                hexdump(fileName);
            }
            catch (invalid_argument& error) {
                cout<<"\"./"<<fileName<<"\" doesn't exist.\n";
            }
        }
    }

    // Return 0 to signal success
    return 0;
}

void hexdump(string fileName) {
    /*
     *    A function for reading a file in hexadecimal.
     */

    ifstream ifs {fileName,ios_base::binary};
    if (!ifs) throwInvalidArgument();

    cout<<"HEXDUMP \""<<fileName<<"\"\n";

    cout<<setfill('0')
        <<hex;

    int count = 0;
    int countTotalBytes = 0;

    int intIn;
    void* address = &intIn;
    while (ifs.read(static_cast<char*>(address),sizeof(char))) {
        // Print the number of total bytes
        // e.g. 00000010
        if (count%16==0 || count==0) {
            cout<<setw(8)<<countTotalBytes<<' ';
        }

        // Print the hexadeximals
        // e.g. 49 6c 6f 76 65 70 61 73 74 61 77 69 74 68 74 6f
        // This, by the way, means "Ilovepastawithto[matosauce]"
        cout<<setw(2)<<intIn<<' ';

        ++count;
        if (count%16==0) {
            cout<<'\n';
            countTotalBytes+=16;
        }
    }

    cout<<'\n';
    ifs.close();
}

void hexdumpAnotherWay(string fileName) {
    /*
     *    Actually, before writing the previous hexdump function,
     *    I wrote this function for better understanding of the problem.
     *
     *    Rather than reading the file as bytes directly,
     *    this function reads the file as char values, converts these
     *    into int values, and then prints the int values in hexadecimal.
     *    Obviously, this is less efficient than directly reading as bytes.
     *    Nevertheless, I like this version too
     *    because it doesn't use any pointer unlike the previous function.
     */

    ifstream ifs {fileName,ios_base::binary};
    if (!ifs) throwInvalidArgument();

    cout<<"HEXDUMP \""<<fileName<<"\"\n";

    cout<<setfill('0')
        <<hex;

    int count = 0;
    int countTotalBytes = 0;

    for (char charIn; ifs.get(charIn);) {
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

    cout<<'\n';
    ifs.close();
}

void throwInvalidArgument() {
    throw std::invalid_argument("Invalid argument");
}
