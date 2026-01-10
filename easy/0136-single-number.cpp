// Problem: Single Number
// Difficulty: Easy
// Topic: Array, Bit Manipulation
// LeetCode URL: https://leetcode.com/problems/single-number/

// Approach:
// Use XOR to find the unique element.
// XOR of a number with itself is 0, and XOR with 0 is the number itself.
// Since every element appears twice except one, XOR-ing all elements results in the single number.

// Example:
// Suppose nums = {1, 2, 4, 2, 1}
// All duplicate elements cancel out due to XOR properties(i.e. 2^2 = 0 and 1^1 = 0), leaving only the element that appears once.
// Final result = 4

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int val : nums) {
            ans ^= val;
        }
        return ans;
    }
};