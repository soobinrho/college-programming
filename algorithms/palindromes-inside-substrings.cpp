#define CATCH_CONFIG_MAIN
#include "catch2/catch_amalgamated.hpp"

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

namespace {
  string getNearbyPalindrome(const string& str,
                             int ptrLeft,
                             int ptrRight) {
    /*
     *   This is used by getLongestPalindrome function for finding
     *   a nearby palindrome given its left index (ptrLeft)
     *   and right index (ptrRight).
     */

    // Expand from the initial pointers and find how far the
    // palindrome goes.
    const int strLength = str.length();
    while (ptrLeft-1>=0 && ptrRight+1<strLength &&
           str[ptrLeft-1]==str[ptrRight+1]) {
      --ptrLeft;
      ++ptrRight;
      // DEBUG
      cout<<"[DEBUG] "<<str.substr(ptrLeft,ptrRight-ptrLeft+1)<<"\n";
    }

    const string localPalindrome = str.substr(ptrLeft,ptrRight-ptrLeft+1);

    return localPalindrome;
  }

  string getLongestPalindrome(string inputStr) {
    /*
     *   A function that finds the longest palindrome inside substrings.
     *   For example, an input of "abcdeffedcbabccba" first finds all
     *   palindromes including "abcdeffedcba" and "abccba". It then
     *   returns the longest of all. Also, if two palindromes have the
     *   same length, the function returns the one with the
     *   greater lexicographical value.
     */

    // TWO POSSIBILITIES FOR PALINDROMES
    // A. The character at the index is the same as the character at
    //    index+1.
    // B. The character at index-1 is the same as index+1.
    string longestPalindrome;
    const int strLength = inputStr.length();
    for (int i=0; i<strLength; ++i) {
      const int char_here = inputStr[i];
      const int char_before = i>0 ? inputStr[i-1] : '!';
      const int char_after = i<strLength-1 ? inputStr[i+1] : '@';

      // A. The character at the index is the same as the character at
      //    index+1.
      if (char_here==char_after) {
        const string localPalindrome = getNearbyPalindrome(inputStr,i,i+1);

        if (localPalindrome.length()>longestPalindrome.length())
          longestPalindrome=localPalindrome;

        else if (localPalindrome.length()==longestPalindrome.length() &&
                 localPalindrome>longestPalindrome)
          longestPalindrome=localPalindrome;
      }

      // B. The character at index-1 is the same as index+1.
      if (char_before==char_after) {
        const string localPalindrome = getNearbyPalindrome(inputStr,i-1,i+1);

        if (localPalindrome.length()>longestPalindrome.length())
          longestPalindrome=localPalindrome;

        else if (localPalindrome.length()==longestPalindrome.length() &&
                 localPalindrome>longestPalindrome)
          longestPalindrome=localPalindrome;
      }
    }

    return longestPalindrome;
  }

  // TODO: move definition of getNearbyPalindrome to here.
}

TEST_CASE("Palindromes Inside Substrings","[core]") {
  SECTION("Testing correct cases") {
    CHECK(getLongestPalindrome("eeeeee")=="eeeeee");
    REQUIRE(getLongestPalindrome("abccef")=="cc");
    CHECK(getLongestPalindrome("abccba")=="abccba");
    CHECK(getLongestPalindrome("abcba")=="abcba");
    CHECK(getLongestPalindrome("abccdefghiihgfed")=="defghiihgfed");
    CHECK(getLongestPalindrome("abccdefghihgfed")=="defghihgfed");
    CHECK(getLongestPalindrome("abcdeffedcbabccba")=="abcdeffedcba");
    CHECK(getLongestPalindrome("abcdeffedcbabcba")=="abcdeffedcba");
    CHECK(getLongestPalindrome("aaaaaabbbaaaaaa")=="aaaaaabbbaaaaaa");
  }
}
