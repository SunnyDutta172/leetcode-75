151. Reverse Words in a String
Given an input string s, reverse the order of the words.
A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
Return a string of the words in reverse order concatenated by a single space.
Note that s may contain leading or trailing spaces or multiple spaces between two words.
The returned string should only have a single space separating the words. Do not include any extra spaces.

class Solution {
public :
  string reverseWords(string s){
    vector<string> words;
    string temp = "";
    for(int i = 0; i < s.length(); i++){
      if(s[i] != ' '){
        temp += s[i];
      }else {
        if(temp != ""){
          words.push_back(temp);
          temp = "";
        }
      }
    }
    if(temp != ""){
      words.push_back(temp);
    }
    string result = "";
    for(int i = words.size()-1; i >= 0; i--){
      result += words[i];
      if(i != 0){
        result += " ";
      }
    }
  return result;
  }
};


This simply builds the output string from the end of the vector.
Example:
["the","sky","is","blue"]

Result:
"blue is sky the"
  
2. Complexity
Time complexity:
O(n)
One pass to extract words
One pass to rebuild string

Space complexity:
O(n)
Extra storage for vector<string>.

3. Pattern Used
This problem uses the Tokenization Pattern:
Scan string
Extract tokens (words)
Store them
Process them (reverse order)

Common problems using this idea:
Reverse words in a string
Split sentence
Parsing input strings
