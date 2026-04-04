// Problem: Two Sum
// Difficulty: Easy
// Topic: Array, Hash Table
// LeetCode URL: https://leetcode.com/problems/two-sum

// Approach:
// We use a hash map (unordered_map) to store elements and their indices as we iterate.
// For each element nums[i], we check if (target - nums[i]) already exists in the map.
// If it exists, we have found the pair and return their indices.
// Otherwise, we store the current element with its index in the map.

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        int i;

        for (i = 0; i < nums.size(); i++) {
            if (m.find(target - nums[i]) != m.end()) {
                return {m[target - nums[i]], i};
            }
            m[nums[i]] = i;
        }
        return {};
    }
};