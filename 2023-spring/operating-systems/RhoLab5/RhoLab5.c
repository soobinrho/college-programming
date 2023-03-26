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

int main() {

  // These are all accepted commands from user input.
  char HELP_1[] = "help\n";
  char HELP_2[] = "?\n";
  char QUIT_1[] = "quit\n";
  char QUIT_2[] = "q\n";
  char TEXTBOOK_1[] = "textbook\n";
  char TEXTBOOK_2[] = "textbook\n";
  char VERBOSE_ON[] = "verbose_on\n";
  char VERBOSE_OFF[] = "verbose_off\n";
  char DUMP[] = "dump\n";

  // The match array has two member because matches[0] is always
  // the entire match, while matches[1] is the first subgroup.
  // Since the DECODE regex has one subgroup - i.e. `([:digit:]+)` -
  // SIZE_GROUPS must be 1 entire match + 1 subgroup = 2.
  size_t SIZE_GROUPS = 2;
  regmatch_t matches[SIZE_GROUPS];
  regex_t DECODE_REGEX;
  // int status = regcomp(&DECODE_REGEX,"decode[:space:]*([:digit:]*)",0);
  (void) regcomp(&DECODE_REGEX,"^decode ([0-9]+)",REG_EXTENDED);

  // ------------------------------------------------------------------
  // Get user input.
  // ------------------------------------------------------------------
  size_t commandLength = 0;
  char *command = NULL;
  bool isTerminated = false;
  while (!isTerminated) {

    // getline is better than scanf in this situation because getline protects
    // against the buffer overflow, if the input is longer than
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
      printf("HELP FUNCTION\n");
    }
    else if (strcmp(command,TEXTBOOK_1)==0 || strcmp(command,TEXTBOOK_2)==0) {
      printf("TEXTBOOK FUNCTION\n");
    }
    else if (strcmp(command,VERBOSE_ON)==0) {
      printf("VERBOSE_ON FUNCTION\n");
    }
    else if (strcmp(command,VERBOSE_OFF)==0) {
      printf("VERBOSE_OFF FUNCTION\n");
    }
    else if (strcmp(command,DUMP)==0) {
      printf("DUMP FUNCTION\n");
    }    
    else if (regexec(&DECODE_REGEX,command,SIZE_GROUPS,matches,0)==0) {
      printf("DECODE FUNCTION with matches[1]\n");
      char *match = command+matches[1].rm_so;
      printf("SUBGROUP: %s\n",match);
    }
    else {
      printf("[ERROR] Invalid input. Enter help (or ?).\n");
    }
  }

  // Return 0 to indicate success.
  regfree(&DECODE_REGEX);
  return 0;
}


