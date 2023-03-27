/*
 *    COSC 310: Operating Systems
 *    Soobin Rho
 *    March 25, 2022
 *    Lab 5: Virtual Memory Simulator
 */ 

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>  // Required for REG_EXTENDED
#include <regex.h>

// --------------------------------------------------------------------
// Initialize the page table. It contains every virtual memory page,
// physical memory page frame, and all of their mappings.
// --------------------------------------------------------------------
#define SIZE_VIRT_ADDRESS 65536  // 2^16 bytes as instructed
#define SIZE_PHYS_ADDRESS 32768  // 2^15 bytes as instructed
#define SIZE_PAGE 4096           // 2^12 bytes as instructed

#define NUM_VIRT_ADDRESS SIZE_VIRT_ADDRESS/SIZE_PAGE  // 16 in this case
#define NUM_PHYS_ADDRESS SIZE_PHYS_ADDRESS/SIZE_PAGE  //  8 in this case

typedef struct PageTable {
  int pages_mapsTo[NUM_VIRT_ADDRESS];
  int pages_isModified[NUM_VIRT_ADDRESS];
  int pageFrames_isFilled[NUM_PHYS_ADDRESS];
  int pageFrames_order[NUM_PHYS_ADDRESS];
} PageTable;

PageTable pageTable = {.pages_mapsTo = {[0 ... NUM_VIRT_ADDRESS-1]=-1},
                       .pages_isModified = {[0 ... NUM_VIRT_ADDRESS-1]=0},
                       .pageFrames_isFilled = {[0 ... NUM_PHYS_ADDRESS-1]=0},
                       .pageFrames_order = {[0 ... NUM_PHYS_ADDRESS-1]=-1}};

void printHelp();
void setTextbookData();
void printPageTable();
void setVerbose(bool onOrOff);
int MMU(int virtAddr, bool isVerbose);

int main() {


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

  bool isVerbose = false;

  // The match array has two member because matches[0] is always
  // the entire match, while matches[1] is the first subgroup.
  // Since the DECODE regex has one subgroup - i.e. `([:digit:]+)` -
  // SIZE_GROUPS must be 1 entire match + 1 subgroup = 2.
  size_t SIZE_GROUPS = 2;
  regmatch_t matches[SIZE_GROUPS];
  regex_t DECODE_REGEX;
  (void) regcomp(&DECODE_REGEX,"^decode ([0-9]+)",REG_EXTENDED);

  // ------------------------------------------------------------------
  // Get user input.
  // ------------------------------------------------------------------
  size_t commandLength = 0;
  char *command = NULL;
  bool isTerminated = false;
  while (!isTerminated) {

    // getline is better than scanf in this situation because getline
    // protects against the buffer overflow, if the input is longer than
    // the allocated size, which happens to be 12 in this case because
    // the longest possible command is `help (or ?)`, which consists of
    // 11 characters + 1 null character (\0).
    printf("Enter a command: ");
    getline(&command,&commandLength,stdin);

    // -----------------------------------------------------------------
    // Execute commands depending on the user input.
    // -----------------------------------------------------------------
    if (regexec(&DECODE_REGEX,command,SIZE_GROUPS,matches,0)==0) {
      // -----------------------------------------------------------------
      // Get the physical address.
      // -----------------------------------------------------------------
      char *virtAddr = command+matches[1].rm_so;
      int physAddr = MMU(*virtAddr,isVerbose);
      if (physAddr!=-1) {
        printf("[RESULT] %d --> %d\n",*virtAddr,physAddr);
      }
      else {
        printf("[ERROR] The maximum value is %d\n",SIZE_VIRT_ADDRESS);
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
  
  return 0;
}

int _getPageFaultPlacement(int virtAddr) {
  // first in, first out replacement (FIFO) policy

  return 0;
}

int _getPhysicalPlacement(int virtAddr) {

  return 0;
}
