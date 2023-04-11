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

#include <unordered_map>
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

void printFileSize (FileSystemContiguous& fileSystem, string fileName);
void _runDefragmentation (FileSystemContiguous& fileSystem);
int _getAvailableBlock (FileSystemContiguous& fileSystem, int howManyBlocks);
void storeFile (FileSystemContiguous& fileSystem, string fileName, int numBytes);

// -- above is real declarations.

void dumpAll (FileSystemContiguous& fileSystem) {
    // Print where every block is mapped to.
    for (int i=0;i<TOTAL_BLOCKS;++i) {
        const string whichBlock = fileSystem.whichFileThisIsMappedTo[i];
        if(whichBlock!="-1") {
            std::cout<<"[INFO] Block "<<i<<" --> \""<<whichBlock<<"\"\n";
        }
        else {
            std::cout<<"[INFO] Block "<<i<<" --> free\n";
        }
    }
}

void dump (FileSystemContiguous& fileSystem) {
    // Print which blocks are free and which blocks are assigned for files.
    unordered_map<string,int> blockCount;
    unordered_map<string,int> blockStartIndex;
    unordered_map<string,int> blockEndIndex;
    vector<string> insertOrder;
    vector<bool> isFree;
    int indexFreeBlockStart {0};
    for (int i=0;i<TOTAL_BLOCKS;++i) {
        const string whichFile = fileSystem.whichFileThisIsMappedTo[i];
        if (whichFile!="-1") {
            ++blockCount[whichFile];
            if (blockCount[whichFile]==1) {
                blockStartIndex[whichFile] = i;
                insertOrder.push_back(whichFile);
                isFree.push_back(false);
            }
            blockEndIndex[whichFile] = i;
        }
        else {
            const string whichBlock = to_string(i);
            ++blockCount[whichBlock];
            if (blockCount[whichBlock]==1) {
                blockStartIndex[whichBlock] = i;
                insertOrder.push_back(whichBlock);
                isFree.push_back(true);
            }
            blockEndIndex[whichBlock] = i;
        }
    }

    for (int i=0;i<insertOrder.size();++i) {
        const string whichBlock = insertOrder[i];
        if (isFree[i] && (i==insertOrder.size()-1 || !isFree[i+1])) {
            std::cout<<"[INFO] Block ~"<<blockEndIndex[whichBlock]
                                       <<" --> free\n";
        } 
        else if (!isFree[i]) {
            std::cout<<"[INFO] Block "<<blockStartIndex[whichBlock]<<'-'
                                      <<blockEndIndex[whichBlock]
                                      <<" --> \""<<whichBlock<<"\"\n";
        }
    }
}


void printAllFiles (FileSystemContiguous& fileSystem) {
    // Print all files and their attributes.
    unordered_map<string,int> foundFiles;
    for (int i=0;i<TOTAL_BLOCKS;++i) {
        const string whichFile = fileSystem.whichFileThisIsMappedTo[i];
        if (whichFile!="-1") {
            ++foundFiles[whichFile];
        }
    }

    for (auto const& file : foundFiles) {
        const string whichFile = file.first;
        const int countBlocks = file.second;
        const int countBytes = countBlocks*BLOCK_SIZE;
        std::cout<<"[INFO] \""<<whichFile<<"\" "<<countBytes<<" bytes ("<<countBlocks<<" blocks)"<<'\n';
    }
}

void printFileSize (FileSystemContiguous& fileSystem, string fileName) {
    // Traverse through the blocks and find the file.
    int index {0};
    int indexFound {-1};
    int countBlocks {0};
    bool isFound {false};
    while (index<TOTAL_BLOCKS) {
        // Count how many blocks are used by the file.
        const string whichFile = fileSystem.whichFileThisIsMappedTo[index];
        if (whichFile==fileName) {
            ++countBlocks;
            if (indexFound==-1) {
                isFound = true;
                indexFound = index;
            }
        }
        else if (indexFound!=-1) {
            break;
        }

        ++index;
    }

    if (isFound) {
        std::cout<<"[INFO] \"./"<<fileName<<"\" | Number of blocks used for storing this file: "<<countBlocks<<'\n';
    }

    else {
        std::cout<<"[ERROR] Access function failed; \"./"<<fileName<<"\" does not exist."<<'\n';
    }
}

void _runDefragmentation (FileSystemContiguous& fileSystem) {
    // This is what this function will return at the end. Basically,
    // traverse through all the blocks; ignore unassigned blocks; and
    // only add files' blocks to the `resultantFileSystem`.
    FileSystemContiguous resultantFileSystem;
    int indexResultant {0};
    for (int i=0;i<TOTAL_BLOCKS;++i) {
        const string whichFile = fileSystem.whichFileThisIsMappedTo[i];
        if (whichFile!="-1") {
            resultantFileSystem.whichFileThisIsMappedTo[indexResultant] = whichFile;
            ++indexResultant;
        }
    }
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

        ++index;
    }

    // If 80% or more of the file system is unavailable, run defragmentation function.
    // After that, traverse through the blocks again since the blocks have changed.
    if (needsDefragmentation) {
        _runDefragmentation(fileSystem);
        index = 0;
        indexFound = -1;
        countAvailableBlocks = 0;
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

            // TODO: REMOVE THIS AFTER COMPLETION
            // std::cout<<"DEBUG2: index "<<index<<" | indexFound "<<indexFound<<" | countAvailableBlocks "<<countAvailableBlocks<<'\n';
            
            ++index;
        }
    } 

    if (indexFound!=-1) return indexFound;

    // If the function reaches this point, it means there's no available block.
    return -1;
}

void storeFile (FileSystemContiguous& fileSystem, string fileName, int numBytes) {
    // Range check the input.
    if (numBytes<=0 || numBytes>TOTAL_SIZE) {
        std::cout<<"[ERROR] file size should be between 0 bytes and "<<TOTAL_SIZE<<" bytes.\n";
        return;
    }

    // Find whether or not the filesystem has enough space for the file.
    // This function returns -1 if no block is available. On the other hand,
    // if there's an available block, it returns the first block's index.
    const int howManyBlocks = std::ceil(numBytes*1.0/BLOCK_SIZE);
    int availableBlock = _getAvailableBlock(fileSystem,howManyBlocks);
    if (availableBlock==-1) {
        std::cout<<"[ERROR] File not saved; file system full.\n";
        return;
    }

    // Store the file.
    const int availableBlockEnd = availableBlock+(howManyBlocks-1);
    for (int i=availableBlock;i<=availableBlockEnd;++i) {
        fileSystem.whichFileThisIsMappedTo[i]=fileName;
    }

    // Report the number of blocks used for storing the file.
    std::cout<<"[RESULTS] \"./"<<fileName<<"\" | Number of blocks used for storing this file: "<<howManyBlocks<<'\n';
}

void storeFile (FileSystemLinkedList& fileSystem, string fileName, int numBytes) {

}

void storeFile (FileSystemLinkedListFAT& fileSystem, string fileName, int numBytes) {

}

void deleteFile (FileSystemContiguous& fileSystem, string fileName) {
    for (int i=0;i<TOTAL_BLOCKS;++i) {
        const string whichFile = fileSystem.whichFileThisIsMappedTo[i];
        if (whichFile==fileName) {
            fileSystem.whichFileThisIsMappedTo[i] = "-1";
        }
    }
}


// TODO: Implement: {dir, store filename numBytes, access filename, del filename, dump, dump-all, help, exit}

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
    const int FILE_SIZE_0 = 190000;  // 204800 = maximum value
    const int FILE_SIZE_1 = 10;
    const int FILE_SIZE_2 = 20;

    storeFile(fileSystemContiguous,FILE_NAME_0,FILE_SIZE_0);
    storeFile(fileSystemContiguous,FILE_NAME_1,FILE_SIZE_1);
    storeFile(fileSystemContiguous,FILE_NAME_2,FILE_SIZE_2);

    // ----------------------------------------------------------------
    // Examples
    // ----------------------------------------------------------------
    printFileSize(fileSystemContiguous,FILE_NAME_0);
    printFileSize(fileSystemContiguous,FILE_NAME_1);
    printFileSize(fileSystemContiguous,FILE_NAME_2);

    printAllFiles(fileSystemContiguous);
    deleteFile(fileSystemContiguous,FILE_NAME_1);
    dump(fileSystemContiguous);

    return 0;
}

// "A disk drive stores fixed-sized blocks of data known as sectors;
// a typical sector size is 512 bytes. The interface between a
// contemporary disk drive and a computer is conceptually quite simple,
// essentially just a large array of sectors. Just like in any array,
// the sectors are consecutively numbered, from 0 up to a maximum
// that depends on the capacity of the drive." (pg. 336)