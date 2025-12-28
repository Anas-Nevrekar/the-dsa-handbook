11. Container_With_Most_Water
Difficulty: medium
Alright, let's walk through this solution.

### 1. Problem Understanding
We're given a series of vertical lines, each represented by a height value in an array. Our task is to pick two of these lines that, when combined with the x-axis, form a container that can hold the maximum amount of water. The container's capacity is determined by the distance between the two lines (its width) and the height of the shorter of the two lines.

### 2. Approach
The code uses a "two-pointer" strategy. We start with two pointers, one at the very left end and one at the very right end of the `height` array. This gives us the widest possible container initially. We calculate its area. To potentially find a larger area, we need to adjust our pointers. The key insight is that if we move the *taller* of the two current lines inwards, the width *always* decreases, and the height cannot possibly increase beyond the *current* shorter line. So, moving the taller line is not a promising step. However, if we move the *shorter* line inwards, the width still decreases, but there's a chance we might encounter a *new* line that is taller than the old shorter line. This new, taller line could potentially compensate for the reduced width and lead to a larger overall area. By consistently discarding the shorter line, we effectively explore configurations that have the best chance of maximizing the container's height while still making progress towards the center.

### 3. Algorithm Steps
*   Initialize a left pointer (`lp`) at the beginning of the `height` array and a right pointer (`rp`) at its end.
*   Keep track of the `maxWater` (largest area) found so far, initialized to zero.
*   Continue iterating as long as the left pointer is to the left of the right pointer:
    *   Calculate the current `width` of the container using the distance between `rp` and `lp`.
    *   Determine the effective `ht` (height) of the container, which is the minimum of the heights at `lp` and `rp`.
    *   Calculate the `currWater` (current area) by multiplying `width` and `ht`.
    *   Update `maxWater` if `currWater` is greater than the current `maxWater`.
    *   Decide which pointer to move: if the height at `lp` is less than the height at `rp`, increment `lp`. Otherwise (if `height[rp]` is less than or equal to `height[lp]`), decrement `rp`. This ensures we always move the pointer associated with the shorter line inwards.
*   Once the pointers meet or cross, the loop terminates.
*   Return the `maxWater` found.

### 4. Time Complexity
The algorithm processes the array using two pointers that converge. In each step of the `while` loop, one of the pointers moves inwards. This means the loop will run at most `N` times, where `N` is the number of elements in the `height` array. Therefore, the time complexity is linear, or O(N).

### 5. Space Complexity
The solution only uses a few variables to store pointer positions, current area, and maximum area. These variables take up a constant amount of memory regardless of the input array's size. No additional data structures are allocated based on input size. Thus, the space complexity is constant, or O(1).
