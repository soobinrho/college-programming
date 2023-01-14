#define CATCH_CONFIG_MAIN
#include "catch2/catch_amalgamated.hpp"

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace {
  vector<int> getSorted(const vector<int>& inputArr) {
    /*
     *   Sort a vector and at the same time keep track of the index.
     *   This function (a) sorts based on how many 1's there are in
     *   the binary version of the number and (b) if two or more
     *   numbers have the same number of 1's sort again
     *   based on the original decimal number.
     */

    // ------------------------------------------------------------------
    // 1. Count how many 1's are in the binary version of the number
    // ------------------------------------------------------------------
    vector<int> onesArr (inputArr.size(),0);
    for (int i=0; i<inputArr.size(); ++i) {
      string memberString = to_string(inputArr[i]);
      for (const char& character: memberString) {
        if (character=='1') ++onesArr[i];
      }
    }

    // ------------------------------------------------------------------
    // 2. Sort the original array based on how many 1's
    // ------------------------------------------------------------------
    vector<int> notSortedOnesArr;
    copy(onesArr.begin(),onesArr.end(),notSortedOnesArr);

    // First, sort by "how many 1's".
    // Note that the sort algorithm sorts in the ascending order.
    // For descending order, use:
    //   sort(numbers.begin(), numbers.end(), std::greater<int>());
    sort(onesArr.begin(),onesArr.end());

    vector<int> sorted;
    vector<bool> isAssigned (inputArr.size(),false);
    for (int i=0; i<inputArr.size(); ++i) {
      
    }

    // ------------------------------------------------------------------
    // 3. Most of the values in the array will stay the same,
    //    but if two or more values have the same "how many 1's" value,
    //    then these values should be sorted again based on their
    //    original decimal numbers.
    // ------------------------------------------------------------------



    return inputArr;
  }
}

TEST_CASE("Keeping Track of the Index While Sorting","[core]") {
  SECTION("Testing correct cases") {
    vector<int> inputArr_1 {0, 111, 111, 111, 111};
    vector<int> answerArr_1 {0, 111, 111, 111, 111};
    CHECK(getSorted(inputArr_1)==answerArr_1);

    vector<int> inputArr_2 {1111, 111, 111, 1, 0};
    vector<int> answerArr_2 {0, 1, 111, 111, 1111};
    CHECK(getSorted(inputArr_2)==answerArr_2);

    vector<int> inputArr_3 {1111, 111, 111, 1, 0};
    vector<int> answerArr_3 {0, 1, 111, 111, 1111};
    CHECK(getSorted(inputArr_3)==answerArr_3);
  }
}
