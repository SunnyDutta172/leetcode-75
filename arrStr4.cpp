605. Can Place Flowers
You have a long flowerbed in which some of the plots are planted, and some are not.
However, flowers cannot be planted in adjacent plots.
Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, 
and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
      int size = flowerbed.size();
      for(int i = 0; i < size; i++){
        if(flowerbed[i] == 0 &&(i == 0 || flowerbed[i-1] == 0) && (i == size-1 || flowerbed[i+1] == 0)){
          flowerbed[i] = 1;
          n--;
          if(n == 0) return true;
        }
      }
    return n <= 0;
    }
};



1. Current plot must be empty
flowerbed[i] == 0

If the plot already has a flower (1), planting is impossible.

Example:

[1,0,0]
 ^

At index 0 → cannot plant because it already contains a flower.

2. Left neighbor must be empty
(i == 0 || flowerbed[i-1] == 0)

Two possibilities:

i == 0 → first position, no left neighbor

or the left plot contains 0

Example:

[0,0,0]
   ^

Left side is 0 → allowed.

Example where it fails:

[1,0,0]
   ^

Left side is 1 → cannot plant.

3. Right neighbor must be empty
(i == size - 1 || flowerbed[i+1] == 0)

Two possibilities:

i == size - 1 → last position

or the right plot contains 0

Example:

[0,0,0]
   ^

Right side is 0 → allowed.

Failing case:

[0,0,1]
   ^

Right side is 1 → cannot plant.

Combined meaning

You can plant only if:

left = empty
current = empty
right = empty

or if you are at the edges where one side doesn't exist.


  flowerbed[i] = 1;

This plants a flower at position i.

The problem rule says no two adjacent flowers can exist.
Once you plant here, the array becomes updated so the next iteration will see:

... 0 0 0 ...
      ↑

after planting:

... 0 1 0 ...
      ↑

This prevents the algorithm from planting at i+1.

2.
n--;

n represents how many flowers still need to be planted.

Every time you successfully plant one:

required flowers = required flowers - 1

Example:

flowerbed = [1,0,0,0,1]
n = 1

At index 2:

[1,0,0,0,1]
     ↑

Valid spot → plant:

[1,0,1,0,1]
n = 0

Now the requirement is satisfied.

Why both are necessary
Line	Purpose
flowerbed[i] = 1	updates the garden so future checks are correct
n--	tracks how many flowers are still needed



1. Greedy Placement Pattern

Core idea:

Make the locally valid decision immediately.

At each index you check:

Can I plant here?

If yes → plant immediately.

Why this works:
Planting earlier never harms future placements, because the only restriction is adjacency.

This is the Greedy Strategy.

Pattern:

scan → check condition → take action immediately

Used in problems like:

Jump Game

Gas Station

2. Neighbor Checking Pattern

Many array problems require checking adjacent elements safely.

General structure:

check current
check left neighbor
check right neighbor

But boundaries must be handled carefully.

Safe pattern:

(i == 0 || left condition)
(i == n-1 || right condition)

This prevents out-of-bounds errors.

You will use this pattern in:

matrix traversal

simulation problems

grid problems

3. In-Place Simulation

You modify the input array while iterating.

flowerbed[i] = 1

Why?

Because future decisions must see the updated state.

This is called:

Simulation with in-place updates

Used in problems like:

seat allocation

scheduling

interval placement

4. Early Termination Optimization

You added:

if(n == 0) return true;

Pattern:

Stop when goal achieved

This improves performance in large inputs.

General Template Learned
for each position:
    if placement is valid:
        place item
        update requirement
        if goal reached:
            stop early
Mental Model

Think of it like placing soldiers on a battlefield:

Rules:

No soldier next to another.

Strategy:

Move left → right

Place whenever possible.

That is greedy placement under constraints.

Important Skill You Practiced

You trained:

boundary handling

greedy decision making

array simulation

adjacency constraints

These appear in many medium-level problems.
