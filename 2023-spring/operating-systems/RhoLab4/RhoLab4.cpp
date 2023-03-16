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
#include <set>

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

int findResourceTreeIndex(vector<unique_ptr<ResourceTree>>&, char);
void printDebugs(const set<char>&, const set<char>&);

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
      <<"* Note that the left hand side is a thread. It only accepts [a-z].\n"
      <<"  Likewise, the right hand side is a resource. It only accepts [A-Z].\n"
      <<"  As per the operator, it should either be < or >.\n"
      <<"* To exit, enter the EOF character. (Ctrl+D if you're on Linux.)\n\n"
      <<"Enter: ";
  string inputStr;
  set<char> threadsList;
  set<char> resourcesList;
  vector<unique_ptr<ResourceTree>> wholeTree;
  while (getline(cin,inputStr)) {

    // ----------------------------------------- //
    // 1. Get user input
    // ----------------------------------------- //
    bool isValid = regex_match(inputStr,matches,regex(patternValid));

    // If the input contains any invalid value, exit with error code.
    if (!isValid) {
      cout<<"[ERROR] Invalid input! | inputStr=\""<<inputStr<<"\"\n";
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
    // If the operator is >, it means a thread tries to get a resource.
    if (op=='>') {

      // ------------------------------------------------------------ //
      // Since a thread can request multiple resources, threads can
      // show up multiple times in an input. Therefore, check if
      // that particular threadID has shown up before.
      // ------------------------------------------------------------ //

      // If this threadID has already been registered:
      if (threadsList.count(threadID)) {
        // const int targetIndex = findResourceTreeIndex(wholeTree,threadID);
        // wholeTree[targetIndex]->forward.push_back(make_unique<ResourceTree>(resourceID));
      }

      // If this is the first occurrence of this threadID: 
      else {
        auto node = make_unique<ResourceTree>(threadID);
        node->forward.push_back(make_unique<ResourceTree>(resourceID));
        // wholeTree.push_back(node);
        threadsList.insert(threadID);
      }
    }

    // Possibility B:
    // If the operator is <, it means a resource is held by a thread.
    else if (op=='<') {

      // Since a resource cannot be held by more than one thread,
      // check for invalid user input.
      

      auto node = make_unique<ResourceTree>(resourceID);

      // If this threadID has already been registered:
      if (threadsList.count(threadID)) {

      }

      // If this is the first occurrence of this threadID: 
      else {
        node->forward.push_back(make_unique<ResourceTree>(threadID));
        threadsList.insert(threadID);
      }

      // wholeTree.push_back(node);
    }


  }  // while (getline(...))

    // . Keep track of the current list L as an unordered map.
    //     Key: the ID of the node
    //     Value: 1 (if that node is checked) || 0 (if not)


    // Print the progress.


    // Reset the list L because these nodes don't have a deadlock.


    // . Exit because a deadlock has been found.




  printDebugs(threadsList,resourcesList);

  return 0;
}

int findResourceTreeIndex(vector<unique_ptr<ResourceTree>>& wholeTree, char id) {
  for (int i=0;i<wholeTree.size();++i) {
    if (wholeTree[i]->id) return i;
  }
  
  // If no search result, give an error.
  throw std::invalid_argument("[ERROR] Invalid argument.");
}

void printDebugs(const set<char>& threadsList,
                 const set<char>& resourcesList) {
  cout<<"// ------------------ //\n"
      <<"// DEBUG: threadsList\n"
      <<"// ------------------ //\n";
  for (const char& id: threadsList) {
    cout<<"id="<<id<<'\n';
  }

  cout<<"// -------------------- //\n"
      <<"// DEBUG: resourcesList\n"
      <<"// -------------------- //\n";
  for (const char& id: resourcesList) {
    cout<<"id="<<id<<'\n';
  }

  // cout<<"// ---------------- //\n"
  //     <<"// DEBUG: wholeTree\n"
  //     <<"// ---------------- //\n";
  // for (int i=0;i<wholeTree.size();++i) {
  //   cout<<"wholetree[i]->id="<<wholeTree[i]->id<<' '<<wholeTree.size()<<'\n';
  // }
}
