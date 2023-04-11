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

#include <cmath>
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
const int TOTAL_BLOCKS_80_PERCENT = std::floor(TOTAL_BLOCKS*0.8);
const int TOTAL_SIZE = BLOCK_SIZE*TOTAL_BLOCKS;

struct FileSystemContiguous {
    vector<string> whichFileThisIsMappedTo;

    FileSystemContiguous () {
        for (int i=0;i<TOTAL_BLOCKS;++i) {
            // -1 here means not used. All numbers from 0 to any
            // positive number indicates the file it's mapped to.
            whichFileThisIsMappedTo.push_back("-1");
        }
    }
    ~FileSystemContiguous () {}
};

struct FileSystemLinkedList {
    string fileName;

    FileSystemLinkedList* next;
    FileSystemLinkedList* previous;

    FileSystemLinkedList () {
        next = nullptr;
        previous = nullptr;
    }
    ~FileSystemLinkedList () {
        if (next!=nullptr) delete next;
        if (previous!=nullptr) delete previous;
    }
};

struct FileSystemLinkedListFAT {
    string fileName;
    string permissions;
    string dateCreated;
    string dateModified;
    string dateAccessed;

    FileSystemLinkedListFAT* next;
    FileSystemLinkedListFAT* previous;

    FileSystemLinkedListFAT () {
        next = nullptr;
        previous = nullptr;
    }
    ~FileSystemLinkedListFAT () {
        if (next!=nullptr) delete next;
        if (previous!=nullptr) delete previous;
    }
};

// --------------------------------------------------------------------
// Declarations for helper functions
// --------------------------------------------------------------------
void accessFile (FileSystemContiguous& fileSystem, string fileName) {

}

void _runDefragmentation (FileSystemContiguous& fileSystem) {

}

int _getAvailableBlock (FileSystemContiguous& fileSystem, int howManyBlocks) {
    // Traverse through the blocks and find a free space.
    int index {0};
    int indexFound {-1};
    int countAvailableBlocks {0};
    bool needsDefragmentation {false};
    while (countAvailableBlocks<howManyBlocks && index<TOTAL_BLOCKS) {
        // Count how many contiguous blocks are not already occupied.
        const string whichFile = fileSystem.whichFileThisIsMappedTo[index];
        if (whichFile=="-1") {
            ++countAvailableBlocks;
            if (indexFound==-1) indexFound = index;
        }
        else {
            indexFound = -1;
            countAvailableBlocks = 0;
        }

        if (index>=TOTAL_BLOCKS_80_PERCENT) {
            needsDefragmentation = true;
            break;
        }

        cout<<"DEBUG: index "<<index<<" | indexFound "<<indexFound<<" | countAvailableBlocks "<<countAvailableBlocks<<'\n';

        ++index;
    }

    // If 80% or more of the file system is unavailable, run defragmentation function.
    // After that, traverse through the blocks again since the blocks have changed.
    if (needsDefragmentation) {
        _runDefragmentation(fileSystem);
        index = 0;
        indexFound = -1;
        countAvailableBlocks = 0;
        needsDefragmentation = false;
        while (countAvailableBlocks<howManyBlocks && index<TOTAL_BLOCKS) {
            const string whichFile = fileSystem.whichFileThisIsMappedTo[index];
            if (whichFile=="-1") {
                ++countAvailableBlocks;
                if (indexFound==-1) indexFound = index;
            }
            else {
                indexFound = -1;
                countAvailableBlocks = 0;
            }

            if (index<=TOTAL_BLOCKS_80_PERCENT) {
                needsDefragmentation = true;
                break;
            }
            
            ++ index;
        }
    } 

    if (indexFound!=-1) return indexFound;

    // If the function reaches this point, it means there's no available block.
    return -1;
}

void storeFile (FileSystemContiguous& fileSystem, string fileName, int numBytes) {
    // Find whether or not the filesystem has enough space for the file.
    // This function returns -1 if no block is available. On the other hand,
    // if there's an available block, it returns the first block's index.
    const int howManyBlocks = std::ceil(numBytes*1.0/BLOCK_SIZE);
    cout<<"DEBUG: "<<howManyBlocks<<'\n';
    int availableBlock = _getAvailableBlock(fileSystem,howManyBlocks);
    if (availableBlock==-1) {
        cout<<"[ERROR] File not saved; file system full.\n";
        return;
    }

    // Store the file.
    const int availableBlockEnd = availableBlock+(howManyBlocks-1);
    for (int i=availableBlock;i<=availableBlockEnd;++i) {
        fileSystem.whichFileThisIsMappedTo[i]=fileName;
    }

    // Report the number of blocks used for storing the file.
    cout<<"[RESULTS] \"./"<<fileName<<"\"\n";
    cout<<"[RESULTS] Number of blocks used for storing this file: "<<howManyBlocks<<'\n';
}

void storeFile (FileSystemLinkedList& fileSystem, string fileName, int numBytes) {

}

void storeFile (FileSystemLinkedListFAT& fileSystem, string fileName, int numBytes) {

}



// TODO: Implement: {dir, store filename numBytes, access filename, del filename, dump, dump-all, help, exit}

// TODO: Notes: dir command lists all files and their attributes.
// TODO: Notes: dump command shows what the OS needs to access files in the system: Write as disk-block map.
// TODO: Notes: dump-all command shows the info given by the dump command as well as a map of each file block (which file it maps to or "free")
// TODO: Notes: access command counts the number of blocks (and therefore blocks) required for reading a given file.

// --------------------------------------------------------------------
// Definitions for main data structures
// --------------------------------------------------------------------

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

    // Switch to stdin redirection later
    const string FILE_NAME_0 = "file_0";
    const string FILE_NAME_1 = "file_1";
    const string FILE_NAME_2 = "file_2";
    const int FILE_SIZE_0 = 20;
    const int FILE_SIZE_1 = 2048;
    const int FILE_SIZE_2 = 2049;

    storeFile(fileSystemContiguous,FILE_NAME_0,FILE_SIZE_0);
    storeFile(fileSystemContiguous,FILE_NAME_1,FILE_SIZE_1);
    storeFile(fileSystemContiguous,FILE_NAME_2,FILE_SIZE_2);

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