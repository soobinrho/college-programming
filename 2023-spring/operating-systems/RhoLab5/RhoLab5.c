/*
 *    COSC 310: Operating Systems
 *    Soobin Rho
 *    March 27, 2023
 *    Lab 5: Virtual Memory Simulator
 */ 

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>  // Required for REG_EXTENDED
#include <regex.h>

// Commands that the user can input.
const char QUIT_1[] = "quit\n";
const char QUIT_2[] = "q\n";
const char HELP_1[] = "help\n";
const char HELP_2[] = "?\n";
const char TEXTBOOK_1[] = "textbook\n";
const char TEXTBOOK_2[] = "Textbook\n";
const char DUMP_1[] = "dumpPageTable\n";
const char DUMP_2[] = "dump\n";
const char VERBOSE_ON[] = "verbose_on\n";
const char VERBOSE_OFF[] = "verbose_off\n";

// --------------------------------------------------------------------
// Initialize the page table. It contains every virtual memory page,
// physical memory page frame, and all of their mappings.
// --------------------------------------------------------------------
#define SIZE_VIRT_ADDRESS 65536  // 2^16 bytes as instructed
#define SIZE_PHYS_ADDRESS 32768  // 2^15 bytes as instructed
#define SIZE_PAGE 4096           // 2^12 bytes as instructed

#define NUM_VIRT SIZE_VIRT_ADDRESS/SIZE_PAGE  // 16 in this case
#define NUM_PHYS SIZE_PHYS_ADDRESS/SIZE_PAGE  //  8 in this case

typedef struct PageTable {
  int pages_mapsTo[NUM_VIRT];
  int pages_isModified[NUM_VIRT];
  int pageFrames_isFilled[NUM_PHYS];
  int pageFrames_refCount[NUM_PHYS];
  int pageFrames_order[NUM_PHYS];
} PageTable;

// Fill the page table's array values with default values.
// Note that the reason why .pages_mapsTo and .pageFrames_order are
// initialized with -1 instead of 0 is because I use -1 to indicate
// whether or not that specific page / page frame has been used before.
// If the value is -1, it means it's the first time it's being used.
// If it's 0 or any positive number, it means it's been used before.
PageTable pageTable = {.pages_mapsTo = {[0 ... NUM_VIRT-1]=-1},
                       .pages_isModified = {0},
                       .pageFrames_isFilled = {0},
                       .pageFrames_refCount = {0},
                       .pageFrames_order = {[0 ... NUM_PHYS-1]=-1}};

void printHelp();
void setTextbookData();
void printPageTable();
void setVerbose(bool onOrOff);
int MMU(int virtAddr, bool isVerbose);
int _getPhysAddr_pageHit(int virtAddr, int page, int offset, bool isVerbose);
int _getPhysAddr_pageFault(int virtAddr, int page, int offset, bool isVerbose);

int main() {
  // Compile regex for the decode command.
  // The match array has two member because matches[0] is always
  // the entire match, while matches[1] is the first subgroup.
  // Since the DECODE regex has one subgroup - i.e. `([:digit:]+)` -
  // SIZE_GROUPS must be 1 entire match + 1 subgroup = 2.
  const size_t SIZE_GROUPS = 2;
  regmatch_t matches[SIZE_GROUPS];
  regex_t DECODE_REGEX;
  (void) regcomp(&DECODE_REGEX,"^decode ([0-9]+)",REG_EXTENDED);

  // ------------------------------------------------------------------
  // Get user input.
  // ------------------------------------------------------------------
  size_t commandLength = 0;
  bool isVerbose = false;
  bool isTerminated = false;
  while (!isTerminated) {

    // getline is better than scanf in this situation because getline
    // protects against the buffer overflow, if the input is longer than
    // the allocated size, which happens to be 12 in this case because
    // the longest possible command is `help (or ?)`, which consists of
    // 11 characters + 1 null character (\0).
    printf("Enter a command: ");
    char *command = NULL;
    getline(&command,&commandLength,stdin);

    // -----------------------------------------------------------------
    // Execute commands depending on the user input.
    // -----------------------------------------------------------------
    if (regexec(&DECODE_REGEX,command,SIZE_GROUPS,matches,0)==0) {
      // -----------------------------------------------------------------
      // Get the physical address.
      // -----------------------------------------------------------------
      int virtAddr = atoi(command+matches[1].rm_so);
      int physAddr = MMU(virtAddr,isVerbose);
      if (physAddr!=-1) {
        printf("[RESULT] %d --> %d\n",virtAddr,physAddr);
      }
      else {
        printf("[ERROR] The maximum value is %d.\n",SIZE_VIRT_ADDRESS);
      }
    }
    else if (strcmp(command,HELP_1)==0 || strcmp(command,HELP_2)==0) {
      printHelp();
    }
    else if (strcmp(command,TEXTBOOK_1)==0 || strcmp(command,TEXTBOOK_2)==0) {
      setTextbookData();
    }
    else if (strcmp(command,DUMP_1)==0 || strcmp(command,DUMP_2)==0) {
      printPageTable();
    }    
    else if (strcmp(command,VERBOSE_ON)==0) {
      isVerbose = true;
    }
    else if (strcmp(command,VERBOSE_OFF)==0) {
      isVerbose = false;
    }
    else if (strcmp(command,QUIT_1)==0 || 
             strcmp(command,QUIT_2)==0 ||
             feof(stdin)) {
      isTerminated = true;
    }
    else {
      printf("[ERROR] Invalid input. Enter help (or ?).\n");
    }
  }

  // Return 0 to indicate success.
  regfree(&DECODE_REGEX);
  return 0;
}

void printHelp() {
  printf("[HELP] VIRTUAL MEMORY SIMULATOR\n\n"
         "       COSC310: Operating Systems\n"
         "       Soobin Rho | March 27, 2023\n\n"
         "       Example:\n"
         "         decode 1998\n"
         "         decode 8\n"
         "         decode 22\n\n"
         "       List of commands:\n"
         "         decode [0-9]\n"
         "         %s"
         "         %s"
         "         %s"
         "         %s"
         "         %s"
         "         %s"
         "         %s"
         "         %s"
         "         %s\n",
         QUIT_1,
         QUIT_2,
         HELP_1,
         HELP_2,
         TEXTBOOK_1,
         DUMP_1,
         DUMP_2,
         VERBOSE_ON,
         VERBOSE_OFF);
}

void setTextbookData() {

}

void printPageTable() {

}

void setVerbose(bool onOrOff) {

}

int MMU(int virtAddr, bool isVerbose) {
  /*
   *   A function that simulates an MMU (Memory Management Unit).
   *
   *   WHAT'S THE PURPOSE OF AN MMU?
   *   Having a virtual memory allows us to use more memory than
   *   the actual amount of physical memory we have. Also, it
   *   solves many problems that are really useful for us.
   *
   *   Here, what MMU does is to orchestrate the mappings of
   *   virtual addresses to physical addresses. Since storing
   *   the mapping of every individual address requires too much
   *   storage, MMU instead uses what's called pages, which are
   *   basically a group of memory addresses instead of just one
   *   memory address. The exact size of a page is system
   *   dependent, but is almost always 4096 bytes.
   *
   *   Virtual addresses are grouped into pages. Physical addresses
   *   are grouped into pages frames. The exact mechanism of how
   *   an MMU maps each page into a page frame depends on both
   *   the hardware and the OS, specifically the fetch policy,
   *   placement policy, and replacement policy.
   *   
   *   My MMU simulator in this lab, however, uses the simplest
   *   possible form of fetch / placement / replacement policies
   *   for learning purposes. This, therefore, will perform much
   *   less efficiently compared to those in Linux or Windows.
   *
   *   Source:
   *     https://gustavus.edu/mcs/max/os-book/
   */

  // Input validation.
  if (virtAddr>SIZE_VIRT_ADDRESS || virtAddr<0) {
    return -1;
  }

  const int page = virtAddr/SIZE_PAGE;
  const int offset = virtAddr%SIZE_PAGE;

  // ------------------------------------------------------------------ 
  // 1. Check if the page already has a mapping or not.
  //
  //    POSSIBILITY A (Page Hit)
  //    - The page already has a mapping. In this case, look up and
  //      return the corresponding physical memory address.
  //
  //    POSSIBILITY B (Page Fault)
  //    - The page doesn't have a mapping, yet. Traverse through every
  //      page frame and see if there's any page frame that is not
  //      already holding a page. If yes, assign that one. If not,
  //      find the oldest page frame; evict it; and replace it.
  // ------------------------------------------------------------------ 
  int physAddr;

  // POSSIBILITY A (Page Hit)
  if (pageTable.pages_mapsTo[page]!=-1) {
    physAddr = _getPhysAddr_pageHit(virtAddr,page,offset,isVerbose);
  }

  // POSSIBILITY B (Page Fault)
  else {
    physAddr = _getPhysAddr_pageFault(virtAddr,page,offset,isVerbose);
  }

  return physAddr;
}

int _getPhysAddr_pageHit(int virtAddr, int page, int offset, bool isVerbose) {
  const int pageFrame = pageTable.pages_mapsTo[page];
  const int physAddr = pageFrame*SIZE_PAGE+offset;

  // If someone requests a decode on this page twice, it should be
  // marked as modified and written to disk -- as per lab instructions.
  // Since a page hit means that it's at least the second time
  // being used, the pageHit function always marks the page as modified.
  pageTable.pages_isModified[page] = 1;
  ++pageTable.pageFrames_refCount[pageFrame];
  if (isVerbose) {
    printf("\n[INFO] Dirty page frame detected. Successfully written to disk.\n"
           "       virtAddr = page*pageSize+offset = %d*%d+%d\n"
           "       physAddr = pageFrame*pageSize+offset = %d*%d+%d\n"
           "       refCount = %d\n",
           page,
           SIZE_PAGE,
           offset,
           pageFrame,
           SIZE_PAGE,
           offset,
           pageTable.pageFrames_refCount[pageFrame]);
  }

  return physAddr;
}

int _getPhysAddr_pageFault(int virtAddr, int page, int offset, bool isVerbose) {
  /*
   *   A page fault can occur in two scenarios.
   *
   *   POSSIBILITY A
   *   - All page frames are occupied. One of them, therefore, needs to
   *     be replaced.
   *
   *   POSSIBILITY B
   *   - There's one or more free page frame.
   */

  bool isEveryPageFrameOccupied = true;
  for (int i=0;i<NUM_VIRT;++i) {
    if (pageTable.pageFrames_isFilled[i]==0) {
      isEveryPageFrameOccupied = false;
      break;
    }
  }

  // POSSIBILITY A
  if (isEveryPageFrameOccupied) {
    // In this lab, I use First-In-First-Out (FIFO) replacement policy.
    // When a new page needs a page frame, the oldest page frame needs
    // to be evicted. For this, it's necessary to record the order
    // in which each page frame has been assigned.
    int currentOrder = -1;
    for (int i=0;i<NUM_PHYS;++i) {
      const int order = pageTable.pageFrames_order[i];
      if (order>currentOrder) currentOrder = order;
    }
    pageTable.pageFrames_order[page] = currentOrder+1;
    pageTable.pageFrames_isFilled[page] = 1;

  }

  // POSSIBILITY B
  else {

  }

  // WHEN NEW PAGE FRAME IS ASSIGNED
  // 1. Add 1 to pageFrames_refCount[pageFrame]
  // 2. Set pages_isModified[page] to 0
  // 3. Set pageFrames_isFilled[pageFrame] to 1

  // WHEN A PAGE IS EVICTED FROM A PAGE FRAME
  // 1. Update entire pageFrames_order
  // 2. Set pages_mapsTo[evictedPage] to -1
  // 3. Set pages_isModified[evictedPage] to 0
  // 4. Set pageFrames_refCount[pageFrame] to 1

  // To find a free


  return 0;
}

