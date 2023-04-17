/*
=======================================================================
COSC 310: Operating Systems
Deepak Govindarajan, Marcus Naess, and Soobin Rho (DMS)
April 17, 2023
Lab 6: File System Simulator
=======================================================================
*/

#ifndef DMSLAB6_FILE_SYSTEM_SIMULATOR_HPP
#define DMSLAB6_FILE_SYSTEM_SIMULATOR_HPP

#include <cmath>
#include <regex>
#include <queue>
#include <vector>
#include <string>
#include <memory>
#include <iomanip>
#include <iostream>
#include <unordered_map>

using namespace std;

// --------------------------------------------------------------------
// Declarations for user input menu options
// --------------------------------------------------------------------
extern const string HELP_1;
extern const string HELP_2;
extern const string EXIT_1;
extern const string EXIT_2;
extern const string DIR;
extern const string DUMP;
extern const string DUMP_ALL;
extern const string DEFRAGMENTATION;

// Regular expression is used for parsing `store fileName fileSize`,
// `access fileName`, and `del fileName` commands.
extern const string STORE_REGEX;
extern const string ACCESS_REGEX;
extern const string DEL_REGEX;
extern smatch matches;

// --------------------------------------------------------------------
// Declarations for main data structures
// --------------------------------------------------------------------
extern const int BLOCK_SIZE;
extern const int TOTAL_BLOCKS;
extern const int TOTAL_BLOCKS_80_PERCENT;
extern const int TOTAL_SIZE;

struct FileSystemContiguous {
    vector<string> whichFileThisIsMappedTo;

    FileSystemContiguous ();
    ~FileSystemContiguous () {}
};

struct FileSystemLinkedList {
    string fileName;

    FileSystemLinkedList* next;
    static inline queue<int> availableBlocks;

    FileSystemLinkedList ();
    ~FileSystemLinkedList () {
        if (next!=nullptr) delete next;
    }
};

struct FileSystemLinkedListFAT {
    string fileName;

    FileSystemLinkedListFAT* next;
    static inline vector<int> fileAllocationTable;

    FileSystemLinkedListFAT () {
        next = nullptr;
    }
    ~FileSystemLinkedListFAT () {
        if (next!=nullptr) delete next;
    }
};

// --------------------------------------------------------------------
// Declarations for helper functions
// --------------------------------------------------------------------
void printHelp ();

void printAllFiles (FileSystemContiguous& fileSystem);
void printAllFiles (FileSystemLinkedList& fileSystem);
void printAllFiles (FileSystemLinkedListFAT& fileSystem);

void dump (FileSystemContiguous& fileSystem);
void dump (FileSystemLinkedList& fileSystem);
void dump (FileSystemLinkedListFAT& fileSystem);

void dumpAll (FileSystemContiguous& fileSystem);
void dumpAll (FileSystemLinkedList& fileSystem);
void dumpAll (FileSystemLinkedListFAT& fileSystem);

void storeFile (FileSystemContiguous& fileSystem, string fileName, int numBytes);
void storeFile (FileSystemLinkedList& fileSystem, string fileName, int numBytes);
void storeFile (FileSystemLinkedListFAT& fileSystem, string fileName, int numBytes);

void printFileSize (FileSystemContiguous& fileSystem, string fileName);
void printFileSize (FileSystemLinkedList& fileSystem, string fileName);
void printFileSize (FileSystemLinkedListFAT& fileSystem, string fileName);

void deleteFile (FileSystemContiguous& fileSystem, string fileName);
void deleteFile (FileSystemLinkedList& fileSystem, string fileName);
void deleteFile (FileSystemLinkedListFAT& fileSystem, string fileName);

void _runDefragmentation (FileSystemContiguous& fileSystem);
int _getAvailableBlock (FileSystemContiguous& fileSystem, int howManyBlocks);

#endif