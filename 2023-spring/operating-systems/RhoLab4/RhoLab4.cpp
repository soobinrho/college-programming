// --------------------------------------------------------------- //
// Soobin Rho
// March 15, 2023
// COSC 310: Operating Systems
// Lab 4: Deadlock Detection Algorithm
// --------------------------------------------------------------- //

#include <iostream>
#include <memory>  // Required for unique_ptr
#include <string>
#include <vector>
#include <regex>

using namespace std;

struct ResourceTree {
  /*
   *   I thought it was best to abstract these data as a linked list.
   *   Behavior of this data structure:
   *   - By nodes, I mean either a resource or a thread.
   *   - This data structure treats both the resource and the thread
   *     the same. Both are a node. Nevertheless, I need to remember
   *     that they have a fundamental difference. A thread can hold
   *     multiple resources, but not the other way around. A resource
   *     in this case - for learning purposes - can only be held by
   *     one thread.
   */
  char id;
  vector<unique_ptr<ResourceTree>> forward;
  ResourceTree (char idInput) : id(idInput) {}
  ~ResourceTree () {}
};

  /*
   *   A recursive function to traverse the ResourceTree
   *   and ... This function must somehow store the root
   *   as well as the previous node.
   */

int main () {
  /*
   *   DEADLOCK DETECTION ALGORITHM
   *   An algorithm that reads a resource tree and then determines
   *   if it has a deadlock or not. The resource tree consists
   *   of three components: <threadID> <operator> <resourceID>
   *
   *   Example:
   *     a<Z
   *     b>X
   *     c<X
   *     d
   *     e
   *
   *   - Note that resourceID is capitalized, while threadID is not.
   */

  // Here, I use a raw string literal.
  // Raw string literal starts with R"( and ends with )"
  smatch matches;
  string patternValid = R"(^\s*([a-z]))"      // e.g. a
                        R"(\s*(<|>))"         // e.g. <
                        R"(\s*([A-Z])\s*$)";  // e.g. Z

  cout<<"DEADLOCK DETECTION ALGORITHM\n"
      <<"Input Example:\n"
      <<"  a<Z\n"
      <<"  a>X\n"
      <<"  b<X\n\n"
      <<"Enter: ";
  string inputStr;
  vector<unique_ptr<ResourceTree>> wholeTree;
  while (getline(cin,inputStr)) {

    // ----------------------------------------- //
    // 1. Get user input
    // ----------------------------------------- //
    bool isValid = regex_match(inputStr,matches,regex(patternValid));

    // If the input contains any invalid value, exit with error code.
    if (!isValid) {
      cout<<"[ERROR] Invalid input.";
      return 1;
    }

    // ----------------------------------------- //
    // Structure of matches:
    // matches[0] -> the whole match
    // matches[1] -> threadID    (e.g. a)
    // matches[2] -> op          (e.g. <)
    // matches[3] -> resourceID  (e.g. Z)
    // ----------------------------------------- //
    const char threadID = matches[1].str()[0];
    const char op = matches[2].str()[0];
    const char resourceID = matches[3].str()[0];

    // Possibility A:
    // If the operator is <, it means a resource is held by a thread.
    if (op=='<') {
      auto node = make_unique<ResourceTree>(resourceID);
      node.forward.push_back(make_unique<ResourceTree>(threadID));
      wholeTree.push_back(node);
    }

    // Possibility B:
    // If the operator is >, it means a thread tries to get a resource.
    else {
      // Since a thread can request multiple resources, threads can show
      // up multiple times in an input. Therefore, check for it.
      if (

      auto node = make_unique<ResourceTree>(threadID);
      node.forward = make_unique<ResourceTree>(resourceID);
      wholeTree.push_back(node);
    }

  }  // while (getline(...))

    // . Keep track of the current list L as an unordered map.
    //     Key: the ID of the node
    //     Value: 1 (if that node is checked) || 0 (if not)


    // Print the progress.


    // Reset the list L because these nodes don't have a deadlock.


    // . Exit because a deadlock has been found.


  return 0;
}
