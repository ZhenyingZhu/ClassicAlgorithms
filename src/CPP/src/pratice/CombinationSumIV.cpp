#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// [Source]: https://leetcode.com/problems/combination-sum-iv/
// http://www.1point3acres.com/bbs/thread-224947-1-1.html

// [Solution]: Back tracking using DP
// [Corner Case]: Notice if there are duplicates, DP doesn't work. If there are negative numbers, need to avoid sum to 0
class Solution {
public:
    int combinationSum4(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> targetWays;
        return helper(nums, target, targetWays);
    }

    int helper(vector<int> &nums, int target, unordered_map<int, int> &targetWays) {
        if (targetWays.count(target))
            return targetWays[target];
        if (target == 0)
            return 1;
        if (target < 0)
            return 0;

        int ways = 0;
        // to make it exit first when nums smaller than target, need the array to be sorted
        for (int i = 0; i < (int)nums.size() && nums[i] <= target; ++i) {
            ways += helper(nums, target - nums[i], targetWays);
        }
        targetWays[target] = ways;
        return ways;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1,2,3};
    cout << sol.combinationSum4(nums, 4) << endl;

    return 0;
}
