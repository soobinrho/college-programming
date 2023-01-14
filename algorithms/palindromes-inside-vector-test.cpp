#include "palindromes-inside-vector.hpp"
#include "catch2/catch_amalgamated.hpp"

TEST_CASE("Finding the best fit palindrome in a vector","[palindrome]") {
  REQUIRE(getLongestPalindrome("abccef")=="cc");
  REQUIRE(getLongestPalindrome("abccba")=="abccba");
  REQUIRE(getLongestPalindrome("abcba")=="abcba");
  REQUIRE(getLongestPalindrome("abccdefghiihgfed")=="defghiihgfed");
  REQUIRE(getLongestPalindrome("abccdefghihgfed")=="defghihgfed");
}
