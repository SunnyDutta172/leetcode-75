//Problem 1:  1768. Merge Strings Alternately
/* You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string. */
class Solution{
public :
string mergeAlternately(string word1, string word2){
  int i = 0;
  int j = 0;
  string result = "";
  while(i < word1.length() && j < word2.length() ){
    result += word1[i++];
    result += word2[j++];
  }
  while(i < word1.length()){
  result += word1[i++];
  }
  while(j < word2.length()){
  result += word2[j++];
  }
  return result;
  }
};


From LeetCode Problem 1768: Merge Strings Alternately you should extract general patterns, not just the solution. These patterns appear frequently in string and array problems.

1. Two-Pointer Traversal Pattern

You used two indices:

int i = 0;
int j = 0;

Each pointer moves through a different sequence.

General structure:

while(i < A.length() && j < B.length()){
    // use A[i] and B[j]
    i++;
    j++;
}

This pattern is used when:

Processing two arrays/strings simultaneously

Merging

Comparing sequences

Typical problems:

Merge two sorted arrays

Compare strings

Intersection of arrays

2. Handling Unequal Lengths

Your main loop stops when one string finishes:

while(i < word1.length() && j < word2.length())

Then you handle the leftover elements.

Pattern:

while(i < n && j < m) { ... }

while(i < n) { ... }

while(j < m) { ... }

This structure appears in many merge-type problems.

Example uses:

Merge step in sorting algorithms

Merging intervals

Combining lists

3. Post-Increment Index Usage

You used:

result += word1[i++];

Meaning:

Use word1[i]

Then increment i

Equivalent expanded form:

result += word1[i];
i++;

Concept: post-increment during traversal.

Useful for:

Compact pointer movement

Iterative scanning

4. Greedy Construction Pattern

You build the answer step-by-step:

result += ...

This is called incremental construction.

Many problems follow this structure:

initialize result
loop through input
decide what to append
append to result
return result

Common in:

String manipulation

Building paths

Generating outputs

5. Linear Scan Pattern

Your algorithm processes each character once.

Time complexity:

O(n + m)

Key insight:
Avoid nested loops if you only need a single pass.

6. Merge Pattern (Very Important)

This problem is a simplified merge.

General merge template:

while(i < n && j < m){
    choose element from A or B
}

append remaining elements

This pattern appears in:

Merge step of Merge Sort

Merging sorted arrays

Interval merging

Stream merging

7. Edge Case Awareness

Important cases this code handles automatically:

word1 = ""
word2 = "abc"

word1 = "abc"
word2 = ""

word1 longer
word2 longer

The leftover loops guarantee correctness.

Mental Template to Remember

When combining two sequences:

1. Use two pointers
2. Process both while both exist
3. Handle leftovers separately

Template:

while(i < n && j < m){
    // process both
}

while(i < n) { ... }

while(j < m) { ... }

Memorize this pattern. It appears in dozens of problems.
