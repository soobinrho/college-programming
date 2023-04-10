/*
=======================================================================
COSC 310: Operating Systems
Soobin Rho
April 10, 2023
Lab 6: File System Simulator
=======================================================================
*/

// For learning purposes, I've written down notes from
// "Operating Systems and Middleware" by Max Hailperin.

#include <string>
#include <vector>
#include <memory>
#include <iostream>

using namespace std;

// TODO: Split to `RhoLab6-file-system-contiguous.cpp` `RhoLab6-file-system-linked-list.cpp` `RhoLab6-file-system-linked-list-FAT.cpp` -- file allocation table
// TODO: #include `RhoLab6-file-systems.hpp` -- split only after completing all and done testing.

// TODO: Notes: I think the difference between FAT and others is that it stores the extra metadata, while the other two don't.
// TODO: Notes: In contiguous allocation system, run the defragmentation whenever it reaches 80% full condition.
// TODO: template <type T>  --> No need. just use polymorphism
//       minimum<int>(1,2);
 
// --------------------------------------------------------------------
// Declarations for main data structures
// --------------------------------------------------------------------
const int BLOCK_SIZE = 1024;
const int TOTAL_BLOCKS = 200;
const int TOTAL_SIZE = BLOCK_SIZE*TOTAL_BLOCKS;

struct FileSystemContiguous {
    vector<int> whichFileThisIsMappedTo;
    vector<string> whichFileName;

    FileSystemContiguous () {};
    ~FileSystemContiguous () {};
};

struct FileSystemLinkedList {
    string fileName;

    FileSystemLinkedList* next;
    FileSystemLinkedList* previous;

    FileSystemLinkedList () {};
    ~FileSystemLinkedList () {};
};

struct FileSystemLinkedListFAT {
    string fileName;
    string permissions;
    string dateCreated;
    string dateModified;
    string dateAccessed;

    FileSystemLinkedListFAT* next;
    FileSystemLinkedListFAT* previous;

    FileSystemLinkedListFAT () {};
    ~FileSystemLinkedListFAT () {};
};

// --------------------------------------------------------------------
// Declarations for helper functions
// --------------------------------------------------------------------
void store (FileSystemContiguous fileSystem, string fileName, int numBytes) {

}


// TODO: Implement: {dir, store filename numBytes, access filename, del filename, dump, dump-all, help, exit}
// TODO: Specifications: {print "File not saved; file system full" if store operation fails}

// TODO: Notes: dir command lists all files and their attributes.
// TODO: Notes: dump command shows what the OS needs to access files in the system: Write as disk-block map.
// TODO: Notes: dump-all command shows the info given by the dump command as well as a map of each file block (which file it maps to or "free")
// TODO: Notes: store command also needs to report the number of blocks used for storing the file.
// TODO: Notes: access command counts the number of blocks (and therefore blocks) required for reading a given file.

// --------------------------------------------------------------------
// Definitions for main data structures
// --------------------------------------------------------------------
FileSystemContiguous::FileSystemContiguous() {
    for (int i=0;i<TOTAL_BLOCKS;++i) {
        // -1 here means not used. All numbers from 0 to any
        // positive number indicates the file it's mapped to.
        whichFileThisIsMappedTo.push_back(-1);
        whichFileName.push_back("-1");;
    }
}

FileSystemLinkedList::~FileSystemLinkedList() {
    if (next!=nullptr) delete next;
    if (previous!=nullptr) delete previous;
}

FileSystemLinkedListFAT::~FileSystemLinkedListFAT() {
    if (next!=nullptr) delete next;
    if (previous!=nullptr) delete previous;
}

// --------------------------------------------------------------------
// Definitions for helper functions
// --------------------------------------------------------------------
// No here yet. Write in declarations for now for testing purposes


int main () {
    // ----------------------------------------------------------------
    // File system initialization
    // ----------------------------------------------------------------
    FileSystemContiguous fileSystemContiguous;
    FileSystemLinkedList fileSystemLinkedList;
    FileSystemLinkedListFAT fileSystemLinkedListFAT;

    // ----------------------------------------------------------------
    // Examples
    // ----------------------------------------------------------------


    return 0;
}

// "A disk drive stores fixed-sized blocks of data known as sectors;
// a typical sector size is 512 bytes. The interface between a
// contemporary disk drive and a computer is conceptually quite simple,
// essentially just a large array of sectors. Just like in any array,
// the sectors are consecutively numbered, from 0 up to a maximum
// that depends on the capacity of the drive." (pg. 336)