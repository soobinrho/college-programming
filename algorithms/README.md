# Algorithms
These are the problem sets I really liked from books, LeetCode,
or Codeforces. All of them are written in C++.
For test cases, I mostly use `Catch2`.

<br>

***List of Algorithms***
```
keeping-index.cpp
palindromes-inside-substrings.cpp
parsing-logs.cpp
...
```

<br>

***How to Compile and Run***
```bash
# Compile example
g++ -o _ palidnromes-inside-substrings.cpp catch2/*

# Run
./_ -s
```

<br>

***Output Example***
```
Randomness seeded to: 2319438253

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
_ is a Catch2 v3.2.1 host application.
Run with -? for options

-------------------------------------------------------------------------------
Palindromes Inside Substrings
  Testing correct cases
-------------------------------------------------------------------------------
palindromes-inside-substrings.cpp:35
...............................................................................

palindromes-inside-substrings.cpp:36: PASSED:
  REQUIRE( getLongestPalindrome("eeeeee")=="eeeeee" )
with expansion:
  "eeeeee" == "eeeeee"

palindromes-inside-substrings.cpp:37: FAILED:
  CHECK( getLongestPalindrome("abccef")=="cc" )
with expansion:
  "abccef" == "cc"

palindromes-inside-substrings.cpp:38: PASSED:
  CHECK( getLongestPalindrome("abccba")=="abccba" )
with expansion:
  "abccba" == "abccba"

palindromes-inside-substrings.cpp:39: PASSED:
  CHECK( getLongestPalindrome("abcba")=="abcba" )
with expansion:
  "abcba" == "abcba"

palindromes-inside-substrings.cpp:40: FAILED:
  CHECK( getLongestPalindrome("abccdefghiihgfed")=="defghiihgfed" )
with expansion:
  "abccdefghiihgfed" == "defghiihgfed"

palindromes-inside-substrings.cpp:41: FAILED:
  CHECK( getLongestPalindrome("abccdefghihgfed")=="defghihgfed" )
with expansion:
  "abccdefghihgfed" == "defghihgfed"

palindromes-inside-substrings.cpp:42: FAILED:
  CHECK( getLongestPalindrome("abcdeffedcbabccba")=="abcdeffedcba" )
with expansion:
  "abcdeffedcbabccba" == "abcdeffedcba"

palindromes-inside-substrings.cpp:43: FAILED:
  CHECK( getLongestPalindrome("abcdeffedcbabcba")=="abcdeffedcba" )
with expansion:
  "abcdeffedcbabcba" == "abcdeffedcba"

-------------------------------------------------------------------------------
Palindromes Inside Substrings
  Testing exceptions
-------------------------------------------------------------------------------
palindromes-inside-substrings.cpp:46
...............................................................................

palindromes-inside-substrings.cpp:48: FAILED:
  CHECK_THROWS_MATCHES( getLongestPalindrome("111"), logic_error, Catch::Matchers::ExceptionMessageMatcher(message) )
because no exception was thrown where one was expected:

===============================================================================
test cases: 1 | 1 failed
assertions: 9 | 3 passed | 6 failed
```

<br>
<br>
<br>
