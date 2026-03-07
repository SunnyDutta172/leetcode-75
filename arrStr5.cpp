345. Reverse Vowels of a String
Given a string s, reverse only all the vowels in the string and return it.
The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

class Solution {
public:
bool isVowel(char c){
  c = tolower(c);
  return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}
string reverseVowels(string s){
  int left = 0;
  int right = s.length()-1;
  while(left < right){
    while(left < right && !isVowel(s[left])){
      left++;
    }
    while(left < right && !isVowel(s[right])){
      right--;
    }
    if(left < right){
    swap(s[left], s[right]);
    left++;
    right--;
    }
  }
   return s;
  }
};




Key Pattern in This Problem

This is a Two Pointer Pattern.

Structure:

left -> start
right -> end

while(left < right)
    move left until condition
    move right until condition
    swap

Used in many problems:

Reverse string

Two sum in sorted array

Remove duplicates

Move zeroes

Container with most water

Recognize it when:

Work happens from both ends of the array/string

Only certain elements need to be swapped/processed.

Time Complexity
O(n)

Each pointer moves at most n times.

Space Complexity:

O(1)

In-place modification.

Example Dry Run

Input

s = "hello"

Step 1

h e l l o
  ↑     ↑

Step 2 (swap vowels)

h o l l e

Output

"holle"
