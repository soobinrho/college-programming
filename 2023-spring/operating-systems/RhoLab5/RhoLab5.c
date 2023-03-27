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
int MMU(int virtAddr, bool isVerbose);
int _getPhysAddr_pageHit(int virtAddr, int page, int offset, bool isVerbose);
int _getPhysAddr_pageFault(int virtAddr, int page, int offset, bool isVerbose);
void _printGetPhysAddr(int page, int offset, int pageFrame, bool isDirty);

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
        printf("[RESULT] %d --> %d\n\n",virtAddr,physAddr);
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
  // The textbook data is hard-coded, as instructed.
  pageTable.pages_mapsTo[0] = 2;
  pageTable.pages_isModified[0] = 0;

  pageTable.pages_mapsTo[1] = 1;
  pageTable.pages_isModified[1] = 0;

  pageTable.pages_mapsTo[2] = 6;
  pageTable.pages_isModified[2] = 0;

  pageTable.pages_mapsTo[3] = 0;
  pageTable.pages_isModified[3] = 0;

  pageTable.pages_mapsTo[4] = 4;
  pageTable.pages_isModified[4] = 0;

  pageTable.pages_mapsTo[5] = 3;
  pageTable.pages_isModified[5] = 0;

  pageTable.pages_mapsTo[6] = -1;
  pageTable.pages_isModified[6] = 0;

  pageTable.pages_mapsTo[7] = -1;
  pageTable.pages_isModified[7] = 0;

  pageTable.pages_mapsTo[8] = -1;
  pageTable.pages_isModified[8] = 0;

  pageTable.pages_mapsTo[9] = 5;
  pageTable.pages_isModified[9] = 0;

  pageTable.pages_mapsTo[10] = -1;
  pageTable.pages_isModified[10] = 0;

  pageTable.pages_mapsTo[11] = 7;
  pageTable.pages_isModified[11] = 0;

  pageTable.pages_mapsTo[12] = -1;
  pageTable.pages_isModified[12] = 0;

  pageTable.pages_mapsTo[13] = -1;
  pageTable.pages_isModified[13] = 0;

  pageTable.pages_mapsTo[14] = -1;
  pageTable.pages_isModified[14] = 0;

  pageTable.pages_mapsTo[15] = -1;
  pageTable.pages_isModified[15] = 0;

  pageTable.pageFrames_isFilled[0] = 1;
  pageTable.pageFrames_refCount[0] = 0;
  pageTable.pageFrames_order[0] = 0;

  pageTable.pageFrames_isFilled[1] = 1;
  pageTable.pageFrames_refCount[1] = 0;
  pageTable.pageFrames_order[1] = 1;

  pageTable.pageFrames_isFilled[2] = 1;
  pageTable.pageFrames_refCount[2] = 0;
  pageTable.pageFrames_order[2] = 2;

  pageTable.pageFrames_isFilled[3] = 1;
  pageTable.pageFrames_refCount[3] = 0;
  pageTable.pageFrames_order[3] = 3;

  pageTable.pageFrames_isFilled[4] = 1;
  pageTable.pageFrames_refCount[4] = 0;
  pageTable.pageFrames_order[4] = 4;

  pageTable.pageFrames_isFilled[5] = 1;
  pageTable.pageFrames_refCount[5] = 0;
  pageTable.pageFrames_order[5] = 5;

  pageTable.pageFrames_isFilled[6] = 1;
  pageTable.pageFrames_refCount[6] = 0;
  pageTable.pageFrames_order[6] = 6;

  pageTable.pageFrames_isFilled[7] = 1;
  pageTable.pageFrames_refCount[7] = 0;
  pageTable.pageFrames_order[7] = 7;
}

void printPageTable() {
  printf("\n    page  mapsTo     pageFrame  refcount\n");
  for (int i=NUM_VIRT-1;i>=0;--i) {

    // Print the virtual memory's pages.
    printf("%8d%8d     ",i,pageTable.pages_mapsTo[i]);

    // Print the physical memory's page frames.
    if(i<NUM_PHYS) {
      printf("%9d%10d\n",i,pageTable.pageFrames_refCount[i]);
    } else printf("\n");
  }

  // Print a newline for better readability.
  printf("\n");
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
  // Check if the page already has a mapping or not.
  //
  // POSSIBILITY A (Page Hit)
  // - The page already has a mapping. In this case, look up and
  //   return the corresponding physical memory address.
  //
  // POSSIBILITY B (Page Fault)
  // - The page doesn't have a mapping, yet. Traverse through every
  //   page frame and see if there's any page frame that is not
  //   already holding a page. If yes, assign that one. If not,
  //   find the oldest page frame; evict it; and replace it.
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
    printf("\n\n[INFO] Page Hit!\n");
    _printGetPhysAddr(page,offset,pageFrame,true);
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

  int physAddr;

  // When a new page needs a page frame, but if all page frames
  // are occupied, one of the page frames needs to be replaced.
  // In this lab, I use First-In-First-Out (FIFO) replacement policy.
  // For this, it's necessary to record the order
  // in which each page frame has been assigned.
  int currentOrder = -1;
  int evictCandidate = -1;
  for (int i=0;i<NUM_PHYS;++i) {
    const int order = pageTable.pageFrames_order[i];
    if (order>currentOrder) currentOrder = order;
    if (order==0) evictCandidate = i;
  }

  // Check if there's any available page frame.
  bool isEveryPageFrameOccupied = true;
  int pageFrame_available = -1;
  for (int i=0;i<NUM_PHYS;++i) {
    if (pageTable.pageFrames_isFilled[i]==0) {
      isEveryPageFrameOccupied = false;
      pageFrame_available = i;
      break;
    }
  }

  // POSSIBILITY A (No page frame available)
  if (isEveryPageFrameOccupied) {

    // Find which page should be evicted.
    int evictedPage;
    for (int i=0;i<NUM_VIRT;++i) {
      if (pageTable.pages_mapsTo[i]==evictCandidate) {
        evictedPage = i;
      }
    }

    // Evict the page from the page frame.
    pageTable.pages_mapsTo[evictedPage] = -1;
    pageTable.pages_isModified[evictedPage] = 0;
    pageTable.pageFrames_isFilled[evictCandidate] = 0;
    pageFrame_available = evictCandidate;

    // As a result of the eviction, the order list needs to be updated.
    for (int i=0;i<NUM_PHYS;++i) {
      --pageTable.pageFrames_order[i];
    }

    // Give the newly freed page frame to the new page.
    pageTable.pages_mapsTo[page] = evictCandidate;
    pageTable.pages_isModified[page] = 0;
    pageTable.pageFrames_isFilled[evictCandidate] = 1;
    pageTable.pageFrames_refCount[evictCandidate] = 1;
    pageTable.pageFrames_order[evictCandidate] = currentOrder;
  }

  // POSSIBILITY B (At least one page frame available)
  else {
    pageTable.pages_mapsTo[page] = pageFrame_available;
    pageTable.pageFrames_isFilled[pageFrame_available] = 1;
    pageTable.pageFrames_refCount[pageFrame_available] = 1;
    pageTable.pageFrames_order[pageFrame_available] = currentOrder+1;
  }

  physAddr = pageFrame_available*SIZE_PAGE+offset;

  if (isVerbose) {
    printf("\n\n[INFO] Page Fault!\n");
    _printGetPhysAddr(page,offset,pageFrame_available,false);
  }

  return physAddr;
}

void _printGetPhysAddr(int page, int offset, int pageFrame, bool isDirty) {
  if (isDirty) {
    printf("[INFO] Dirty page frame detected. Successfully written to disk.\n");
  }

  printf("[INFO] virtAddr = page*pageSize+offset = %d*%d+%d\n"
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

