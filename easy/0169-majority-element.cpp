// Problem: Majority Element
// Difficulty: Easy
// Topic: Array
// LeetCode URL: https://leetcode.com/problems/majority-element

// Approach:
// Moore's Voting Algorithm.

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int freq = 0, ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (freq == 0) {
                ans = nums[i];
            }
            if (ans == nums[i]) {
                freq++;
            } else {
                freq--;
            }
        }

        // Verify whether the ans occurs more than n/2 times or not.
        int count = 0;
        for (int val : nums) {
            if (val == ans) {
                count++;
            }
        }

        if (count > nums.size() / 2) {
            return ans;
        } else {
            return -1;
        }
    }
};