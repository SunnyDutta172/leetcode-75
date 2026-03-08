334. Increasing Triplet Subsequence
Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k].
If no such indices exists, return false.

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX;
        int second = INT_MAX;
        for(int num : nums){
            if(num <= first){
                first = num;
            }else if(num <= second){
                second = num;
            }else {
                return true;
            }
        }
        return false;
    }
};

Look at the three conditions carefully.

if(num <= first)
    first = num;

else if(num <= second)
    second = num;

else
    return true;

These three branches mean three different things.

1. First condition
num <= first

We found a new smaller number.

So update the smallest value.

Example:

nums = [5, 3]
first = 5
num = 3 → first = 3
2. Second condition
num <= second

This means:

first < num <= second

So num becomes the second smallest number.

Example:

nums = [2,5]
first = 2
second = 5

We now have:

first < second
3. The else condition

The else runs only when both previous conditions fail.

So:

num > first
num > second

Since we already ensured:

first < second

Now we have:

first < second < num

That is exactly the increasing triplet.

So the algorithm returns true.

Example walk-through
nums = [2,1,5,0,4,6]

Start:

first = ∞
second = ∞
num = 2
first = 2
num = 1
first = 1
num = 5
second = 5

Now we have:

1 < 5
num = 0
first = 0

Now:

0 < 5
num = 4
second = 4

Now:

0 < 4
num = 6

Check conditions:

6 <= first ?  → no
6 <= second ? → no

So we enter else:

0 < 4 < 6

Triplet exists → return true.

Key idea

The algorithm continuously tries to build the smallest possible pair:

first < second

The moment a number larger than both appears, the triplet is confirmed.

Mental shortcut

Think of it like this:

first  → smallest number seen
second → second smallest number after first
num    → if bigger than both → triplet

So the else condition works because all smaller cases were already eliminated.
