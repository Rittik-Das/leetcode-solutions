// Problem: Maximum Subarray
// Difficulty: Medium
// Topic: Array
// LeetCode URL: https://leetcode.com/problems/maximum-subarray

// Approach:
// Use a running sum to track the current subarray sum
// Track the maximum sum obtained during traversal
// A negative running sum does not contribute to a maximum subarray
// Reset the running sum when it becomes negative
// The maximum tracked sum is the answer

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int max_sum = INT_MIN, current_sum = 0;
        for (auto val : nums) 
        {
            current_sum += val;
            max_sum = max(current_sum, max_sum);
            if (current_sum < 0) 
            {
                current_sum = 0;
            }
        }
        return max_sum;
    }
};