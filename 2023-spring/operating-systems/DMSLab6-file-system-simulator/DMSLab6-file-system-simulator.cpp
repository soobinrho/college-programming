/*
=======================================================================
COSC 310: Operating Systems
Deepak Govindarajan, Marcus Naess, and Soobin Rho (DMS)
April 17, 2023
Lab 6: File System Simulator
=======================================================================
*/

#include "./DMSLab6-file-system-simulator.hpp"

// --------------------------------------------------------------------
// Definitions for user input menu options
// --------------------------------------------------------------------
const string HELP_1 = "help";
const string HELP_2 = "?";
const string EXIT_1 = "exit";
const string EXIT_2 = "q";
const string DIR = "dir";
const string DUMP = "dump";
const string DUMP_ALL = "dump-all";
const string DEFRAGMENTATION = "defragmentation";

// Regular expression is used for parsing `store fileName fileSize`,
// `access fileName`, and `del fileName` commands.
const string STORE_REGEX = R"(store\s+(\w+)\s+(\d+))";
const string ACCESS_REGEX = R"(access\s+(\w+))";
const string DEL_REGEX = R"(del\s+(\w+))";
smatch matches;

// --------------------------------------------------------------------
// Declarations for main data structures
// --------------------------------------------------------------------
const int BLOCK_SIZE = 1024;
const int TOTAL_BLOCKS = 200;
const int TOTAL_BLOCKS_80_PERCENT = std::floor(TOTAL_BLOCKS*0.8);
const int TOTAL_SIZE = BLOCK_SIZE*TOTAL_BLOCKS;

FileSystemContiguous::FileSystemContiguous() {
    for (int i=0;i<TOTAL_BLOCKS;++i) {
        // -1 here means not used.
        whichFileThisIsMappedTo.push_back("-1");
    }
}

// --------------------------------------------------------------------
// Definitions for helper functions
// --------------------------------------------------------------------
void printHelp () {
    const int PRINT_WIDTH = 23;
    cout<<setw(PRINT_WIDTH)<<left<<HELP_1<<" : Print help.\n"
        <<setw(PRINT_WIDTH)<<left<<EXIT_1<<" : Exit.\n"
        <<setw(PRINT_WIDTH)<<left<<"store fileName fileSize"<<" : Store a file.\n"
        <<setw(PRINT_WIDTH)<<left<<"access fileName"<<" : Access a file.\n"
        <<setw(PRINT_WIDTH)<<left<<"del fileName"<<" : Delete a file.\n"
        <<setw(PRINT_WIDTH)<<left<<DIR<<" : List all files and their attributes.\n"
        <<setw(PRINT_WIDTH)<<left<<DUMP<<" : Dump the block-file mapping table.\n"
        <<setw(PRINT_WIDTH)<<left<<DUMP_ALL<<" : Dump the block-file mapping table (detailed).\n"
        <<'\n';
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

    // Print a newline for better readability.
    std::cout<<'\n';

    for (auto const& file : foundFiles) {
        const string whichFile = file.first;
        const int countBlocks = file.second;
        const int numBytes = countBlocks*BLOCK_SIZE;
        std::cout<<"[INFO] \""<<whichFile<<"\" "<<numBytes<<" bytes ("<<countBlocks<<" blocks)"<<'\n';
    }
}

void printAllFiles (FileSystemLinkedList& fileSystem) {
}

void printAllFiles (FileSystemLinkedListFAT& fileSystem) {
}

void dump (FileSystemContiguous& fileSystem) {
    // TODO: Implement the dump table
}

void dump (FileSystemLinkedList& fileSystem) {
}

void dump (FileSystemLinkedListFAT& fileSystem) {
}

void dumpAll (FileSystemContiguous& fileSystem) {
    // TODO: Insert the dump function here

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

    // Print a newline for better readability.
    std::cout<<'\n';

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

void dumpAll (FileSystemLinkedList& fileSystem) {
}

void dumpAll (FileSystemLinkedListFAT& fileSystem) {
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
    std::cout<<"\n[RESULTS] \"./"<<fileName<<"\" | Number of blocks used for storing this file: "<<howManyBlocks<<'\n';
}

void storeFile (FileSystemLinkedList& fileSystem, string fileName, int numBytes) {
}

void storeFile (FileSystemLinkedListFAT& fileSystem, string fileName, int numBytes) {
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

    // Print a newline for better readability.
    std::cout<<'\n';

    if (isFound) {
        std::cout<<"[INFO] \"./"<<fileName<<"\" | Number of blocks used for storing this file: "<<countBlocks<<'\n';
    }

    else {
        std::cout<<"[ERROR] Access function failed; \"./"<<fileName<<"\" does not exist."<<'\n';
    }
}

void printFileSize (FileSystemLinkedList& fileSystem, string fileName) {
}

void printFileSize (FileSystemLinkedListFAT& fileSystem, string fileName) {
}

void deleteFile (FileSystemContiguous& fileSystem, string fileName) {
    int howManyBlocks {0};
    for (int i=0;i<TOTAL_BLOCKS;++i) {
        const string whichFile = fileSystem.whichFileThisIsMappedTo[i];
        if (whichFile==fileName) {
            fileSystem.whichFileThisIsMappedTo[i] = "-1";
            ++howManyBlocks;
        }
    }

    // Report the number of blocks deleted.
    std::cout<<"\n[RESULTS] \"./"<<fileName<<"\" | Number of blocks deleted: "<<howManyBlocks<<'\n';
}

void deleteFile (FileSystemLinkedList& fileSystem, string fileName) {
}

void deleteFile (FileSystemLinkedListFAT& fileSystem, string fileName) {
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

    fileSystem = resultantFileSystem;
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
            
            ++index;
        }
    } 

    if (indexFound!=-1 && countAvailableBlocks>=howManyBlocks) {
        return indexFound;
    }

    // If the function reaches this point, it means there's no available block.
    return -1;
}

// BACKGROUND READINGS ON FILE SYSTEMS
// "Operating Systems and Middleware" by Max Hailperin.

// You can ignore this part, unless you want to know more about the background
// information of file systems. Below, we've summarized the file systems chapter.
// We found these information particularly useful for this assignment.

// "A disk drive stores fixed-sized blocks of data known as sectors;
// a typical sector size is 512 bytes. The interface between a
// contemporary disk drive and a computer is conceptually quite simple,
// essentially just a large array of sectors. Just like in any array,
// the sectors are consecutively numbered, from 0 up to a maximum
// that depends on the capacity of the drive." (pg. 336)

// "In virtual memory, the mapping is from virtual addresses within address
// spaces to physical addresses within memory. In a file system, the mapping
// is from positions within files to locations in persistent storage. For
// efficiency, the mapping is done at a coarse granularity, several kibibytes
// at a time. In virtual memory,// each page is mapped into a page frame." (pg. 350)

// "Key objectives for allocation: minimizing wasted space and time …
// these goals can be expressed as minimizing fragmentation and maximizing locality." (pg. 351)
// 
// "One source of waste is that space is allocated only in integer multiples
// of some file system block size. For example, a file system might allocate
// space only in units of 4 KiB. A file that is too big to fit in a single
// 4-KiB unit will be allocated 8 KiB of space—even if it is only a single
// byte larger than 4 KiB. The unused space in the last file block is called
// internal fragmentation." (pg. 351)
// 
// "A defragmentation program moves files’ blocks around on disk so as to
// leave each file in a single extent. To allow future allocations to be
// non-fragmented, the defragmentation program also arranges the files so
// that the free space on the disk is clustered together." (pg. 351)
// 
// "1. The space allocated for each file should be broken into as few
// extents as possible. 2. If a file needs to be allocated more than one
// extent, each extent should be nearby to the previous one.
// 3. Files that are commonly used in close succession (or concurrently)
// should be placed near one another." (pg. 354)
// 
// "Recall that in a system with separate address spaces, each process has
// its own page table, storing the information regarding which page frame
// holds that process’s page 0, page 1, and so forth. Similarly, each file
// has its own metadata storing the information regarding which disk block
// holds that file’s block 0, block 1, and so forth. You will see that,
// as with page tables, there are several choices for the data structure
// holding this mapping information." (pg. 358)

// READINGS FOR LINKED-LIST FILE SYSTEMS
// "File Systems" by Bracy and Van Renesse (Especially pg. 33~37)
//   http://www.cs.cornell.edu/courses/cs4410/2015fa/slides/10-filesystems.pdf