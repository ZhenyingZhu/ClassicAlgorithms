/*
 * [Source] https://leetcode.com/problems/partition-equal-subset-sum/
 * [Difficulty]: Medium
 * [Tag]: Dynamic Programming
 */

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

// [Solution]: Backtracking with some tricky ordering change, it passed AC!
// [Corner Case]:
class SolutionBacktracking {
public:
    bool canPartition(vector<int>& nums) {
        if (nums.size() < 2)
            return false;

        int sum = 0;
        for (int &num : nums)
            sum += num;

        if (sum % 2 == 1)
            return false;

        sort(nums.begin(), nums.end(), greater<int>());

        return helper(0, nums, 0, sum / 2);
    }

    bool helper(int idx, vector<int> &nums, int preSum, int target) {
        if (preSum == target)
            return true;

        if (idx == (int)nums.size() || preSum > target)
            return false;

        // sum it
        if (helper(idx + 1, nums, preSum + nums[idx], target))
            return true;
        // not sum number on idx
        if (helper(idx + 1, nums, preSum, target))
            return true;
        return false;
    }
};

// [Solution]: Use DP on sum. Notice need to update the DP in a special order to make each num sum only once
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int &num : nums)
            sum += num;
        if (sum % 2 == 1)
            return false;

        int target = sum / 2;
        vector<bool> canSumTo(target + 1, false);
        canSumTo[0] = true;

        for (int idx = 0; idx < (int)nums.size(); ++idx) {
            // in reverse order so that nums[idx] will not be used twice
            for (int subsetSum = target; subsetSum >= nums[idx]; --subsetSum) {
                if (canSumTo[subsetSum])
                    continue;
                if (canSumTo[subsetSum - nums[idx]]) {
                    canSumTo[subsetSum] = true;
                    continue;
                }
            }
        }
        return canSumTo[target];
    }
};

int main() {
    Solution sol;

    //vector<int> nums = {1, 5, 11, 5};
    //vector<int> nums = {1, 2, 3, 5};
    vector<int> nums = {2, 2, 3, 5};
    cout << sol.canPartition(nums) << endl;

    return 0;
}
