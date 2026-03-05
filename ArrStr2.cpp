//1071. Greatest Common Divisor of Strings
/* For two strings s and t, we say "t divides s" if and only if s = t + t + t + ... + t + t (i.e., t is concatenated with itself one or more times).

Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.*/
In C++, substr(start, length) means:

start → starting index
length → number of characters to take

So:

str.substr(0,2)

means:

start at index 0
take 2 characters


class Solution {
public:
string gcdOfStrings(string str1, string str2){
  if(str1 + str2 != str2 + str1) return "";
    int g = gcd(str1.length(), str2.length());
  return str1.substr(0,g);
  }
};

Example

Input

str1 = "ABCABC"
str2 = "ABC"

Step 1

ABCABC + ABC
=
ABC + ABCABC

Valid.

Step 2

gcd(6,3) = 3

Step 3

str1.substr(0,3) = "ABC"

Output

"ABC"
Complexity

Time

O(n + m)

Space

O(1)
Concepts You Should Learn From This
1. Pattern detection in strings

If two strings share a divisor pattern:

A + B == B + A

This trick appears in multiple string problems.

2. Using mathematical GCD in strings

Sometimes the structure of repetition depends on the GCD of lengths.

3. String repetition reasoning

If a string divides another:

str = base repeated k times

Example

ABCABCABC
= "ABC" repeated 3 times
Core Pattern to Remember

For string divisibility problems:

1. Check concatenation symmetry
2. Use gcd(length1, length2)
3. Extract prefix
