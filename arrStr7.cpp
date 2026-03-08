238. Product of Array Except Self
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.

class Solution {
public :
vector<int> productExceptSelf(vector<int>& nums) {
  int n = nums.size();
  vector<int> answer(n,1);
  int leftProduct = 1;
  for(int i = 0; i < n; i++){
    answer[i] = leftProduct;
    leftProduct *= nums[i];
  }
  int rightProduct = 1;
  for(int i = n-1; i >= 0; i--){
    answer[i] *= rightProduct;
    rightProduct *= nums[i];
  }
 return answer;
 }
};

Your implementation is the correct optimal solution for this problem. The idea is to compute prefix products and suffix products without using division.

Core Idea

For every index i:

answer[i] = product of elements left of i × product of elements right of i

Example:

nums = [1,2,3,4]

answer[0] = 2*3*4 = 24
answer[1] = 1*3*4 = 12
answer[2] = 1*2*4 = 8
answer[3] = 1*2*3 = 6

Instead of calculating this separately (which would be O(n²)), you compute it in two passes.

Step 1 — Prefix (left products)

Code:

int leftProduct = 1;
for(int i = 0; i < n; i++){
    answer[i] = leftProduct;
    leftProduct *= nums[i];
}

Meaning:

answer[i] = product of all elements before i

Example:

nums = [1,2,3,4]

Iteration:

i	leftProduct	answer
0	1	[1,,,_]
1	1	[1,1,,]
2	2	[1,1,2,_]
3	6	[1,1,2,6]

Now:

answer = [1,1,2,6]

These are prefix products.

Step 2 — Suffix (right products)

Code:

int rightProduct = 1;
for(int i = n-1; i >= 0; i--){
    answer[i] *= rightProduct;
    rightProduct *= nums[i];
}

Meaning:

Multiply the product of elements to the right

Iteration:

Start:

answer = [1,1,2,6]
rightProduct = 1
i	answer[i]	rightProduct
3	6×1=6	4
2	2×4=8	12
1	1×12=12	24
0	1×24=24	24

Final:

answer = [24,12,8,6]
Why Division Is Not Needed

Typical naive solution:

totalProduct / nums[i]

But this fails when zeros exist.

Example:

[1,2,0,4]

Division breaks. The prefix–suffix method works correctly.

Complexity

Time:

O(n)

Two passes over the array.

Space:

O(1) extra space

answer is not counted because it is required output.

Pattern Learned

This problem teaches the Prefix–Suffix Pattern.
General template:

prefix[i] = prefix[i-1] * nums[i-1]
suffix[i] = suffix[i+1] * nums[i+1]

answer[i] = prefix[i] * suffix[i]

Optimized version merges both into one array (your code).
Important Interview Insight
This pattern appears in many problems:
Product except self
Trapping rain water
Maximum product subarray
Range product queries
Prefix sum problems
