/*
 *   How to sort a vector twice. The tricky part of this is to remember
 *   the original index. What I just said here doesn't make a lot of
 *   sense, I know, but it will be more clear as I explain it below.
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> getSorted(const vector<int>& inputArray) {
  /*
   *   A function that (a) first sorts based on how many
   *   1's there are in a number and (b) if two or more
   *   numbers have the same number of 1's sort again
   *   based on the original decimal number.
   */

  // ------------------------------------------------------------------
  // 1. Count how many 1's are in a number
  // ------------------------------------------------------------------
  vector<int> onesArray (inputArray.size(),0);
  for (int i=0; i<inputArray.size(); ++i) {
    string memberString = to_string(inputArray[i]);
    for (const char& character: memberString) {
      if (character=='1') ++onesArray[i];
    }
  }

  // ------------------------------------------------------------------
  // 2. Sort the original array based on how many 1's
  // ------------------------------------------------------------------
  vector<int> notSortedOnesArray;
  copy(onesArray.begin(),onesArray.end(),notSortedOnesArray);

  // First, sort by "how many 1's".
  // Note that the sort algorithm sorts in the ascending order.
  // For descending order, use:
  //   sort(numbers.begin(), numbers.end(), std::greater<int>());
  sort(onesArray.begin(),onesArray.end());

  vector<int> sorted;
  vector<bool> isAssigned (inputArray.size(),false);
  for (int i=0; i<inputArray.size(); ++i) {
    
  }

  

  // ------------------------------------------------------------------
  // 3. Most of the values in the array will stay the same,
  //    but if two or more values have the same "how many 1's" value,
  //    then these values should be sorted again based on their
  //    original decimal numbers.
  // ------------------------------------------------------------------



  return inputArray;
}

int main() {
  /*
   *   Main driver
   */
  vector<int> inputArray {0, 111, 111, 111, 111};
  vector<int> sorted = getSorted(inputArray);

  for (const int member: sorted) cout<<member<<' ';
}
