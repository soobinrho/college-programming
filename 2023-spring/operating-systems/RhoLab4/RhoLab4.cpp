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
#include <unordered_map>

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
  vector<char> forward;
  ResourceTree (char idInput) : id(idInput) {}
  ~ResourceTree () {}
};

  /*
   *   A recursive function to traverse the ResourceTree
   *   and ... This function must somehow store the root
   *   as well as the previous node.
   */

void printDebugs(const set<char>&,
                 const set<char>&,
                 unordered_map<char,unique_ptr<ResourceTree>>&);

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
  unordered_map<char,unique_ptr<ResourceTree>> wholeTree;
  while (getline(cin,inputStr)) {

    // ----------------------------------------- //
    // 1. Get user input.
    // ----------------------------------------- //
    bool isValid = regex_match(inputStr,matches,regex(patternValid));

    // Check if the input contains any invalid value.
    if (!isValid) {
      throw std::invalid_argument("[ERROR] Invalid input!");
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
    // Thus, set the thread's forward to that resource.
    if (op=='>') {
      if (wholeTree.count(threadID)) {
        wholeTree[threadID]->forward.push_back(resourceID);
      }
      else {
        wholeTree[threadID] = make_unique<ResourceTree>(threadID);
        wholeTree[threadID]->forward.push_back(resourceID);
      }
    }

    // Possibility B:
    // If the operator is <, it means a resource is held by a thread.
    // Thus, set the resource's forward to that thread.
    else if (op=='<') {
      if (wholeTree.count(resourceID)) {
        throw invalid_argument("[ERROR] A resouce can be held by only one thread.");
      }
      else {
        wholeTree[resourceID] = make_unique<ResourceTree>(resourceID);
        wholeTree[resourceID]->forward.push_back(threadID);
      }
    }

    resourcesList.insert(resourceID);
    threadsList.insert(threadID);
  }  // while (getline(...))


  // ----------------------------------------- //
  // 2. Loop through every node.
  // ----------------------------------------- //
  vector<char> nodes;
  for (const char& ID: resourcesList) {
    if (resourcesList.count(ID)) nodes.push_back(ID);
  }
  for (const char& ID: threadsList) {
    if (threadsList.count(ID)) nodes.push_back(ID);
  }

  cout<<"\n[INFO] Traversing through every node of the resource tree:\n";

  // This unordered map marks whether or not a node has been checked.
  //   Key: the ID of the node
  //   Value: 1 (if that node is checked) || 0 (if not)
  unordered_map<char,bool> isChecked;
  for (int i=0;i<nodes.size();++i) {
    

    // Print the progress.


    // Reset the list L because these nodes don't have a deadlock.


    // . Exit because a deadlock has been found.


  }

  printDebugs(threadsList,resourcesList,wholeTree);

  return 0;
}

void printDebugs(const set<char>& threadsList,
                 const set<char>& resourcesList,
                 unordered_map<char,unique_ptr<ResourceTree>>& wholeTree) {
  cout<<"\n\n// ------------------ //\n"
      <<"// DEBUG: threadsList\n"
      <<"// ------------------ //\n";
  for (const char& ID: threadsList) {
    cout<<"ID="<<ID<<'\n';
  }

  cout<<"\n// -------------------- //\n"
      <<"// DEBUG: resourcesList\n"
      <<"// -------------------- //\n";
  for (const char& ID: resourcesList) {
    cout<<"ID="<<ID<<'\n';
  }

  cout<<"\n// ---------------- //\n"
      <<"// DEBUG: wholeTree\n"
      <<"// ---------------- //\n";
  for (const char& ID: threadsList) {
    if (wholeTree.count(ID)) {
      cout<<"wholeTree[ID]->ID = "<<ID<<" | ->forward = ";
      const vector<char> forwardList = wholeTree[ID]->forward;
      for (int i=0;i<forwardList.size();++i) {
        cout<<forwardList[i]<<' ';
      }
      cout<<'\n';
    }
  }
  for (const char& ID: resourcesList) {
    if (wholeTree.count(ID)) {
      cout<<"wholeTree[ID]->ID = "<<ID<<" | ->forward = ";
      const vector<char> forwardList = wholeTree[ID]->forward;
      for (int i=0;i<forwardList.size();++i) {
        cout<<forwardList[i]<<' ';
      }
      cout<<'\n';
    }
  }
}
