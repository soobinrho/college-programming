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
const int SIZE_VIRT_ADDRESS = 65536;  // 2^16 as instructed
const int SIZE_PHYS_ADDRESS = 32768;  // 2^15 as instructed
const int SIZE_PAGE = 4096;           // 2^12 as instructed

struct PageTable {
  static const int NUM_VIRT_ADDRESS = SIZE_VIRT_ADDRESS/SIZE_PAGE;  // = 16
  static const int NUM_PAGE_ADDRESS = SIZE_PHYS_ADDRESS/SIZE_PAGE;  // =  8
  int pages[NUM_VIRT_ADDRESS];
  int pageTables[NUM_PAGE_ADDRESS];
};

void printHelp();
void setTextbookData();
void printPageTable();
void setVerbose(bool onOrOff);
int MMU(int virtAddr, bool isVerbose);

int main() {
  // These are all accepted commands from user input.
  char QUIT_1[] = "quit\n";
  char QUIT_2[] = "q\n";
  char HELP_1[] = "help\n";
  char HELP_2[] = "?\n";
  char TEXTBOOK_1[] = "textbook\n";
  char TEXTBOOK_2[] = "Textbook\n";
  char DUMP_1[] = "dumpPageTable\n";
  char DUMP_2[] = "dump\n";
  char VERBOSE_ON[] = "verbose_on\n";
  char VERBOSE_OFF[] = "verbose_off\n";

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
    if (strcmp(command,QUIT_1)==0 || strcmp(command,QUIT_2)==0) {
      isTerminated = true;
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
    else if (regexec(&DECODE_REGEX,command,SIZE_GROUPS,matches,0)==0) {
      // -----------------------------------------------------------------
      // Get the physical address.
      // -----------------------------------------------------------------
      char *virtAddr = command+matches[1].rm_so;
      int physAddr = MMU(*virtAddr,isVerbose);
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
   *   WHAT'S THE PURPOSE OF MMU?
   *   Having a virtual memory allows us to use more memory than
   *   the actual amount of physical memory we have. Also, it
   *   solves many problems for us, such as 
   *   
   *   
   *   
   *   
   *   
   *   
   *   
   *   
   *   
   *   
   *   Source:
   *     https://gustavus.edu/mcs/max/os-book/
   */

  // I gotta implement _getPageFaultReplacement(int virtAddr) somehow.
  // Also, _getPhysicalPlacement(int virtAddr)

  return 0;
}

int _getPageFaultReplacement(int virtAddr) {

  return 0;
}

int _getPhysicalPlacement(int virtAddr) {

  return 0;
}
