#define CATCH_CONFIG_MAIN
#include "catch2/catch_amalgamated.hpp"

#include <string>
#include <stdexcept>

using namespace std;

namespace {
  string getNearbyPalindrome(string str) {
    return str;
  }

  string getLongestPalindrome(string inputStr) {
    return "inputStr";
  }
}

TEST_CASE("Palindromes inside a vector","[palindrome]") {
  SECTION("Testing correct cases") {
    REQUIRE(getLongestPalindrome("eeeeee")=="eeeeee");
    CHECK(getLongestPalindrome("abccef")=="cc");
    CHECK(getLongestPalindrome("abccba")=="abccba");
    CHECK(getLongestPalindrome("abcba")=="abcba");
    CHECK(getLongestPalindrome("abccdefghiihgfed")=="defghiihgfed");
    CHECK(getLongestPalindrome("abccdefghihgfed")=="defghihgfed");
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
