#define CATCH_CONFIG_MAIN
#include "catch2/catch_amalgamated.hpp"

#include <string>
#include <stdexcept>

using namespace std;

namespace {
  string getNearbyPalindrome(string& str) {
    /*
     *   This is used by getLongestPalindrome function for finding
     *   a nearby palindrome given its 
     */

    return str;
  }


  string getLongestPalindrome(string inputStr) {
    /*
     *   A function that finds the longest palindrome inside substrings.
     *   For example, an input of "abcdeffedcbabccba" first finds all
     *   palindromes including "abcdeffedcba" and "abccba". It then
     *   returns the longest of all.
     */

    return inputStr;
  }

  // TODO: move definition of getNearbyPalindrome to here
}

TEST_CASE("Palindromes Inside Substrings","[core]") {
  SECTION("Testing correct cases") {
    REQUIRE(getLongestPalindrome("eeeeee")=="eeeeee");
    CHECK(getLongestPalindrome("abccef")=="cc");
    CHECK(getLongestPalindrome("abccba")=="abccba");
    CHECK(getLongestPalindrome("abcba")=="abcba");
    CHECK(getLongestPalindrome("abccdefghiihgfed")=="defghiihgfed");
    CHECK(getLongestPalindrome("abccdefghihgfed")=="defghihgfed");
    CHECK(getLongestPalindrome("abcdeffedcbabccba")=="abcdeffedcba");
    CHECK(getLongestPalindrome("abcdeffedcbabcba")=="abcdeffedcba");
  }

  SECTION("Testing exceptions") {
    string message = "Invalid input.";
    CHECK_THROWS_MATCHES(
      getLongestPalindrome("111"),
      logic_error,
      Catch::Matchers::ExceptionMessageMatcher(message)
    );
  }
}
