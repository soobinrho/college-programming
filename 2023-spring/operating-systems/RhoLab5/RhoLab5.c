/*
 *    COSC 310: Operating Systems
 *    Soobin Rho
 *    March 25, 2022
 *    Lab 5: Virtual Memory Simulator
 */ 

#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <regex.h>

int main() {

  char DUMP[] = "dump\n";
  char VERBOSE_ON[] = "verbose_on\n";
  char VERBOSE_OFF[] = "verbose_off\n";
  char TEXTBOOK[] = "textbook\n";
  char HELP_1[] = "help\n";
  char HELP_2[] = "?\n";
  char QUIT_1[] = "quit\n";
  char QUIT_2[] = "q\n";

  regex_t DECODE;
  (void) regcomp(&DECODE,"decode[:space:]+[:digit:]+",0);

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
    printf("INPUT: %s \n",command);
    if (strcmp(command,QUIT_1)==0 || strcmp(command,QUIT_2)==0) {
      isTerminated = true;
    }
    else if (strcmp(command,HELP_1)==0 || strcmp(command,HELP_2)==0) {
      printf("HELP FUNCTION");
    }
    else if (strcmp(command,VERBOSE_ON)==0) {
      printf("VERBOSE_ON FUNCTION");
    }
    else if (strcmp(command,VERBOSE_OFF)==0) {
      printf("VERBOSE_OFF FUNCTION");
    }


    else {
      printf("NOPE %d\n",strcmp(command,QUIT_1));
    }

  }


  return 0;
}


