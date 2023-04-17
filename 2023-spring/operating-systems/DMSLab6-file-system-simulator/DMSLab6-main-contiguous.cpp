/*
=======================================================================
COSC 310: Operating Systems
Deepak Govindarajan, Marcus Naess, and Soobin Rho (DMS)
April 17, 2023
Lab 6: File System Simulator
=======================================================================
*/

#include "./DMSLab6-file-system-simulator.hpp"

int main () {
    // ----------------------------------------------------------------
    // File system initialization
    // ----------------------------------------------------------------
    FileSystemContiguous fileSystemContiguous;

    // ----------------------------------------------------------------
    // Loop until user inputs exit
    // ----------------------------------------------------------------
    printHelp();
    bool isExit = false;
    while (!isExit) {
        cout<<"Enter a command: ";
        string buffer;
        getline(cin,buffer);
        if (buffer==HELP_1 || buffer==HELP_2) {
            printHelp();
        }
        else if (buffer==EXIT_1 || buffer==EXIT_2 || cin.eof()) {
            isExit = true;
        }
        else if (buffer==DIR) {
            printAllFiles(fileSystemContiguous);
        }
        else if (buffer==DUMP) {
            dump(fileSystemContiguous);
        }
        else if (buffer==DUMP_ALL) {
            dumpAll(fileSystemContiguous);
        }
        else if (buffer==DEFRAGMENTATION) {
            _runDefragmentation(fileSystemContiguous);
        }
        else if (regex_match(buffer,matches,regex(STORE_REGEX))==1) {
            // Structure of matches:
            // matches[0] --> the whole match  (e.g. store Rho.cpp 1024)
            // matches[1] --> fileName         (e.g. Rho.cpp)
            // matches[2] --> numBytes       (e.g. 1024)
            storeFile(fileSystemContiguous,matches[1],stoi(matches[2]));
        }
        else if (regex_match(buffer,matches,regex(ACCESS_REGEX))==1) {
            printFileSize(fileSystemContiguous,matches[1]);
        }
        else if (regex_match(buffer,matches,regex(DEL_REGEX))==1) {
            deleteFile(fileSystemContiguous,matches[1]);
        }
        else {
            std::cout<<"[ERROR] Invalid input; type "<<HELP_1<<".\n";
        }
    }

    return 0;
}