#define CATCH_CONFIG_MAIN
#include "catch2/catch_amalgamated.hpp"

#include <string>

using namespace std;

string getNearbyPalindrome(string str) {
  return str;
}

string getLongestPalindrome(string inputStr) {
  return inputStr;
}

TEST_CASE("Palindromes inside a vector","[palindrome]") {
  SECTION("Testing all palindrome cases") {
    REQUIRE(getLongestPalindrome("abccef")=="cc");
    REQUIRE(getLongestPalindrome("abccba")=="abccba");
    REQUIRE(getLongestPalindrome("abcba")=="abcba");
    REQUIRE(getLongestPalindrome("abccdefghiihgfed")=="defghiihgfed");
    REQUIRE(getLongestPalindrome("abccdefghihgfed")=="defghihgfed");
  }
}
