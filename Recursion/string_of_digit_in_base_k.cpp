
// Recursion: String of Digit in Base K  
// Leetcode Problem: 2149
//Difficulty: Easy
// Problem Link: https://leetcode.com/problems/string-of-digits-in-base-k/submissions/1697041419/
// Problem Statement: Given an integer n, return the sum of its digits when it is written in base k.

//Approach: Using Recursion
// 1. Define a recursive function that takes three parameters: n (the number), k (the base), and s (the sum of digits).
// 2. If n is 0, return the sum s.
// 3. Calculate the quotient q of n divided by k and the remainder r of n modulo k.
// 4. Add the remainder r to the sum s.
// 5. Call the recursive function with the quotient q, base k, and updated sum s.
// 6. The base case is when n becomes 0, at which point the function returns the accumulated sum of digits.

class Solution {
public:
    int ans(int n, int k, int s)
        {
            if (n == 0) return s;
            int q = n / k;
            int r = n % k;
            s += r;
            return ans(q,k,s);
        }
    int sumBase(int n, int k) {
        return ans(n,k,0);
    }
};

// Time Complexity: O(log n), where n is the number of digits in the base k
// Space Complexity: O(log n), due to the recursive call stack depth.
// Note: The recursion depth is logarithmic in relation to the value of n, as each recursive call reduces n by a factor of k.
