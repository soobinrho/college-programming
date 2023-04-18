/*
=======================================================================
COSC 310: Operating Systems
Deepak Govindarajan, Marcus Naess, and Soobin Rho (DMS)
April 17, 2023
Lab 6: File System Simulator
=======================================================================
*/

#include "./include/DMSLab6-file-system-simulator.hpp"

// Initialize the fileAllocationTable
vector<int> FileSystemLinkedListFAT::fileAllocationTable = vector<int>(TOTAL_BLOCKS, -1);

int main()
{
    // ----------------------------------------------------------------
    // File system initialization
    // ----------------------------------------------------------------
    FileSystemLinkedListFAT fileSystemLinkedListFAT;

    // ----------------------------------------------------------------
    // Loop until user inputs exit
    // ----------------------------------------------------------------
    printHelp();
    bool isExit = false;
    while (!isExit)
    {
        cout << "Enter a command: ";
        string buffer;
        getline(cin, buffer);
        if (buffer == HELP_1 || buffer == HELP_2)
        {
            printHelp();
        }
        else if (buffer == EXIT_1 || buffer == EXIT_2 || cin.eof())
        {
            isExit = true;
        }
        else if (buffer == DIR)
        {
            printAllFiles(fileSystemLinkedListFAT);
        }
        else if (buffer == DUMP)
        {
            dump(fileSystemLinkedListFAT);
        }
        else if (buffer == DUMP_ALL)
        {
            dumpAll(fileSystemLinkedListFAT);
        }
        else if (regex_match(buffer, matches, regex(STORE_REGEX)) == 1)
        {
            // Structure of matches:
            // matches[0] --> the whole match  (e.g. store Rho.cpp 1024)
            // matches[1] --> fileName         (e.g. Rho.cpp)
            // matches[2] --> numBytes       (e.g. 1024)
            storeFile(fileSystemLinkedListFAT, matches[1], stoi(matches[2]));
        }
        else if (regex_match(buffer, matches, regex(ACCESS_REGEX)) == 1)
        {
            printFileSize(fileSystemLinkedListFAT, matches[1]);
        }
        else if (regex_match(buffer, matches, regex(DEL_REGEX)) == 1)
        {
            deleteFile(fileSystemLinkedListFAT, matches[1]);
        }
        else
        {
            std::cout << "[ERROR] Invalid input; type " << HELP_1 << ".\n";
        }
    }

    return 0;
}