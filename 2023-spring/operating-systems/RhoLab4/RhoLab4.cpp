// --------------------------------------------------------------- //
// Soobin Rho
// March 15, 2023
// COSC 310: Operating Systems
// Lab 4: Deadlock Detection Algorithm
// --------------------------------------------------------------- //

#include <unordered_map>
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
  bool isChecked;
  vector<char> forward;
  ResourceTree (char idInput) : id(idInput) {isChecked = false;}
  ~ResourceTree () {}
};

// WHY?
// Normally, I would just make the ResourceTree struct to be
// a linked list where it points to another instance of itself,
// but the problem was that a node can point to multiple nodes
// instead of just one. So, I decided to use a vector inside
// the ResourceTree and make another wholeTree to compensate
// for the lack of the regular linked list structure.
//
// At the same time, I hate creating a data structure on the
// global space. I know there must be better ways, but it's
// just that this is the best I could come up with
// in the limited time I have now -- it's 3:22AM 😎
unordered_map<char,unique_ptr<ResourceTree>> wholeTree;

char isDeadlock (char, char, char, vector<char>&);

void printTables(const set<char>&, const set<char>&);

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

    // POSSIBILITY A:
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

      // Add the resource node to the tree.
      if (wholeTree.count(resourceID)==0) {
        wholeTree[resourceID] = make_unique<ResourceTree>(resourceID);
      }
    }

    // POSSIBILITY B:
    // If the operator is <, it means a resource is held by a thread.
    // Thus, set the resource's forward to that thread.
    else if (op=='<') {
      if (wholeTree.count(resourceID)) {
        wholeTree[resourceID]->forward.push_back(threadID);
      }

      else {
        wholeTree[resourceID] = make_unique<ResourceTree>(resourceID);
        wholeTree[resourceID]->forward.push_back(threadID);
      }

      // Add the thread node to the tree.
      if (wholeTree.count(threadID)==0) {
        wholeTree[threadID] = make_unique<ResourceTree>(threadID);
      }
    }

    resourcesList.insert(resourceID);
    threadsList.insert(threadID);
  }  // while (getline(...))

  // ----------------------------------------- //
  // 2. Loop through every node.
  // ----------------------------------------- //
  vector<char> nodes;
  for (const char& resourceID: resourcesList) {
    nodes.push_back(resourceID);
  }
  for (const char& threadID: threadsList) {
    nodes.push_back(threadID);
  }

  cout<<"\n\n\n[INFO] Traversing through every node of the resource tree...\n";
  int subtreesCount = 0;
  for (int indexNodes=0;indexNodes<nodes.size();++indexNodes) {
    vector<char> traverseList;
    const char ID = nodes[indexNodes];

    // No need to traverse through every node. Check if it's the kind of a node
    // that requires checking.
    if (wholeTree[ID]->forward.size()>0 && wholeTree[ID]->isChecked==false) {
      cout<<"SUBTREE["<<subtreesCount<<"] ";

      // ----------------------------------------- //
      // 3. Check for any deadlock.
      // ----------------------------------------- //
      char result = isDeadlock(ID,' ',ID,traverseList);
      if (result=='1') {
        printTables(threadsList,resourcesList);

        // Print the sub tree where the deadlock occurs.
        cout<<"\n[RESULT] traverseList = ";
        for (const char& deadlockMemeber: traverseList) {
          cout<<deadlockMemeber<<' ';
        }
        cout<<"\n[RESULT] A deadlock has been detected.\n";

        return 0;
      }
      cout<<"|\n";
      ++subtreesCount;
    }
  }

  // If the program has come this far, it means all checks passed.
  // There's no deadlock.
  printTables(threadsList,resourcesList);
  cout<<"\n[RESULT] The resource tree doesn't have any deadlock.\n";

  return 0;
}

char isDeadlock (char ID,
                 char IDPrevious,
                 char IDRoot,
                 vector<char>& traverseList) {

  cout<<"| Node "<<ID<<' ';

  // -------------------------------------------------------------------- //
  // When a deadlock is detected, this function returns '1'.
  // This is possible because we know all ID's are either [a-z] or [A-Z].
  // Numbers are reserved for this purpose:
  //
  // THIS FUNCTION'S RETURN VALUES:
  //   '1': Deadlock detected.
  //   '0': No deadlock detected.
  // -------------------------------------------------------------------- //

  if (std::find(traverseList.begin(),
                traverseList.end(),
                ID)!=traverseList.end() || ID=='1') {
    traverseList.push_back(ID);
    return '1';
  }
  else if (ID=='0') return 0;

  traverseList.push_back(ID);

  const int arcsSize = wholeTree[ID]->forward.size();
  for (int i=0;i<arcsSize;++i) {
    const char IDDeeper = wholeTree[ID]->forward[i];
    if (wholeTree[IDDeeper]->isChecked==false) {
      const char result = isDeadlock(IDDeeper,ID,IDRoot,traverseList);
      wholeTree[IDDeeper]->isChecked = true;
      if (result=='1') return '1';
    }
  }

  return '0';
}

void printTables(const set<char>& threadsList,
                 const set<char>& resourcesList) {

  // UNCOMMENT TO SEE threadsList and resourcesList:
  // cout<<"\n\n// ====================\n"
  //     <<"// [RESULT] threadsList\n"
  //     <<"// ====================\n";
  // for (const char& ID: threadsList) {
  //   cout<<"ID = "<<ID<<'\n';
  // }
  //
  // cout<<"\n// ====================== //\n"
  //     <<"// [RESULT] resourcesList\n"
  //     <<"// ====================== //\n";
  // for (const char& ID: resourcesList) {
  //   cout<<"ID = "<<ID<<'\n';
  // }

  cout<<"\n\n\n// ==================\n"
      <<"// [RESULT] wholeTree\n"
      <<"// ==================\n";
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
