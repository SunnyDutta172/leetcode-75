1431. Kids With the Greatest Number of Candies
There are n kids with candies. You are given an integer array candies, where each candies[i] represents the number of candies the ith kid has, and an integer extraCandies, denoting the number of extra candies that you have.

Return a boolean array result of length n, where result[i] is true if, after giving the ith kid all the extraCandies, they will have the greatest number of candies among all the kids, or false otherwise.

Note that multiple kids can have the greatest number of candies.

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies){
      int maxCandy = 0;
      for(int c : candies){
        maxCandy = max(maxCandy, c);
      }
      vector<bool> result;
      result.reserve(candies.size());
      for(int c : candies){
        if(c + extraCandies >= maxCandy){
          result.push_back(true);
        }else {
          result.push_back(false);
        }
      }
  return result;
  }
};


Step 1 — What the problem requires

For each child check:

𝑐andies[i] + extraCandies >= max(candies)

If true → true, otherwise → false.

Step 2 — Your Algorithm

Find the maximum candies among all kids.

Traverse again and check if each kid can reach or exceed that maximum after adding extraCandies.

Time Complexity:

First loop: O(n)

Second loop: O(n)
Total: O(n)

Space Complexity:

Result vector: O(n)
