// --------------------------------------------------------------- //
// Soobin Rho
// March 15, 2023
// COSC 310: Operating Systems
// Lab 4: Deadlock Detection Algorithm
// --------------------------------------------------------------- //

#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main () {
  /*
   *   DEADLOCK DETECTION ALGORITHM
   *   An algorithm that reads a resource tree and then determines
   *   if it has a deadlock or not. The resource tree consists
   *   of three components: source id, destination id, and an operator.
   *
   *   Example input:
   *   A>B
   *   C<B
   *   C>D
   *   E<D
   *   E>A
   */

  // Here, I use a raw string literal.
  // Raw string literal starts with R"( and ends with )"
  smatch matches;
  string patternValid = R"(^\s*([a-z]))"        // e.g. a
                         R"(\s*(<|>))"           // e.g. <
                         R"(\s*([A-Z])\s*$)";    // e.g. Z

  cout<<"DEADLOCK DETECTION ALGORITHM\n"
      <<"Input Example:\n"
      <<"  a<Z\n"
      <<"  a>X\n"
      <<"  b<X\n\n"
      <<"Enter: ";
  string inputStr;
  while (getline(cin,inputStr)) {

    // ----------------------------------------- //
    // 1. Get user input
    // ----------------------------------------- //
    bool isValid = regex_match(inputStr,matches,regex(patternValid));

    // If the input contains any invalid value, exit with error code.
    if (!is_valid) {
      cout<<"[ERROR] Invalid input.";
      return 1;
    }

    // ----------------------------------------- //
    // Structure of matches:
    // matches[0] -> the whole match
    // matches[1] -> threadID      (e.g. a)
    // matches[2] -> operator      (e.g. <)
    // matches[3] -> resourceID    (e.g. Z)
    // ----------------------------------------- //
    const char threadID = matches[1].str()[0];
    const char operator = matches[2].str()[0];
    const char resourceID = matches[3].str()[0];

    // . I thought it was best to abstract these data as a linked list.



    // Behavior of this data structure:
    // - By nodes, I mean either a resource or a thread.
    // - Nodes can only point to only one node.
    //   To be exact, they can point to either 1 node or no node at all.
    // - Although nodes can point to only one another node,
    //   multiple nodes can point to one node at the same time.

  
    // . Keep track of the current list L as an unordered map.


    // Print the progress.


    // Reset the list L because these nodes don't have a deadlock.


    // . Exit because a deadlock has been found.


  return 0;
}
