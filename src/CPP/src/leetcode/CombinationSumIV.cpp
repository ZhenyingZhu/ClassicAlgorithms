/*
 * [Source] https://leetcode.com/problems/combination-sum-iv/
 * [Difficulty]: Medium
 * [Tag]: Dynamic Programming
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// [Solution]: Use a hash map to store the ways a target can make from. For each target, break it with each number, and get a list of new targets.
// [Corner Case]: If negative numbers are allowed, cannot have a pair of negative number and positive number sum up to 0.
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if (nums.empty())
            return 0;

        sort(nums.begin(), nums.end());
        unordered_map<int, int> targetWays;

        return helper(target, nums, targetWays);
    }

    int helper(int target, vector<int> &nums, unordered_map<int, int> &targetWays) {
        if (target == 0)
            return 1;

        if (targetWays.find(target) != targetWays.end())
            return targetWays[target];

        int ways = 0;
        for (int i = 0; i < (int)nums.size() && target >= nums[i]; ++i) {
            ways += helper(target - nums[i], nums, targetWays);
        }

        targetWays[target] = ways;
        return ways;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 3};
    cout << sol.combinationSum4(nums, 4) << endl;

    return 0;
}
